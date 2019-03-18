#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------Estructuras LISTA----------------------------*/
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

/*-------------------------------------------Estructuras PILA Y COLA---------------------*/

typedef int TipoL;
typedef Lista Pila;

typedef int TipoL;
typedef Lista Cola;

/*-------------------------------------------PROTOTIPOS LISTA----------------------------*/

Lista iniciaLista(void);
void anexaNodoLista(Lista ,int );
void insLista(Lista, int );
void elimNodoLista(Lista);
void destruirLista(Lista);
void posLista(Lista, int);
void situarLista(Lista, Ventana);
Ventana ventanaLista(Lista);
void primLista(Lista);
void ultLista(Lista);
int finLista(Lista);
void sigLista(Lista);
int infoLista(Lista);
int longLista(Lista);
void imprimirLista(Lista);
Lista copiarLista(Lista);
void concatenarLista(Lista, Lista);
void adicLista(Lista, int);
void sustelemLista(Lista, int);
void estaLista(Lista, int);
void imprimirListaPos(Lista);

void invLista(Lista);

/*-------------------------------------------PROTOTIPOS PILA------------------------------*/

Pila inicPila(void);
void adicPila(Pila, int );
void elimPila(Pila);
int infoPila(Pila);
int vaciaPila(Pila);
void destruirPila(Pila);
void imprimirPila(Pila);

Pila copiarPila(Pila);
void invPila(Pila);
int igualesPilas(Pila, Pila );

/*-------------------------------------------PROTOTIPOS COLA------------------------------*/

Cola inicCola(void);
void adicCola(Cola , int );
void elimCola(Cola );
int infoCola(Cola );
int vaciaCola(Cola );
void destruirCola(Cola);
void imprimirCola(Cola );

/*-----------------------------MAIN-----------------------------*/

int main()
{
    Lista lista1;
    lista1=iniciaLista();
    
    anexaNodoLista(lista1,2);
    anexaNodoLista(lista1,4);
    anexaNodoLista(lista1,23);
    anexaNodoLista(lista1,243);
    imprimirLista(lista1);

    invLista(lista1);
    imprimirLista(lista1);

    Pila pila1,pila2;
    pila1=inicPila();
    adicPila(pila1,2);
    adicPila(pila1,3);
    adicPila(pila1,4);
    adicPila(pila1,5);
    imprimirPila(pila1);

    printf("\n****Pila1\n");
    imprimirPila(pila1);

    pila2=copiarPila(pila1);
    printf("\n****Pila2\n");
    imprimirPila(pila2);
    igualesPilas(pila1,pila2);

    invPila(pila2);
    imprimirPila(pila2);

    igualesPilas(pila1,pila2);
    
    return 0;
}

/*-----------------------------TDA PILA DINÁMICO----------------*/

Pila inicPila(void)
{
    return iniciaLista();
}

void adicPila(Pila pila, int elemento)
{
    primLista(pila);
    insLista(pila,elemento);
}

void elimPila(Pila pila)
{
    primLista(pila);
    elimNodoLista(pila);
}

int infoPila(Pila pila)
{
    primLista(pila);
    return infoLista(pila);
}

int vaciaPila(Pila pila)
{
    pila->longitud=0;    
    return longLista(pila);
}

void destruirPila(Pila pila)
{
    destruirLista(pila);
}

void imprimirPila(Pila pila)
{
    imprimirLista(pila);
}

/*-----------------------------TDA COLA DINÁMICO----------------*/

Cola inicCola(void)
{
    return iniciaLista();
}

void adicCola(Cola cola,int elemento)
{
    ultLista(cola);
    anexaNodoLista(cola,elemento);
}

void elimCola(Cola cola)
{
    primLista(cola);
    elimNodoLista(cola);    
}

int infoCola(Cola cola)
{
    primLista(cola);
    return infoLista(cola);
}

int vaciaCola(Cola cola)
{
    cola->longitud=0;
    return longLista(cola);
}

void destruirCola(Cola cola)
{
    destruirLista(cola);
}

void imprimirCola(Cola cola)
{
    imprimirLista(cola);
}

/*-------------------------------------TDA LISTAS(Manejo de ventana)-------------------------------*/
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

