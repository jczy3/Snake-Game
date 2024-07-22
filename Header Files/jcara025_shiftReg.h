// Permission to copy is granted provided that this header remains intact. 
// This software is provided with no warranties.

#ifndef SHIFTREG_H
#define SHIFTREG_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "helper.h"

int nums[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, //0
    {0, 1, 1, 0, 0, 0, 0}, //1
    {1, 1, 0, 1, 1, 0, 1}, //2
    {1, 1, 1, 1, 0, 0, 1}, //3
    {0, 1, 1, 0, 0, 1, 1}, //4 
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 0, 1, 1, 1, 1, 1}, //6
    {1, 1, 1, 0, 0, 0, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1}  //9
};

void shift (int x){
    int currVal = 0;
    PORTD = SetBit(PORTD, 3, 0);  // latch
    PORTD = SetBit(PORTD, 2, 0);  // set clock pin to 0

    for (int i = 6; i >= 0; i--){
        currVal = nums[x][i];
        PORTD = SetBit(PORTD, 4, currVal);  //set data pin to 1 or 0
        PORTD = SetBit(PORTD, 2, 1);        //set clock to 1, put data into a pin on the register
        PORTD = SetBit(PORTD, 2, 0);        //set clock to 0, shift data to the register
    }

    PORTD = SetBit(PORTD, 3, 1);            //set latch to 1, transmit data
}


#endif // shiftReg.h
