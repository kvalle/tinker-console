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

void handleShortButtonPress(int idx, int v, int up)
{
  buzzer1.play(marioCoin);
}

void handleLongButtonPress(int idx, int v, int up)
{
  buzzer1.play(marioGameOver);
}

void handleButtonPress(int idx, int v, int up)
{
  if (v)
  {
    Serial.println("Button pressed: " + String(idx));
    if (idx == 1)
    {
      Serial.println("Button 1 pressed");
      buzzer1.play(marioCoin);
    }
    else if (idx == 2)
    {
      Serial.println("Button 2 pressed");
      buzzer1.play(marioPowerUp);
    }
    else if (idx == 3)
    {
      Serial.println("Button 3 pressed");
      buzzer1.play(marioOneUp);
    }
    else if (idx == 4)
    {
      Serial.println("Button 4 pressed");
      buzzer1.play(marioGameOver);
    }
  }
}

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  buzzer1.setup();
  buzzer2.setup();

  button1.begin(D0)
      .longPress(2, 1000)
      .onPress(1, handleShortButtonPress, 1)
      .onPress(2, handleLongButtonPress, 1);

  button2.begin(D5)
      .onPress(handleButtonPress, 2);
  button3.begin(D6)
      .onPress(handleButtonPress, 3);
  button4.begin(D7)
      .onPress(handleButtonPress, 4);

  buzzer1.play(fanfare);
}

void loop()
{
  automaton.run();
  buzzer1.update();
  buzzer2.update();
}
