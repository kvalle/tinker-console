#include <Arduino.h>
#include "Buzzer.h"
#include "Sounds.h"

Buzzer buzzer1(D1);
Buzzer buzzer2(D2);

#define BUTTON_PIN_1 D0
#define BUTTON_PIN_2 D5
#define BUTTON_PIN_3 D6
#define BUTTON_PIN_4 D7

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);

  buzzer1.setup();
  buzzer2.setup();

  buzzer1.play(fanfare);
}

void loop()
{
  buttonState1 = digitalRead(BUTTON_PIN_1);
  buttonState2 = digitalRead(BUTTON_PIN_2);
  buttonState3 = digitalRead(BUTTON_PIN_3);
  buttonState4 = digitalRead(BUTTON_PIN_4);

  if (buttonState1 == HIGH)
  {
    Serial.println("Button pressed");
    buzzer1.play(buttonPressDouble);
  }

  if (buttonState2 == HIGH)
  {
    Serial.println("Button pressed");
    buzzer1.play(buttonPressDouble);
  }

  if (buttonState3 == HIGH)
  {
    Serial.println("Button pressed");
    buzzer1.play(buttonPressDouble);
  }

  if (buttonState4 == HIGH)
  {
    Serial.println("Button pressed");
    buzzer1.play(buttonPressDouble);
  }

  buzzer1.update();
  buzzer2.update();
}
