
#include <stdio.h>

int main(void)
{
	float x,y;

	printf("x: ");
	scanf("%f", &x);

    printf("y: ");
	scanf("%f", &y);
    //Com %.50f , podemos especificar o número de casas decimais exibidas.
    // overflow “vazamento” de inteiro
    printf("%.50f\n", x / y;); 
}