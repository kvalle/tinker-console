#include "NeoPixel.h"

NeoPixel::NeoPixel(uint8_t pin, uint16_t numLeds)
    : strip(numLeds, pin, NEO_GRB + NEO_KHZ800),
      numPixels(numLeds) {}

void NeoPixel::setup()
{
    strip.begin();
    strip.clear();
    strip.show();
}

void NeoPixel::setSpeed(uint16_t ms)
{
    speed = ms;
}

void NeoPixel::setEffect(EffectType effectType)
{
    effect = static_cast<uint8_t>(effectType);
    pos = 0;
}

void NeoPixel::nextEffect()
{
    setEffect(static_cast<EffectType>((effect + 1) % EFFECT_COUNT));
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
    case 2:
        effectColorWave();
        break;
    }
}

void NeoPixel::effectChase()
{
    strip.clear();
    strip.setPixelColor(pos % numPixels, strip.Color(255, 0, 0));
    strip.show();
    pos++;
}

void NeoPixel::effectRainbow()
{
    strip.rainbow(pos * 256);
    strip.show();
    pos++;
}

void NeoPixel::effectColorWave()
{
    for (uint16_t i = 0; i < numPixels; i++)
    {
        uint8_t colorIndex = (pos + i) % 256;
        uint32_t color = strip.ColorHSV(colorIndex * 256, 255, 255);
        strip.setPixelColor(i, color);
    }
    strip.show();
    pos++;
}
