int analogPin = A3;
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(analogPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(analogPin, HIGH);  //analogWrite values from 0 to 255  
}
