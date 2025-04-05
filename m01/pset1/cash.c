#include <stdio.h>
// possibilidades de saque de cash do programa:

// valor para saque - 25 cash - 10 cash - 5 cash - 1 cash
int cash25 = 25 , cash10 = 10 ,cash5 = 5 , cash1 = 1 ;

int saqueCash25 ,saqueCash10 ,saqueCash5 ,saqueCash1 ;

float resto;
void validaSaque(int c);

void exibeSaque(void);
int main(void)
{   
    float c;
    do{
      //Solicitar altura do usuario
    printf("Qual valor em Dolar $ quer trocar: \n");
	scanf("%f", &c);
    }while(c<=0);

    validaSaque(c);
    exibeSaque();
}

void validaSaque(int c){
    resto = c;
    //cash de 25
    if(resto>=cash25){
        do {
        saqueCash25++;
            resto -= cash25;
        }while(resto>=cash25);
    }

    //cash de 10
    if(resto>=cash10){
        do {
        saqueCash10++;
            resto -= cash10;
        }while(resto>=cash10);
    }

    //cash de 5
    if(resto>=cash5){
        do {
        saqueCash5++;
            resto -= cash5;
        }while(resto>=cash5);
    }

        //cash de 1
    if(resto>=cash1){
        do {
            saqueCash1++;
             resto -= cash1;
    }while(resto>=cash1);
     }

}

void exibeSaque(void){
    printf("Cash  $25 : %d\n",saqueCash25);
    printf("Cash  $10 : %d\n",saqueCash10);
    printf("Cash  $5 : %d\n",saqueCash5);
    printf("Cash  $1 : %d\n",saqueCash1);
    printf("Cash restante : $%.2f\n",resto);
}