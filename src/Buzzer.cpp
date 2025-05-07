#include "Buzzer.h"

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
    tone(BUZZER_PIN, notes[currentNote][0]);
}

void NotePlayer::update()
{
    if (!isPlaying)
        return;

    unsigned long currentTime = millis();

    if (currentTime - noteStartTime >= (unsigned long)notes[currentNote][1])
    {
        noTone(BUZZER_PIN);
        currentNote++;
        if (currentNote < numNotes)
        {
            noteStartTime = currentTime;
            tone(BUZZER_PIN, notes[currentNote][0]);
        }
        else
        {
            isPlaying = false;
        }
    }
}

NotePlayer notePlayer;

NotePlayer &getNotePlayer()
{
    return notePlayer;
}

void playNotesNonBlocking(const int notes[][2], int numNotes)
{
    if (notePlayer.isPlaying)
        return;

    notePlayer.start(notes, numNotes);
}

void playCoin()
{
    const int coinTones[][2] = {
        {NOTE_E5, SIXTEENTH_NOTE},
        {NOTE_G5, SIXTEENTH_NOTE}};
    playNotesNonBlocking(coinTones, sizeof(coinTones) / sizeof(coinTones[0]));
}

void playPowerUp()
{
    const int powerUpTones[][2] = {
        {NOTE_C4, EIGHTH_NOTE},
        {NOTE_E4, EIGHTH_NOTE},
        {NOTE_G4, EIGHTH_NOTE},
        {NOTE_C5, EIGHTH_NOTE}};
    playNotesNonBlocking(powerUpTones, sizeof(powerUpTones) / sizeof(powerUpTones[0]));
}

void play1Up()
{
    const int oneUpTones[][2] = {
        {NOTE_C5, EIGHTH_NOTE},
        {NOTE_E5, EIGHTH_NOTE},
        {NOTE_G5, EIGHTH_NOTE},
        {NOTE_C6, EIGHTH_NOTE}};
    playNotesNonBlocking(oneUpTones, sizeof(oneUpTones) / sizeof(oneUpTones[0]));
}

void playGameOver()
{
    const int gameOverTones[][2] = {
        {NOTE_C5, QUARTER_NOTE},
        {NOTE_G4, QUARTER_NOTE},
        {NOTE_E4, QUARTER_NOTE},
        {NOTE_C4, HALF_NOTE}};
    playNotesNonBlocking(gameOverTones, sizeof(gameOverTones) / sizeof(gameOverTones[0]));
}

void playFlagpole()
{
    const int flagpoleTones[][2] = {
        {NOTE_C4, SIXTEENTH_NOTE},
        {NOTE_D4, SIXTEENTH_NOTE},
        {NOTE_E4, SIXTEENTH_NOTE},
        {NOTE_F4, SIXTEENTH_NOTE},
        {NOTE_G4, EIGHTH_NOTE}};
    playNotesNonBlocking(flagpoleTones, sizeof(flagpoleTones) / sizeof(flagpoleTones[0]));
}
