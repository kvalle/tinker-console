#include <Arduino.h>
#include "Buzzer.h"

Buzzer buzzer(D1);

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  buzzer.setup();
  playMarioThemeStart(buzzer);
}

void loop()
{
  buzzer.update();
}
