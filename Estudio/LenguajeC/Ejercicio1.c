//*Construya un algorítmo que permita sumar los primeros 100 términos de la serie: 3n+6n+9n+12n+.....siendo n ingresado por el teclado*/
#include <stdio.h>

void serie(int);

int main(){
   int n;
   printf("ingrese un número cualquiera\n");
   scanf("%d", &n);
   serie(n);   
   return 0;
}

void serie(int a){
     int aux=3, i=1, res=3*a;
     while(i<=100){
         printf("%d\n", res);
         res=res+((aux+3)*a);
         aux+=3;
         i+=1;
     } 
 
}
// no tiene controlador de errores
