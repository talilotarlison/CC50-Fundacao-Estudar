#include <stdio.h>
// fim da string e identificado pelo \0 
// sempre aumeta um byte na string por causa do \0

int main(void){
    char c[3] = "HI!";
    // fim da string retorna 0 , se continuar com numeros maiores acessa outros locais da memoria do computador
    printf("%c\n", c[4]);
}

  