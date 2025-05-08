#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer(int pin) : isPlaying(false), pin(pin), numNotes(0), currentNote(0), noteStartTime(0) {}

void Buzzer::play(const int (*notesArray)[2], int totalNotes)
{
    if (isPlaying)
        return;

    numNotes = totalNotes;
    for (int i = 0; i < numNotes; i++)
    {
        notes[i][0] = notesArray[i][0];
        notes[i][1] = notesArray[i][1];
    }
    currentNote = 0;
    noteStartTime = millis();
    isPlaying = true;
    tone(pin, notes[currentNote][0]);
}

void Buzzer::update()
{
    if (!isPlaying)
        return;

    unsigned long currentTime = millis();

    if (currentTime - noteStartTime >= (unsigned long)notes[currentNote][1])
    {
        noTone(pin);
        currentNote++;
        if (currentNote < numNotes)
        {
            noteStartTime = currentTime;
            tone(pin, notes[currentNote][0]);
        }
        else
        {
            isPlaying = false;
        }
    }
}

void Buzzer::setup()
{
    pinMode(pin, OUTPUT);
}

void playCoin(Buzzer &buzzer)
{
    const int coinTones[][2] = {
        {NOTE_E5, SIXTEENTH_NOTE},
        {NOTE_G5, SIXTEENTH_NOTE}};
    buzzer.play(coinTones, sizeof(coinTones) / sizeof(coinTones[0]));
}

void playPowerUp(Buzzer &buzzer)
{
    const int powerUpTones[][2] = {
        {NOTE_C4, EIGHTH_NOTE},
        {NOTE_E4, EIGHTH_NOTE},
        {NOTE_G4, EIGHTH_NOTE},
        {NOTE_C5, EIGHTH_NOTE}};
    buzzer.play(powerUpTones, sizeof(powerUpTones) / sizeof(powerUpTones[0]));
}

void play1Up(Buzzer &buzzer)
{
    const int oneUpTones[][2] = {
        {NOTE_C5, EIGHTH_NOTE},
        {NOTE_E5, EIGHTH_NOTE},
        {NOTE_G5, EIGHTH_NOTE},
        {NOTE_C6, EIGHTH_NOTE}};
    buzzer.play(oneUpTones, sizeof(oneUpTones) / sizeof(oneUpTones[0]));
}

void playGameOver(Buzzer &buzzer)
{
    const int gameOverTones[][2] = {
        {NOTE_C5, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_C4, HALF_NOTE}};
    buzzer.play(gameOverTones, sizeof(gameOverTones) / sizeof(gameOverTones[0]));
}

void playFlagpole(Buzzer &buzzer)
{
    const int flagpoleTones[][2] = {
        {NOTE_C4, SIXTEENTH_NOTE},
        {NOTE_D4, SIXTEENTH_NOTE},
        {NOTE_E4, SIXTEENTH_NOTE},
        {NOTE_F4, SIXTEENTH_NOTE},
        {NOTE_G4, EIGHTH_NOTE}};
    buzzer.play(flagpoleTones, sizeof(flagpoleTones) / sizeof(flagpoleTones[0]));
}

void playMarioThemeStart(Buzzer &buzzer)
{
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
        {NOTE_G4, QUARTER_NOTE}};

    buzzer.play(marioThemeStart, sizeof(marioThemeStart) / sizeof(marioThemeStart[0]));
}
