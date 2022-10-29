#include <stdio.h>

#include "basic_function.h"

int main() {
  Hide_Cursor();
  Init_Background();
  Move_Cursor(WIDTH/2,HEIGHT/2);
  printf("#");
  
  getchar();
  return 0;
}