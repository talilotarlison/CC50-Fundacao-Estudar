#include <stdio.h>

int main (){
    // tipos int tem 32 bytes
	int x,y;

	printf("x: ");
	scanf("%i", &x);

    printf("y: ");
	scanf("%i", &y);

    if(x > y){
       printf("x %i e maior que y %i\n",x,y); 
    }else if(x<y){
        printf("x %i e menor que y %i\n",x,y); 
    }else{
        printf("x %i e y %i sao iguais.\n",x,y); 
    }
	return (0);
}