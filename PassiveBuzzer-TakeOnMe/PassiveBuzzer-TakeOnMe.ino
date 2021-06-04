//A-ha!
//by GeneralSpud

// For this to work, we need the pitches library

#include "pitches.h"

int pinBuzzer = 31;

// Two things need to be created: the array for the notes of the melody (in order)
// and the duration of each (think of it like sheet music in two parts)

// BOTH ARRAYS MUST BE THE SAME SIZE!

// The melody array 
int melody[] = {
  NOTE_FS4, NOTE_FS4, NOTE_D4, NOTE_B3, NOTE_B3, NOTE_E4, 
  NOTE_E4, NOTE_E4, NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_B4, 
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_D4, NOTE_FS4, 
  NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_E4
};

// The note duration, 8 = 8th note, 4 = quarter note, etc.
int durations[] = {
  8, 8, 8, 4, 4, 4, 
  4, 8, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 8, 8, 8, 8, 8
};
// determine the length of the arrays to use in the loop iteration
int songLength = sizeof(melody)/sizeof(melody[0]);
void setup() {
 pinMode(pinBuzzer,OUTPUT);
}

void loop() {
  // Iterate through both arrays
  // Notice how the iteration variable thisNote is created in the parenthesis
  // The for loop stops when it is equal to the size of the melody array
  for (int thisNote = 0; thisNote < songLength; thisNote++){
    // determine the duration of the notes that the computer understands
    // divide 1000 by the value, so the first note lasts for 1000/8 milliseconds
    int duration = 1000/ durations[thisNote];
    tone(pinBuzzer, melody[thisNote], duration);
    // pause between notes
    int pause = duration * 1.3;
    delay(pause);
    // stop the tone
    noTone(pinBuzzer);
  }

  //delay(5000);
}
