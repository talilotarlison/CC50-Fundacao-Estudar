#include <stdio.h>

int main(void){
    int n;
    do{

	printf("Comprimento: ");
	scanf("%d", &n);

    }while(n< 1);

// for do numero escolhido
    for(int i = 0 ; i< n;i++){
     printf("[?]");
    }
     printf("\n");
}
