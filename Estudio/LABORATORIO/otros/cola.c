//TDA COLA ESTATICA	
#include <stdio.h>
#include <stdlib.h>
#define max 100 //macro

void iniciar_cola(struct col *q);
void imprimir(struct col q);
void agregar(struct col *q, int elemento);
void destruir_cola(struct col);
void cola_vacia(struct col);

typedef struct cola{
	int info[max];
	int primero;
	int ultimo;
}*col;

//iniciar cola
void iniciar_cola(struct col *q){
	int i;
	*q=(col)malloc(sizeof(struct cola)); //busca la memoria
	(*q)->primero=-1; //para saber si el primero es -1 (que no exista)
	(*q)->ultimo=-1; //para saber si el ultimo es -1 (no existe)
	i=0; //contador
	while(i<max){ //si el contador es 
		(*q)->info[i]=-1;
		i++;
	}
}

//imprimir cola
void imprimir(struct col q){
	int i=q->primero;
	while(i<=q->ultimo){
		printf("%i\n", (q)->info[i]);
	}
}
//agregar elemento a la cola
void agregar(struct col *q, int elemento){
	if((*q)->ultimo==max-1){
		if((*q)->info[0]==-1){
			(*q)->ultimo=0;
			(*q)->info[0]=elemento;
		}
	}
	else{
		if(is_empty(*q)==0){
			if((*q)->info[((*q)->ultimo)+1]==-1){
				((*q)->ultimo)++;
				elemento[(*q),*ultimo]=elemento;
			}
		}
	}
}
		
//vaciar o destruir cola
void destruir_cola(struct col){
	free(*q);
}

//verificar si la cola esta vacia
void cola_vacia(struct col){
	if(is_empty(q)==0){
		printf("\nLa cola se encuentra vacia\n");
	}
	else{
		printf("\nLa cola no se encuentra vacia\n");
	}
}

int main(){
int opc=1;
	printf("\nIngrese la opcion al siguiente menu: \n");
	printf("\n1.- Iniciar la cola\n");
	printf("\n2.- Imprimir cola\n");
	printf("\n3.- Vaciar cola\n");
	printf("\n4.- Verificar si esta vacia\n");
	printf("\n5.- Agregar elemento\n");
	printf("\n6.- Salir\n");
	scanf("%i", &opc);
	if(opc==1){
		iniciar_cola(struct col *q); //iniciar cola
	}
	if(opc==2){
		imprimir(struct col q); //imprimir la cola
	}
	if(opc==3){
		destruir_cola(struct col); //vaciar la cola
	}
	if(opc==4){
		cola_vacia(struct col); //verificar si la cola esta vacia
	}
	if(opc==5){
		agregar(struct col *q, int elemento); //agregar un elemento a la cola
	}
	if(opc==6){
	
	}
}
