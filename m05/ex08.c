#include <stdio.h>
#include <string.h>

// Uma struct em C permite armazenar múltiplos tipos de dados relacionados em uma única unidade. Aqui, criamos uma struct pessoa que contém:
// Definição da struct
struct Pessoa {
    char nome[50];  // Nome da pessoa
    int idade;      // Idade da pessoa
};

int main() {
    // Criando uma variável do tipo struct Pessoa
    struct Pessoa pessoa1;

    // Atribuindo valores
    strcpy(pessoa1.nome, "Carlos");
    pessoa1.idade = 28;

    // Acessando e imprimindo os dados
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);

    return 0;
}
