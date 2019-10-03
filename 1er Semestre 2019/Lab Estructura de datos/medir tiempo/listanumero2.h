typedef struct Lista {
	int cantidad,longitud;
	int *arreglo;
}ListaNumero;

ListaNumero* crearlistavacia(int tamano){

	ListaNumero* aux = (ListaNumero *)malloc(sizeof(struct Lista));
	aux->cantidad=0;
	aux->longitud=tamano;
	aux->arreglo = (int*)malloc(tamano* sizeof(int));
	//printf("lista vacia creada\n");
	return aux;
}
ListaNumero* crearlistallena(int tamano , int max){
	ListaNumero* temp = crearlistavacia(tamano);
	int i;
	srand(time(NULL));
	for(i=0;i<tamano;i++){
		temp->arreglo[i]=1+rand()%max;
	}
	//printf("lista llena creada\n");
	return temp ;
}
int buscaNumeroEnListaNumeros (ListaNumero* Llena,int unNumero){
	int i;
	for(i=0 ; i<Llena->longitud ; i++){
		if(Llena->arreglo[i] == unNumero){
			return i;
		}
	}
	return -1;
}
int eliminaListaNumero(ListaNumero* Llena){
	free(Llena->arreglo);
	free(Llena);
	//printf(" Lista Eliminada");
	return 0;
}
void print(ListaNumero* Llena ){
	int j ;
	for (j=0 ; j<Llena->longitud; j++){
		printf(" %d-",Llena->arreglo[j]);
	}
	printf("\n");
}


  

