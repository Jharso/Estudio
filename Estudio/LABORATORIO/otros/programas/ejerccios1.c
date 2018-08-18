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
     int indice,contador;
     indice=0; contador=0;
     while(indice < max){
             numeros[indice]=contador;
             contador=contador + 3;
             indice=indice +1;
       }
}

void menu(int* opcion){
      int valor;
      dibuja();
      valor=0;
      while(valor<1 || valor>4){
            printf("\n\nIngrese una opcion valida-->");
            scanf("%i",&valor);
       }
       *opcion=valor;
}
void dibuja(){
      printf("\n\n\n");
      printf("  MENU\n");
      printf("\n\n\n");
      printf("1.- Crear Arreglo\n";
      printf("2.- Llenar arreglo con datos\n");
      printf("3.- Imprimir arreglo\n");
      printf("4.- salir\n)";
      printf("\n\n\n");
}                   
                                      
                      
