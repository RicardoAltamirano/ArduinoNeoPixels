// Arduino sumador simple
 
int pinX = 12;
int pinY = 8;
int pinS = 2;
int pinC = 4;

void setup() {                
  pinMode(pinS, OUTPUT);   
  pinMode(pinC, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
}

bool funcionS(bool x, bool y) {
  bool result = (!x && y)||(x && !y);
  return result;
}

bool funcionC(bool x, bool y) {
  bool result = (x && y);
  return result;
}

void loop() {
  bool x = digitalRead(pinX);
  bool y = digitalRead(pinY);
  bool s;
  bool c;

  digitalWrite(pinS, funcionS(x, y));
  digitalWrite(pinC, funcionC(x, y));
  
}
