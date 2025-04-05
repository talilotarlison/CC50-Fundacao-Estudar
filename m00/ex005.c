#include <stdio.h>
// Como o código funciona:
// 1. Divisão: A função mergeSort divide o array em duas metades.
// 2. Conquista: Chama a si mesma recursivamente para ordenar as duas metades.
// 3. Combinação: A função merge combina as duas metades já ordenadas em um único array ordenado.

// Para compilar e executar o código, você pode usar um compilador C, como gcc:

// gcc -o mergesort_example mergesort_example.c

// Função para mesclar duas partes do array
void merge(int arr[], int left, int right, int mid) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criando arrays temporários
    int L[n1], R[n2];

    // Copiando dados para os arrays temporários
    for (i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    // Mesclando os arrays temporários
    i = 0; // Índice do primeiro sub-array
    j = 0; // Índice do segundo sub-array
    k = left; // Índice do array mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontrando o ponto médio
        int mid = left + (right - left) / 2;

        // Ordenando a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mesclando as duas metades ordenadas
        merge(arr, left, right, mid);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
        printf("\n");
    }

}

// Função principal
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("Array ordenado: \n");
    printArray(arr, arrSize);
    return 0;
}
