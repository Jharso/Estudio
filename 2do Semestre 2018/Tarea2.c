#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct
{ 
    int tope;
    int info[max];
} TPila, *Pila;

typedef struct
{
    int info[max]; /* Vector circular */
    int primero; /* Posición del primer elemento */
    int ultimo; /* Posición del último elemento */
} TCola, *Cola;

/*---------------------------------PROTOTIPOS PILA----------------------------------*/

Pila inicPila(void );
void adicPila(Pila ,int );
void elimPila(Pila );
int infoPila(Pila );
int vaciaPila(Pila );
void destruirPila(Pila );
void imprimirPila(Pila );

/*---------------------------------PROTOTIPOS COLA----------------------------------*/

Cola inicCola(void );
void adicCola(Cola ,int );
void elimCola(Cola );
int infoCola(Cola );
int vaciaCola(Cola );
void destruirCola(Cola );
void imprimirCola(Cola );

/*----------------------------------PROGRAMA----------------------------------------*/

int main()
{
    int i;
    Pila pila1;
    Cola cola1;
    
    printf("\n*******************PILA*********************\n");
    pila1=inicPila();    
    for(i=0;i<max;i++)//For para llenar pila con fines demostrativos
    {
        adicPila(pila1,(i+1)*10);
    }
    
    imprimirPila(pila1);
    printf("\n");

    elimPila(pila1);      
    imprimirPila(pila1);
    
    printf("\n");
    printf("Elemento en tope: %d\n",infoPila(pila1));

    vaciaPila(pila1);
    imprimirPila(pila1);

    destruirPila(pila1);
    imprimirPila(pila1);//imprime basura en la dirección de memoria donde se guardaba el tope

    /*-----------------------------------------------------------------------------*/

    printf("\n*******************COLA*********************\n");
    cola1=inicCola();
    for(i=0;i<5;i++)//For para llenar Cola con fines demostrativos
    {
        adicCola(cola1,(i+1)*10);
    }
    
    imprimirCola(cola1);
    printf("\n");

    elimCola(cola1);      
    imprimirCola(cola1);
    
    printf("\n");
    printf("Primer Elemento: %d\n",infoCola(cola1));

    vaciaCola(cola1);
    imprimirCola(cola1);

    destruirCola(cola1);
    imprimirCola(cola1);

    return 0;
}

/*---------------------------------------TDA PILA-----------------------------------*/

Pila inicPila(void)
{
    Pila pil=(Pila)malloc(sizeof(TPila));
    pil->tope=0;
    return pil;
}

void adicPila(Pila pil,int elemento)
{
    pil->info[pil->tope++]=elemento;
}

void elimPila(Pila pil)
{
    pil->tope--;
}

int infoPila(Pila pil)
{
    return pil->info[pil->tope-1];
}

int vaciaPila(Pila pil)
{
    printf("\nVaciando pila\n");
    return pil->tope=0;
}

void destruirPila(Pila pil)
{
    printf("\nDestruyendo pila\n");
    free(pil);
}

/*---------------------------------------TDA COLA-----------------------------------*/

Cola inicCola( void )
{
    Cola col = (Cola)malloc(sizeof(TCola));
    col->primero=col->ultimo=-1;
    return col;
}

void adicCola(Cola col, int elemento)
{
    if( col->primero == -1 )
    { 
        col->info[0]=elemento;
        col->primero=col->ultimo=0;
    }
    else
    { 
        col->ultimo=(col->ultimo+1)%max;
        col->info[col->ultimo]=elemento;
    }
}

void elimCola(Cola col)
{
    if(col->primero==col->ultimo)
    {
        col->primero=col->ultimo=-1;
    }
    else
    {
        col->primero=(col->primero+1)%max;
    }
}

int infoCola(Cola col)
{ 
    return col->info[col->primero];
}

int vaciaCola(Cola col)
{
    printf("\nVaciando cola\n");
    col->primero=-1;
    col->ultimo=-1;
    return col->primero && col->ultimo;
}

void destruirCola(Cola col)
{
    printf("\nDestruyendo cola\n");
    free(col);
}

/*--------------------------------FUNCIÓN IMPRIMIR CON FIN DEMOSTRATIVO-------------------*/

void imprimirPila(Pila pil)
{
    int i;
    printf("\nImprimiendo\n");
    printf("valor de tope: %d\n",pil->tope);
    for(i=pil->tope;i>0;i--)//para no interferir con la estructura de la pila no se utilizan funciones del tda pila para imprimir
    {
        printf(" %d \n",pil->info[i-1]);
    }
}

void imprimirCola(Cola col)
{
    printf("\nImprimiendo\n");
    int i;
    for(i=col->primero;i<col->ultimo+1;i++)
    {
        printf("%d \n",col->info[i]);
    }
}

//Rodrigo Jaramillo Solar
//Universidad de la Serena.