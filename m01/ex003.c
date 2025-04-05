#include <stdio.h>

int main (){
    // tipos int tem 32 bytes
	int x,y;

	printf("x: ");
	scanf("%d", &x);

    printf("y: ");
	scanf("%d", &y);
    // conversao de tipo ou typecast
    // Para corrigir isso, vamos fazer o casting, ou seja, converter nossos números inteiros para float antes de dividi-los
    float z = (float)x/(float)y;
    // divisao vai retorna apenas inteiros, o decimal e truncado para um inteiro pois as varias e int
	printf("Divisao %.2f\n",z);

	return (0);
}