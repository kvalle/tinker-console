#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer(int pin, int bpm) : pin(pin), bpm(bpm), notes(nullptr), numNotes(0), currentNote(0), noteStartTime(0), isPlaying(false) {}

void Buzzer::setBPM(int bpm)
{
    this->bpm = bpm;
}

void Buzzer::play(const int (*notesArray)[2])
{
    notes = notesArray;
    if (isPlaying)
        return;

    // Calculate the number of notes if not provided
    int totalNotes = 0;
    while (notesArray[totalNotes][0] != 0 || notesArray[totalNotes][1] != 0)
    {
        totalNotes++;
    }

    notes = notesArray; // Store the pointer to the notes array
    numNotes = totalNotes;
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

    // Calculate the duration of the note including a small pause
    unsigned long pauseDuration = 10;                                                 // Length of pause between notes
    unsigned long currentNoteDuration = notes[currentNote][1];                        // Length of the current note in default 150 BPM
    unsigned long noteDuration = (150.0 / bpm) * currentNoteDuration - pauseDuration; // Duration in milliseconds in chosen BPM

    if (currentTime - noteStartTime >= noteDuration + pauseDuration)
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
    else if (currentTime - noteStartTime >= noteDuration)
    {
        noTone(pin); // Stop the tone to create a pause
    }
}

void Buzzer::setup()
{
    pinMode(pin, OUTPUT);
}
