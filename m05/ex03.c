#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do nó
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

// Função para criar um novo nó
node *create_node(int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    new_node->number = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Função para inserir um novo valor na árvore
node *insert(node *tree, int value)
{
    if (tree == NULL)
    {
        return create_node(value);
    }

    if (value < tree->number)
    {
        tree->left = insert(tree->left, value);
    }
    else if (value > tree->number)
    {
        tree->right = insert(tree->right, value);
    }

    return tree;
}

// Função para pesquisar um número na árvore
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else
    {
        return true; // Encontramos o número
    }
}

// Função para liberar a memória da árvore
void free_tree(node *tree)
{
    if (tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

// Função principal para testar a árvore binária
int main()
{
    node *root = NULL;

    // Inserindo valores na árvore
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // Testando a busca
    int target = 7;
    if (search(root, target))
    {
        printf("Número %d encontrado na árvore.\n", target);
    }
    else
    {
        printf("Número %d não encontrado na árvore.\n", target);
    }

    // Liberando a memória
    free_tree(root);

    return 0;
}

// Com uma árvore de pesquisa binária, incorremos no custo de ainda mais memória, já que cada nó agora precisa de espaço para um valor e dois ponteiros. A inserção de um novo valor levaria tempo O (log n ), uma vez que precisamos encontrar os nós entre os quais ele deve ficar.