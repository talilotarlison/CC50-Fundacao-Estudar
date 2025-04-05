    #include<stdio.h>
    #include <stdbool.h>

    int main(void)
    {
      int notas[4] = {7, 9.5, 1,3};
      int tamanhoArr = 4;
      bool encontrado = false;
      int busca = 10;

        printf("Exibindo os Valores do Vetor Original: \n\n");
        for (int k = 0; k < 4; k++) {
            printf("notas[%d] = %d\n",k, notas[k]);
        }
        

        printf("Busca Linear no Array: \n\n");
        for (int i = 0; i < tamanhoArr; i++) {  
            if(notas[i] == busca){
               printf("Valor encontrado no arr[%d] = %d\n",i, notas[i]);
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