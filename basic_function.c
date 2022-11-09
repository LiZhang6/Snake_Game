#include "basic_function.h"

int background[HEIGHT][WIDTH] = {0};
SH head;
SB body[HEIGHT * WIDTH];
enum Direction direction = 0;

// Initialize background
void Init_Background() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == 0 || i == HEIGHT - 1) {
        printf("-");
        background[i][j] = WALL;
      } else if (j == 0 || j == WIDTH - 1) {
        printf("|");
        background[i][j] = WALL;
      } else {
        printf(" ");
        background[i][j] = EMPTY;
      }
    }
    printf("\n");
  }
}

// Hide Cursor
void Hide_Cursor() {
  HANDLE console_handle;
  CONSOLE_CURSOR_INFO cursor_info;
  cursor_info.bVisible = FALSE;
  cursor_info.dwSize = sizeof(cursor_info);
  console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorInfo(console_handle, &cursor_info);
}

// Move Cursor
void Move_Cursor(int x, int y) {
  HANDLE console_handle;
  console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD pos = {x, y};
  SetConsoleCursorPosition(console_handle, pos);
}

// Initialize a food
void Init_Food() {
  int i = 0, j = 0;
  int rand_num = rand();
  do {
    i = rand_num % WIDTH;
    j = rand_num % HEIGHT;

  } while (background[j][i] != EMPTY);
  Move_Cursor(i, j);
  printf("#");
  background[j][i] = FOOD;
}
// Initialize a snake
void Init_Snake() {
  head.len = 2;
  head.x = WIDTH / 2;
  head.y = HEIGHT / 2;

  body[0].x = WIDTH / 2 + 1;
  body[0].y = HEIGHT / 2;
  body[1].x = WIDTH / 2 + 2;
  body[1].y = HEIGHT / 2;

  background[head.y][head.x] = HEAD;
  background[body[0].y][body[0].x] = BODY;
  background[body[1].y][body[1].x] = BODY;
}

// Draw a Snake
void Draw_Snake(int flag) {
  if (flag == 1) {
    Move_Cursor(head.x, head.y);
    printf("@");
    for (int i = 0; i < head.len; i++) {
      Move_Cursor(body[i].x, body[i].y);
      printf("0");
    }
  } else {
    Move_Cursor(body[head.len - 1].x, body[head.len - 1].y);
    printf(" ");
  }
}

// Move Snake
void Move_Snake(int x, int y) {
  Draw_Snake(0);  // Remove the tail of snake
  // mark the change part
  background[body[head.len - 1].y][body[head.len - 1].x] = EMPTY;

  // change the coordinate of body
  for (int i = head.len - 1; i >= 0; i--) {
    body[i].x = body[i - 1].x;
    body[i].y = body[i - 1].y;
  }

  // change the connection part between body and head
  body[0].x = head.x;
  body[0].y = head.y;

  // mark the change part
  background[body[0].y][body[0].x] = BODY;

  // change the coordinate of head
  head.x = head.x + x;
  head.y = head.y + y;

  // mark the change part
  background[head.y][head.x] = HEAD;

  Draw_Snake(1);
}

// control the snake
void Control_Snake() {
  switch (direction) {
    case UP:
      Move_Snake(0, -1);
      break;
    case DOWN:
      Move_Snake(0, 1);
      break;
    case LEFT:
      Move_Snake(-1, 0);
      break;
    case RIGHT:
      Move_Snake(1, 0);
      break;
    default:
      Move_Snake(1, 0);
      break;
  }
}

// Start Game
void Game() {
  direction = LEFT;  // define the default direction of snake: left
  int tmp = 0;       // use to record the moving direction of last time
  while(1){
     while (_kbhit()) {
    direction = getch();
    switch (direction) {
      case UP:
      Move_Snake(0, -1);
      break;
    case DOWN:
      Move_Snake(0, 1);
      break;
    case LEFT:
      Move_Snake(-1, 0);
      break;
    case RIGHT:
      Move_Snake(1, 0);
      break;
    }
  }
  }
 
}

// Show 2D Arry
void Show_2D_Arry(int *arry, int col, int row) {
  int i = 0, j = 0;
  for (i = 0; i < col; i++) {
    for (j = 0; j < row; j++) {
      printf("%d", arry[i * row + j]);
    }
    printf("\n");
  }
}