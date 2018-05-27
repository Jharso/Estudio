#include<stdio.h>
#include <time.h>
#define max  10
int una_tabla(){
	 int x,tabla[max];
           x=0;
           printf("imprimeeeee");
            while(x<=max)
            {
        	tabla[x]=rand()%100;
         	printf("%d\n",tabla[x]);
           	x++;
            }
            return 0;
}
int ordenar_numero(int tabla[max]){
	int pivote,indice,aux;
	pivote=0;
		while(pivote<=max-1){
			indice=pivote+1;
			while(indice>max){
				if(tabla[pivote]<tabla[indice]){
					aux=tabla[pivote];
					tabla[pivote]=tabla[indice];
					tabla[indice]=aux;
					printf("%d",tabla[indice]);
				}			
				indice++;
			}
			pivote++;
		}
return 0;
}

int main()
{

  una_tabla();
  ordenar_numero(max);
  
  return 0;
 }

