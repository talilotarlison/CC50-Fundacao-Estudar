

#include <stdio.h>
#include <cs50.h>
int main(void)
{

float troco;
int moedas, moedas25, moedas10, moedas5, moedas1;
int m25 = 25, m10 = 10, m5 = 5, m1 = 1;
moedas25 = 0, moedas10 = 0, moedas5 = 0, moedas1 = 0;

    do
   {
    troco = get_float("qual é o troco: ");
   }
      while (troco < 0);

        troco = (troco * 100);

        //calcula moedas de 25 centavos

          if (troco >= 25)

        do
      {
          troco = troco - 25;
          moedas25++;
      }
      while(troco >= 25);



    printf("o número de moedas de 25 centavos é %i", moedas25);

        //calcula moedas de 10 centavos
         if (troco >= 10)

        do
      {
          troco = troco - 10;
          moedas10++;
      }
     while(troco >= 10);


    printf("\no número de moedas de 10 centavos é %i", moedas10);

        //calcula moedas de 5 centavos

         if (troco >= 5)

        do
      {
          troco = troco - 5;
          moedas5++;
      }
     while(troco >= 5);


    printf("\no número de moedas de 5 centavos é %i", moedas5);

        //calcula moedas de 1 centavo

         if (troco >= 1)

        do
      {
          troco = troco - 1;
          moedas1++;
      }
     while(troco >= 1);


    printf("\no número de moedas de 1 centavos é %i\n", moedas1);

}