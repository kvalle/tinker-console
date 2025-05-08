#include "Sounds.h"

const int marioCoin[][2] = {
    {NOTE_E5, SIXTEENTH_NOTE},
    {NOTE_G5, SIXTEENTH_NOTE},
    {0, 0} // Fine
};

const int marioPowerUp[][2] = {
    {NOTE_C4, EIGHTH_NOTE},
    {NOTE_E4, EIGHTH_NOTE},
    {NOTE_G4, EIGHTH_NOTE},
    {NOTE_C5, EIGHTH_NOTE},
    {0, 0} // Fine
};

const int marioOneUp[][2] = {
    {NOTE_C5, EIGHTH_NOTE},
    {NOTE_E5, EIGHTH_NOTE},
    {NOTE_G5, EIGHTH_NOTE},
    {NOTE_C6, EIGHTH_NOTE},
    {0, 0} // Fine
};

const int marioGameOver[][2] = {
    {NOTE_C5, QUARTER_NOTE},
    {NOTE_G4, QUARTER_NOTE},
    {NOTE_E4, QUARTER_NOTE},
    {NOTE_C4, HALF_NOTE},
    {0, 0} // Fine
};

const int marioFlagpole[][2] = {
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

const int fanfare[][2] = {
    {NOTE_C4, EIGHTH_NOTE},
    {NOTE_E4, EIGHTH_NOTE},
    {NOTE_G4, EIGHTH_NOTE},
    {NOTE_C5, EIGHTH_NOTE},
    {NOTE_E5, EIGHTH_NOTE},
    {NOTE_G5, EIGHTH_NOTE},
    {NOTE_C6, QUARTER_NOTE},
    {NOTE_G5, EIGHTH_NOTE},
    {NOTE_C6, HALF_NOTE},
    {0, 0} // Fine
};

const int buttonPress[][2] = {
    {NOTE_C5, EIGHTH_NOTE},
    {0, 0} // Fine
};

const int buttonPressDouble[][2] = {
    {NOTE_C5, SIXTEENTH_NOTE},
    {NOTE_E5, SIXTEENTH_NOTE},
    {0, 0} // Fine
};