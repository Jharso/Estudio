#include "medir_tiempo.h"

int main(){
	int  tiempo = 0;
	ListaNumero *lista;//correcto
	lista=crearlistallena(10, 10);//correcto
	mergesort( lista, 0,10);//lista de tamano 10
	//tiempo = promedio_caso_azar(lista);
	printf("%i",lista->arreglo[9]);
	return 0 ;
} 
