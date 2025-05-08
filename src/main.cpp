#include <Arduino.h>
#include "Buzzer.h"
#include "Sounds.h"

Buzzer buzzer1(D1);
Buzzer buzzer2(D2);

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  buzzer1.setup();
  buzzer1.play(marioThemeFull);

  buzzer2.setup();
  buzzer2.play(fanfare);
}

void loop()
{
  buzzer1.update();
  buzzer2.update();
}
