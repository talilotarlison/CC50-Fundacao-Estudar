// Outro exemplo de estrutura de dados abstrata é um dicionário , onde podemos mapear chaves para valores, como palavras para suas definições. Podemos implementar um com uma tabela hash ou um array, levando em consideração a relação entre tempo e espaço.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Tamanho da tabela hash

// Estrutura para um nó na lista encadeada (colisão)
typedef struct Node {
    char key[50];  // Chave (ex: nome)
    int value;     // Valor (ex: idade)
    struct Node* next;
} Node;

// Estrutura para a tabela hash
typedef struct {
    Node* buckets[TABLE_SIZE];  // Array de ponteiros para listas encadeadas
} HashTable;

// Função de hash (simples: soma dos caracteres da chave % tamanho da tabela)
unsigned int hash(char* key) {
    unsigned int hash_value = 0;
    while (*key) {
        hash_value += *key++;
    }
    return hash_value % TABLE_SIZE;
}

// Criar uma tabela hash vazia
HashTable* create_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Inserir um par chave-valor na tabela
void insert(HashTable* table, char* key, int value) {
    unsigned int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = table->buckets[index];  // Inserir no início da lista (encadeamento separado)
    table->buckets[index] = newNode;

    printf("Inserido: [%s -> %d] na posição %d\n", key, value, index);
}

// Buscar um valor pela chave
int search(HashTable* table, char* key) {
    unsigned int index = hash(key);
    Node* temp = table->buckets[index];

    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;  // Chave encontrada
        }
        temp = temp->next;
    }
    return -1;  // Chave não encontrada
}

// Remover uma chave da tabela
void delete(HashTable* table, char* key) {
    unsigned int index = hash(key);
    Node* temp = table->buckets[index];
    Node* prev = NULL;

    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Chave '%s' removida.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Chave '%s' não encontrada.\n", key);
}

// Exibir todos os elementos da tabela hash
void display(HashTable* table) {
    printf("\nTABELA HASH:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> ", i);
        Node* temp = table->buckets[i];
        while (temp) {
            printf("[%s: %d] -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Liberar memória da tabela hash
void free_table(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table->buckets[i];
        while (temp) {
            Node* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(table);
}

// Função principal para testar o dicionário
int main() {
    HashTable* table = create_table();

    // Inserindo valores
    insert(table, "João", 25);
    insert(table, "Maria", 30);
    insert(table, "Ana", 28);
    insert(table, "Carlos", 35);
    insert(table, "Pedro", 22);
    
    display(table);

    // Buscando valores
    char key_to_search[] = "Maria";
    int age = search(table, key_to_search);
    if (age != -1) {
        printf("\nIdade de %s: %d\n", key_to_search, age);
    } else {
        printf("\n%s não encontrado.\n", key_to_search);
    }

    // Removendo um valor
    delete(table, "Carlos");
    display(table);

    // Liberando memória
    free_table(table);

    return 0;
}
