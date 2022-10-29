#include <stdio.h>
#include "basic_function.h"
//create background 
void SetBackground(){
    int background[HEIGHT][WIDTH] = {0} ; 
    for (int i =0; i<HEIGHT; i++){
        if(i == 0 || i == HEIGHT) printf("-");
        for(int j =0; j<WIDTH; j++) {
            if(j==0||j==WIDTH) printf("|");
        }
        printf("\n");       
    }
}