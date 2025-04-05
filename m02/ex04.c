#include <stdio.h>

int get_int(char msg[]);
float average(int length, int scores[]);

const int TOTAL = 3 ;

int main(void){
    int scores[TOTAL];
      for(int i = 0 ; i < TOTAL;i++){
        int score = get_int("Score: ");
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

int get_int(char msg[]){
    float score;
    printf("%s: ", msg);
    scanf("%f",&score);
    return score;
}