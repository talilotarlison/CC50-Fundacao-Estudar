#include <stdio.h>

// https://homepages.dcc.ufmg.br/~rodolfo/aedsi-2-10/printf_scanf/printfscanf.html
// https://www.onlinegdb.com/online_c_compiler

int main(void)
{   
    char nome[50];

    printf("Qual seu nome?\n");
    scanf("%s", nome);
    printf("Bem vindo, %s!\n", nome);
}