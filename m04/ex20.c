// Valgrind

// valgrind é uma ferramenta de linha de comando que podemos usar para executar nosso programa e ver se há algum memory leak (“vazamento de memória”) ou memória que alocamos sem liberar, o que pode eventualmente fazer com que o computador fique sem memória.

// Vamos construir uma string, mas alocar menos do que precisamos na memória.c :

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(3);
    s[0] = 'H';
    s[1] = 'I';
    s[2] = '!';
    s[3] = '\0';
    printf("%s\n", s);
}