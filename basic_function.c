#include "basic_function.h"

#include <stdio.h>
#include <windows.h>
// Initialize background
void Init_Background() {
  int background[HEIGHT][WIDTH] = {0};
  for (int i = 0; i < HEIGHT + 1; i++) {
    for (int j = 0; j < WIDTH + 1; j++) {
      if (i == 0 || i == HEIGHT) {
        printf("-");
      } else if (j == 0 || j == WIDTH) {
        printf("|");
      } else {
        printf(" ");
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
  COORD pos={x, y};
  SetConsoleCursorPosition(console_handle, pos);
}

// Initialize a food
void Init_Food() {}