#include <Arduino.h>
#include "Buzzer.h"
#include "Sounds.h"

Buzzer buzzer(D1);

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  buzzer.setup();
  buzzer.play(marioThemeFull);
}

void loop()
{
  buzzer.update();
}
