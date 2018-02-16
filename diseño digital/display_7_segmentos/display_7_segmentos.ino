// Arduino 7 segment display example software
// http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
// License: http://www.opensource.org/licenses/mit-license.php (Go crazy)
 
int pina = 13;
int pinb = 12;
int pinc = 11;
int pind = 10;

void setup() {                
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(pina, INPUT);
  pinMode(pinb, INPUT);
  pinMode(pinc, INPUT);
  pinMode(pind, INPUT);
  //writeDot(0);  // start with the "dot" off
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
  

  
  bool a = digitalRead(pina);
  bool b = digitalRead(pinb);
  bool c = digitalRead(pinc);
  bool d = digitalRead(pind);

  digitalWrite(2, funcionA(a,b,c,d));
  digitalWrite(3, funcionB(a,b,c,d));
  digitalWrite(4, funcionC(a,b,c,d));
  digitalWrite(5, funcionD(a,b,c,d));
  digitalWrite(6, funcionE(a,b,c,d));
  digitalWrite(7, funcionF(a,b,c,d));
  digitalWrite(8, funcionG(a,b,c,d));
  
  delay(000);
}
