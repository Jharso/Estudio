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

int main()
{
    Lista L1,L2,L3;
    int i,a,n;
    srand(time(NULL));
    printf("\nIngrese la cantidad de elementos a generar.\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        L1=agregarLista(L1,rand()%100);
    }
    L2=L3=NULL;
    imprimirLista(L1);
    //L2=determinaPar(L1,L2);
    //L3=determinaImpar(L1,L3);

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

/*Lista determinaPar(Lista LA, Lista LB)
{    
    Lista aux;
    aux=LA;
    while(aux != NULL)
    {
        if((aux->dato %2) == 0)
        {
            agregarLista(LB,aux->dato);
        }
        aux=aux->sig;        
    }
    return LB;
}*/