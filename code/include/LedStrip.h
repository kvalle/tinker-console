#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint8_t LEDSTRIP_LED_COUNT = 9;

class LedStrip
{
public:
    LedStrip(uint8_t pin);
    void setup();
    void update();
    void green();
    void yellow();
    void red();
    void blue();
    void setSpeed(uint16_t ms);

private:
    Adafruit_NeoPixel strip;
    unsigned long lastUpdate = 0;
    uint16_t speed = 100;
    uint16_t pos = 0;
    uint32_t currentColor;
};
