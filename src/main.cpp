#include <Arduino.h>
#include "Buzzer.h"

Buzzer buzzer(D1);

const int coinTones[][2] = {
    {NOTE_E5, SIXTEENTH_NOTE},
    {NOTE_G5, SIXTEENTH_NOTE},
    {0, 0} // Fine
};

const int powerUpTones[][2] = {
    {NOTE_C4, EIGHTH_NOTE},
    {NOTE_E4, EIGHTH_NOTE},
    {NOTE_G4, EIGHTH_NOTE},
    {NOTE_C5, EIGHTH_NOTE},
    {0, 0} // Fine
};

const int oneUpTones[][2] = {
    {NOTE_C5, EIGHTH_NOTE},
    {NOTE_E5, EIGHTH_NOTE},
    {NOTE_G5, EIGHTH_NOTE},
    {NOTE_C6, EIGHTH_NOTE},
    {0, 0} // Fine
};

const int gameOverTones[][2] = {
    {NOTE_C5, QUARTER_NOTE},
    {NOTE_G4, QUARTER_NOTE},
    {NOTE_E4, QUARTER_NOTE},
    {NOTE_C4, HALF_NOTE},
    {0, 0} // Fine
};

const int flagpoleTones[][2] = {
    {NOTE_C4, SIXTEENTH_NOTE},
    {NOTE_D4, SIXTEENTH_NOTE},
    {NOTE_E4, SIXTEENTH_NOTE},
    {NOTE_F4, SIXTEENTH_NOTE},
    {NOTE_G4, EIGHTH_NOTE},
    {0, 0} // Fine
};

const int marioThemeStart[][2] = {
    {NOTE_E5, EIGHTH_NOTE},
    {NOTE_E5, EIGHTH_NOTE},
    {0, EIGHTH_NOTE}, // Rest
    {NOTE_E5, EIGHTH_NOTE},
    {0, EIGHTH_NOTE}, // Rest
    {NOTE_C5, EIGHTH_NOTE},
    {NOTE_E5, EIGHTH_NOTE},
    {NOTE_G5, QUARTER_NOTE},
    {0, QUARTER_NOTE}, // Rest
    {NOTE_G4, QUARTER_NOTE},
    {0, 0} // Fine
};

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("\nSerial communication started.");

  buzzer.setup();
  buzzer.play(marioThemeStart);
}

void loop()
{
  buzzer.update();
}
