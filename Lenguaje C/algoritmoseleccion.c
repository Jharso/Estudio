#include <stdio.h>


int main(){

    int n=8, a[8], aux;
    int i=0;
  
    printf("ingrese uno por uno los elementos de su arreglo\n");

    while(i <= n){
         scanf("%i \n", &aux);
          
         a[i]=aux;
         i=i+1;
        
    }
    printf("valor de i= %i \n",i);
    i=0;
    printf("los elementos de su arreglo son\n");

    while(i <= n){
        printf("%i, ",a[i]);
        i=i+1;
    }

    printf("estoy aca");

    
    return 0;

}