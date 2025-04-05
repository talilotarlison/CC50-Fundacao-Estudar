#include <stdio.h>

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
    while (n < 1 || n > 8);


//Pense que você esta escrevendo uma linha em um caderno, você começa a escrever da esquerda para direita

    for (int i = 0; i < n; i++)

    {
        for (int h = n - 1 ; h > i ; h--)         //Primeiro já defino a escada da primeira pirâmide, tiro 1 de cima pra baixo até fique igual ao valor de i
        {
            printf(" ");
        }
        for (int a = 0; a < i; a++)             //Após adicionar os espaços da "escada" adiciono os # nas linhas, sendo que cada pulo de linha será adiciona mais um #
        {
            printf("#");
        }

        printf("#  ");                                 //Como nossa linha começa a contar somente na segunda, coloquei para imprimir um hash em cada linha, sendo assim, aproveitei e coloquei espaço entre uma pirâmide e outra

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("#\n");                                  //Adiciona um # no final e pula linha
    }
}