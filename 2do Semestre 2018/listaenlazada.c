#include <stdio.h>
#include <stdlib.h>

typedef struct nodostruct{
    int dato;
    struct nodostruct *siguiente;
};

struct nodostruct agregar(struct nodostruct ,struct nodostruct *,struct nodostruct *);

int main(){
    struct nodostruct *primer = NULL;
    struct nodostruct *ultimo = NULL;
    struct nodostruct *primerNodo = malloc(sizeof(struct nodostruct));
    primerNodo -> dato = 5;

    struct nodostruct *segundoNodo = malloc(sizeof(struct nodostruct));
    segundoNodo -> dato = 7;

    printf("%i\n", primerNodo->dato);

    agregar(primerNodo,&primer,&ultimo);
    agregar(segundoNodo,&primer,&ultimo);

    struct nodostruct *i = primerNodo;   
    while(i != NULL){
        printf("%i\n", i->dato);
        i = i -> siguiente;         
    }
    
    return 0;
}

struct nodostruct agregar(struct nodostruct agregado,struct nodostruct *first,struct nodostruct *last){

    //agregado -> siguiente = NULL;
    printf("%i\n", first->dato);

    if(first == NULL){
        first = agregado;
        printf("%i\n", first->dato);
        last = agregado;
        printf("%i\n", last->dato);
    }else{
         printf("prueba 2 \n");
        last -> siguiente = agregado;
        last = agregado;
    }
    
}