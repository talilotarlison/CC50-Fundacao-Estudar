#include <stdio.h>

int pegarNumNegativo(void);

int main (){
    // tipos int tem 32 bytes

    int resultado = pegarNumNegativo();
	printf("Numero: %d\n",resultado);

	return (0);
}

int pegarNumNegativo(void){
    int n;
    do{

	printf("n: ");
	scanf("%d", &n);

    }while(n>0);
    return n;
}
