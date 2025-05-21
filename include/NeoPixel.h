#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class NeoPixel
{
public:
    NeoPixel(uint8_t pin, uint16_t numLeds);
    void setup();
    void update();
    void setSpeed(uint16_t ms);
    void nextEffect();
    void setEffect(uint8_t effectIndex);

private:
    Adafruit_NeoPixel strip;
    uint16_t numPixels;
    unsigned long lastUpdate = 0;
    uint16_t speed = 100;
    uint8_t effect = 0;
    uint16_t pos = 0;

    void effectChase();
    void effectRainbow();
};
