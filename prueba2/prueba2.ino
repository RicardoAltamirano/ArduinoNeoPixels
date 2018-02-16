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

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

void setup() {
 
  pixels.setBrightness(20);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() {

 // escalaRojo();
 // escalaAzul();
 // escalaMorado();
  escalaAzulMorado();
}

void escalaRojo(){
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
    r += 5;
    g += 5;
    b -= 30;
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

