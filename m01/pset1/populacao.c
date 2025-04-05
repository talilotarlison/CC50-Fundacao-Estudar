#include <stdio.h>
// Digamos que temos uma população de n lhamas. A cada ano, nascem n/3 novas lhamas e n/4 morrem.

// Por exemplo, se começarmos com n = 1.200 lhamas, no primeiro ano, 1.200 / 3 = 400 novas lhamas nascerão e 
// 1.200 / 4 = 300 lhamas morrerão. No final daquele ano, teríamos 1.200 + 400 - 300 = 1.300 lhamas.

// Para tentar outro exemplo, se começarmos com n = 1000 lhamas, no final do ano teremos 1000/3 = 333,33 novas lhamas. 
// Não podemos ter uma parte decimal de uma lhama, entretanto, vamos truncar o decimal para que 333 novas lhamas nasçam. 
// 1000/4 = 250 lhamas passarão, então terminaremos com um total de 1000 + 333 - 250 = 1083 lhamas no final do ano.

int main(void)
{
// variaveis 
    int populacaoInicial;
    int populacaoFinal;
    int n,numeroDeAnos=0;

// TODO: Solicite o valor inicial ao usuário
    do{
        printf("Indique a População Inicial:\n ");
        scanf("%d", &populacaoInicial);

    }while(populacaoInicial< 9);

// TODO: Solicite o valor final ao usuário
    do{
        printf("Digite agora a população desejada/final:\n");
        scanf("%d", &populacaoFinal);
    }while(populacaoFinal<=populacaoInicial); 
// TODO: Calcule o número de anos até o limite
    while (populacaoFinal > populacaoInicial){
        n = populacaoInicial + (populacaoInicial/3) - (populacaoInicial /4);
        numeroDeAnos++;
        populacaoInicial = n;
    }

// TODO: Imprima o número de anos
    printf("Anos: %i\n", numeroDeAnos);

     return 0;
}