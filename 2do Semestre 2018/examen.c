#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo
{
	int dato;
	struct nodo *ant, *sgte;
} *lista;

lista agregar(lista,int);
lista crear_lista(lista);

void imprimir_lista(lista);

void main()
{
	lista L=NULL;
	L =crear_lista(L);
	imprimir_lista(L);
	lista aux, L1,L2;
    L1=NULL;
    L2=NULL;
	aux=L;
	while(aux!=NULL)
    {
		if((aux->dato %2) ==0)
        {
            printf("par %i ",aux->dato); 
            L1 = agregar(L1,aux->dato);
        }
		else
        {
            printf("impar %i ",aux->dato);
            L2 = agregar(L2,aux->dato);
        }
		aux = aux->sgte;
	}
	imprimir_lista(L1);
	imprimir_lista(L2);
}

lista crear_lista(lista L)
{
	int valor,contador = 1;
	srand(time(NULL));
	while (contador<=10)
    {
		valor = rand()%100;
		printf("\nvalor = %i \n", valor);
		L=agregar(L,valor);//imprimir_lista(L);
		contador = contador + 1;
	}
	return(L);
}

lista agregar(lista L,int valor)
{
	lista laux,flag, aux;
    aux = (lista)malloc(sizeof(struct nodo));
	aux->dato = valor;
    aux->ant=aux->sgte=NULL;
	if (L == NULL)
    {
        L=aux;//si la lista está vacía
    }
	else
    {
		laux = L;
        flag = NULL;
		while(laux != NULL)
        {
			if (laux->dato > valor)
            {
				if (laux->ant ==NULL)
                {
					laux->ant = aux;
                    aux->sgte = laux; 
                    L = aux;
                    laux =NULL;
                }
				else
                {
                    (laux->ant)->sgte = aux; 
                    aux->ant = laux->ant;
                    laux->ant = aux; 
                    aux->sgte = laux;
                    laux = NULL;
                }
            }
			else
            {
                flag = laux; 
				laux = laux->sgte;
            }
		}
		if(flag!=NULL)
        {
            flag->sgte = aux; 
            aux->ant = flag;
        }
	}
	//imprimir_lista(L);
	return(L);
}

void imprimir_lista(lista L)
{
	lista aux;
	aux = L;
    printf("\n LISTA\n");
	while(aux!=NULL)
    {	
		printf("%i ",aux->dato);
		aux = aux->sgte;
	}
	printf("\n");
}
