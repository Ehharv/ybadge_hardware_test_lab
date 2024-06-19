#include <Arduino.h>
#include "SparkFun_LIS2DH12.h"
#include "yboard.h"
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>


#include "Arduino.h"
#include "yboard.h"

// Screen Constants
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_TITLE_HEIGHT 16
#define SCREEN_BODY_HEIGHT 48
// Screen Orientation
#define ZERO_DEG 0
#define NINETY_DEG 1
#define ONE_EIGHTY_DEG 2
#define TWO_SEVENTY_DEG 3
// Screen Brightness
#define BRIGHTNESS_DAMPER 0.8 // 0 is brightest
#define REFRESH_RATE 50       // Measured in ms

Adafruit_SSD1306 display(128, 64); // Create display

void setup(){
    delay(1000); // Display needs time to initialize
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // Initialize display with I2C address: 0x3C
    display.clearDisplay();
    display.setTextColor(1);
    display.setRotation(ZERO_DEG); // Can be 0, 90, 180, or 270
    display.setTextWrap(false);
    display.dim(BRIGHTNESS_DAMPER);
    display.display();
}

void loop(){
    display.clearDisplay();
    uint8_t text_size = 2;
    // Draw Title
    display.setCursor(0, 0);
    display.setTextSize(text_size);
    display.print("GPIO Test");
    display.display();

}