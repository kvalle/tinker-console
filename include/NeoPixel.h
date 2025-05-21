#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint8_t EFFECT_COUNT = 2; // Oppdater dette tallet når nye effekter legges til

enum class EffectType
{
    Chase,
    Rainbow
};

class NeoPixel
{
public:
    NeoPixel(uint8_t pin, uint16_t numLeds);
    void setup();
    void update();
    void setSpeed(uint16_t ms);
    void nextEffect();
    void setEffect(EffectType effectType);

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
