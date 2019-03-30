#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct nodo{
    int id;
    char fullName[25];
    struct nodo *ant, *sig;
}*Nodo;

Nodo agregarLista(Nodo lista, int idnumber, char name[]);
void imprimirLista(Nodo lista);
void ordenarLista(Nodo lista);
int longitudLista(Nodo lista);

int main(){
    int i;
    char nombre[25];
    Nodo L1=NULL;    
    for(i=1;i<6;i++){
        printf("\nIngrese Nombre\n");
        scanf("%s",nombre);
        L1=agregarLista(L1, i,nombre);
    }
    printf("\nLa longitud %d\n",longitudLista(L1));
    imprimirLista(L1);
    ordenarLista(L1);
    imprimirLista(L1);

    return 0;
}

Nodo agregarLista(Nodo lista, int idnumber, char name[]){
    Nodo aux, nuevo;
    nuevo=(Nodo)malloc(sizeof(struct nodo));
    nuevo->id=idnumber;
    strcpy(nuevo->fullName, name);
    nuevo->ant=nuevo->sig=NULL;
    if(lista == NULL){
        lista=nuevo;
    }else{
        aux=lista;
        aux->ant=nuevo;
        nuevo->sig=aux;
        lista=nuevo;
        return lista;
    }
}

void imprimirLista(Nodo lista){
    int i;
    Nodo aux;
    aux=lista;    
    printf("\nID           Nombre                   \n");
    if(lista->sig == NULL){
        printf("\n%d           %s\n",aux->id,aux->fullName);                
    }else{
        for(aux=lista;aux != NULL; aux=aux->sig){
            printf("\n%d           %s\n",aux->id,aux->fullName);
        }
    }
    printf("\n\n");
}

int longitudLista(Nodo lista){
    int cont=0;
    Nodo aux;
    aux=lista;    
    while(aux != NULL){
        cont=cont+1;
        aux=aux->sig;
    }
    return cont;
}

void ordenarLista(Nodo lista){
    int i,j,a,longitud;
    Nodo aux,temp,aux2;
    longitud=longitudLista(lista);   
    aux=lista; 
    for(i=0;i<longitud-1;i++){
        printf("\nprimer for\n");
        aux2=aux;
        for(j=0;j<longitud-1;j++){
            printf("\nsegundo for\n");
            imprimirLista(lista);    
            scanf("%d",&a);       
            if(aux2->id > aux2->sig->id){
                temp=aux2;                
                aux2->sig=aux2->sig->sig;
                aux2->sig->ant=aux2->ant;
                aux2->ant=temp->sig->ant;                
                aux2->sig->sig=aux2;
            }
            aux2=aux2->sig;            
        } 
        aux=aux->sig;
        longitud=longitud-1;       
    }
    printf("\ntermina algoritmo\n");
}