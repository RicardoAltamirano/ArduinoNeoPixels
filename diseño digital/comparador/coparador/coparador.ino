// Arduino sumador simple
 

bool a[] = {1,1,1,0};
bool b[] = {1,1,0,0};

int pinIgual=3;
int pinMayor=2;
int pinMenor=4;

void setup() {                
  pinMode(pinIgual, OUTPUT);
  pinMode(pinMayor, OUTPUT);
  pinMode(pinMenor, OUTPUT);
}


bool funcionIgual(bool x[], bool y[]) {
  for(int i=0; i<4; i++){
    if(x[i]!=y[i]) return false;
  }
  return true;
}

bool funcionMayor(bool x[], bool y[]) {
  return ( (x[3]&&!y[3]) || (getX(3, x, y) && x[2] && !y[2] ) || (getX(3, x, y) && getX(2, x, y) && x[1] && !y[1]) ||
  (getX(3, x, y) && getX(2, x, y) && getX(1, x, y)&& x[0] && !y[0] )  );
}

bool funcionMenor(bool x[], bool y[]) {
  return ( (!x[3]&&y[3]) || (getX(3, x, y) && !x[2] && y[2] ) || (getX(3, x, y) && getX(2, x, y) && !x[1] && y[1]) ||
  (getX(3, x, y) && getX(2, x, y) && getX(1, x, y)&& !x[0] && y[0] )  );
}

bool getX(int indice, bool x[], bool y[]){
  return (x[indice]&&y[indice] || !x[indice]&&!y[indice]);  
}

void loop() {

  digitalWrite(pinIgual, funcionIgual(a,b));
  digitalWrite(pinMayor, funcionMayor(a,b));
  digitalWrite(pinMenor, funcionMenor(a,b));
  
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
