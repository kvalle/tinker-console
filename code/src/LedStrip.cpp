#include "LedStrip.h"

const uint32_t COLOR_GREEN = Adafruit_NeoPixel::Color(0, 200, 0);
const uint32_t COLOR_YELLOW = Adafruit_NeoPixel::Color(255, 200, 0);
const uint32_t COLOR_RED = Adafruit_NeoPixel::Color(220, 20, 20);
const uint32_t COLOR_BLUE = Adafruit_NeoPixel::Color(0, 70, 200);

LedStrip::LedStrip(uint8_t pin)
    : strip(LEDSTRIP_LED_COUNT, pin, NEO_GRB + NEO_KHZ800), currentColor(COLOR_GREEN) {}

void LedStrip::setup()
{
    strip.begin();
    strip.clear();
    strip.show();
}

void LedStrip::setSpeed(uint16_t ms)
{
    speed = ms;
}

void LedStrip::update()
{
    unsigned long now = millis();
    if (now - lastUpdate < speed)
        return;
    lastUpdate = now;

    strip.clear();
    strip.setPixelColor(pos % LEDSTRIP_LED_COUNT, currentColor);
    strip.show();
    pos++;
}

void LedStrip::green() { currentColor = COLOR_GREEN; }
void LedStrip::yellow() { currentColor = COLOR_YELLOW; }
void LedStrip::red() { currentColor = COLOR_RED; }
void LedStrip::blue() { currentColor = COLOR_BLUE; }
