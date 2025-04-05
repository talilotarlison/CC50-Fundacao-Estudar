#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0;
    int cont = 0;
    int endpop = 0;
    int startpop = 0;
    do
    {
        printf("Indique a População Inicial:\n ");
        scanf("%d", &startpop);
        if(startpop < 9)
        {
            printf("[AVISO!]\n O número precisa ser maior do que 9, digite novamente.\n ");
        }

    }
    while(startpop < 9);

    do
    {
        printf("Digite agora a população desejada/final:\n");
        scanf("%d", &endpop);
        if(endpop <= startpop)
        {
            printf("[AVISO!]\n O número precisa ser maior do que o Inicial, digite novamente\n ");
        }
    }
    while(endpop <= startpop);

    while(endpop > startpop)
    {
          n = startpop + (startpop/3) - (startpop/4);
          cont++;
          startpop = n;
    }

     printf("Anos: %i\n", cont);

     return 0;
}