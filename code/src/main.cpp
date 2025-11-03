#include <Arduino.h>
#include <Automaton.h>
#include "Buzzer.h"
#include "LedStrip.h"
#include "Sounds.h"

Buzzer buzzer1(D1, 120);
Buzzer buzzer2(D8, 120);

Atm_button button1;
Atm_button button2;
Atm_button button3;
Atm_button button4;

uint16_t potAvgBuffer[16];
Atm_analog pot;

LedStrip neo(D4);

void handleShortButtonPress(int idx, int v, int up)
{
  if (v)
  {
    if (idx == 1)
    {
      Serial.println("Red button pressed");
      buzzer1.play(buttonPress1);
      neo.red();
    }
    else if (idx == 2)
    {
      Serial.println("Blue button pressed");
      buzzer1.play(buttonPress2);
      neo.blue();
    }
    else if (idx == 3)
    {
      Serial.println("Yellow button pressed");
      buzzer1.play(buttonPress3);
      neo.yellow();
    }
    else if (idx == 4)
    {
      Serial.println("Green button pressed");
      buzzer1.play(buttonPress4);
      neo.green();
    }
  }
}

void handleLongButtonPress(int idx, int v, int up)
{
  if (v)
  {
    if (idx == 1)
    {
      Serial.println("Red button longpressed");
    }
    else if (idx == 2)
    {
      Serial.println("Blue button longpressed");
    }
    else if (idx == 3)
    {
      Serial.println("Yellow button longpressed");
    }
    else if (idx == 4)
    {
      Serial.println("Green button longpressed");
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

  buzzer2.play(panelStartup);
}

void loop()
{
  automaton.run();
  buzzer1.update();
  buzzer2.update();
  neo.update();
}
