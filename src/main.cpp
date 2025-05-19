#include <Arduino.h>
#include <Automaton.h>
#include "Buzzer.h"
#include "Sounds.h"

Buzzer buzzer1(D1);
Buzzer buzzer2(D2);

Atm_button button1;
Atm_button button2;
Atm_button button3;
Atm_button button4;

uint16_t potAvgBuffer[16];
Atm_analog pot;

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
      playSoundForCurrentMode();
    }
    else if (idx == 2)
    {
      playSoundForCurrentMode();
    }
    else if (idx == 3)
    {
      playSoundForCurrentMode();
    }
    else if (idx == 4)
    {
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
      currentMode = CONSOLE_MODE_1;
    }
    else if (idx == 2)
    {
      currentMode = CONSOLE_MODE_2;
    }
    else if (idx == 3)
    {
      currentMode = CONSOLE_MODE_3;
    }
    else if (idx == 4)
    {
      currentMode = CONSOLE_MODE_4;
    }
  }
}

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  pot.begin(A0)
      .range(50, 300)
      .average(potAvgBuffer, sizeof(potAvgBuffer))
      .onChange([](int idx, int v, int up)
                { Serial.println("Potentiometer value: " + String(v)); });

  buzzer1.setup();
  buzzer2.setup();

  button1.begin(D0)
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
  button4.begin(D7)
      .longPress(2, 1000)
      .onPress(1, handleShortButtonPress, 4)
      .onPress(2, handleLongButtonPress, 4);

  buzzer1.play(fanfare);
}

void loop()
{
  automaton.run();
  buzzer1.update();
  buzzer2.update();
}
