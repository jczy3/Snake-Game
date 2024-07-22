#ifndef SNAKE_H
#define SNAKE_H
#include "jcara025_draw.h"
#include "serialATmega.h"
#include "jcara025_music.h"
#include "jcara025_rand.h"
#define upOrientation (1)
#define downOrientation (2)
#define leftOrientation (3)
#define rightOrientation (4)


int xBeg0;
int xEnd0;
int yBeg0;
int yEnd0;
bool appleisEaten = true;

class snakeNode{            //class for snake nodes
private:                    //private data members for a snake node
  int xBeg, xEnd, yBeg, yEnd;
  snakeNode* nextNodePtr;


public:
  snakeNode(int xSt, int xFin, int ySt, int yFin){
      xBeg = xSt;
      xEnd = xFin;
      yBeg = ySt;
      yEnd = yFin;
  }
  void setNext(snakeNode* nextNode){
      this->nextNodePtr = nextNode;
  }
  snakeNode* getNext() const{
      return this->nextNodePtr;
  }
  int getxBeg(){
      return this->xBeg;
  }
  int getxEnd(){
      return this->xEnd;
  }
  int getyBeg(){
      return this->yBeg;
  }
  int getyEnd(){
      return this->yEnd;
  }
  void setxBeg(int x0){
      this->xBeg = x0;
  }
  void setxEnd(int x1){
      this->xEnd = x1;
  }
  void setyBeg(int y0){
      this->yBeg = y0;
  }
  void setyEnd(int y1){
      this->yEnd = y1;
  }
};



class snake {
private:
    snakeNode* head;
    snakeNode* tail;
    snakeNode* apple;

public:
    snake() : head(nullptr), tail(nullptr), apple(nullptr) {}

    ~snake() {
        snakeNode* currNode = head;
        snakeNode* nextNode;

        // Delete each node in the snake
        while (currNode != nullptr) {
            nextNode = currNode->getNext();
            delete currNode;
            currNode = nextNode;
        }

        // Set head, tail, and apple pointers to nullptr
        head = nullptr;
        tail = nullptr;
        apple = nullptr;
    }

    void snakeInit() {
        // Initialize snake with three segments
        head = tail = nullptr;
        int length = 3;

        for (int i = 0; i < length; i++) {
            int xBeg = (head == nullptr) ? 64 : tail->getxBeg() - 8;
            int xEnd = xBeg + 7;
            int yBeg = 64;
            int yEnd = yBeg + 7;

            snakeNode* newNode = new snakeNode(xBeg, xEnd, yBeg, yEnd);
            newNode->setNext(nullptr);

            if (head == nullptr) {
                head = tail = newNode;
                drawHead(xBeg, xEnd, yBeg, yEnd);
            } else {
                tail->setNext(newNode);
                tail = newNode;
                drawBody(xBeg, xEnd, yBeg, yEnd);
            }
        }
    }

    void createApple() {
        if (appleisEaten) {
            getAppleCoords();
            appleisEaten = false;

            if (apple == nullptr) {
                apple = new snakeNode(xBeg0, xEnd0, yBeg0, yEnd0);
            } else {
                apple->setxBeg(xBeg0);
                apple->setxEnd(xEnd0);
                apple->setyBeg(yBeg0);
                apple->setyEnd(yEnd0);
            }

            drawApple(apple->getxBeg(), apple->getxEnd(), apple->getyBeg(), apple->getyEnd());
        }
    }

    bool appleEaten() {
        if (head->getxBeg() == apple->getxBeg() && head->getxEnd() == apple->getxEnd() &&
            head->getyBeg() == apple->getyBeg() && head->getyEnd() == apple->getyEnd()) {
            //serial_println("eaten");
            appleisEaten = true;
            return true;
        }
        return false;
    }

    void moveSnake(int deltaX, int deltaY) {
        snakeNode* current = head;
        int prevxBeg = current->getxBeg();
        int prevxEnd = current->getxEnd();
        int prevyBeg = current->getyBeg();
        int prevyEnd = current->getyEnd();

        current->setxBeg(prevxBeg + deltaX);
        current->setxEnd(prevxEnd + deltaX);
        current->setyBeg(prevyBeg + deltaY);
        current->setyEnd(prevyEnd + deltaY);

        drawHead(current->getxBeg(), current->getxEnd(), current->getyBeg(), current->getyEnd());

        current = current->getNext();

        while (current != nullptr) {
            int currentxBeg = current->getxBeg();
            int currentxEnd = current->getxEnd();
            int currentyBeg = current->getyBeg();
            int currentyEnd = current->getyEnd();

            current->setxBeg(prevxBeg);
            current->setxEnd(prevxEnd);
            current->setyBeg(prevyBeg);
            current->setyEnd(prevyEnd);

            drawBody(current->getxBeg(), current->getxEnd(), current->getyBeg(), current->getyEnd());

            prevxBeg = currentxBeg;
            prevxEnd = currentxEnd;
            prevyBeg = currentyBeg;
            prevyEnd = currentyEnd;

            current = current->getNext();
        }
    }

    void growSnake(int deltaX, int deltaY) {
        int xBeg = tail->getxBeg() + deltaX;
        int xEnd = tail->getxEnd() + deltaX;
        int yBeg = tail->getyBeg() + deltaY;
        int yEnd = tail->getyEnd() + deltaY;

        snakeNode* newNode = new snakeNode(xBeg, xEnd, yBeg, yEnd);
        newNode->setNext(nullptr);

        tail->setNext(newNode);
        tail = newNode;

        drawBody(xBeg, xEnd, yBeg, yEnd);
    }

    bool snakeCollision() {
        if (head->getxBeg() < 0 || head->getxEnd() > 127 || head->getyBeg() < 0 || head->getyEnd() > 127) {
            serial_println("BOUNDS");
            return true;
        }

        snakeNode* current = head->getNext();
        while (current != nullptr) {
            if (head->getxBeg() == current->getxBeg() && head->getxEnd() == current->getxEnd() &&
                head->getyBeg() == current->getyBeg() && head->getyEnd() == current->getyEnd()) {
                serial_println("COLLIDE!!!");
                return true;
            }
            current = current->getNext();
        }

        return false;
    }

    void getAppleCoords() {
        xBeg0 = randRange(0, 120);
        xEnd0 = xBeg0 + 7;
        yBeg0 = randRange(0, 120);
        yEnd0 = yBeg0 + 7;
    }

    void printApple() {
        drawApple(apple->getxBeg(), apple->getxEnd(), apple->getyBeg(), apple->getyEnd());
    }
};



#endif





