// Uma struct em C permite armazenar múltiplos tipos de dados relacionados em uma única unidade. Aqui, criamos uma struct pessoa que contém:
// Usando Ponteiros para struct
// Podemos usar ponteiros para acessar membros da struct com ->:

#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa pessoa1;
    struct Pessoa *ptr = &pessoa1;  // Criando um ponteiro para struct

    // Atribuindo valores usando o ponteiro
    strcpy(ptr->nome, "Ana");
    ptr->idade = 35;

    // Acessando os valores usando o ponteiro
    printf("Nome: %s\n", ptr->nome);
    printf("Idade: %d\n", ptr->idade);

    return 0;
}
