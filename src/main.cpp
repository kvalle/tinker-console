#include <Arduino.h>
#include "Buzzer.h"

void setup()
{
  Serial.begin(9600);
  delay(2000);
  Serial.println("\nSerial communication started. Testing non-blocking notes.");

  pinMode(BUZZER_PIN, OUTPUT);

  playPowerUp();
}

void loop()
{
  getNotePlayer().update();
}
