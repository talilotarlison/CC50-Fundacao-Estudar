#include <stdio.h>
//manual.cc50.io
#include <string.h>

int main(void){
    char words[2];
    char c[3] = "HI!";
    char d[3] = "BY!";
    // como a string e uma array de caracter, temos que palavra e uma array de array
    words[0] = *c;
    words[1] = *d;

    // chame a funcao uma unica vez e nao tem necessidade de chamar mais pois o valor ja esta na variavel

    printf("%s\n", words);
   
}

