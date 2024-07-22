#include "helper.h"
#include "periph.h"
#include "serialATmega.h"
#include "jcara025_spiAVR.h"
#include "jcara025_music.h"
#include "jcara025_draw.h"
#include "jcara025_shiftReg.h"
#include "jcara025_snake.h"
#include "jcara025_rand.h"


// from up/down, can only go left/right.
// from left/right, can only go up/down.


#define NUM_TASKS 4 //TODO: Change to the number of tasks being used
// snake game task
// main menu task
bool upBool, downBool, leftBool, rightBool, pressBool;
bool snakeGameStart = false;
int snakeDir = rightOrientation;
int score = 0;
snake user;

//Task struct for concurrent synchSMs implmentations
typedef struct _task{
 signed   char state;    //Task's current state
 unsigned long period;     //Task period
 unsigned long elapsedTime;  //Time elapsed since last task tick
 int (*TickFct)(int);    //Task tick function
} task;


//TODO: Define Periods for each task
// e.g. const unsined long TASK1_PERIOD = <PERIOD>
const unsigned long joystickPer = 100;
const unsigned long fourDigit7SegmentPer = 1;
const unsigned long snakePer = 500;
const unsigned long menuPer = 12;
const unsigned long GCD_PERIOD = 1;//TODO:Set the GCD Period


task tasks[NUM_TASKS]; // declared task array with 5 tasks




void TimerISR() {
 for ( unsigned int i = 0; i < NUM_TASKS; i++ ) {                   // Iterate through each task in the task array
   if ( tasks[i].elapsedTime == tasks[i].period ) {           // Check if the task is ready to tick
     tasks[i].state = tasks[i].TickFct(tasks[i].state); // Tick and set the next state for this task
     tasks[i].elapsedTime = 0;                          // Reset the elapsed time for the next tick
   }
   tasks[i].elapsedTime += GCD_PERIOD;                        // Increment the elapsed time by GCD_PERIOD
 }
}


//TODO: Create your tick functions for each task
enum joystickEnum {joystickInit, idle, up, down, left, right};
//states dictate snakeDir orientation
int joystickFunction(int state){
 switch (state){

   case joystickInit:
     state = idle;
     break;

   case idle:
   if (upBool){
       state = up;
     }
     else if (downBool){
       state = down;
     }
     else if (leftBool){
       state = left;
     }
     else if (rightBool){
       state = right;
     }
     else{
       state = idle;
     }
     break;
    
   case up:            // let state actions dictate snakeDir orientation
     state = idle;
     break;


   case down:         
     state = idle;
     break;


   case left:
     state = idle;
     break;


   case right:
     state = idle;
     break;


   default:
     state = joystickInit;
     break;


 }


 switch (state){
   case joystickInit:
     break;


   case idle:
     break;


   case up:
     snakeDir = upOrientation;
     break;

  
   case down:
     snakeDir = downOrientation;
     break;


   case left:
     snakeDir = leftOrientation;
     break;


   case right:
     snakeDir = rightOrientation;
     break;


   default:
     break;


 }
 return state;
}

enum fourDigit7segmentEnum {digitInit, dig1State, dig2State, dig3State, dig4State};

int fourDigit7segmentFunction(int state){
  int dig1 = score % 10;
  int dig2 = (score / 10) % 10;
  int dig3 = (score / 100) % 10;
  int dig4 = 0;
 switch (state){

   case digitInit:
     state = dig1State;
     break;


   case dig1State:
     state = dig2State;
     break;


   case dig2State:
     state = dig3State;
     break;


   case dig3State:
     state = dig4State;
     break;


   case dig4State:
     state = dig1State;
     break;
     

   default:
     state = digitInit;
     break;


 }


 switch (state){


   case digitInit:
     break;


   case dig1State:
     PORTD = SetBit(PORTD, 6, 1);
     shift(dig1);
     PORTC = SetBit(PORTC, 3,0);
     break;


   case dig2State:
     PORTC = SetBit(PORTC, 3,1);
     shift(dig2);
     PORTC = SetBit(PORTC, 4,0);
     break;


   case dig3State:
     PORTC = SetBit(PORTC, 4,1);
     shift(dig3);
     PORTC = SetBit(PORTC, 5,0);
     break;


   case dig4State:
     PORTC = SetBit(PORTC, 5,1);
     shift(dig4);
     PORTD = SetBit(PORTD, 6,0);
     break;

   default:
     break;


 }
 return state;
}


