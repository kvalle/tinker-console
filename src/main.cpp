#include <Arduino.h>
#include "Buzzer.h"

#define BUZZER_PIN D1

NotePlayer notePlayer(BUZZER_PIN);

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  notePlayer.setup();
  playMarioThemeStart(notePlayer);
}

void loop()
{
  notePlayer.update();
}
