#include <stdio.h>

int main (){
    // tipos char um caracter
    char c;

	printf("Voce aceita os termos? ");
	scanf("%c", &c);
    // para representar um caracter em c usar aspa simples
    if(c == 'y'){
       printf("Aceito!!\n");
    }else if(c == 'n'){
        printf("Nao aceito!");
    }else{
        printf("Entrada invalida!");
    }
	return (0);
}