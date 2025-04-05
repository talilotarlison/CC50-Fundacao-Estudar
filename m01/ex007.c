#include <stdio.h>

int main (){
    // tipos char um caracter
    char c;

	printf("Voce aceita os termos? ");
	scanf("%c", &c);
    // para representar um caracter em c usar aspa simples
    // operadores logicos
    if(c == 'y' || c == 'Y'  ){
       printf("Aceito!!\n");
    }else if(c == 'n' || c == 'N' ){
        printf("Nao aceito!");
    }else{
        printf("Entrada invalida!");
    }
	return (0);
}