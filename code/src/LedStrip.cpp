#include "LedStrip.h"

const uint32_t COLOR_GREEN = Adafruit_NeoPixel::Color(0, 200, 0);
const uint32_t COLOR_YELLOW = Adafruit_NeoPixel::Color(255, 200, 0);
const uint32_t COLOR_RED = Adafruit_NeoPixel::Color(220, 20, 20);
const uint32_t COLOR_BLUE = Adafruit_NeoPixel::Color(0, 70, 200);
const uint32_t COLOR_WHITE = Adafruit_NeoPixel::Color(200, 200, 200);

LedStrip::LedStrip(uint8_t pin)
    : strip(LEDSTRIP_LED_COUNT, pin, NEO_GRB + NEO_KHZ800)
{
}

void LedStrip::setup()
{
    strip.begin();
    strip.setBrightness(179); // ~70% of max brightness
    strip.clear();
    strip.show();

    nextColor = COLOR_WHITE;
}

void LedStrip::setSpeed(uint16_t ms)
{
    speed = ms;
}

void LedStrip::setAnimationMode(AnimationMode mode)
{
    animationMode = mode;
}

void LedStrip::update()
{
    unsigned long now = millis();
    if (now - lastUpdate < frequency_ms)
        return;
    lastUpdate = now;

    // Animate based on configured mode and speed interval
    if (now - lastAnimate >= speed)
    {
        animate();
        lastAnimate = now;
    }

    for (uint8_t i = 0; i < LEDSTRIP_LED_COUNT; ++i)
    {
        strip.setPixelColor(i, colors[i]);
    }
    strip.show();
}

void LedStrip::animate()
{
    switch (animationMode)
    {
    case AnimationMode::ShiftRight:
        for (int i = LEDSTRIP_LED_COUNT - 1; i > 0; --i)
        {
            colors[i] = colors[i - 1];
        }
        colors[0] = nextColor;
        break;
    case AnimationMode::ShiftLeft:
        for (int i = 0; i < LEDSTRIP_LED_COUNT - 1; ++i)
        {
            colors[i] = colors[i + 1];
        }
        colors[LEDSTRIP_LED_COUNT - 1] = nextColor;
        break;
    case AnimationMode::CenterOut:
    {
        const int center = LEDSTRIP_LED_COUNT / 2; // 4 when count=9
        // shift left half outward (towards index 0)
        for (int i = 0; i < center; ++i)
        {
            colors[i] = colors[i + 1];
        }
        // shift right half outward (towards last index)
        for (int i = LEDSTRIP_LED_COUNT - 1; i > center; --i)
        {
            colors[i] = colors[i - 1];
        }
        colors[center] = nextColor;
        break;
    }
    case AnimationMode::EdgeIn:
    {
        const int center = LEDSTRIP_LED_COUNT / 2; // 4 for 9 LEDs
        uint32_t original[LEDSTRIP_LED_COUNT];
        for (int i = 0; i < LEDSTRIP_LED_COUNT; ++i)
        {
            original[i] = colors[i];
        }
        // Move left side inward (towards center)
        for (int i = center; i > 0; --i)
        {
            colors[i] = original[i - 1];
        }
        // Move right side inward (towards center)
        for (int i = center; i < LEDSTRIP_LED_COUNT - 1; ++i)
        {
            colors[i] = original[i + 1];
        }
        // Inject new color at edges
        colors[0] = nextColor;
        colors[LEDSTRIP_LED_COUNT - 1] = nextColor;
        // Center adopts right incoming color (no blending)
        colors[center] = original[center + 1];
        break;
    }
    }
}

void LedStrip::green()
{
    nextColor = COLOR_GREEN;
}

void LedStrip::yellow()
{
    nextColor = COLOR_YELLOW;
}

void LedStrip::red()
{
    nextColor = COLOR_RED;
}

void LedStrip::blue()
{
    nextColor = COLOR_BLUE;
}
