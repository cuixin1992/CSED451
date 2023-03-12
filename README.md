# Jump Rectangle - 2D Game Development ![image](https://user-images.githubusercontent.com/55921538/224548489-5a469c52-a3aa-40f3-b79b-24eccdd3ffd8.png)

This 2D jump rectangle game is developed by 우아밑 for CSED451-01 Computer Graphics (Spring 2023) Assignment #1. 



## Introduction
This is a simple 2D game developed in C++ using OpenGL drawing libraries. The objective of the game is to collect as many stars as possible to gain scores. In the game, a character, represented by a rectangle, who can only move horizontally and jump to collect stars while avoiding obstacles like fireballs and holes, is controlled. 

## User Interface 
The game features a user-friendly graphic user interface (GUI) that displays all the game elements, including the character, terrain, hole, fireball, star, and score.

![image](https://user-images.githubusercontent.com/55921538/224548548-ba346264-87a8-4844-aab4-936394186373.png)

## How to Play

1. Start the game.
2. Press the spacebar to make the character jump. Note that the character can only jump once during a jump.
3. Collect stars by jumping up and touching them as they move across the screen from right to left. Each star collected will increase your score (5 scores for each star).
4. Avoid fireballs and holes that move quickly across the screen from right to left. If you touch a fireball or fall into a hole in the terrain, the game is over.
5. You can end the game by pressing the “q”, “Q”, or “esc” buttons on your keyboard. 
6. Your final score will be displayed on the screen. 
7. Have fun playing the jumping rectangle game. 

![image](https://user-images.githubusercontent.com/55921538/224548641-2b6349ac-53c3-4771-b2b7-163500ebcb81.png)

## Command Keys

| Keyboard | Description      
| :-------- | :------- |  
| `spacebar` | Charater jump |  
| `esc, Q, q,` | Quit game |  

## Environment
C++,
OpenGL 4.6,
Visual Studio 2019

## Directory layout 
    .
    ├── Debug                 
    ├── bin                   
    ├── include                    
    ├── lib      
    ├── Source.cpp 
    └── README.md

