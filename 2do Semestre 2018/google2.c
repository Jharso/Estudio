#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define tamano 20

int ale(int *);
int imprimir(int *);
int buscar(int *);

int main(){
   int anumero[tamano];
   ale(anumero);
   imprimir(anumero);
   evaluar(anumero);
    return 0;
}

int buscar(int anumero[tamano]){
    int i,j;
    for(i=0;i<tamano;i++){
        aux=anumero[i]-8;
        for(j=0;j<tamaño;j++){
            if(i==j){
                
            }else{}
            
        }
    }
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
         anumero[i]=rand()%10;
     }
     return *anumero;
}
