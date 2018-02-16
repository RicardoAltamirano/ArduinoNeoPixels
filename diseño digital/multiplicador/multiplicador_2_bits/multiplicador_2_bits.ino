// Arduino sumador simple
 

int y[] = {1,1};
int x[] = {1,1};
int s[] = {0,0,0,0};
int c[] = {0,0,0,0};
int s1[] = {0,0,0,0,0};
int s2[] = {0,0,0,0,0};

int pinA1=0;
int pinB1=1;
int pinC1=2;
int pinD1=3;
int pinE1=4;
int pinF1=5;
int pinG1=6;

int pinA2=7;
int pinB2=8;
int pinC2=9;
int pinD2=10;
int pinE2=11;
int pinF2=12;
int pinG2=13;

void setup() {                
  pinMode(pinA1, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinC1, OUTPUT);
  pinMode(pinD1, OUTPUT);
  pinMode(pinE1, OUTPUT);
  pinMode(pinF1, OUTPUT);
  pinMode(pinG1, OUTPUT);

  pinMode(pinA2, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(pinC2, OUTPUT);
  pinMode(pinD2, OUTPUT);
  pinMode(pinE2, OUTPUT);
  pinMode(pinF2, OUTPUT);
  pinMode(pinG2, OUTPUT);
}

bool funcionS(bool x, bool y, bool ci) {
  bool result = (!ci && !x && y)||(!ci && x && !y)||(ci && !x && !y)||(ci && x && y);
  return result;
}

bool funcionCi(bool x, bool y, bool ci) {
  bool result = (ci && x)||(ci && y)||(x && y);
  return result;
}

bool funcionMult(bool x, bool y) {
  bool result = (x && y);
  return result;
}

bool funcionA(bool a, bool b, bool c, bool d) {
  bool result = (!a && c)||(b && c)||(a && !d)||(!b && !d)||(!a && b && d)||(a && !b && !c);
  return result;
}

bool funcionB(bool a, bool b, bool c, bool d) {
  bool result = (!a && !b)||(!b && !d)||(!a && !d && !c)||(!a && c && d)||(a && !c && d);
  return result;
}

bool funcionC(bool a, bool b, bool c, bool d) {
  bool result = (!a && !c)||(!a && d)||(d && !c)||(!a && b)||(a && !b);
  return result;
}

bool funcionD(bool a, bool b, bool c, bool d) {
  bool result = (a && !c)||(!a && !b && !d)||(b && !c && d)||(!b && c && d)||(b && c && !d);
  return result;
}

bool funcionE(bool a, bool b, bool c, bool d) {
  bool result = (!b && !d)||(c && !d)||(a && c)||(a && b);
  return result;
}

bool funcionF(bool a, bool b, bool c, bool d) {
  bool result = (!c && !d)||(b && !d)||(a && !b)||(a && c)||(!a && b && !c);
  return result;
}

bool funcionG(bool a, bool b, bool c, bool d) {
  bool result = (!b && c)||(c && !d)||(a && !b)||(a && d)||(!a && b && !c);
  return result;
}

void loop() {
  int cont=3;
  for(int j = 1; j > -1 ; j--){
    s1[cont]=funcionMult(x[1],y[j]);
    cont--;
    //Serial.println(cont,DEC);
  }
  cont=2;
  for(int k = 1; k > -1 ; k--){
    s2[cont]=funcionMult(x[0],y[k]);
    cont--;
  }

  /*s1[3]=funcionMult(1,0);
  s1[2]=funcionMult(1,1);
  s2[2]=funcionMult(0,0);
  s2[1]=funcionMult(0,1);
  */
  for (int i = 3; i > -1 ; i--){
    s[i]=funcionS(s1[i], s2[i], c[i]);
    c[i-1]=funcionCi(s1[i], s2[i], c[i]);
  }
  if(c[0] == 1){
    s[0]=1;
  }

  //s[0]=funcionS(1, 1, 0);
  digitalWrite(pinA1, funcionA(s[0],s[1],s[2],s[3]));
  digitalWrite(pinB1, funcionB(s[0],s[1],s[2],s[3]));
  digitalWrite(pinC1, funcionC(s[0],s[1],s[2],s[3]));
  digitalWrite(pinD1, funcionD(s[0],s[1],s[2],s[3]));
  digitalWrite(pinE1, funcionE(s[0],s[1],s[2],s[3]));
  digitalWrite(pinF1, funcionF(s[0],s[1],s[2],s[3]));
  digitalWrite(pinG1, funcionG(s[0],s[1],s[2],s[3]));
/*
  digitalWrite(pinA2, funcionA(c[0],c[1],c[2],c[3]));
  digitalWrite(pinB2, funcionB(c[0],c[1],c[2],c[3]));
  digitalWrite(pinC2, funcionC(c[0],c[1],c[2],c[3]));
  digitalWrite(pinD2, funcionD(c[0],c[1],c[2],c[3]));
  digitalWrite(pinE2, funcionE(c[0],c[1],c[2],c[3]));
  digitalWrite(pinF2, funcionF(c[0],c[1],c[2],c[3]));
  digitalWrite(pinG2, funcionG(c[0],c[1],c[2],c[3]));
*/
}
