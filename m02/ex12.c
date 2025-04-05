#include <stdio.h>
#include <string.h>

int main(void){
    char words[2];
    char c[3] = "HI!";
    char d[3] = "BY!";
// como a string e uma array de caracter, temos que palavra e uma array de array
    words[0] = *c;
    words[1] = *d;

    // chame a funcao uma unica vez e nao tem necessidade de chamar mais pois o valor ja esta na variavel
    int n = strlen(words);
    int m = strlen(c);
    for(int i=0;i<n; i++){
        printf("%c\n", words[i]);     
     }
   
    
}
