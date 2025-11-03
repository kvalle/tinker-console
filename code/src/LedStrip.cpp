#include "LedStrip.h"

const uint32_t COLOR_GREEN = Adafruit_NeoPixel::Color(0, 200, 0);
const uint32_t COLOR_YELLOW = Adafruit_NeoPixel::Color(255, 200, 0);
const uint32_t COLOR_RED = Adafruit_NeoPixel::Color(220, 20, 20);
const uint32_t COLOR_BLUE = Adafruit_NeoPixel::Color(0, 70, 200);
const uint32_t COLOR_WHITE = Adafruit_NeoPixel::Color(200, 200, 200);

LedStrip::LedStrip(uint8_t pin)
    : strip(LEDSTRIP_LED_COUNT, pin, NEO_GRB + NEO_KHZ800)
{
    colors[0] = COLOR_WHITE; // first LED white
    for (uint8_t i = 1; i < LEDSTRIP_LED_COUNT; ++i)
    {
        colors[i] = 0; // rest starts off
    }
}

void LedStrip::setup()
{
    strip.begin();
    strip.setBrightness(179); // ~70% of max brightness
    strip.clear();
    strip.show();

    colors[0] = COLOR_WHITE;
}

void LedStrip::setSpeed(uint16_t ms)
{
    speed = ms;
}

void LedStrip::update()
{
    unsigned long now = millis();
    if (now - lastUpdate < frequency_ms)
        return;
    lastUpdate = now;

    // Shift colors right based on speed interval
    if (now - lastShift >= speed)
    {
        shiftRight();
        lastShift = now;
    }

    for (uint8_t i = 0; i < LEDSTRIP_LED_COUNT; ++i)
    {
        strip.setPixelColor(i, colors[i]);
    }
    strip.show();
}

void LedStrip::shiftRight()
{
    for (int i = LEDSTRIP_LED_COUNT - 1; i > 0; --i)
    {
        colors[i] = colors[i - 1];
    }
    // colors[0] remains as injection point
}

void LedStrip::green()
{
    colors[0] = COLOR_GREEN;
}

void LedStrip::yellow()
{
    colors[0] = COLOR_YELLOW;
}

void LedStrip::red()
{
    colors[0] = COLOR_RED;
}

void LedStrip::blue()
{
    colors[0] = COLOR_BLUE;
}
