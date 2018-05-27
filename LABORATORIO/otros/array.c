#include <stdio.h>
    
    int arreglo[10];
    int  i=1, n=1, m=10, opt;
    
   
  void array(void){
   
       while(i<=10){
       
       arreglo[i]=n;
       printf("El nùmero aletorio es %d \n", arreglo[i]);
       i=i+1;
       n=n+1;
     }

}
void array2(void){
    
      
     while(i<=10){
       
       arreglo[i]=m;
       printf("El nùmero aletorio es %d \n", arreglo[i]);
       i=i+1;
       m=m-1;
     }

}

void main(){
  
  
       printf("presione 1 para Imprimir arreglo ascendente\n");
       printf("presione 2 para Imprimir arreglo descendente\n");
       printf("presione 3 para salir\n");
       
       
   while(opt<3){
   
       scanf("%d",&opt);
      
             
        if  ( opt==2 ){
      
               array2();
               
         }
         
        if(opt==1){
         
               array();
               
         }       
      }

}










