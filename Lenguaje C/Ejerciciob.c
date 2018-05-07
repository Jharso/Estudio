//Construya un algoritmo que dado tres números ingresados por teclado busque el mayor de los tres
#include <stdio.h>

int main(){
    int n1;
    int n2;
    int n3;

    printf("ingrese 3 números cualquier\n");
    printf("Número 1\n");
    scanf("%d",&n1);
    printf("Número 2\n");
    scanf("%d",&n2);
    printf("Número 3\n");
    scanf("%d",&n3);

    if((n1 >n2)&&(n1 > n3)){
        printf("%d es el número mayor", n1);
    }
    if((n2 > n1)&&(n2 > n3)){
        printf("%d es el número mayor", n2);
    }
    if((n3 > n1)&&(n3 > n2)){
        printf("%d es el número mayor", n3);
    } else {
        printf("los tres números son iguales");
    }
    
}


