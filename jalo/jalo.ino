void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}


void loop() {
  digitalWrite(5, HIGH);
  delay(700);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(6, HIGH);
  delay(700);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(7, HIGH);
  delay(700);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(100);
  
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  delay(50);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(50);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);
  delay(50);
  
  digitalWrite(6, HIGH);
  delay(700);
  digitalWrite(6, LOW);
  delay(100);
}
