#ifndef RAND_H
#define RAND_H
#define mult 1664525
#define inc 1013904223
#define mod 294967296

unsigned long seed = 1; // Initial seed value
const unsigned long a = mult;
const unsigned long c = inc; 
const unsigned long l = mod; 

// Seed value function
void srand(unsigned long val) {
    seed = val;
}

// Function that generates next random number
unsigned long rand() {
    seed = (a * seed + c) % l;
    return seed;
}

// Used to generate number within a range
unsigned long randRange(unsigned long MIN, unsigned long MAX) {
    unsigned long randValue = MIN + rand() % ((MAX - MIN) / 8 + 1); // Generate a random value within the range
    return randValue * 8;                                           // Make sure the random value is a multiple of 8
}

#endif