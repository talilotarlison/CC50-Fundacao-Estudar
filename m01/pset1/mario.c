#include <stdio.h>

int main(void){
	float y;

    do{
    printf("Tamanho: ");
	scanf("%f", &y);
    }while(y<=0 || y > 8);

// for do numero escolhido
    int control = 1;
    for(int i = 0 ; i< y ;i++){
        for(int j = 0 ; j < control;j++){
            printf("[-]");
        }
        control++;
         printf("\n");
    } 
}