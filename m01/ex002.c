#include <stdio.h>

int main (){
    // tipos int tem 32 bytes
	int x,y,z;

	printf("x: ");
	scanf("%d", &x);

    printf("y: ");
	scanf("%d", &y);

    z = x+y;

	printf("Soma %d\n",z);

	return (0);
}