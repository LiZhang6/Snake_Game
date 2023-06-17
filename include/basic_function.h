#ifndef INCLUDE_BASIC_FUNCTION
#define INCLUDE_BASIC_FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 60   // determine the width of the screen
#define HEIGHT 25  // determine the height of the screen
#define EMPTY 0
#define WALL 1
#define FOOD 2
#define HEAD 3
#define BODY 4

enum Direction { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };

extern int background[HEIGHT][WIDTH];

// define head of snake
typedef struct Snake_Head {
  int len;  // The length of the snake
  int x;    // coordinate of head in x
  int y;    // coordinate of head in y
} SH;

// define body of snake
typedef struct Snake_Body {
  int x;  // coordinate of body in x
  int y;  // coordinate of body in y
} SB;

extern void Init_Background();  // initiate background and screen
extern void Init_Food();        // initiate the food: create the random food
extern void
Init_Snake();  // initiate snake and place the snake in the middle of screen
extern void Hide_Cursor();              // hide the cursor
extern void Move_Cursor(int x, int y);  // move the cursor


extern void Draw_Snake(int flag);  // prameter = 1 : draw a snake   prameter != 0 : move cursor
extern void Move_Snake(int x, int y);
extern void Control_Snake(int direction);
extern void Read_KeyBoard();
extern void Game();
extern void Judgement(int x, int y);

// debug
extern void Show_2D_Arry(int *arry, int col, int row);

#endif /* INCLUDE_BASIC_FUNCTION */
