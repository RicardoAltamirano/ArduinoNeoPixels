// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8
#define MINRANDOM      10
#define MAXRANDOM      255
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second


const int analogPin = A0;
int value;      //variable que almacena la lectura analógica raw
int position;   //posicion del potenciometro en tanto por ciento
 


void setup() {
 
  pixels.setBrightness(40);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() {
/*
  escalaRojo(); delay(2000);
  escalaAmarillo();delay(2000);
  escalaRojoAmarillo();delay(2000);
  escalaAzul();delay(2000);
  escalaMorado();delay(2000);
  escalaAzulMorado();delay(2000);
  escalaVerde();delay(2000);
  randomColors();delay(2000);
  randomBlue();delay(2000);
*/
  value = analogRead(analogPin);       // realizar la lectura analógica raw
  position = map(value, 0, 1023, 0, 10);  // convertir a porcentaje
 
  rotador(position);

  
}

void rotador(int i){
  int r=255, g=0, b=0;
  for(int j = 0 ; j < pixels.numPixels(); j ++){
    if(i > 7){
      pixels.setPixelColor(7, pixels.Color(200, 100, 0));
    }else{
      if(i == j){
        pixels.setPixelColor(j, pixels.Color(200, 100, 0));
      }else{
        pixels.setPixelColor(j, pixels.Color(0, 0, 0));
      }
    }
  }
 // pixels.setPixelColor(i, pixels.Color(r, g, b));
  
  pixels.show(); 
//  delay(delayval);
     
  
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


