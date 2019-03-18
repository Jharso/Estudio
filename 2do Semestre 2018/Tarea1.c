#include<stdio.h>
#include<stdlib.h>

/*-------------------------------------------Estructuras----------------------------------*/
typedef struct ListaNodo
{
    int entero;
    struct ListaNodo *ant, *sig;    //puntero hacia un elemento de este mismo tipo (struct ListaNodo)
} *pListaNodo;

typedef struct
{
    pListaNodo primero, ultimo, ventana;
    int longitud;
}TLista, *Lista;              //Variables de esta estructura

typedef pListaNodo Ventana;
/*-------------------------------------------PROTOTIPOS----------------------------------*/

Lista iniciaLista(void);
void anexaNodoLista(Lista ,int );
void elimNodoLista(Lista);
void posLista(Lista, int);
void situarLista(Lista, Ventana);
Ventana ventanaLista(Lista);
void primLista(Lista);
int finLista(Lista);
void sigLista(Lista);
int infoLista(Lista);
void imprimirLista(Lista);
Lista copiarLista(Lista);
void concatenarLista(Lista, Lista);
void adicLista(Lista, int);
void sustelemLista(Lista, int);
void estaLista(Lista, int);
void imprimirListaPos(Lista);


/*--------------------------------------------Programa------------------------------------------*/

int main()
{
    int i;
    Lista lista1,lista2,lista3;   
    printf("*****************************TDA************************************\n");
    lista1=iniciaLista();      //importante

    //la siguiente función llena una lista x con el fin de demostrar el funcionamiento del TDA
    for(i=1;i<11;i++)
    {
        anexaNodoLista(lista1,i);
    }
    printf("\n");
    imprimirLista(lista1);

    posLista(lista1,9);
    elimNodoLista(lista1);
    imprimirLista(lista1);

    lista2=copiarLista(lista1);
    imprimirLista(lista2);
    
    concatenarLista(lista1,lista2);
    imprimirLista(lista1);

    posLista(lista1,10);
    sustelemLista(lista1,12);
    imprimirLista(lista1);

    estaLista(lista1,2);

    imprimirListaPos(lista1);

    return 0;
}

/*-------------------------------------MANEJO DE VENTANA----------------------------------------*/
void posLista(Lista lista, int pos)
{
    int i;
    for(lista->ventana=lista->primero, i=1; i<pos; i++)
    {
        lista->ventana=lista->ventana->sig;
    }
}

void situarLista(Lista lista, Ventana vent)
{
    lista->ventana=vent;
}

Ventana ventanaLista(Lista lista)
{
    return lista->ventana;
}

void primLista(Lista lista)
{
    lista->ventana=lista->primero;
}

void ultLista(Lista lista)
{
    lista->ventana=lista->ultimo;
}

int finLista(Lista lista)
{
    int i;
    if(lista->ventana==NULL)
    {
        i=1;
    }
    else
    {
        i=0;
    }
    return i;    
}

void sigLista(Lista lista)
{
    lista->ventana=lista->ventana->sig;
}

/*-----------------------------------Funciones constructoras-------------------------------------*/

Lista iniciaLista(void)
{
    Lista resp;
    resp=(Lista)malloc(sizeof(TLista));
    resp->primero=resp->ultimo=resp->ventana=NULL;
    resp->longitud=0;    

    return resp;
}

/*-----------------------------------Funciones modificadoras-------------------------------------*/
void anexaNodoLista(Lista lista, int elemento)
{   
    pListaNodo nuevo=(pListaNodo)malloc(sizeof(struct ListaNodo));
    nuevo->entero = elemento;
    nuevo->ant=nuevo->sig=NULL;
    if(lista->longitud==0)//lista vacía
    {
        lista->primero=lista->ultimo=nuevo;
    }
    else if(lista->ventana==lista->ultimo)//ventana en el último elemento
    {
        lista->ventana->sig=lista->ultimo=nuevo;
        nuevo->ant=lista->ventana;
    }
    else//ventana en elemento intermedio
    {
        nuevo->ant=lista->ventana;   
        nuevo->sig=lista->ventana->sig;
        lista->ventana->sig->ant=nuevo;
        lista->ventana->sig=nuevo;
    }    
    lista->ventana=nuevo;
    lista->longitud++;         
}

