#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer(int pin) : isPlaying(false), pin(pin), numNotes(0), currentNote(0), noteStartTime(0) {}

void Buzzer::play(const int (*notesArray)[2])
{
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
