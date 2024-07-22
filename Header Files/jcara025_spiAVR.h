
#ifndef jcara025_SPIAVR_H
#define jcara025_SPIAVR_H
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "helper.h"
//RESET: pin B0
//CS: B2
//A0: D7
/*B5 should always be SCK(spi clock) (13) and B3 should always be MOSI. (11, SDA)  
If you are using an
SPI peripheral that sends data back to the arduino, you will need to use B4 as the MISO pin.
The SS pin can be any digital pin on the arduino. Right before sending an 8 bit
value with
the SPI_SEND() funtion, you will need to set your SS pin to low. If you have
multiple SPI
devices, they will share the SCK, MOSI and MISO pins but should have different SS
pins.
To send a value to a specific device, set it's SS pin to low and all other SS
pins to high.*/

//Outputs, pin definitions
#define PIN_SCK PORTB5//SHOULD ALWAYS BE B5 ON THE ARDUINO
#define PIN_MOSI PORTB3//SHOULD ALWAYS BE B3 ON THE ARDUINO
#define PIN_SS PORTB2
//If SS is on a different port, make sure to change the init to take that into account.

unsigned char max = 0x80;

void SPI_INIT(){
DDRB |= (1 << PIN_SCK) | (1 << PIN_MOSI) | (1 << PIN_SS); //initialize your pins.
SPCR |= (1 << SPE) | (1 << MSTR); //initialize SPI coomunication
}
void SPI_SEND(char data)
{
SPDR = data;//set data that you want to transmit
while (!(SPSR & (1 << SPIF)));// wait until done transmitting
}

void HardwareReset(){
  PORTB = SetBit(PORTB, 0, 0);  //setResetPinToLow;
  _delay_ms(200);
  PORTB = SetBit(PORTB, 0, 1);  //setResetPinToHigh;
  _delay_ms(200);
}

void sendCommand(unsigned char command){     //send command
    PORTB = SetBit(PORTB, 2, 0); // Set CS pin to 0
    PORTD = SetBit(PORTD, 7, 0);
    SPI_SEND(command);
}

void sendData(unsigned char data){           //send data
    PORTB = SetBit(PORTB, 2, 0); // Set CS pin to 0
    PORTD = SetBit(PORTD, 7, 1);
    SPI_SEND(data);  
}


void ST7735_INIT() {
    HardwareReset();
    PORTB = SetBit(PORTB, 2, 0); // Set CS pin to 0
    sendCommand(0x01); // SWRESET - command
    _delay_ms(150);
    sendCommand(0x11); // SLPOUT  - command
    _delay_ms(200);
    sendCommand(0x0C); // COLMOD  - command
    sendData(0x06);    // for 18 bit color mode - data
    _delay_ms(10);
    sendCommand(0x29); // DISPON  - command
    _delay_ms(200);

    //serial_println("hallo");
}

void setBounds(unsigned char xBeg, unsigned char xEnd, unsigned char yBeg, unsigned char yEnd){
    sendCommand(0x2A); // CASET
    sendData(0x00);    //start_beg
    sendData(xBeg);    //start_fin
    sendData(0x00);    //end_beg
    sendData(xEnd);    //end_fin
    sendCommand(0x2B); // RASET
    sendData(0x00);    //start_beg
    sendData(yBeg);    //start_fin
    sendData(0x00);    //end_beg
    sendData(yEnd);    //end_fin
}


void drawPixelInit(){
    sendCommand(0x2C);
    PORTD = SetBit(PORTD, 7, 1); //A0
}

void drawPixel(unsigned b, unsigned g, unsigned r) {
    sendData(b);
    sendData(g);
    sendData(r);
}

void setBackgroundColor(unsigned char b, unsigned char g, unsigned char r){
    setBounds(0, 127, 0, 127);
    drawPixelInit();
    for (int i = 0; i < 135 * 135; i++){
        drawPixel(b,g,r);
    }
}

#endif /* jcara025_SPIAVR_H */

