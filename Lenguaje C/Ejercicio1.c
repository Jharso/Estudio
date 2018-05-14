/*Construya un algorítmo que permita sumar los primeros 100 términos de la serie: 3n+6n+9n+12n+.....siendo n ingresado por el teclado*/
#include <stdio.h>
#include <stdlib.h>

int n, aux=1, suma=0, cont=3;

int main (){
        printf("ingrese un número cualquiera para calcular la sumatoria\n");
        scanf("%d",&n);
    while(aux<=100){
        
        suma=(n*cont)+suma;
        printf("la suma de la serie 3n+6n+9n+12n....suma = %d ;    posición %d \n", suma, aux);
        aux=aux+1;
        cont=cont+3;
        
        
    }

    return 0;

}
