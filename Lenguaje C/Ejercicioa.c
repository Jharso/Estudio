/*Construya un algorítmo que permita sumar los primeros 100 términos de la serie: 36n+6n+9n+12n+.....siendo n ingresado por el teclado*/
#include <stdio.h>
#include <stdlib.h>                                              //pre procesos command

int main()                                                       //int main() es una funcion base que todo programa debe tener
{
    int res;                                                     //el nombre de una variable no puede comenzar con número
    int n;
    int aux=3;
    
    printf("Ingrese un número cualquiera por favor: ");
    scanf("%d", &n);                                            //el &d indica el tipo de dato que se leerá y n es la variable donde almacenaremos ese dato
    
    while(aux <= 100){
        res = (n*aux)+res;
        aux = aux+3;
       } 
    printf("La suma de los primeros 100 términos de la serie 3n+6n+9n+12n es: %d",res);
}