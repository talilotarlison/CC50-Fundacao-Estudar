// Implementar o desenho da pirâmide de Mario, chamando uma função:

#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
     int height = get_int("Altura: ");
     draw(height);
}

void draw(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
             printf("#");
        }
        printf("\n");
     }
}

// Podemos alterar draw para ser recursiva:

void draw(int h)
{
    draw(h - 1);
    for (int i = 0; i < h; i++)
    {
         printf("#");
    }
    printf("\n");
}

// Ao adicionar um base case (“caso base”), a função draw irá parar de chamar a si mesma em algum ponto:

void draw(int h)
{
    if (h == 0)
    {
         return;
    }
    draw(h - 1);
    for (int i = 0; i < h; i++)
    {
         printf("#");
    }
    printf("\n");
}