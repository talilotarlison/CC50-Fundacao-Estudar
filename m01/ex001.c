#include <stdio.h>

int main(void)
{   char name[50];
    printf("Qual seu nome: ");
    scanf("%s", name);    
    printf("hello, %s!\n", name);
}