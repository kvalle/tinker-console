#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint8_t EFFECT_COUNT = 4;

enum class EffectType
{
    Chase,
    Rainbow,
    ColorWave,
    TheaterChase
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
    EffectType effect = EffectType::Chase;
    uint16_t pos = 0;

    void effectChase();
    void effectRainbow();
    void effectColorWave();
    void effectTheaterChase();
};
