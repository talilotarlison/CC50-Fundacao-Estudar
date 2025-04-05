#include <stdio.h>
#include <string.h>

int main(void){
    char c[3] = "HI!";
    // não e uma boa pratica chamar a funcao no for pois sempre ela vai ser chamada
    // se o array tem muitos numeros aumenta o tempo de execulção do codigo
    for(int i=0;i<strlen(c); i++)
    printf("%c\n", c[i]);
}
