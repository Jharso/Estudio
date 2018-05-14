//Construya un algoritmo que dado tres números ingresados por teclado busque el mayor de los tres
#include <stdio.h>

int n[2], i=0;

void evaluar();
int main(){
    while(i<=2){

          printf("Ingrese número\n");
          scanf("%d", &n[i]);
          i=i+1;
          
             }

        evaluar();
    return 0;
}

void evaluar(){

    printf("pos:  %d  %d  %d \n", n[0],n[1],n[2]);

    if((n[0]>n[1])&&(n[1]>n[2])){
    
        printf("El número mayor es %d",n[0]);
    }
    if((n[1]>n[2])&&(n[2]>n[0])){
    
        printf("El número mayor es %d",n[1]);
    }
    if((n[2]>n[1])&&(n[1]>n[0])){
    
        printf("El número mayor es %d",n[2]);
    }

}