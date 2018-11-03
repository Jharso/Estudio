#include <stdio.h>
#include <stdlib.h>

void burbuja(int [6]);
void seleccion(int [6]);
void inserccion(int [6]);
void imprimir(int [6]);

int main(){
  int datos[6]={2,7,4,1,5,3};
    imprimir(datos);
    //burbuja(datos);    
   // printf("\n\n");
   // imprimir(datos);
    seleccion(datos);
    printf("\n\n");
    imprimir(datos);

}

void burbuja(int datos[6]){
    int i=0,j=0,aux;
    while(j<5){
      while(i<5){
          if(datos[i]>datos[i+1]){
              aux=datos[i+1];
              datos[i+1]=datos[i];
              datos[i]=aux;
          }
          i++;
      }
      i=0;
      j++;
    }
}

void seleccion(int datos[6]){
    int i=0, j=0, aux, imin;
    while(i<5){
        imin=i;
        j=i+1;
        while(j<6){
            printf("\nvalor de j:%i de i:%i, de imin: %i\n", j,i,imin);
            if(datos[j]<datos[imin]){
                imin=j;
            }
            j++;
        }
        aux=datos[i];
        datos[i]=datos[imin];
        datos[imin]=aux;                        
        i++;
        }
}

void imprimir(int datos[6]){
    int i=0;
    while(i<6){
        printf("\n      %i\n", datos[i]);
        i++;
    }
}