#include "FastLED.h"

#define DATA_PIN 3
#define NUM_LEDS 30

CRGB leds[NUM_LEDS];

void setup() {
  delay(100);
  //I used a WS2812B LED strip that I bought from Aliexpress
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.clear();
}

//Make the entire LED strip the given color
void fillStrip(CRGB color){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
  }
}

//Fills LED strip from the left to the right side
void fillStripLeft(CRGB color, int delayAmount){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(delayAmount);
  }
}

//Fills LED strip from the right to the left side
void fillStripRight(CRGB color, int delayAmount){
  for(int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = color;
    FastLED.show();
    delay(delayAmount);
  }
}

//Empty LED strip from the right to the left side
void emptyStripRight(CRGB color, int delayAmount){
  fillStrip(color);
  for(int i = NUM_LEDS; i >= 0; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(delayAmount);
  }
}

//Fills LED strip from the left to the right side
void emptyStripLeft(CRGB color, int delayAmount){
  fillStrip(color);
  delay(1000);
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(delayAmount);
  }
}

//Fills LED strip from the left to the right side
void closeStrip(CRGB color, int delayAmount){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    leds[NUM_LEDS - 1 - i] = color;
    FastLED.show();
    leds[i] = CRGB::Black;
    leds[NUM_LEDS - 1 - i] = CRGB::Black;
    delay(delayAmount);
  }
}

void loop() {
  fillStrip(CRGB::Green);
  delay(1000);

  fillStripLeft(CRGB::Blue, 50);
  delay(1000);

  fillStripRight(CRGB::Blue, 50);
  delay(1000);

  emptyStripRight(CRGB::Blue, 50);
  delay(1000);

  emptyStripLeft(CRGB::Blue, 50);
  delay(1000);

  closeStrip(CRGB::Red, 50);
  delay(1000);
}
