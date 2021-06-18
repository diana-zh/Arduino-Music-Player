// Arduino Uno Music Player - Everglow (Coldplay)
// Diana Zhang, June 2021
// Musical arrangement done by me, template credits: Robson Couto at https://github.com/robsoncouto/arduino-songs
 
// define notes in song with ~frequency in Hz
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define REST 0
 
// set speed of the song in beats per minute
int tempo = 120; 
 
// speaker from my project was connected to pin 8 of my Arduino
int buzzer = 8;
 
// array containing each note + its duration of the song. Numbers used for duration correlate to the note (eg. eigth note = 8, quarter note = 4, whole note = 1, etc)
int melody[] =
{
  // arrangement done by ear

  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_E5, 4,  NOTE_DS5, 4,  NOTE_CS5, 2,  NOTE_B4, 2,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_B4, 4,  NOTE_GS4, 4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_FS4, 4,  NOTE_E4, 4,  NOTE_CS4, 2,  NOTE_B3, 2,  REST, 8,  NOTE_B3, 8,
  NOTE_E4, 4,  NOTE_FS4, 8,  NOTE_GS4, -4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_E5, 4,  NOTE_DS5, 4,  NOTE_CS5, 2,  NOTE_B4, 2,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_B4, 4,  NOTE_GS4, 4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_FS4, 4,  NOTE_E4, 4,  NOTE_CS4, 2,  NOTE_B3, 2,  REST, 8,  NOTE_B3, 8, NOTE_E4, 4,  NOTE_FS4, 8,  NOTE_FS4, -4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_B4, 4,  NOTE_B4, 4, NOTE_CS5, 1,  NOTE_GS4, 4,  NOTE_GS4, 4,  NOTE_GS4, 4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_FS4, 4,  NOTE_E4, 4,  NOTE_CS4, 2,  NOTE_B3, 2,  NOTE_B3, 4,  NOTE_E4, 4,  NOTE_FS4, 8,  NOTE_GS4, -4,  NOTE_FS4, 1,
  NOTE_E4, 4,  NOTE_GS4, 4,  NOTE_B4, 4,  NOTE_B4, 4,  NOTE_CS5, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_GS4, 4,  NOTE_GS4, 4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_FS4, 4,  NOTE_E4, 4,  NOTE_CS4, 2,  NOTE_B3, 4,  NOTE_GS3, 2,
  NOTE_E4, -4,  NOTE_B3, -4, NOTE_DS4, 4,  NOTE_DS4, -4,  NOTE_B3, 8,  NOTE_E4, 16,  NOTE_B3, 16,  NOTE_E4, 16,  NOTE_B4, 16,  NOTE_E5, 16,  NOTE_B4, 16,  NOTE_E5, 16,  NOTE_B5, 16,  NOTE_GS5, 16,  NOTE_E5, 16,  NOTE_B4, 16,  NOTE_GS4, 16,  NOTE_B4, 4,  NOTE_FS4, 4,  NOTE_FS4, 2,
  NOTE_E4, 16,  NOTE_B3, 16,  NOTE_E4, 16,  NOTE_B4, 16,  NOTE_GS4, 16,  NOTE_E4, 16,  NOTE_B3, 16,  NOTE_GS3, 16,  NOTE_B3, 8,  NOTE_E4, 8,  NOTE_DS4, 3,  NOTE_E5, 16,  NOTE_B4, 16,  NOTE_E5, 16,  NOTE_B5, 16,  NOTE_GS5, 16,  NOTE_E5, 16,  NOTE_B4, 16,  NOTE_GS4, 16,  NOTE_B4, 4, NOTE_B4, 3,
  NOTE_E4, 16,  NOTE_B3, 16,  NOTE_E4, 16,  NOTE_B4, 16,  NOTE_GS4, 16,  NOTE_E4, 16,  NOTE_B3, 16,  NOTE_GS3, 16,  NOTE_B3, 8,  NOTE_E4, 8,  NOTE_DS4, 2,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_B4, 4,  NOTE_B4, 4,  NOTE_CS5, 1, 
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_GS4, 4,  NOTE_GS4, 4,  NOTE_FS4, 1,
  NOTE_E4, 8,  NOTE_FS4, 8,  NOTE_GS4, 4,  NOTE_FS4, 4,  NOTE_E4, 4,  NOTE_CS4, 2,  NOTE_B3, 4,  NOTE_E4, 1,

};
 
// set up condition in for loop
int notes = sizeof(melody) / sizeof(melody[0]) / 2; 
 
// whole note duration
int wholenote = (60000 * 4) / tempo;
 
int divider = 0, noteDuration = 0;
 
void setup()
{
  // notes of song iterate
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) // adds 2 to account for size + duration of each note
  {
    divider = melody[thisNote + 1]; // calculates the duration of each note
    
    if (divider > 0) // proceeds as a regular note
    {
      noteDuration = (wholenote) / divider;
    }
    else if (divider < 0) // dotted notes entered in durations < 0
    {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // adds half duration for dotted notes
    }
 
    // slight pause added in note duration
    tone(buzzer, melody[thisNote], noteDuration*0.9);
 
    // delay for previous note's duration before proceeding to next note
    delay(noteDuration);
  }
}
 
void loop(){ // song does not repeat
}