void elimNodoLista(Lista lista)
{
    printf("Eliminando nodo de lista\n");
    pListaNodo aux;
    if(lista->ventana==lista->primero)
    {
        if(lista->ultimo==lista->primero)
        {
            lista->ultimo=NULL;
        }
        lista->primero=lista->primero->sig;
        free(lista->ventana);
        lista->ventana=lista->primero;
    }
    else
    {
        if(lista->ultimo==lista->ventana)
        {
            lista->ultimo=lista->ultimo->ant;
        }
        lista->ventana->ant->sig=lista->ventana->sig;
        if(lista->ventana->sig!=NULL)
            {
                lista->ventana->sig->ant=lista->ventana->ant;   //"corta" la ventana y une los nodos laterales
            }        
        aux=lista->ventana;
        lista->ventana=lista->ventana->ant;
        free(aux);        
    }
    lista->longitud--;    
    printf("----------------------------------------------------------------\n\n");
}


/*-----------------------------------Funcion analizadora-------------------------------------*/
int infoLista(Lista lista)
{
    int aux;
    aux=lista->ventana->entero;
    return aux;
}

/*----------------------------------3 ejercicios resueltos-------------------------------------/
imprimir el contenido de una lista de enteros. La complejidad de esta rutina es O( n ), donde n es la longitud
de la lista.*/

void imprimirLista(Lista lista)
{
    if(lista->longitud==0)
    {
        printf("\nLa lista está vacía\n");
    }
    else
    {
        printf("Imprimiendo lista\n");
        for(primLista(lista);!finLista(lista);sigLista(lista))
            {        
                printf(" %d ",infoLista(lista));
            }
        printf("\nSe han impreso todos los elementos de la lista\n");
        printf("----------------------------------------------------------------\n\n");        
    }    
}

/*Hacer una copia de una lista. La complejidad de esta rutina es O( n ), donde n es la longitud de la lista.*/
Lista copiarLista(Lista lista)
{
    printf("Copiando lista\n\n");
    Lista resp=iniciaLista();
    for(primLista(lista);!finLista(lista);sigLista(lista))
    {
        anexaNodoLista(resp,infoLista(lista));
    }
    printf("----------------------------------------------------------------\n\n");
    return resp;
}
/*Concatenar dos listas listaA y listaB, dejando el resultado en la primera de ellas. La complejidad de esta rutina es
O( m ), donde m es la longitud de la segunda lista.*/
void concatenarLista(Lista listaA, Lista listaB)
{
    printf("Concatenando elementos de la lista\n");
    ultLista(listaA);
    for(primLista(listaB);!finLista(listaB);sigLista(listaB))
    {
        anexaNodoLista(listaA,infoLista(listaB));
    }
    printf("----------------------------------------------------------------\n\n");
}

/*-------------------------------------- 4 Ejercicios propuestos --------------------------------*/

void adicLista(Lista lista,int elemento) //Adiciona el elemento al final de la lista.
{
    ultLista(lista);
    anexaNodoLista(lista, elemento);
}

void sustelemLista(Lista lista,int elemento)//sustituye elemento donde se encuentra la ventana.
{
    elimNodoLista(lista);    
    printf("Sustituyendo elemento de la lista\n");
    anexaNodoLista(lista, elemento);
    printf("----------------------------------------------------------------\n\n");
}

void estaLista(Lista lista,int elemento)//Devuelve información sobre elemento consultado.
{
    int aux=0;
    for(primLista(lista);!finLista(lista);sigLista(lista))
    {
        if(infoLista(lista)==elemento)
        {
            aux=aux+1;
        }                
    }
    if(aux>0)
    {
        printf("El elemento %d está contenido %d veces en la lista\n\n",elemento,aux);
    }
    else
    {
        printf("El elemento no está contenido en la lista\n\n");
    }
    printf("----------------------------------------------------------------\n\n");
}

void imprimirListaPos(Lista lista)//imprime elemento utilizando la función de posición de ventana.
{
    int i;
    printf("imprimiendo lista utilizando la función 'posLista' para avanzar\n");
    for(primLista(lista),i=1;!finLista(lista);i++,posLista(lista,i))
    {
        printf(" %d ",infoLista(lista));
    }
    printf("\n----------------------------------------------------------------\n\n");
}

/*----------------------------------------------------------------------------------------------------------*/


//Rodrigo Jaramillo Solar
//Universidad de la Serena.