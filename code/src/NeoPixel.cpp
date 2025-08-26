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
    effect = effectType;
    pos = 0;
}

void NeoPixel::nextEffect()
{
    effect = static_cast<EffectType>((static_cast<int>(effect) + 1) % EFFECT_COUNT);
}

void NeoPixel::update()
{
    unsigned long now = millis();
    if (now - lastUpdate < speed)
        return;
    lastUpdate = now;

    switch (effect)
    {
    case EffectType::Chase:
        effectChase();
        break;
    case EffectType::Rainbow:
        effectRainbow();
        break;
    case EffectType::ColorWave:
        effectColorWave();
        break;
    case EffectType::TheaterChase:
        effectTheaterChase();
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

void NeoPixel::effectTheaterChase()
{
    strip.clear();
    for (int i = 0; i < numPixels; i++)
    {
        if ((i + pos) % 3 == 0)
        {
            strip.setPixelColor(i, strip.Color(255, 0, 255)); // Rosa-lilla
        }
    }
    strip.show();
    pos++;
}
