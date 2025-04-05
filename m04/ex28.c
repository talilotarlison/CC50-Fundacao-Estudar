// Manipular Arquivos

// Com a capacidade de usar ponteiros, também podemos abrir arquivos, como uma lista telefônica digital:
// fopen é uma nova função que podemos usar para abrir um arquivo. Ele retornará um ponteiro para um novo tipo, FILE , de onde podemos ler e escrever. O primeiro argumento é o nome do arquivo, e o segundo argumento é o modo em que queremos abrir o arquivo (r para ler, w para escrever e a para acrescentar ou adicionar).

// Adicionaremos um “checkpoint” para sair, caso não possamos abrir o arquivo por algum motivo.

// Depois de obter algumas strings, podemos usar fprintf para imprimir em um arquivo.

// Finalmente, fechamos o arquivo com fclose.
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char *nome = get_string("Nome: ");
    char *numero = get_string("Número: ");
    fprintf(file, "%s,%s\n", nome, numero);
    fclose(file);
}