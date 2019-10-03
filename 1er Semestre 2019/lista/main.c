//
//  main.c
//  lista
//  Created by Mauro San Martin  on 01-04-14.
//  Copyright (c) 2014 Mauro San Martin . All rights reserved.
//

#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif

#ifndef lista_h
#include "lista_arreglo.h"
#define lista_h
#endif



int main(int argc, const char * argv[])
{
    Lista *lista = creaLista();
    
    insertaEltoLista(lista, 5, 0);
    recorreLista(lista);
    insertaEltoLista(lista, 6, 1);
    recorreLista(lista);
    insertaEltoLista(lista, 7, 2);
    recorreLista(lista);
    insertaEltoLista(lista, 8, 1);
    recorreLista(lista);
    insertaEltoLista(lista, 9, 0);
    recorreLista(lista);
    
    sacaEltoLista(lista, localizaEltoLista(lista, 8));
    recorreLista(lista);
    //sacaEltoLista(lista, localizaEltoLista(lista, 9));
    sacaEltoLista(lista, 0);
    recorreLista(lista);
    sacaEltoLista(lista, localizaEltoLista(lista, 7));
    recorreLista(lista);
    
    printf("Elemento en la posicion 2 = %d \n", recuperaEltoLista(lista,2));
    printf("Elemento en la posicion 1 = %d \n", recuperaEltoLista(lista,1));
    
    sacaEltoLista(lista, localizaEltoLista(lista, 5));
    recorreLista(lista);
    sacaEltoLista(lista, localizaEltoLista(lista, 6));
    recorreLista(lista);
    
    printf("%d\n", finLista(lista));
    
    printf("\n\nLISTA USADA COMO PILA POR EL INICIO\n");
    // implementación con lista enlazada: no hay desplazamientos
    // implementación con arreglo: no es buena idea -> muchos desplazamientos
    
    insertaEltoLista(lista, 5, inicioLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 6, inicioLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 7, inicioLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 8, inicioLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 9, inicioLista(lista));
    recorreLista(lista);
       
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    
    insertaEltoLista(lista, 10, inicioLista(lista));
    recorreLista(lista);
    
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    
    printf("\n\nLISTA USADA COMO PILA POR EL FINAL\n");
    // implementación con lista enlazada: no hay desplazamientos
    // implementación con arreglo: no hay desplazamientos
    insertaEltoLista(lista, 5, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 6, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 7, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 8, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 9, finLista(lista));
    recorreLista(lista);
    
    sacaEltoLista(lista, finLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, finLista(lista));
    recorreLista(lista);
    
    insertaEltoLista(lista, 10, finLista(lista));
    recorreLista(lista);
    
    sacaEltoLista(lista, finLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, finLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, finLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, finLista(lista));
    recorreLista(lista);
    
    printf("\n\nLISTA USADA COMO COLA\n");
    // llegan por el fin y salen por el principio
    insertaEltoLista(lista, 5, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 6, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 7, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 8, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 9, finLista(lista));
    recorreLista(lista);
    insertaEltoLista(lista, 20, finLista(lista)); //con capacidad == 5, esta insercion no tiene efecto
    recorreLista(lista);
    
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    
    insertaEltoLista(lista, 10, finLista(lista));
    recorreLista(lista);
    
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    sacaEltoLista(lista, inicioLista(lista));
    recorreLista(lista);
    
    scanf("...");
    
    return(0);
}
