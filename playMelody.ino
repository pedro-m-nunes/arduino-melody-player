/* Based on http://www.arduino.cc/en/Tutorial/Tone */

#include "config.h"
#include "pitches.h"

// class Song? attributes: notePitches, noteValues, compassesMeters (?), bpm.
// int[] compassesMeters replacing timeSignature? // array for changing time signatures, validation needed then...

/* Song: Can't Stop by the Red Hot Chili Peppers (Bass riff) */

double bpm = 91;
int timeSignatureNumerator = 4;
int timeSignatureDenominator = 4;

int notePitches[] = {
  E2, D3, E3, E2, PAUSE, E2, D3, PAUSE, E3, PAUSE, E2, 
  D2, D3, E3, D2, PAUSE, D2, D3, PAUSE, E3, PAUSE, A2, 
  B1, B2, B2, B1, B1, B2, B1, B2, PAUSE, B1, 
  C2, C3, C3, C2, C2, C3, C2, C3, PAUSE, C2
};

int noteValues[] = {
  8, 8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 
  8, 8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 
  8, 8, 8, 8, 16, 16, 16, 16, 16, 8, 8, 
  8, 8, 8, 8, 16, 16, 16, 16, 16, 8, 8
};


/* Project methods */

void playSong(double bpm, int timeSignatureNumerator, int timeSignaturaDenominator, int notePitches[], int noteValues[], int quantityOfNotes) {
  double barDuration = 60000 * timeSignatureNumerator / bpm; // ! // Denominator?

    for (int i = 0; i < quantityOfNotes; i++) {
      double noteLength = barDuration / noteValues[i];

      playNote(notePitches[i], noteLength);
    }
}

void playNote(int notePitch, int noteLength) {
  tone(PIEZO_PIN, notePitch, noteLength * (1 - PAUSE_DURATION_PERCENTAGE));
  delay(noteLength);
  noTone(PIEZO_PIN);
}


/* Arduino methods */

void setup() {
  if(!LOOP_SONG) {
    playSong(bpm, timeSignatureNumerator, timeSignatureDenominator, notePitches, noteValues, sizeof(notePitches) / sizeof(int));
  }
}

void loop() {
  if(LOOP_SONG) {
    playSong(bpm, timeSignatureNumerator, timeSignatureDenominator, notePitches, noteValues, sizeof(notePitches) / sizeof(int));
    delay(DELAY_BETWEEN_REPETITIONS);
  }
}
