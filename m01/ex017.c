#include <stdio.h>

int main(void){
    int a,l;
    do{
	printf("Altura: ");
	scanf("%d", &a);
	printf("Largura: ");
	scanf("%d", &l);

    }while(a< 1 && l< 1);

// for do numero escolhido

    for(int i = 0 ; i< a ;i++){
        for(int j = 0 ; j < l;j++){
            printf("[-]");
        }
         printf("\n");
    } 
}

   