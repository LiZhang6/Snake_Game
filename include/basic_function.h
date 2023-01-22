#ifndef BASIC_FUNCTION
#define BASIC_FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH 60
#define HEIGHT 25
#define EMPTY 0
#define WALL 1
#define FOOD 2
#define HEAD 3
#define BODY 4

enum Direction {
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77
};

extern int background[HEIGHT][WIDTH];

// define head of snake
typedef struct Snake_Head{
    int len; // The length of the snake
    int x;  // coordinate of head in x
    int y; // coordinate of head in y
}SH;

// define body of snake 
typedef struct Snake_Body{
    int x; // coordinate of body in x
    int y; // coordinate of body in y
}SB;

extern void Init_Background();
extern void Init_Food();
extern void Init_Snake();
extern void Hide_Cursor();
extern void Move_Cursor(int x, int y);
extern int Get_Rand();

extern void Draw_Snake();
extern void Move_Snake(int x, int y);
extern void Control_Snake();
extern void Read_KeyBoard();
extern void Game();

//debug
extern void Show_2D_Arry(int *arry,int col, int row);

#endif /* BASIC_FUNCTION */
