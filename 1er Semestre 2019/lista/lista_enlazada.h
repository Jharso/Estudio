//
//  lista_enlazada.h
//  lista
//  Created by Mauro San Martin  on 01-04-14.
//  Copyright (c) 2014 Mauro San Martin . All rights reserved.
//
// TAD Lista de enteros positivos implementado con una lista enlazada.
// Implementa la interfaz usual de lista que soporta acceso directo a
// cualquier posición (comportamiento análogo a la implementación con
// arreglo).
// Cada elemento puede ser referenciado por un entero que representa
// su posicion en la lista. Posicion puede variar de 0 a FIN (ultimo +1).
// No hay una capacidad preestablecida.
// La lista se maneja con una estructura que contiene un puntero al
// primer elemento de la lista y la posicion del ultimo.
// Cada elemento es de tipo nodo y contiene un dato de tipo entero y un
// puntero al siguiente elemento.


#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif


typedef struct tipo_nodo{
    int dato;
    struct tipo_nodo *sgte;
} Nodo;
// El tipo nodo podría considerarse un TAD en sí mismo y definirse en su propio archivo


typedef  struct tipo_lista{
    int ultimo;
    Nodo *inicio;
} Lista;


Lista *creaLista(){
    Lista *tmp;
    tmp = malloc(sizeof(Lista));
    tmp->ultimo = -1;
    tmp->inicio = NULL;
    return (tmp);
}

int insertaEltoLista(Lista *lista, int valor, int posicion){
    // Para emular el comportamiento de la lista implementada en un arreglo
    // es necesario insertar antes. Como se trata de una lista enlazada simple
    // sera necesario recorrerla sin perder la referencia al elemento anterior.
    Nodo *nuevo, *actual, *anterior;
    int cuentaPos;
    if((posicion > lista->ultimo+1) || (posicion < 0))
        return(-1); //error:posicion fuera de rango
    nuevo = malloc(sizeof(Nodo));
    if(nuevo == NULL) return(-1); //error: no hay memoria disponible
    nuevo->dato = valor;
    nuevo->sgte = NULL;
    if(posicion == 0){ //insertar en la cabeza de la lista
        actual = lista->inicio;
        lista->inicio = nuevo;
        nuevo->sgte = actual;
    }else{           //buscar la posicion y luego insertar
        actual = lista->inicio;
        anterior = NULL;
        cuentaPos = 0;
        while((actual != NULL) && (cuentaPos < posicion)){
            anterior = actual;
            actual = actual->sgte;
            cuentaPos++;
        }
        nuevo->sgte = actual;
        anterior->sgte = nuevo;
    }
    lista->ultimo++;
    return(1);
}


int localizaEltoLista(Lista *lista, int valor){
    Nodo *temp;
    int cuenta_pos=0;
    temp = lista->inicio;
    while(temp != NULL){
        if(temp->dato == valor) return(cuenta_pos);
        temp = temp->sgte;
        cuenta_pos++;
    }
    return(-1); // no encontrado
}

int recuperaEltoLista(Lista *lista, int posicion){
    // asume que la lista contiene lista->ultimo +1 elementos
    // indizados desde 0
    if((posicion > lista->ultimo) || (posicion < 0))
        return(-1); //error:posicion fuera de rango
    Nodo *temp;
    int cuentaPos=0;
    temp = lista->inicio;
    while((temp != NULL) && (cuentaPos < posicion)){
        temp = temp->sgte;
        cuentaPos++;
    }
    // si la lista está consistente el ciclo simpre terminará
    // al alcanzar la posición deseada
    return(temp->dato);
}

int sacaEltoLista(Lista *lista, int posicion){
    // Como en insertar se debe usar usar la referencia del elemento anterior.
    Nodo *temp, *actual;
    int cuentaPos;
    if((lista->ultimo < 0) || (posicion > lista->ultimo+1) || (posicion < 0))
        return(-1); //error:posicion fuera de rango
    if(posicion == lista->ultimo+1) posicion = lista->ultimo;
    if(posicion==0){ //eliminar en la cabeza de la lista
        temp = lista->inicio;
        lista->inicio = lista->inicio->sgte;
    }else{           //buscar la posicion y luego insertar
        actual = lista->inicio;
        cuentaPos = 0;
        while(cuentaPos < posicion - 1){
            actual = actual->sgte;
            cuentaPos++;
        }
        temp = actual->sgte;
        actual->sgte = actual->sgte->sgte;
    }
    free(temp);
    lista->ultimo--;
    return(1);
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
    //retorna el indice del primer elemento vacío, en un arreglo de C
    //esto equivale a la cantidad de elementos actualamente almacenados
}

void vaciaLista(Lista *lista){
    //asume que la lista a sido inicializada
    Nodo *temp;
    if(lista->inicio!=NULL){
        temp = lista->inicio;
        while(temp!=NULL){
            Nodo *temp_sgte;
            temp_sgte = temp->sgte;
            free(temp);
            temp = temp_sgte;
        }
        lista->inicio=NULL;
    }
    lista->ultimo = -1;
}


void eliminaLista(Lista *lista){
    vaciaLista(lista);
    free(lista);
}

int esVaciaLista(Lista *lista){
    if (lista->inicio==NULL) {
        return (1);
    }else{
        return (0);
    }
}

void recorreLista(Lista *lista){
    // En este caso recorre e imprime, podria ser cualquier
    // otra la accion llevada a cabo sobre cada elemento.
    Nodo *actual;
    actual = lista->inicio;
    printf("INICIO LISTA\n");
    printf("Ultimo elemento en posicion = %d\n", lista->ultimo);
    for(int i = 0; i<=lista->ultimo; i++){
        printf("lista[%d] = %d\n", i, actual->dato);
        actual = actual->sgte;
    }
    printf("FIN LISTA\n\n");
}





