#include <stdio.h>
// tipycode
int get_negative_int(void);

int main(void){
    int i = get_negative_int();
    printf("%i",i);
}

int get_negative_int(void){
    int n;
    do{
        printf("Entre com numero Negativo: ");
        scanf("%i",&n);
    }while(n>0);
    return n;
 }
 