void insLista(Lista lista, int elemento)
{   
    pListaNodo nuevo=(pListaNodo)malloc(sizeof(struct ListaNodo));
    nuevo->entero = elemento;
    nuevo->ant=nuevo->sig=NULL;
    if(lista->longitud==0)//lista vacía
    {
        lista->primero=lista->ultimo=nuevo;
    }
    else if(lista->ventana==lista->primero)//ventana en el primer elemento
    {
        lista->ventana->ant=lista->primero=nuevo;
        nuevo->sig=lista->ventana;
    }
    else//ventana en elemento intermedio(no se aplica en pilas ni colas por la naturaleza de la estructura)
    {
        nuevo->sig=lista->ventana;   
        nuevo->ant=lista->ventana->ant;
        lista->ventana->ant->sig=nuevo;
        lista->ventana->ant=nuevo;
    }    
    lista->ventana=nuevo;
    lista->longitud++;         
}

void elimNodoLista(Lista lista)
{
    //printf("Eliminando nodo de lista\n");
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
}

/*-----------------------------------Funcion destructora-------------------------------------*/
void destruirLista(Lista lista)
{
    pListaNodo p,q;
    for(p=lista->primero;p!=NULL;)//esta iteración va eliminando nodo por nodo hasta que encuentre un nodo vacío
    {
        q=p;
        p=p->sig;
        free(q);
    }
    
    free(lista);
}

/*-----------------------------------Funcion analizadora-------------------------------------*/
int infoLista(Lista lista)
{
    int aux;
    aux=lista->ventana->entero;
    return aux;
}

int longLista(Lista lista)
{
    return lista->longitud;
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


/*--------------------------------------4 Ejercicios propuestos --------------------------------*/

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

/*------------------------------------------------------------------EJERCICIOS TAREA 4----------------------------------------
Invertir una lista utilizando una pila. La complejidad de esta rutina es O( n ), donde n es el número de
componentes de la lista.*/

void invLista(Lista lista)
{
    Pila pila=inicPila();
    for(primLista(lista);!finLista(lista);elimNodoLista(lista))
    {
        adicPila(pila,infoLista(lista));
    }
    for(;longLista(pila)!=0;elimPila(pila))
    {
        anexaNodoLista(lista,infoPila(pila));
    }
    destruirPila(pila);
}

/*Copiar una pila. Esta rutina debería ser una operación del TAD, puesto que su implementación sobre las
operaciones existentes es un poco dispendiosa, aunque perfectamente posible. La complejidad de esta
función es O( n ), donde n es la longitud de la pila.*/

Pila copiarPila(Pila pila)
{
    Pila resp=inicPila();
    Lista lista;
    for(lista=iniciaLista();longLista(pila)!=0;elimPila(pila))
    {
        insLista(lista,infoPila(pila));
    }
    for(primLista(lista);!finLista(lista);elimNodoLista(lista))
    {
        adicPila(pila, infoLista(lista));
        adicPila(resp, infoLista(lista));
    }
    destruirLista(lista);
    return resp;
}

/*Invertir el contenido de una pila. La complejidad de esta rutina es O( n ), donde n es el número de elementos
de la estructura.*/

void invPila(Pila pila)
{
    Pila aux=copiarPila(pila);
    destruirPila(pila);
    for(pila=inicPila();longLista(aux)!=0;elimPila(aux))
    {
        adicPila(pila,infoPila(aux));
    }
    destruirPila(aux);
}

/*Decidir si dos pilas son iguales sin destruir su contenido. Esta rutina también debería hacer parte de las
operaciones del TAD Pila. Su implementación resulta poco natural, pero se utiliza en este ejemplo para
ilustrar el uso de las operaciones.*/

int igualesPilas(Pila pilaA, Pila pilaB)
{
    Pila aux1=copiarPila(pilaA);
    Pila aux2=copiarPila(pilaB);
    while(longLista(aux1)!=0 && longLista(aux2)!=0)
    {
        if(infoPila(aux1)!=infoPila(aux2))
        {
            destruirPila(aux1);
            destruirPila(aux2);
            printf("\nPilas distintas\n");
            return 0;
        }
        elimPila(aux1);
        elimPila(aux2);
    }
    if(longLista(aux1)==0 && longLista(aux2)==0)
    {
        printf("\nPilas iguales\n");
        return 1;
    }
    else
    {
        destruirPila(aux1);
        destruirPila(aux2);
        return 0;
    }    
}

//Rodrigo Jaramillo Solar
//Universidad de la Serena.