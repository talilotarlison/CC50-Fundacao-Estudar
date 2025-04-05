
#include <stdio.h>
#include <cs50.h>

int main()
{
// valor das moedas para da troco
//c1 = 25, c2 = 10 ,c3 = 5, c4 = 1;
float c1 = 25 ;
float c2 = 10 ;
float c3 = 5;
float c4 = 1;
//Valor entrada do usuario
float troco ;
do{
    printf("Trocamos seu dinheiro com valor acima de 1 Dolar.");
    troco = get_float("Digite o valor de dinheiro a ser trocado.\n");
}while(troco < 1);

float valorDecremento = troco ;
int numeroMoedas = 0;


 while (valorDecremento > 0)
{
  if(valorDecremento >= c1){
      valorDecremento = valorDecremento - c1 ;
      numeroMoedas =  numeroMoedas + 1;
  }else if(valorDecremento >= c2){
      valorDecremento = valorDecremento - c2 ;
      numeroMoedas =  numeroMoedas + 1;
  }else if(valorDecremento >= c3){
       valorDecremento = valorDecremento - c3 ;
      numeroMoedas =  numeroMoedas + 1;
  }else if(valorDecremento >= c4){
      valorDecremento = valorDecremento - c4 ;
      numeroMoedas =  numeroMoedas + 1;
  }

}

printf("O valor do seu donheiro $ %f a ser trocado! \n", troco);
printf("Numero de moedas de troco é %d .\n", numeroMoedas);

  return 0;
}

