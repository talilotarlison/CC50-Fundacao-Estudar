#include <stdio.h>

int main (){
    // tipos int tem 32 bytes
	float x,y;

	printf("x: ");
	scanf("%f", &x);

    printf("y: ");
	scanf("%f", &y);

    float z = x/y;
    // divisao de decimais vai retornar decimais
	printf("Divisao %.2f\n",z);

	return (0);
}