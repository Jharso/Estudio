//
//  lista_arreglo.h
//  lista
//  Created by Mauro San Martin  on 01-04-14.
//  Copyright (c) 2014 Mauro San Martin . All rights reserved.
//
// TAD Lista de enteros positivos implementado con un arreglo.
// Implementa la interfaz usual de lista que soporta acceso
// directo a cualquier posición.
// Asume que el principio de la lista se mantendrá en la primera
// posicion del arreglo. Las posiciones varian entre 0 y capacidad-1,
// ultimo es el indice del ultimo elemento.


#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

#define CAPACIDAD 10

typedef  struct tipo_lista{
    int ultimo;
    int capacidad;
    int *elementos;
} Lista;


Lista *creaLista(){
    Lista *tmp;
    tmp = malloc(sizeof(Lista));
    tmp->ultimo = -1;
    tmp->capacidad = CAPACIDAD;
    tmp->elementos = malloc(tmp->capacidad*sizeof(int));
    return (tmp);
}

Lista *creaListaCapacidad(int unaCapacidad){
    Lista *tmp;
    tmp = malloc(sizeof(Lista));
    tmp->ultimo = -1;
    tmp->capacidad = unaCapacidad;
    tmp->elementos = malloc(tmp->capacidad*sizeof(int));
    return (tmp);
}

int insertaEltoLista(Lista *lista, int valor, int posicion){
    if(((lista->ultimo + 1) == lista->capacidad) //arreglo lleno
       || (posicion > lista->ultimo+1)
       || (posicion < 0))
        return(-1); //error
    for(int i =lista->ultimo; i>= posicion; i--){
        lista->elementos[i+1] = lista->elementos[i];
    }
    lista->elementos[posicion] = valor;
    lista->ultimo ++;
    return(0);
}

int localizaEltoLista(Lista *lista, int valor){
    for(int i = 0; i<=lista->ultimo; i++){
        //retorna el primero encontrado
        if(lista->elementos[i] == valor) return(i);
    }
    return(-1); // no encontrado
}

int recuperaEltoLista(Lista *lista, int posicion){
    if((posicion >= 0) && (posicion <= lista->ultimo))
        return(lista->elementos[posicion]);
    else
        return(-1); //error
}

int sacaEltoLista(Lista *lista, int posicion){
    if((lista->ultimo < 0) //lista vacia
       || (posicion > lista->ultimo+1) //!!!
       || (posicion < 0))
        return(-1); //error
    for(int i = posicion; i<lista->ultimo; i++){
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->ultimo--;
    return(0);
}

int anteriorLista(Lista *lista, int posicion){
    if((posicion > 0) && (posicion <= lista->ultimo))
        return(posicion--);
    else
        return(-1); //error
}

int siguienteLista(Lista *lista, int posicion){
    if((posicion >= 0) && (posicion < lista->ultimo))
        return(posicion++);
    else
        return(-1); //error
}

int inicioLista(Lista *lista){
    return(0);
}

int finLista(Lista *lista){
    return(lista->ultimo+1);
    //retorna el indice del primer elemento vacío en un arreglo de C
    //esto equivale a la cantidad de elementos actualamente almacenados
}

void vaciaLista(Lista *lista){
    lista->ultimo = -1;
}

void eliminaLista(Lista *lista){
    free(lista->elementos);
    free(lista);
}

int esVaciaLista(Lista *lista){
    if (lista->ultimo==-1) {
        return (1);
    }else{
        return (0);
    }
}

void recorreLista(Lista *lista){
    // En este caso recorre e imprime, podria ser cualquier
    // otra la accion llevada a cabo sobre cada elemento.
    printf("INICIO LISTA ESTATICA\n");
    printf("Ultimo elemento en posicion = %d\n", lista->ultimo);
    for(int i = 0; i<=lista->ultimo; i++){
        printf("lista[%d] = %d\n", i, lista->elementos[i]);
    }
    printf("FIN LISTA\n\n");
}




