#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      8
#define NUM_LEDS      8
#define MINRANDOM      10
#define MAXRANDOM      255

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // delay for half a second

const int analogPin = A0;
int value;      //variable que almacena la lectura analógica raw
int position;   //posicion del potenciometro en tanto por ciento

void setup() {
 
  pixels.setBrightness(5);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() {
  value = analogRead(analogPin);       // realizar la lectura analógica raw
  position = map(value, 0, 1023, 0, 10);  // convertir a porcentaje
  rotador(position); 
}

void rotador(int valor){
  switch(valor){
    case 1: escalaRojo();
      break;
    case 2: escalaAmarillo();
      break;

    case 3: escalaRojoAmarillo();
      break;

    case 4: escalaAzul();
      break;

    case 5: escalaMorado();
      break;
      
    case 6: escalaAzulMorado();
      break;
    
    case 7: escalaVerde();
      break;

    case 8: randomColors();
      break;

    case 9: randomBlue();
      break;

    case 0: Fire(55,120,100);
      break;
  }
}


void escalaRojo(){
  int r=255, g=0, b=0;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r -= 22;
    g += 8;
    b += 0;
  }
}

void escalaAmarillo(){
  int r=255, g=255, b=0;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r -= 0;
    g += 0;
    b += 10;
  }
}

void escalaRojoAmarillo(){
  int r=255, g=0, b=0;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r -= 15;
    g += 20;
    b += 3;
  }
}

void escalaAzul(){
  int r=0, g=0, b=255;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r += 0;
    g += 8;
    b -= 29;
  }
  
}

void escalaMorado(){
  int r=255, g=0, b=255;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r -= 30;
    g += 5;
    b -= 30;
  }
  
}

void escalaAzulMorado(){
  int r=0, g=0, b=255;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r += 30;
    g += 5;
    b -= 10;
  }
  
}

void escalaVerde(){
  int r=0, g=255, b=0;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r += 7;
    g -= 27;
    b += 0;
  }
}

void randomColors(){
  int r=random(MINRANDOM, MAXRANDOM), g=random(MINRANDOM, MAXRANDOM), b=random(MINRANDOM, MAXRANDOM);
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r = random(MINRANDOM, MAXRANDOM);
    g = random(MINRANDOM, MAXRANDOM);
    b = random(MINRANDOM, MAXRANDOM);
  }
}

void randomBlue(){
  int r=0, g=0, b=random(MINRANDOM, MAXRANDOM);
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
    r = random(0, 50);
    g = random(0, 50);
    b = random(MINRANDOM, MAXRANDOM);
  }
}

void off(){
  int r=0, g=0, b=0;
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show(); 
    delay(delayval);
  }
}

//FIRE

void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NUM_LEDS];
  int cooldown;
  
  // Step 1.  Cool down every cell a little
  for( int i = 0; i < NUM_LEDS; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);
    
    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }
  
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
    
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < NUM_LEDS; j++) {
    setPixelHeatColor(j, heat[j] );
  }

  showStrip();
  delay(SpeedDelay);
}

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature/255.0)*191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
 
  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    setPixel(Pixel, 255, 255, heatramp);
  } else if( t192 > 0x40 ) {             // middle
    setPixel(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    setPixel(Pixel, heatramp, 0, 0);
  }
}

void showStrip() {
   pixels.show();
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
   pixels.setPixelColor(Pixel, pixels.Color(red, green, blue));
}
