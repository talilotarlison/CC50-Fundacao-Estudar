    #include<stdio.h>
    #include <stdbool.h>

    // https://www.w3schools.com/c/c_booleans.php
    // https://stackoverflow.com/questions/6118846/which-header-file-do-you-include-to-use-bool-type-in-c
    // https://www.guj.com.br/t/funcao-booleana-em-c/328251/11
    // https://www.bosontreinamentos.com.br/programacao-em-linguagem-c/passando-arrays-para-funcoes-em-c/

    int buscavalor(int arr[],int tamanhoArr, int busca){
         bool encontrado = false;
        for (int i = 0; i < tamanhoArr; i++) {  
            if(arr[i] == busca){
               printf("Valor encontrado no arr[%d] = %d\n",i, arr[i]);
               encontrado = true; 
            }  
        }

        if(encontrado){
            printf("Valor encontrado no Array"); 
        }else{
             printf("Valor nao encontrado no Array"); 
        }
          
           return 0;
    }

    int main(void)
    {
      int notas[4] = {7, 9.5, 1,3};

        printf("Exibindo os Valores do Vetor Original: \n\n");
        for (int k = 0; k < 4; k++) {
            printf("notas[%d] = %d\n",k, notas[k]);
        }

      int aux;
       // ordenacao de valores com c
      // declarando e inicializando o vetor notas
        for (int i = 0; i < 3; i++) {
                for (int j = i + 1; j < 4; j++) {
                if(notas[i]>notas[j]){
                    aux = notas[i];
                    notas[i] = notas[j];
                    notas[j] = aux;
                }
          }
        }

        printf("Exibindo os Valores do Vetor Ordenado: \n\n");
        for (int k = 0; k < 4; k++) {
            printf("notas[%d] = %d\n",k, notas[k]);
        }

      buscavalor(notas,4,3);
      return 0;
    }