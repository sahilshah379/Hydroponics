#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    10
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
    delay(3000);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}
void loop() {
    for (int x = 0; x < NUM_LEDS; x++) {
        leds[x] = CRGB(255, 0, 255);
    }
    FastLED.show();
    delay(10);
}

//#define DHpin 8
//byte dat [5];
//
//void setup () {
//  Serial.begin (9600);
//  pinMode (DHpin, OUTPUT);
//}
// 
//void loop () {
//    digitalWrite (DHpin, LOW);
//    delay (30);
//    digitalWrite (DHpin, HIGH);
//    delayMicroseconds (40);
//    pinMode (DHpin, INPUT);
//    while (digitalRead (DHpin) == HIGH);
//    delayMicroseconds (80);
//    if (digitalRead (DHpin) == LOW);
//    delayMicroseconds (80);
//    for (int i = 0; i < 4; i ++) {
//        byte data;
//        for (int i = 0; i < 8; i ++) {
//            if (digitalRead (DHpin) == LOW) {
//                while (digitalRead (DHpin) == LOW);
//                delayMicroseconds (30);
//                if (digitalRead (DHpin) == HIGH){
//                    dat[i] |= (1 << (7-i));
//                }
//                while (digitalRead (DHpin) == HIGH);
//            }
//        }
//    }
//    pinMode (DHpin, OUTPUT);
//    digitalWrite (DHpin, HIGH);
//    
//    Serial.print ("Current humdity =");
//    Serial.print (dat [0], DEC);
//    Serial.print ('.');
//    Serial.print (dat [1], DEC);
//    Serial.println ('%');
//    Serial.print ("Current temperature =");
//    Serial.print (dat [2], DEC);
//    Serial.print ('.');
//    Serial.print (dat [3], DEC);
//    Serial.println ('C');
//    delay (700);
//}
