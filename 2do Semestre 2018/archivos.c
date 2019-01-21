/*.- 
Se realiza en clases solución de tarea para gestionar archivos en C.

Crear archivo de alumnos (Nombre Apellido Paterno Apellido Materno) en C
Agregar datos al archivo
Leer el archivo
Eliminar el archivo
Además se explican los conceptos de Registros, Atributos o campos en un archivo de datos.
2.- Se procede a desarrollar algoritmos de Back Tracking Iterativo.
Se desarrolla un bosquejo de la plantilla de solución
Se desarrolla el ejercicio del Caballo.
Se requiere construir un algoritmo que permita visitar todas las posiciones del tablero de ajedrez, una única vez siguiendo los movimientos del Caballo a partir de la posición inicial (X,Y).
Se da de tarea para el domingo 4 de noviembre.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define n 20
int leer_archivo(char direccion[]);
int imprimir(int *);
typedef struct estr_alum{
    char nombre[10];
    int edad;
    int notas[5];
}stats;

int main(){
    stats a[n];
    int i;
    char direccion[]="database.txt",nombre[20],app[20],apm[20];   
    FILE *archivo;
    archivo = fopen(direccion, "a");
    printf("Ingrese nombre: ");
		scanf("%s",nombre);

		printf("Ingrese apellido paterno: ");
		scanf("%s",app);

		printf("Ingrese apellido materno: ");
		scanf("%s",apm);

		fprintf(archivo,"%s %s %s\n",nombre,app,apm);

		fclose(archivo);
        leer_archivo(direccion);
}


int leer_archivo(char direccion[]){
    FILE *archivo;
    char nombre[200],app[200],apm[200];
	archivo = fopen(direccion,"r");

	if(archivo == NULL){
		printf("No se puede leer el archivo");
		return 1;
	}

	while(!feof(archivo)){
		fscanf(archivo,"%s %s %s",nombre,app,apm);
		if(feof(archivo) == 0){
               		printf("%s %s %s\n",nombre,app,apm);  //esta función lee el documento entero
		}
	}


}
