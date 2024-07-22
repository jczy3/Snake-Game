//ICR1 values for notes
#ifndef jcara025_MUSIC_H
#define jcara025_MUSIC_H
#include "timerISR.h"
#define NoteEFlat (6350)
#define NoteG (4950)
#define NoteE (6000)
#define NoteB (8000)
#define NoteD (6750)
#define NoteCSharp (7300)
#define NoteC (7650)
#define NoteA (9000)
#define LowC (15000)
#define LowE (12000)
#define LowG (10000)
#define pause (0)

int i=0,cnt=0;

//Main menu music values for ICR
unsigned int menu[35] = {NoteE,NoteEFlat,NoteE,NoteEFlat,NoteE,NoteB,NoteD,NoteC,NoteA,
                        LowC,LowE,NoteA,NoteB, LowE,NoteA,NoteB,NoteC,LowE,
                        NoteE,NoteEFlat,NoteE,NoteEFlat,NoteE,NoteB,NoteD,NoteC,NoteA,
                        LowC,LowE,NoteA,NoteB,LowE,NoteC,NoteB,NoteA};
int menuNoteTimes[35] = {50,50,50,50,50,50,50,50,100,
50,50,50,100,50,50,50,100,50,
50,50,50,50,50,50,50,50,100,
50,50,50,100,50,50,50,150};

unsigned int death[23] = {NoteE,pause,NoteE,NoteEFlat,pause,NoteD,pause,NoteCSharp,pause,
                          NoteC,pause,NoteC,pause,NoteC,pause,NoteC,pause,NoteC,pause,NoteC,pause,NoteC,pause};

int deathNoteTimes[23] = {50,50,50,75,100,75,100,75,100,25,25,25,25,25,25,25,25,25,25,25,25,25,25};

unsigned int apple[7] = {NoteC,pause,NoteE,pause,NoteG,pause};

int appleNoteTimes[7] = {20,10,20,10,20,2^32};

void resetVariables() {
    i = 0;
    cnt = 0;
}

bool mainMenuPlaying = false; // Flag to indicate whether main menu music is playing

void playMainMenu(){
  if (!mainMenuPlaying) {
    DDRB = SetBit(DDRB, 1, 1);
    resetVariables(); // Reset i and cnt only if main menu music is not already playing
    mainMenuPlaying = true; // Set flag to indicate main menu music is playing
  }

  ICR1 = menu[i];
  OCR1A = ICR1/2;
  cnt++;
  if(cnt == menuNoteTimes[i]){
    i++;
    cnt = 0;
  }
  i%=35;
}

void stopBuzzer() {
  DDRB = SetBit(DDRB, 1, 0);
  mainMenuPlaying = false; // Reset flag when stopping the buzzer
  resetVariables(); // Reset i and cnt
}

void deathMusic(){
  DDRB = SetBit(DDRB, 1, 1);
  ICR1 = death[i];
  OCR1A = ICR1/2;
  cnt++;
  if(cnt == deathNoteTimes[i]){
    i++;
    cnt = 0;
  }
}


void appleSound(){
  DDRB = SetBit(DDRB, 1, 1);
  ICR1 = apple[i];
  OCR1A = ICR1/2;
  cnt++;
  if(cnt == appleNoteTimes[i]){
    i++;
    cnt = 0;
  }
}
#endif