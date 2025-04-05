#include <stdio.h>

int main()
{   // representação de strings em C
    char nome_cliente[30] = "Fulano";
 
    char nome_cliente1[30] = {'F','u','l','a','n','o','1'};
    //Para armazenar “Fulano”, são necessários 6 caracteres + 1 para o finalizador \0.

    char nome_cliente2[] = "Fulano2";
    
    printf("%s", nome_cliente);
     printf("%s", nome_cliente1);
      printf("%s", nome_cliente2);

    return 0;
}