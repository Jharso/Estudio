#include <stdio.h>
#define max 10

void crear_arregl(int*);
void imprimir_arreglo(int*);
void menu(int*);
void dibuja();
void main()
{        int seguir, opcion;
         int numeros[max]; //crea arreglo numeros
         seguir=1;
         while(seguir){
            menu(&opcion);
            if(opcion==1){ crear_arreglo(numeros);}
            if(opcion==2){ /*llenar_arreglo(numeros);*/}
            if(opcion==3){ imprimir_arreglo(numeros);}
            if(opcion==4){ seguir=0;}
        }

}           
 
void imprimir_arreglo(int numeros[max]){
     int indice;char pausa;
     indice=0;
     printf("\n\nArreglo de numeros\n\n");
     while(indice < max){
             printf("\n numeros [%i]=%i",indice,numeros[indice]);
             indice=indice+1;
     }
     fflush(stdin);
     scanf("%c",&pausa);
     fflush(stdin);
     scanf("%c",&pausa);
}

void crear_arreglo(int numeros[max]){             
                      
