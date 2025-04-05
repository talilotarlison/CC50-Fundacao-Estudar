
// Por exemplo, uma estrutura de dados abstrata é uma queue (ou fila), como uma fila de pessoas esperando, onde o primeiro valor que colocamos são os primeiros valores que são removidos, ou first-in-first-out (FIFO). Para adicionar um valor que enfileira-lo, e para remover um valor que desenfileira-lo. Essa estrutura de dados é abstrata porque é uma ideia que podemos implementar de diferentes maneiras: com um array que redimensionamos à medida que adicionamos e removemos itens, ou com uma lista vinculada onde acrescentamos valores ao final.
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estrutura da fila
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Função para criar uma fila vazia
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Inserir elemento na fila (enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Elemento %d inserido na fila.\n", value);
}

// Remover elemento da fila (dequeue)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Mostrar elementos da fila
void display(Queue* q) {
    if (q->front == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    
    Node* temp = q->front;
    printf("Fila: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Liberar memória da fila
void freeQueue(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
}

// Função principal
int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Removido: %d\n", dequeue(q));
    display(q);

    freeQueue(q);
    return 0;
}

