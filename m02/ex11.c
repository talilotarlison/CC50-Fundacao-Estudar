#include <stdio.h>
#include <string.h>

int main(void){
    char c[3] = "HI!";
    // chame a funcao uma unica vez e nao tem necessidade de chamar mais pois o valor ja esta na variavel
    int n = strlen(c);
    for(int i=0;i<n; i++)
    printf("%c\n", c[i]);
}
