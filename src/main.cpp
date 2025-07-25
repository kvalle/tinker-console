#include <Arduino.h>
#include <Automaton.h>
#include "Buzzer.h"
#include "NeoPixel.h"
#include "Sounds.h"

Buzzer buzzer1(D1, 120);
Buzzer buzzer2(D8, 150);

Atm_button button1;
Atm_button button2;
Atm_button button3;
Atm_button button4;

uint16_t potAvgBuffer[16];
Atm_analog pot;

NeoPixel neo(D4, 9);

enum ConsoleMode
{
  CONSOLE_MODE_1,
  CONSOLE_MODE_2,
  CONSOLE_MODE_3,
  CONSOLE_MODE_4
};

ConsoleMode currentMode = CONSOLE_MODE_1;

void playSoundForCurrentMode()
{
  switch (currentMode)
  {
  case CONSOLE_MODE_1:
    buzzer1.play(marioCoin);
    break;
  case CONSOLE_MODE_2:
    buzzer1.play(marioPowerUp);
    break;
  case CONSOLE_MODE_3:
    buzzer1.play(marioOneUp);
    break;
  case CONSOLE_MODE_4:
    buzzer1.play(marioGameOver);
    break;
  }
}

void handleShortButtonPress(int idx, int v, int up)
{
  if (v)
  {
    if (idx == 1)
    {
      Serial.println("Button 1");
      // buzzer1.play(popcornMelody);
      playSoundForCurrentMode();
    }
    else if (idx == 2)
    {
      Serial.println("Button 2");
      // Serial.println("Playing sound 2");
      // buzzer2.play(popcornMelody);
      playSoundForCurrentMode();
    }
    else if (idx == 3)
    {
      Serial.println("Button 3");
      playSoundForCurrentMode();
    }
    else if (idx == 4)
    {
      Serial.println("Button 4");
      playSoundForCurrentMode();
    }
  }
}

void handleLongButtonPress(int idx, int v, int up)
{
  if (v)
  {
    if (idx == 1)
    {
      neo.setEffect(EffectType::Chase);
      currentMode = CONSOLE_MODE_1;
    }
    else if (idx == 2)
    {
      neo.setEffect(EffectType::Rainbow);
      currentMode = CONSOLE_MODE_2;
    }
    else if (idx == 3)
    {
      neo.setEffect(EffectType::ColorWave);
      currentMode = CONSOLE_MODE_3;
    }
    else if (idx == 4)
    {
      neo.setEffect(EffectType::TheaterChase);
      currentMode = CONSOLE_MODE_4;
    }
  }
}

void setup()
{
  buzzer1.setup();
  buzzer2.setup();

  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  neo.setup();

  pot.begin(A0)
      .range(20, 500)
      .average(potAvgBuffer, sizeof(potAvgBuffer))
      .onChange([](int idx, int v, int up)
                { 
                  neo.setSpeed(v);
                  Serial.println("Potentiometer value: " + String(v)); });

  button1.begin(D2)
      .longPress(2, 1000)
      .onPress(1, handleShortButtonPress, 1)
      .onPress(2, handleLongButtonPress, 1);
  button2.begin(D5)
      .longPress(2, 1000)
      .onPress(1, handleShortButtonPress, 2)
      .onPress(2, handleLongButtonPress, 2);
  button3.begin(D6)
      .longPress(2, 1000)
      .onPress(1, handleShortButtonPress, 3)
      .onPress(2, handleLongButtonPress, 3);
  button4.begin(D3)
      .longPress(2, 1000)
      .onPress(1, handleShortButtonPress, 4)
      .onPress(2, handleLongButtonPress, 4);

  buzzer2.play(fanfare);
}

void loop()
{
  automaton.run();
  buzzer1.update();
  buzzer2.update();
  neo.update();
}
