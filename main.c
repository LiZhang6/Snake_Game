#include "basic_function.h"

int main() {
  srand((unsigned)time(NULL));  // create random seed 
  Hide_Cursor();
  Init_Background();
  Init_Food();
  Init_Snake();
  Draw_Snake(1);
  // Move_Snake(-1,0);
  // Move_Snake(0,-1);
  // Move_Snake(1,0);
  // Move_Snake(1,0);
  Game();
  // printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  // Show_2D_Arry(background,HEIGHT,WIDTH);
  getchar();
  return 0;
}