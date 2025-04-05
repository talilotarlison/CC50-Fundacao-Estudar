#include <stdio.h>

void falarMiau(int quantidadeVezes){

    for(int i = 0 ; i< quantidadeVezes;i++){
      printf("Miau!\n");
    }
}

int main(void)
{
    falarMiau(4);
  
}