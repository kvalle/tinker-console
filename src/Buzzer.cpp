#include <Arduino.h>
#include "Buzzer.h"

NotePlayer::NotePlayer(int pin) : isPlaying(false), pin(pin), numNotes(0), currentNote(0), noteStartTime(0) {}

void NotePlayer::start(const int (*notesArray)[2], int totalNotes)
{
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

void NotePlayer::update()
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

void NotePlayer::playNotesNonBlocking(const int notes[][2], int numNotes)
{
    if (isPlaying)
        return;

    start(notes, numNotes);
}

void NotePlayer::setup()
{
    pinMode(pin, OUTPUT);
}

void playCoin(NotePlayer &notePlayer)
{
    const int coinTones[][2] = {
        {NOTE_E5, SIXTEENTH_NOTE},
        {NOTE_G5, SIXTEENTH_NOTE}};
    notePlayer.playNotesNonBlocking(coinTones, sizeof(coinTones) / sizeof(coinTones[0]));
}

void playPowerUp(NotePlayer &notePlayer)
{
    const int powerUpTones[][2] = {
        {NOTE_C4, EIGHTH_NOTE},
        {NOTE_E4, EIGHTH_NOTE},
        {NOTE_G4, EIGHTH_NOTE},
        {NOTE_C5, EIGHTH_NOTE}};
    notePlayer.playNotesNonBlocking(powerUpTones, sizeof(powerUpTones) / sizeof(powerUpTones[0]));
}

void play1Up(NotePlayer &notePlayer)
{
    const int oneUpTones[][2] = {
        {NOTE_C5, EIGHTH_NOTE},
        {NOTE_E5, EIGHTH_NOTE},
        {NOTE_G5, EIGHTH_NOTE},
        {NOTE_C6, EIGHTH_NOTE}};
    notePlayer.playNotesNonBlocking(oneUpTones, sizeof(oneUpTones) / sizeof(oneUpTones[0]));
}

void playGameOver(NotePlayer &notePlayer)
{
    const int gameOverTones[][2] = {
        {NOTE_C5, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_C4, HALF_NOTE}};
    notePlayer.playNotesNonBlocking(gameOverTones, sizeof(gameOverTones) / sizeof(gameOverTones[0]));
}

void playFlagpole(NotePlayer &notePlayer)
{
    const int flagpoleTones[][2] = {
        {NOTE_C4, SIXTEENTH_NOTE},
        {NOTE_D4, SIXTEENTH_NOTE},
        {NOTE_E4, SIXTEENTH_NOTE},
        {NOTE_F4, SIXTEENTH_NOTE},
        {NOTE_G4, EIGHTH_NOTE}};
    notePlayer.playNotesNonBlocking(flagpoleTones, sizeof(flagpoleTones) / sizeof(flagpoleTones[0]));
}

void playMarioThemeStart(NotePlayer &notePlayer)
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

    notePlayer.playNotesNonBlocking(marioThemeStart, sizeof(marioThemeStart) / sizeof(marioThemeStart[0]));
}

void playHanna(NotePlayer &notePlayer)
{
    const int hannaTheme[][2] = {
        {NOTE_E3, EIGHTH_NOTE},
        {NOTE_E3, EIGHTH_NOTE},
        {0, EIGHTH_NOTE}, // Rest
        {NOTE_E3, EIGHTH_NOTE},
        {0, EIGHTH_NOTE}, // Rest
        {NOTE_C3, EIGHTH_NOTE},
        {NOTE_E3, EIGHTH_NOTE},
        {NOTE_G3, QUARTER_NOTE},
        {0, QUARTER_NOTE}, // Rest
        {NOTE_G2, QUARTER_NOTE}};

    notePlayer.playNotesNonBlocking(hannaTheme, sizeof(hannaTheme) / sizeof(hannaTheme[0]));
}

void playBaaBaaBlackSheep(NotePlayer &notePlayer)
{
    const int baaBaaBlackSheep[][2] = {
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_D4, QUARTER_NOTE},
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_C4, QUARTER_NOTE},
        {NOTE_C4, QUARTER_NOTE},
        {NOTE_D4, HALF_NOTE},
        {0, QUARTER_NOTE}, // Rest
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_F4, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_F4, QUARTER_NOTE},
        {NOTE_E4, HALF_NOTE},
        {0, QUARTER_NOTE}, // Rest
        {NOTE_D4, QUARTER_NOTE},
        {NOTE_D4, QUARTER_NOTE},
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_C4, QUARTER_NOTE},
        {NOTE_D4, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_G4, HALF_NOTE}};

    notePlayer.playNotesNonBlocking(baaBaaBlackSheep, sizeof(baaBaaBlackSheep) / sizeof(baaBaaBlackSheep[0]));
}
