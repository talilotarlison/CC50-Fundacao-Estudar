
#include <stdio.h>

int main()
{
// valor das moedas para da troco
//c1 = 25, c2 = 10 ,c3 = 5, c4 = 1;
float c1 = 25 ;
float c2 = 10 ;
float c3 = 5;
float c4 = 1;
//Valor entrada do usuario
float troco = 1;
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

printf("Seu troco %f \n", troco);
printf("numero de moedas de troco é %d", numeroMoedas);

  return 0;
}

