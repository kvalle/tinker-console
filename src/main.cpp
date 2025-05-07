#include <Arduino.h>

#define BUZZER_PIN D1 // GPIO5
#define BPM 150       // Beats per minute

#define NOTE_C4 262   // C4
#define NOTE_CS4 277  // C#4/Db4
#define NOTE_D4 294   // D4
#define NOTE_DS4 311  // D#4/Eb4
#define NOTE_E4 330   // E4
#define NOTE_F4 349   // F4
#define NOTE_FS4 370  // F#4/Gb4
#define NOTE_G4 392   // G4
#define NOTE_GS4 415  // G#4/Ab4
#define NOTE_A4 440   // A4
#define NOTE_AS4 466  // A#4/Bb4
#define NOTE_B4 494   // B4
#define NOTE_C5 523   // C5
#define NOTE_CS5 554  // C#5/Db5
#define NOTE_D5 587   // D5
#define NOTE_DS5 622  // D#5/Eb5
#define NOTE_E5 659   // E5
#define NOTE_F5 698   // F5
#define NOTE_FS5 740  // F#5/Gb5
#define NOTE_G5 784   // G5
#define NOTE_GS5 831  // G#5/Ab5
#define NOTE_A5 880   // A5
#define NOTE_AS5 932  // A#5/Bb5
#define NOTE_B5 988   // B5
#define NOTE_C6 1047  // C6
#define NOTE_CS6 1109 // C#6/Db6
#define NOTE_D6 1175  // D6
#define NOTE_DS6 1245 // D#6/Eb6
#define NOTE_E6 1319  // E6
#define NOTE_F6 1397  // F6
#define NOTE_FS6 1480 // F#6/Gb6
#define NOTE_G6 1568  // G6
#define NOTE_GS6 1661 // G#6/Ab6
#define NOTE_A6 1760  // A6
#define NOTE_AS6 1865 // A#6/Bb6
#define NOTE_B6 1976  // B6
#define NOTE_C7 2093  // C7
#define NOTE_CS7 2217 // C#7/Db7
#define NOTE_D7 2349  // D7
#define NOTE_DS7 2489 // D#7/Eb7
#define NOTE_E7 2637  // E7
#define NOTE_F7 2794  // F7
#define NOTE_FS7 2960 // F#7/Gb7
#define NOTE_G7 3136  // G7
#define NOTE_GS7 3322 // G#7/Ab7
#define NOTE_A7 3520  // A7
#define NOTE_AS7 3729 // A#7/Bb7
#define NOTE_B7 3951  // B7

const int BEAT_DURATION_MS = (60 * 1000) / BPM;

const int WHOLE_NOTE = 4 * BEAT_DURATION_MS;
const int HALF_NOTE = 2 * BEAT_DURATION_MS;
const int QUARTER_NOTE = BEAT_DURATION_MS;
const int EIGHTH_NOTE = BEAT_DURATION_MS / 2;
const int SIXTEENTH_NOTE = BEAT_DURATION_MS / 4;

struct NotePlayer
{
  int notes[10][2]; // Local buffer for notes (supports up to 10 notes)
  int numNotes;
  int currentNote;
  unsigned long noteStartTime;
  bool isPlaying;

  void start(const int (*notesArray)[2], int totalNotes)
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

  void update()
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
};

NotePlayer notePlayer;

void playNotesNonBlocking(const int notes[][2], int numNotes)
{
  if (notePlayer.isPlaying)
    return;

  // Debugging: Print the notes array and durations
  Serial.println("Starting non-blocking playback:");
  for (int i = 0; i < numNotes; i++)
  {
    Serial.print("Note ");
    Serial.print(i);
    Serial.print(": Frequency = ");
    Serial.print(notes[i][0]);
    Serial.print(", Duration = ");
    Serial.println(notes[i][1]);
  }

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

void setup()
{
  Serial.begin(9600); // Set baud rate to 9600 for compatibility
  delay(2000);        // Wait 2 seconds to allow Serial Monitor to open
  Serial.println("\nSerial communication started. Testing non-blocking notes.");

  pinMode(BUZZER_PIN, OUTPUT);

  const int testTones[][2] = {
      {NOTE_C4, 500},
      {NOTE_E4, 500},
      {NOTE_G4, 500},
      {NOTE_C5, 500}};
  playNotesNonBlocking(testTones, sizeof(testTones) / sizeof(testTones[0]));
}

void loop()
{
  notePlayer.update();
}
