/*
** Copyright © 2022 Mike Wilsom
**
** Permission is hereby granted, free of charge, to any person obtaining a copy of this 
** software and associated documentation files (the “Software”), to deal in the Software 
** without restriction, including without limitation the rights to use, copy, modify, 
** merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
** permit persons to whom the Software is furnished to do so, subject to the following 
** conditions:
**
** The above copyright notice and this permission notice shall be included in all copies 
** or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
** INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
** PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
** FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
** OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
** DEALINGS IN THE SOFTWARE.
*/

/*
** A simple program to demonstrate varying the backlight brightness on a WT32-SC01 board.
** Uses the ESP32 built in LED Control to set the brightness using PWM. See
** https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/ledc.html
** for more about ESP32 LED Control.
*/

#include <Arduino.h>
#include <TFT_eSPI.h>

static const uint8_t backlightChannel = 1;
static uint32_t currentBrightness = 16;

TFT_eSPI tft = TFT_eSPI();

/*
** Set te PWM duty cycle for the backlight.
*/

static void setBrightness(uint32_t brightness) {
    ledcWrite(backlightChannel, brightness);
}

void setup() {
    Serial.begin(115200);

    /*
    ** Initialise the WT32's TFT display.
    */

    tft.init();
    tft.setRotation(1);
    tft.setSwapBytes(true);
    tft.setTextColor(TFT_WHITE);
    tft.fillScreen(TFT_BLACK);
    tft.drawCentreString("12.34", 160, 54, 6);

    /*
    ** Attach LED Control channel to pin 23.
    */

    ledcSetup(backlightChannel, 100, 8);
    ledcAttachPin(23, backlightChannel);
}

/*
** Slowly increase the brightness up the maximum, then start again from a low setting.
*/

void loop() {
    setBrightness(currentBrightness);
    currentBrightness += 16;

    if (currentBrightness > 255) {
        currentBrightness = 16;
    }

    delay(1000);
}
