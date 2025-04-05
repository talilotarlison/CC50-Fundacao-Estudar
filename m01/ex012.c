#include <stdio.h>

int pegarNumPositivo(void);

int main (){
    // tipos int tem 32 bytes

    int resultado = pegarNumPositivo();
	printf("Numero: %d\n",resultado);

	return (0);
}

int pegarNumPositivo(void){
    int n;
    do{

	printf("n: ");
	scanf("%d", &n);

    }while(n<1);
    return n;
}
