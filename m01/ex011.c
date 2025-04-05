#include <stdio.h>

void falarMiau(int quantidadeVezes);

int main(void)
{
    falarMiau(4);
  
}

void falarMiau(int quantidadeVezes){
    // funcao tem efeito coletareal pois nao retorna nada apenas imprime na tela
    for(int i = 0 ; i< quantidadeVezes;i++){
      printf("Miau!\n");
    }
}
