#include <stdio.h>

int main(void){

// for do numero escolhido
    int contro=1;
    for(int i = 0 ; i< 5 ;i++){
        for(int j = 5 ; j > contro;j--){
            printf("[-]");
        }
        contro++;
         printf("\n");
    } 
}