enum moveSnakeEnum {snakeInit, start, moveLeft, moveRight, moveUp, moveDown, loseState};
// actually moves snake using snakeDir
// sets snakeGameStart to communicate with menuFunction to tell whether game is running or not
int moveSnakeFunction(int state){
 switch (state){
   case snakeInit:
     state = start;
     break;


   case start:
     if(snakeGameStart == true){
       setBackgroundColor(0,255,0);
       user.snakeInit();
       user.createApple();
       state = moveRight;
     }
     else state = start;
     break;


   case moveUp:
     if (snakeDir == leftOrientation) state = moveLeft;
     else if (snakeDir == rightOrientation) state = moveRight;
     else state = moveUp;
     if(user.snakeCollision() == true){
       setBackgroundColor(0,255,0);
       snakeGameStart = false;
       state = loseState;
       score = 0;
     }
     break;


   case moveDown:
     if (snakeDir == leftOrientation) state = moveLeft;
     else if (snakeDir == rightOrientation) state = moveRight;
     else state = moveDown;
     if(user.snakeCollision() == true){
       setBackgroundColor(0,255,0);
       snakeGameStart = false;
       state = loseState;
       score = 0;
     }
     break;


   case moveLeft:
     if (snakeDir == upOrientation) state = moveUp;
     else if (snakeDir == downOrientation) state = moveDown;
     else state = moveLeft;
     if(user.snakeCollision() == true){
       setBackgroundColor(0,255,0);
       snakeGameStart = false;
       state = loseState;
       score = 0;
     }
     break;


   case moveRight:
     if (snakeDir == upOrientation) state = moveUp;
     else if (snakeDir == downOrientation) state = moveDown;
     else state = moveRight;
     if(user.snakeCollision() == true){
       setBackgroundColor(0,255,0);
       snakeGameStart = false;
       state = loseState;
       score = 0;
     }
     break;


   case loseState:
     if(snakeGameStart == true){
       setBackgroundColor(0,255,0);
       user.snakeInit();
       user.createApple();
       state = moveRight;
     }
     else state = start; // Transition back to start state
     //deathMusic();
     break;


   default:
     break;
 }


 switch (state){     //change head orientation in states


   case snakeInit:
     break;


   case start:
     //user.moveSnake(8,0);
     break;


   case moveUp:
     setBackgroundColor(0,255,0);
     user.moveSnake(0,-8);
     user.printApple();
     if (user.appleEaten() == true){
      user.createApple();
      user.growSnake(0,-8);
      score++;
      //appleSound();
     }
     break;


   case moveDown:
     setBackgroundColor(0,255,0);
     user.moveSnake(0,8);
     user.printApple();
     if (user.appleEaten() == true){
      user.createApple();
      user.growSnake(0,8);
      score++;
      //appleSound();
     }
     break;


   case moveLeft:
     setBackgroundColor(0,255,0);
     user.moveSnake(-8,0);
     user.printApple();
     if (user.appleEaten() == true){
      user.createApple();
      user.growSnake(-8,0);
      score++;
      //appleSound();
     }
     break;


   case moveRight:
     setBackgroundColor(0,255,0);
     user.moveSnake(8,0);
     user.printApple();
     if (user.appleEaten() == true){
      user.createApple();
      user.growSnake(8,0); //and play sound and add to score
      score++;
      //appleSound();
     }
     break;

   case loseState:
     break;

   default:
     break;

 }
 return state;
}


enum menuEnum {menuInit, menuIdle, startGame, loseGame};
int menuFunction(int state){
 switch (state){


   case menuInit:
     setBackgroundColor(0,255,0);
     printSnake();
     printStart();
     state = menuIdle;
     break;


   case menuIdle:
     if (pressBool){
       stopBuzzer();
       DDRB = SetBit(DDRB, 1, 0);
       snakeGameStart = true;
       state = startGame;
     }
     else{
       state = menuIdle;
       playMainMenu();
     }
     break;


   case startGame:
     if (snakeGameStart == false){
       state = loseGame;
     }
     else{
       state = startGame;
     }
     break;


   case loseGame:
     if (pressBool){
       state = menuInit;
     }
     else{
       state = loseGame;
     }
     break;


   default:
     break;


 }


 switch (state){    


   case menuInit:
     break;


   case menuIdle:
     break;


   case startGame:
     break;


   case loseGame:
     printLose();
     break;


   default:
     break;


 }
 return state;
}


int main(void) {
   //TODO: initialize all your inputs and ouputs
   DDRB = 0xFF; PORTB = 0x00;
   DDRC = 0b111000; PORTC = 0b000111;
   DDRD = 0xFF; PORTD = 0x00;
   ADC_init();   // initializes ADC
   serial_init(9600);
   SPI_INIT();
   ST7735_INIT();
   setBackgroundColor(0,255,0);
  


   //TODO: Initialize the buzzer timer/pwm(timer0)
   TCCR1A |= (1 << WGM11) | (1 << COM1A1);
   TCCR1B |= (1 << WGM12) | (1 << WGM13)| (1 << CS11);


   //left signal
   tasks[0].period = joystickPer;
   tasks[0].state = joystickInit;
   tasks[0].elapsedTime = tasks[0].period;
   tasks[0].TickFct = &joystickFunction;


   tasks[1].period = fourDigit7SegmentPer;
   tasks[1].state = digitInit;
   tasks[1].elapsedTime = tasks[1].period;
   tasks[1].TickFct = &fourDigit7segmentFunction;


   tasks[2].period = snakePer;
   tasks[2].state = snakeInit;
   tasks[2].elapsedTime = tasks[2].period;
   tasks[2].TickFct = &moveSnakeFunction;


   tasks[3].period = menuPer;
   tasks[3].state = menuInit;
   tasks[3].elapsedTime = tasks[3].period;
   tasks[3].TickFct = &menuFunction;


   TimerSet(GCD_PERIOD);
   TimerOn();


   while (1) {
     //x axis - Pin A0, left is > 900, right is < 200
     //y axis - Pin A1, up is > 900, down is < 200
     //printSnake();
     //printStart();
     //drawApple(70,77,70,77);
     //appleSound();
     upBool = ADC_read(1) > 900;
     downBool = ADC_read(1) < 200;
     leftBool = ADC_read(0) > 900;
     rightBool = ADC_read(0) < 200;
     pressBool = !((PINC >> 2) & 0x01);
     serial_println(score);
   }


   return 0;
}



