#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    30
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
CRGB color;
unsigned long startTime;
boolean on;
long intervalOn = 14*3600*1000;
long intervalOff = 10*3600*1000;

void setup() {
    delay(3000);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    color = CRGB(255, 0, 255);
    on = true;
    startTime = millis();
}
void loop() {
    for (int x = 0; x < NUM_LEDS; x++) {
        leds[x] = color;
    }
    FastLED.show();

    unsigned long currentTime = millis();
    if (on && (currentTime - startTime >= intervalOn)) {
        color = CRGB(0, 0, 0);
        on = false;
        startTime = millis();
    } else if (!on && (currentTime - startTime >= intervalOff)) {
        color = CRGB(255, 0, 255);
        on = true;
        startTime = millis();
    }
}
