/* definir aplicación o programa que permita manejar la estructura alumnos y la estructura libros
libros: título, autor, año, editorial, número de paginas.
cargar (load) los datos a partir de un archivo de alumnos y de libros respectivamente*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 3
#define k 10
void ingresar(char direccion[]);  //guarda
void eliminar(char direccion[]);  //borra
void imprimir(char direccion[]);  //carga
void actualizar(char direccion[]);

typedef struct estr_alum
{
    char nombre[10];
    int edad;
    int notas[5];
}stats;
//NO HACE FALTA PASAR LA ESTRUCTURA COMO ARGUMENTO, YA QUE SE GUARDA EN EL ARCHIVO

void main()
{
    char direccion[]="datos.dat";
    int opcion=0;
    
    while(opcion < 5)
    {
        printf("\nDigite una opcion: ");
        printf("\n1. Agregar");
        printf("\n2. Borrar");
        printf("\n3. Imprimir");
        printf("\n4. Actualizar");
        printf("\n5. Salir");
        printf("\n : ");
        scanf("%i",&opcion);
        
        switch(opcion)
        {
            case 1: ingresar(direccion); break;    
            case 2: eliminar(direccion); break;
            case 3: imprimir(direccion); break;
            case 4: actualizar(direccion); break;
        }
    }
}

void ingresar(char direccion[])
{
    int i;
    stats alumno[n];
    
    FILE *archivo;
    archivo=fopen(direccion,"a");
     if(archivo==NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
        exit(1)
    }
    else
    {
        for(i=0,i<n,i++)
        {
            scanf();
        }
        
    }


    fclose(archivo);
}

void eliminar(char direccion[])
{
    FILE *archivo;
    archivo=fopen(direccion,"r");
    fclose(archivo);
}

void imprimir(char direccion[])
{
     FILE *archivo;
    archivo=fopen(direccion,"r");
    fclose(archivo);
}

void actualizar(char direccion[])
{
     FILE *archivo;
    archivo=fopen(direccion,"a");
    fclose(archivo);
}