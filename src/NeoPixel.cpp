#include "NeoPixel.h"

NeoPixel::NeoPixel(Adafruit_NeoPixel &s) : strip(s) {}

void NeoPixel::setSpeed(uint16_t ms)
{
    speed = ms;
}

void NeoPixel::setEffect(uint8_t effectIndex)
{
    effect = effectIndex;
    pos = 0;
}

void NeoPixel::nextEffect()
{
    setEffect((effect + 1) % 2); // 2 effekter foreløpig
}

void NeoPixel::update()
{
    unsigned long now = millis();
    if (now - lastUpdate < speed)
        return;
    lastUpdate = now;

    switch (effect)
    {
    case 0:
        effectChase();
        break;
    case 1:
        effectRainbow();
        break;
    }
}

void NeoPixel::effectChase()
{
    strip.clear();
    strip.setPixelColor(pos % strip.numPixels(), strip.Color(255, 0, 0));
    strip.show();
    pos++;
}

void NeoPixel::effectRainbow()
{
    strip.rainbow(pos * 256);
    strip.show();
    pos++;
}
