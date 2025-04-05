#include <stdio.h>

float average(int length, int scores[]);

const int TOTAL = 3 ;

int main(void){
    int scores[TOTAL];
        float score;
      for(int i = 0 ; i < TOTAL;i++){
        printf("Score %i: ", i);
        scanf("%f",&score);
        scores[i] = score;
      }

    float avg = average(TOTAL,scores);
    printf("AVG: %.2f",avg);
}

float average(int length, int scores[]){
    int sum = 0;
     for(int i = 0 ; i <length;i++){
       sum += scores[i];
    }
    return sum / (float)length;
}