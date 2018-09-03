/*Arreglos 2 dimensiones.

Crear una arreglo de enteros llamado Matriz de tamaño 10 x 5.
Llenar el arreglo con datos al azar.
Imprimir el arreglo.
Ordenar el arreglo utilizando método Selección, Inserción y Burbuja
Búsqueda Binaria sobre el arreglo Matriz*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define filas 10
#define columnas 5
void crearmatriz(int (*)[columnas]);
void imprimirmatriz(int (*)[columnas]);
void ordenarmatrizburbuja(int (*)[columnas]);
void ordenarmatrizseleccion(int (*)[columnas]);
void ordenarmatrizinsercion(int (*)[columnas]);
void busquedabinaria(int (*)[columnas]);

void main (){
    int matriz[filas][columnas];
     crearmatriz(matriz);
     imprimirmatriz(matriz);
	 ordenarmatrizburbuja(matriz);
	 imprimirmatriz(matriz);
	 ordenarmatrizseleccion(matriz);
	 imprimirmatriz(matriz);
	 ordenarmatrizinsercion(matriz);
	 imprimirmatriz(matriz);
	 busquedabinaria(matriz);
}

void crearmatriz(int matriz[][columnas]){                        //Llena aleatoriamente la matriz utilizando función srand
	int i,j;
	i=0; srand(time(NULL));
	while(i < filas){
		j = 0;
		while(j < columnas){
			matriz[i][j]=rand()%200;
			j++;
		}
		i++;
	}
}
void imprimirmatriz(int matriz[][columnas]){                         //imprime matriz creada en "crearmatriz"
	int i,j;
	i=0;
	while(i < filas){
		j = 0;
		while(j < columnas){
			printf(" %i ",matriz[i][j]);
			j++;
		}
		i++;
        
        printf("\n");
	}
	printf("\n");
}

void ordenarmatrizburbuja(int matriz[][columnas]){
int i, j, f, c, f2, c2, aux;
	i=1;
	printf("\nMétodo burbuja\n");
	while(i< filas*columnas){
		j=1; f= filas -1; f2 = filas -1; c= columnas -1; c2 = columnas-2;           //f=9 y f2 =9
		while(j<filas*columnas){                                                    //mientras j sea menor a 50       
			
			if(matriz[f][c] < matriz[f2][c2]){                                       
			
				aux = matriz[f][c];                               //almacena datos de matriz posición f,c en var aux
				matriz[f][c]=matriz[f2][c2];                      //hace trasvasije de variable matriz posicion f,c a posicion f2,c2
				matriz[f2][c2]=aux;                               //linea 63-68  hace swap de posición en la matriz (ordenamiento)
			}
			c2 = c2 - 1;                                          //mueve la posición en la matriz para el siguiente análisis
			c = c -1; 
			if (c2 == -1){f2 = f2 - 1;c2 = columnas-1;}           //hace salto de fila en fila reiniciando posición de columnas (primera pasada de fila posición 9 a 8)
			if (c == -1){f = f - 1;c = columnas-1;}
			j++;
		}
		i++;
	}
}

void ordenarmatrizseleccion(int matriz[][columnas]){
	int i, j, aux, f, f2, c, c2;                               //declaro la variable "y" para ajustar la cantidad de comparaciones cada vez que 
	i = 1;f = 0; c = 0;          
	printf("\nMétodo selección\n");                              //encuentre un término mínimo 
    while(i < filas*columnas)	{
	    j = i; f2 = f; c2 = c + 1;
		while(j < filas*columnas){
		    if(matriz[f2][c2] < matriz[f][c]){                 //evalua buscando por mínimo, si encuentra menor cambia de posicion (f,c) por (f2,c2)
			aux = matriz[f][c];
			matriz[f][c] = matriz[f2][c2];
			matriz[f2][c2] = aux;
			}
         c2 = c2+1;                                                             
		 if(c2 == columnas){f2 = f2+1; c2 = 0;}
		j++;
	    }
	i++;
	c++;                                                         //aumentar el valor de c permite evaluar todo el resto de la matriz con el siguiente término mínimo.
    if(c == columnas){f = f+1; c = 0;}
	} 
}

void ordenarmatrizinsercion(int matriz[][columnas]){
	int i, j, loc, aux,f,c;
    i = 0; f = 0 ; c = 0;
	printf("\nMétodo inserción\n");
	while(i < filas*columnas){
		loc = i; aux = matriz[f][loc];                             //declara variable loc de posición
		while((loc > 0)&&(aux < matriz[f][loc-1])){                //compara datos en var loc con datos de la izquierda loc-1
			
			matriz[f][loc] = matriz[f][loc-1];                     //intercambia datos de posición
			loc--;
			c++;
		}
		i++;
		matriz[f][loc] = aux;                                       //último swap
		
	}
	
}  

void busquedabinaria(int matriz[][columnas]){
	int x, mark, prim, ult, med,f,c;
	f = 0; c = 0; x = 0;
	printf("ingrese elemento a buscar \n", x);
	scanf("%i", &x);
	prim = 0; ult = (filas*columnas)-1;
	while(prim<=ult)
    {
        med=(prim+ult)/2;
 
        if(x==matriz[f][med]){
            mark=1;
            break;
        }
        else
            if(x>matriz[f][med])
                prim=med+1;
            else
                ult=med-1;
    }
 
    if(mark==1)
        printf("\nElemento encontrado en la posición %d",med+1);
    else
        printf("\nElemento no encontrado");
 
}



// Rodrigo A. Jaramillo Solar
// Ing. Computación U.L.S.