/*archivo con funciones relacionadas al tda de la estructura*/

typedef struct lista{
  int tamano, max, cantidad;
  int *datos;
} ListaNumeros;

ListaNumeros *creaListaNumerosVacia(int tamano);
ListaNumeros *creaListaNumerosLlena(int tamano, int max);  //retorna un puntero a de lista
int eliminaListaNumeros(ListaNumeros *lista);
int buscaNumeroEnListaNumeros(ListaNumeros *lista, int elemento); //retorna -1 si no encuentra el elemento

ListaNumeros *creaListaNumerosVacia(int tamano){
  ListaNumeros *lista;
  lista=malloc(sizeof(ListaNumeros));
  lista->tamano=tamano;
  lista->max=lista->cantidad=0;
  lista->datos=(int *)malloc(sizeof(int)*tamano);
  return (lista);  
}

ListaNumeros *creaListaNumerosLlena(int tamano, int max){
  ListaNumeros *lista=creaListaNumerosVacia(tamano);

}