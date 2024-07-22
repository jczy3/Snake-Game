#ifndef jcara025_DRAW_H
#define jcara025_DRAW_H
#include "jcara025_spiAVR.h"

void drawHead(int xSt, int xFin, int ySt, int yFin){
    setBounds(xSt, xFin, ySt, yFin);
    drawPixelInit();
    for(int i = 0; i < 8; i++){
        drawPixel(0, 0, 0);
    }
    for(int i = 0; i < 6; i++){
        drawPixel(0, 0, 0);
        for(int j = 0; j < 6; j++){
            drawPixel(255, 255, 255);
        }
        drawPixel(0, 0, 0);
    }
    for(int i = 0; i < 8; i++){
        drawPixel(0, 0, 0);
    }
}

void drawBody(int xSt, int xFin, int ySt, int yFin){
    setBounds(xSt, xFin, ySt, yFin);
    drawPixelInit();
    for(int i = 0; i < 8; i++){
        drawPixel(0, 0, 0);
    }
    for(int i = 0; i < 6; i++){
        drawPixel(0, 0, 0);
        for(int j = 0; j < 6; j++){
            drawPixel(125, 0, 0);
        }
        drawPixel(0, 0, 0);
    }
    for(int i = 0; i < 8; i++){
        drawPixel(0, 0, 0);
    }
}

void drawApple(int xSt, int xFin, int ySt, int yFin){
    setBounds(xSt, xFin, ySt, yFin);
    drawPixelInit();
    for(int i = 0; i < 8; i++){
        drawPixel(0, 0, 0);
    }
    for(int i = 0; i < 6; i++){
        drawPixel(0, 0, 0);
        for(int j = 0; j < 6; j++){
            drawPixel(0, 0, 255);
        }
        drawPixel(0, 0, 0);
    }
    for(int i = 0; i < 8; i++){
        drawPixel(0, 0, 0);
    }
}

void printSnake(){
    //S

    setBounds(105, 115, 104, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(113, 115, 95, 105);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(105, 115, 94, 96);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(105, 107, 85, 95);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(105, 115, 84, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }

    //N

    setBounds(90, 92, 84, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(81, 91, 104, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(81, 83, 84, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }

    //A

    setBounds(66, 68, 84, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(58, 66, 104, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 27; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(57, 59, 84, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(58, 66, 94, 96);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }

    //K

    setBounds(42, 44, 84, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(40, 42, 94, 96);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }

    // descent

    setBounds(38, 40, 92, 94);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(36, 38, 90, 92);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(34, 36, 88, 90);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(32, 34, 86, 88);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(30, 32, 84, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }

    //ascent

    setBounds(38, 40, 96, 98);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(36, 38, 98, 100);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(34, 36, 100, 102);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(32, 34, 102, 104);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(30, 32, 104, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 9; i++){
        drawPixel(0, 0, 0);
    }

    //E

    setBounds(18, 20, 84, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(12, 20, 104, 106);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 27; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(12, 20, 94, 96);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 27; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(12, 20, 84, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 27; i++){
        drawPixel(0, 0, 0);
    }
}

void printStart(){
    //S
    setBounds(85, 90, 50, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(89, 90, 45, 50);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(85, 90, 45, 46);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(85, 86, 40, 45);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(85, 90, 40, 41);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }

    //T
    setBounds(75, 80, 50, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(77, 78, 40, 50);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 22; i++){
        drawPixel(0, 0, 255);
    }

    //A
    setBounds(69, 70, 40, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 24; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(65, 68, 50, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 10; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(64, 65, 40, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 24; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(64, 68, 45, 46);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 10; i++){
        drawPixel(0, 0, 255);
    }

    //R
    setBounds(57, 58, 40, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 24; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(53, 57, 50, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 10; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(53, 57, 45, 46);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 10; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(52, 53, 45, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 14; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(54, 55, 43, 44);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 4; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(53, 54, 42, 43);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 4; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(52, 53, 41, 42);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 4; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(52, 52, 40, 41);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 2; i++){
        drawPixel(0, 0, 255);
    }
    // 40,41 for last y

    //T
    setBounds(42, 47, 50, 51);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 12; i++){
        drawPixel(0, 0, 255);
    }
    setBounds(44, 45, 40, 50);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 22; i++){
        drawPixel(0, 0, 255);
    }
}

/*void printGameover(){
    //G
    setBounds(105, 115, 84, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(115, 117, 67, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 60; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(105, 115, 67, 80);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(105, 107, 67, 75);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 27; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(105, 110, 75, 77);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 18; i++){
        drawPixel(0, 0, 0);
    }

    //A
    setBounds(91, 93, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(83, 91, 84, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 27; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(82, 84, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(83, 91, 74, 76);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 33; i++){
        drawPixel(0, 0, 0);
    }

    //M
    setBounds(68, 70, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
}*/

void printLose(){
    //L
    setBounds(91, 93, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(80, 93, 64, 66);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    //O
    setBounds(71, 73, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(63, 73, 64, 66);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(61, 63, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(63, 73, 84, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    //S

    setBounds(43, 53, 64, 66);  //bootom
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(43, 53, 84, 86);  //top
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(51, 53, 74, 86);  //
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(43, 53, 74, 76);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(41, 43, 64, 76);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }

    //E
    setBounds(31, 33, 64, 86);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 69; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(23, 33, 64, 66);  //bottom
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(23, 33, 84, 86);  //top
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
    setBounds(23, 33, 74, 76);  //area = (endX - startX + 1) * (endY - startY + 1)
    drawPixelInit();
    for(int i = 0; i < 42; i++){
        drawPixel(0, 0, 0);
    }
}

#endif /* jcara025_DRAW_H */