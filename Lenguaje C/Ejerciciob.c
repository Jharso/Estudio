//Construya un algoritmo que dado tres números ingresados por teclado busque el mayor de los tres
#include <stdio.h>

void main(){
    int n1;
    int n2;
    int n3;

    printf("ingrese 3 números cualquiera\n");
    printf("Número 1: ");
    scanf("%d",&n1);
    printf("Número 2: ");
    scanf("%d",&n2);
    printf("Número 3: ");
    scanf("%d",&n3);

    if (n1>n2 && n1>n3){
        printf("%d es el número mayor\n", n1);
    }
    if (n2>n1 && n2>n3){
        printf("%d es el número mayor\n", n2);
    }
    if (n3>n1 && n3>n2){
        printf("%d es el número mayor\n", n3);
    } 
    if (n1==n2 && n2==n3){
        printf("Los números son iguales\n");
    }   
    if (n1>n3 && n1==n2){
        printf("El primer y segundo número ingresados son iguales y ambos son mayores que el tercer número ingresado\n");
    }
    if (n1>n2 && n1==n3){
        printf("El primer y tercer número ingresados son iguales y ambos son mayores que el segundo número ingresado\n");
    }
    if (n2>n1 && n2==n3){
        printf("El segundo y tercer número ingresados son iguales y ambos son mayores que el primer número ingresado\n");
    }

}


