// Uma estrutura de dados “oposta” seria um stack (ou pilha), onde os itens adicionados mais recentemente são removidos primeiro: último a entrar , primeiro a sair (UEPS). Em uma loja de roupas, podemos pegar, ou abrir , o suéter de cima de uma pilha, e novos suéteres são adicionados, ou empurrados, para cima também.
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da pilha
typedef struct {
    Node* top;
} Stack;

// Criar uma pilha vazia
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Inserir elemento na pilha (push)
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Elemento %d inserido na pilha.\n", value);
}

// Remover elemento da pilha (pop)
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Ver o topo da pilha (peek)
int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return s->top->data;
}

// Mostrar os elementos da pilha
void display(Stack* s) {
    if (s->top == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Node* temp = s->top;
    printf("Pilha (Topo -> Base): ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Liberar memória da pilha
void freeStack(Stack* s) {
    while (s->top != NULL) {
        pop(s);
    }
    free(s);
}

// Função principal
int main() {
    Stack* s = createStack();

    push(s, 10);
    push(s, 20);
    push(s, 30);

    display(s);

    printf("Topo da pilha: %d\n", peek(s));

    printf("Removido: %d\n", pop(s));
    display(s);

    freeStack(s);
    return 0;
}

