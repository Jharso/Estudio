/*Crear una arreglo de enteros llamado datos de tamaño 20.
    Llenar el arreglo con datos al azar.
    Imprimir el arreglo.
    Ordenar el arreglo utilizando método Selección, Inserción y Burbuja
    Búsqueda Binaria sobre el arreglo datos.*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define datos 20

void crearmatriz(int *);
void imprimir_numeros(int *);
void ordenarmatrizburbuja(int *);
void ordenarmatrizseleccion(int *);
void ordenarmatrizinsercion(int *);
void busquedabinaria(int *);

void main (){
    int matriz[datos];
    crearmatriz(matriz);
    imprimir_numeros(matriz);
    ordenarmatrizburbuja(matriz);
    imprimir_numeros(matriz);
    ordenarmatrizseleccion(matriz);
    imprimir_numeros(matriz);
    ordenarmatrizinsercion(matriz);
    imprimir_numeros(matriz);
    busquedabinaria(matriz);
    
}

void crearmatriz(int matriz[datos]){
    int i;
	i=0;srand(time(NULL));
	while(i < datos){
		matriz[i]=rand()%100;
		i=i+1;
	}

}

void imprimir_numeros(int matriz[datos]){
	int i;
	i=0;
	while(i < datos){
		printf("\n\tnumeros[%d] = %d",i+1,matriz[i]);
		i=i+1;
	}
	printf("\n");
}

void ordenarmatrizburbuja(int matriz[datos]){
int i, j, d, d2, aux;
	i=1;
    printf("\nMétodo burbuja\n");
    while(i< datos){
		j=1; d = datos -1; d2 = datos-2;           
		while(j<datos){                                                       
			
			if(matriz[d] < matriz[d2]){                                       
			
				aux = matriz[d];                               
				matriz[d]=matriz[d2];                      
				matriz[d2]=aux;                               
			}
			d2 = d2 - 1;                                         
			d = d -1; 
			j++;
		}
		i++;
	}
}

void ordenarmatrizseleccion(int matriz[datos]){
	int i, j, aux, d, d2;                               //declaro la variable "y" para ajustar la cantidad de comparaciones cada vez que 
	i = 1; d = 0;  
    printf("\nMétodo selección\n");                                      //encuentre un término mínimo 
    while(i < datos)	{
	    j = i; d2 = d + 1;
		while(j < datos){
		    if(matriz[d2] < matriz[d]){                 //evalua buscando por mínimo, si encuentra menor cambia de posicion (f,c) por (f2,c2)
			aux = matriz[d];
			matriz[d] = matriz[d2];
			matriz[d2] = aux;
			}
         d2 = d2+1;                                                             
		j++;
	    }
	i++;
	d++;                                                         //aumentar el valor de c permite evaluar todo el resto de la matriz con el siguiente término mínimo.
   	} 
}

void ordenarmatrizinsercion(int matriz[datos]){
	int i, j, loc, aux,d;
    i = 0; d = 0;
    printf("\nMétodo inserción\n");
	while(i < datos){
		loc = i; aux = matriz[loc];                             //declara variable loc de posición
		while((loc > 0)&&(aux < matriz[loc-1])){                //compara datos en var loc con datos de la izquierda loc-1
			
			matriz[loc] = matriz[loc-1];                     //intercambia datos de posición
			loc--;
			d++;
		}
		i++;
		matriz[loc] = aux;                                       //último swap
		
	}
	
} 

void busquedabinaria(int matriz[datos]){
	int x, mark, prim, ult, med,d;
	d = 0; x = 0;
	printf("\ningrese elemento a buscar \n");
	scanf("%i", &x);
	prim = 0; ult = datos-1;
	while(prim<=ult)
    {
        med=(prim+ult)/2;
 
        if(x==matriz[med]){
            mark=1;
            break;
        }
        else
            if(x>matriz[med])
                prim=med+1;
            else
                ult=med-1;
    }
 
    if(mark==1)
        printf("\nElemento encontrado en la posición %d",med+1);
    else
        printf("\nElemento no encontrado\n");
 
}

// Rodrigo A. Jaramillo Solar
// Ing. Computación U.L.S.