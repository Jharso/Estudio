#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define tamano 20

int ale(int *);
int imprimir(int *);
int evaluar(int *);

int main(){
   int anumero[tamano];
   ale(anumero);
   imprimir(anumero);
   evaluar(anumero);
    return 0;
}

int imprimir(int anumero[tamano]){
    int i;
    for(i=0;i<tamano;i++){
        printf("%d  ",anumero[i]);
    }
    printf("\n");
    return 0;
}

int ale(int anumero[tamano]){
    int i;
    srand(time(NULL));
     for(i=0;i<tamano;i++){
         anumero[i]=rand()%80;
     }
     return *anumero;
}

int evaluar(int anumero[tamano]){
    int i,j;
    for(i=0;i<tamano;i++){        
        for(j=0;j<tamano;j++){
            if((anumero[i]+anumero[j])==82){
                printf("El primer par de números encontrados que satisfacen la condición son: %d y %d y suman 8\n",anumero[i],anumero[j]);
                return 0;
            }            
        }
    }
    printf("No hay par de numeros encontrados que satisfagan la condición\n");
    return 0;
}