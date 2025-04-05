
#include<stdio.h>

int main(void)
{
    //obter um numero inteiro positivo do usuario
    int n;
    do
    {
      //Solicitar altura do usuario
    printf("Tamanho de 1 a 8: ");
	scanf("%i", &n);

    }
    //condição para loop
    while(n<1 || n >= 9);
    //Criação da pirâmide
    for(int i = 0; i < n ; i++)
    {
      for(int j = 7; j > i; j--)
      {
        printf(" ");
      }
      for(int h = -1; h < i; h++)
      {
        printf("#");
      }
      //condição para espaços em branco
      printf("  ");
      //Criação da pirâmide
      for(int c = -1; c < i; c++)
      {
        printf("#");
      }
printf("\n");

    }
    printf("\n");
}