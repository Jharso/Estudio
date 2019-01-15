#include<stdio.h>
#include<stdlib.h>

int evaluar(int);

int main(){
    int numero;
    printf("Ingrese un número \n");
    scanf("%d",&numero);
    evaluar(numero);
    
    return 0;
}

int evaluar(int numero){
    int r;
    if(numero<=0){
        if(numero==0){
        printf("El número es par\n");    
        }else{
            printf("El número es impar");
        }  
        return 1;      
    }else{
        evaluar(numero-2);        
    }
    return 0;
}