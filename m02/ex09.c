#include <stdio.h>
// fim da string e identificado pelo \0 
// sempre aumeta um byte na string por causa do \0
int main(void){
    char c[3] = "HI!";
    for(int i=0;c[i]!='\0'; i++)
    printf("%c\n", c[i]);
}
