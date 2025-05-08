#include <Arduino.h>
#include "Buzzer.h"

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  pinMode(BUZZER_PIN, OUTPUT);

  playMarioThemeStart();
}

void loop()
{
  getNotePlayer().update();
}
