# Snake-Game
In the snake game, there will be dots that the snake collects by eating them, in which it increases size for each dot it eats. The player’s score will increase for each dot it eats. If the snake runs into itself or into the edge of the screen, the player loses and the game ends. The goal of the game is to attempt to get the highest score possible.

Computing:
* Atmega 328p microcontroller

Input:
* Arduino joystick (Analog pins A0-A3)

Output:
* HiLetgo ST7735 
* 8-bit shift registers (Digital pin 15)
* 4 digit 7 segment display (Digital pins 2-13) 
* Passive Buzzer (Digital pin 14) pin 8

Functionality:
When the game is turned on, the player will be greeted by a main menu in which the music for the game will be playing. The player will be able to access an option (pressing the joystick) to see high scores and the player’s names who achieved these scores. There will also be a settings option to make the screen brighter or dimmer and to increase or decrease the sound. When the player selects the play option, the player will be able to control a snake using the arduino joystick. Each time the player eats a dot, the passive buzzer will play a custom sound. The 4D7S will display the current score of the player. When the player loses by running into itself or into the edge of the display, a death sound will play and the game over screen will be displayed. If the player reaches a high score in the end (top 3 places), the 4D7S will flash “WIN” and the passive buzzer will play unique music. The player will then be able to type their name to show up on the leaderboard (up to 4 characters) and their score will be placed next to their name. Otherwise, the 4D7S will display “LOSE” and will not flash. 

Build Upons:
* HiLetgo ST7735 LCD display
* 8-bit shift registers for data storage
* Passive buzzer to play unique music/sounds for the menu, starting game, each time score increases, and death sound

Wiring Diagram with full build:
![snake0](https://github.com/user-attachments/assets/59c6652e-2491-486b-99fe-c0e518fb34b4)

Task Diagram:
![task diagram](https://github.com/user-attachments/assets/ea73c488-597a-460a-9ce8-d6e9b802a00d)

Joystick State Machine:
![joysticksm](https://github.com/user-attachments/assets/c564a5df-5ce8-4fb9-9f71-13db5039d124)

Menu State Machine:
![menusm](https://github.com/user-attachments/assets/42dd5e7d-eee0-42be-9643-3732f813e3dd)

Move Snake State Machine:
![movesnakesm](https://github.com/user-attachments/assets/e5be12bf-1ea1-454a-beb8-7f97e7f92894)

Four Digit Seven Segment State Machine:
![4d7ssm](https://github.com/user-attachments/assets/21f95575-37ef-46b1-a1cc-77f518d3f0b6)
