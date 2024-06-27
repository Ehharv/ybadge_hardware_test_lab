#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#include "SparkFun_LIS2DH12.h"
#include "Arduino.h"
#include "yboard.h"

// Screen Constants
#define BRIGHTNESS_DAMPER 0.8 // 0 is brightest
#define REFRESH_RATE 50       // Measured in ms
#define ZERO_DEG 0



Adafruit_SSD1306 display(128, 64); // Create display

void setup() {
    Serial.begin(9600);
    Yboard.setup();

    // test speaker
    Yboard.play_notes("D C#8 D C8 D8 B8 G8< F<"); // Play fight song
  
    // Display setup
    delay(1000); // Display needs time to initialize
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // Initialize display with I2C address: 0x3C
    display.clearDisplay();
    display.setTextColor(1);
    display.setRotation(ZERO_DEG); // Can be 0, 90, 180, or 270
    display.setTextWrap(false);
    display.dim(BRIGHTNESS_DAMPER);
    display.display();

}

void loop() {
    // Test switches
    if (Yboard.get_switch(1)) {
        Yboard.set_led_color(1, 255, 0, 0);
    } else {
        Yboard.set_led_color(1, 0, 0, 0);
    }

    if (Yboard.get_switch(2)) {
        Yboard.set_led_color(2, 255, 0, 0);
    } else {
        Yboard.set_led_color(2, 0, 0, 0);
    }

    // Test buttons
    if (Yboard.get_button(1)) {
        Yboard.set_led_color(3, 255, 0, 0);
        Yboard.loop_speaker();
    } else {
        Yboard.set_led_color(3, 0, 0, 0);
    }

    if (Yboard.get_button(2)) {
        Yboard.set_led_color(4, 255, 0, 0);
    } else {
        Yboard.set_led_color(4, 0, 0, 0);
    }

    // Test Knob
    Yboard.set_led_color(5, map(Yboard.get_knob(), 0, 100, 0, 255), 0, 0);

    // Test accelerometer
    if (Yboard.accelerometer_available()) {
        accelerometer_data accel_data = Yboard.get_accelerometer();
        Yboard.set_led_color(6, map(accel_data.x, -1000, 1000, 0, 255), 0, 0);
        Yboard.set_led_color(7, map(accel_data.y, -1000, 1000, 0, 255), 0, 0);
        Yboard.set_led_color(8, map(accel_data.z, -1000, 1000, 0, 255), 0, 0);
    }

    // Test temp and humidity
    temperature_data temp_data = Yboard.get_temperature();
    if (temp_data.temperature > 26) {
        Yboard.set_led_color(9, 255, 165, 0); // Yellow
    } else {
        Yboard.set_led_color(9, 0, 0, 255); // Blue
    }

    if (temp_data.humidity > 35) {
        Yboard.set_led_color(10, 255, 165, 0); // Yellow
    } else {
        Yboard.set_led_color(10, 0, 0, 255); // Blue
    }
   


     // Test Display
     display.clearDisplay();
     uint8_t text_size = 2;
     display.setCursor(0, 0);
     display.setTextSize(text_size);
     display.print("GPIO Test"); 
     display.display(); // Draw on display

}
