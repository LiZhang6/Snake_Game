#include "basic_function.h"

int main() {
  srand((unsigned)time(NULL));  // create random seed 
  Hide_Cursor();
  Init_Background();
  Init_Food();
  Init_Snake();
  Draw_Snake(1);
  // printf("%d %d",background[1][59],background[24][2]);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  Show_2D_Arry(background,HEIGHT,WIDTH);
 
  
 
  // printf("\n\n\n\n\n\n\n\n\n");
  // Show_2D_Arry(background,HEIGHT,WIDTH);
  // Move_Snake(0,-1);
  // Show_2D_Arry(background,HEIGHT,WIDTH);
  getchar();
  return 0;
}