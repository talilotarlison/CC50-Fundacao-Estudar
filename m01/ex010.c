#include <stdio.h>

// funcoes declaradas abaixo da funcao mean precisa de declaracao de elevacao 
// codigo lido de baixo para cima

// prototype
void miau(void);

int main(void){

    for(int i = 0 ; i< 3;i++){
     miau();
    }
}

void miau(void){
printf("Miau!\n");
}