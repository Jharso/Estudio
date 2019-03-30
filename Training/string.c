#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo{
    char nombre[25];
    struct nodo *sig, *ant;
}*Nodo;

Nodo agregarLista(Nodo lista, char *name);

void main(){
    Nodo lista,auxiliar;
    char nombre[25];
    nombre="Rodrigo"
    agregarLista(lista,nombre);

}

Nodo agregarLista(Nodo lista, char name[]){
    Nodo aux, bandera, nuevo;
    nuevo=(Nodo)malloc(sizeof(struct nodo));
    strcpy(nuevo->nombre, &name);
    if(lista == NULL){
        lista=nuevo;
    }else{
        aux=lista;
        if(aux->ant == NULL){
            aux->ant=nuevo;
            nuevo->sig=aux;
            lista=nuevo;            
            return lista;
        }else if(aux->sig == NULL){
            aux->sig=nuevo;
            nuevo->ant=aux;        
            return lista;      
        }else{
            aux->ant->sig=nuevo;
            nuevo->ant=aux->ant;
            aux->ant=nuevo;
            nuevo->sig=aux;
            return lista;
        }        
    }

}
