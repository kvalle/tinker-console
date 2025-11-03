#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint8_t LEDSTRIP_LED_COUNT = 9;

class LedStrip
{
public:
    enum class AnimationMode : uint8_t
    {
        ShiftRight,
        ShiftLeft,
        CenterOut,
        EdgeIn
    };

    LedStrip(uint8_t pin);
    void setup();
    void update();
    void green();
    void yellow();
    void red();
    void blue();
    void setSpeed(uint16_t ms);
    void setAnimationMode(AnimationMode mode);

private:
    void animate();
    Adafruit_NeoPixel strip;
    unsigned long lastUpdate = 0;
    unsigned long lastAnimate = 0;
    uint16_t speed = 400;
    uint16_t frequency_ms = 20;
    uint32_t colors[LEDSTRIP_LED_COUNT] = {};
    uint32_t nextColor = 0;
    AnimationMode animationMode = AnimationMode::ShiftRight;
};
