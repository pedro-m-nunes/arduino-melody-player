/* Adapted from http://www.arduino.cc/en/Tutorial/Tone */

#include "pitches.h"

const int piezoPin = 11;

int notes[] = { // Can't Stop by the Red Hot Chili Peppers (Bass riff)
  E2, D3, E3, E2, PAUSE, E2, D3, PAUSE, E3, PAUSE, E2, 
  D2, D3, E3, D2, PAUSE, D2, D3, PAUSE, E3, PAUSE, A2, 
  B1, B2, B2, B1, B1, B2, B1, B2, PAUSE, B1, 
  C2, C3, C3, C2, C2, C3, C2, C3, PAUSE, C2
};

int noteLengthDenominators[] = {
  8, 8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 
  8, 8, 8, 16, 16, 16, 16, 16, 16, 8, 8, 
  8, 8, 8, 8, 16, 16, 16, 16, 16, 8, 8, 
  8, 8, 8, 8, 16, 16, 16, 16, 16, 8, 8
};

double bpm = 91;
int notesInBar = 4;

void setup() {
  int notesArraySize = sizeof(notes) / sizeof(int);
  double barDuration = 60000 * notesInBar / bpm;
  double pauseDurationPercentage = 0.01;
  
  for (int i = 0; i < notesArraySize; i++) {
    double noteLength = barDuration / noteLengthDenominators[i];
    // pauseBetweenNotes // ?
    
    tone(piezoPin, notes[i], noteLength * (1 - pauseDurationPercentage));
    delay(noteLength);
    noTone(piezoPin);
  }
}

void loop() {
  
}
