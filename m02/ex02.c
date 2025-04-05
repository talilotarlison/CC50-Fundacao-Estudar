#include <stdio.h>

int main(void){
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
    float avg = ((float)(score1) + (float)(score2) + (float)(score3)) / (float)(3);
    printf("AVG: %.2f",avg);
}
