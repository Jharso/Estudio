#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo
{
    int dato;
    struct nodo *ant, *sig;
}*Lista;

Lista agregarLista(Lista ,int);
void imprimirLista(Lista);
Lista determinaPar(Lista, Lista);
Lista determinaImpar(Lista, Lista);
Lista eliminaLista(Lista, int);

int main()
{
    Lista L1,L2,L3;
    int i,a,n,e;
    L1=L2=L3=NULL;
    srand(time(NULL));
    printf("\nIngrese la cantidad de elementos a generar.\n");
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        L1=agregarLista(L1,rand()%100);
    }
    imprimirLista(L1);
    L2=determinaPar(L1,L2);
    imprimirLista(L2);
    L3=determinaImpar(L1,L3);
    imprimirLista(L3);
    printf("\nIngrese el elemento a eliminar:\n");
    scanf("%d",&e);
    eliminaLista(L1,e);
    imprimirLista(L1);
    agregarLista(L1,23);
    agregarLista(L1,24);
    imprimirLista(L1);
    return 0;
}

Lista agregarLista(Lista L, int elemento)
{
    Lista aux,nuevo,bandera;
    nuevo=(Lista)malloc(sizeof(struct nodo));
    nuevo->dato=elemento;
    nuevo->ant=nuevo->sig=NULL;
    if(L == NULL)
    {
        L=nuevo;
    }
    else
    {
        aux=L;
        bandera=NULL;
        while(aux != NULL)
        {
            if(elemento < aux->dato)
            {
                if(aux->ant == NULL)
                {
                    aux->ant=nuevo;
                    nuevo->sig=aux;
                    L=nuevo;
                    aux=NULL;
                }
                else
                {
                    aux->ant->sig=nuevo;
                    nuevo->ant=aux->ant;
                    aux->ant=nuevo;
                    nuevo->sig=aux;
                    aux=NULL;
                }                
            }
            else
            {
                bandera=aux;
                aux=aux->sig;
            }            
        }
        if(bandera != NULL)
        {
            bandera->sig=nuevo;
            nuevo->ant=bandera;
        }        
    }
    return L;
}

void imprimirLista(Lista L)
{
    Lista aux;
    aux=L;
    printf("\n");
    while(aux != NULL)
    {
        printf("%d ",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}

Lista determinaPar(Lista LA, Lista LB)
{    
    Lista aux;
    aux=LA;
    while(aux != NULL)
    {
        if((aux->dato %2) == 0)
        {
            LB=agregarLista(LB,aux->dato);
        }
        aux=aux->sig;        
    }
    return LB;
}

Lista determinaImpar(Lista LA, Lista LB)
{    
    Lista aux;
    aux=LA;
    while(aux != NULL)
    {
        if((aux->dato %2) != 0)
        {
            LB=agregarLista(LB,aux->dato);
        }
        aux=aux->sig;        
    }
    return LB;
}

Lista eliminaLista(Lista L, int elemento)
{
    Lista aux;
    aux=L;
    while(aux!=NULL)
    {
        if(elemento == aux->dato)
        {
            aux->ant->sig=aux->sig;
            aux->sig->ant=aux->ant;
            aux->sig=aux->ant=NULL;
        }
        aux=aux->sig;
    }
    if(aux==NULL)
    {
        printf("\nEl elemento no existe en la lista\n");
    }
    return L;
}