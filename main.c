#include <basic_function.h>
int main() {
  srand((unsigned)time(NULL));  // create random seed
  Hide_Cursor();
  Init_Background();
  Init_Snake();
  Draw_Snake(1);
  Init_Food();
  Game();

  // Show_2D_Arry(background,HEIGHT,WIDTH);
 
  getchar();
  return 0;
}