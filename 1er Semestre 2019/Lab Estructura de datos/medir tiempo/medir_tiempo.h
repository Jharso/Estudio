#include"listanumero2.h"	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec tInicio, tFin;

FILE *op;
/*-----------------modulos necesarios dentro de otros---------------*/
void mergesort(ListaNumero *lista,int primera,int ultima);
void ordenar(ListaNumero *lista,int primera,int mid,int ultima);
double medir_tiempo_segundos(ListaNumero *lista,int tam);
void anadir(double promedio);			//anade a un archivo un dato del tipo float
double medir_tiempo_peor_caso(ListaNumero *lista); //recorre un arreglo entero y retorna tiempo en nano segundos
double medir_tiempo(ListaNumero *lista,int tam);	//recorre un arreglo hasta encontra el numero que necesita y retorna tiempo en nano segundos

/*--------------- constantes --------------------------------------*/

#define tam_promedio 1000		//tamano de arreglos de tamanos iguales para la repeticion
#define Numero_iteraciones 100		//se usa en los bucles de promedio
#define Numero_iteraciones_max 1000	//se usa en el modulo de los max casos

/*-----------------------------------------------------------------*/

double promedio_caso_azar(ListaNumero *aux){
	int i = 1;double promedio = 0 , tiempo_busqueda = 0;
	while(i<=Numero_iteraciones)
	{
	 	aux = crearlistallena((tam_promedio),tam_promedio);//inicializa lista y la llena
		tiempo_busqueda = medir_tiempo(aux,(tam_promedio));
		promedio += tiempo_busqueda;			// se suma el tiempo de busqueda de una iteracion para generar un promedio
		i++;
	}
	promedio = (promedio/Numero_iteraciones);		//divide la sumatoria de los tiempo de busqueda y los divide para sacar el promedio
	return(promedio);				
}


/*-----------------------------------------------------------------*/

double promedio_peor_caso(ListaNumero *aux){
	int i = 1;double promedio = 0 , tiempo_busqueda = 0;
	while(i<=Numero_iteraciones){
		aux = crearlistallena((tam_promedio),tam_promedio);//inicia y llena lista
		tiempo_busqueda = medir_tiempo_peor_caso(aux);	//asigna a tiempo_busqueda el valor en nano segundo retornado por medir_tiempo..
		promedio += tiempo_busqueda;			//esto entrega el promedio de las 10 busqueda caso peor
		i++;
	}
	promedio = (promedio/Numero_iteraciones);
	return(promedio);
}

/*-----------------------------------------------------------------*/

void repeticion_de_mediciones(ListaNumero *aux){
	int i = 1;double tiempo_busqueda;
	while(i<=Numero_iteraciones_max )//total de datos que queremos
	{
		aux = crearlistallena((i*tam_promedio),(i*tam_promedio));	//inicia y llena la lista con valores que con cada iteracion aumenta 
		tiempo_busqueda = /*medir_tiempo_segundos(aux,i*10000);*/medir_tiempo(aux,(i*tam_promedio));	//tiempo de busqueda en un arreglo
		anadir(tiempo_busqueda);			//se guarda el tiempo de busqueda en un archivo
		i++;						//avanzo en el bucle
	}
}

/*----------------------------------------------------------------*/

void crear()
{
	op=fopen("datosdetiempo.txt","w");
	if(op==NULL)
	{
		printf("error al crear archivo\n");
	}
	else
	{
		printf("el archivo a sido creado correctamete\n");
	}
	fclose(op);
}

/*-----------------------------------------------------------------*/

double medir_tiempo_peor_caso(ListaNumero *lista)
{
	int num = (tam_promedio+2);//numero que nunca estara en el arreglo
	double tiempo_de_ejecucion;
	int resultado_busqueda = 0;
	clock_gettime(CLOCK_REALTIME,&tInicio);
	resultado_busqueda=buscaNumeroEnListaNumeros(lista,num);
	clock_gettime(CLOCK_REALTIME,&tFin);
	eliminaListaNumero(lista);
	tiempo_de_ejecucion=(tFin.tv_nsec-tInicio.tv_nsec);
	return (tiempo_de_ejecucion);
}

/*------------------------------------------------------------------*/

double medir_tiempo(ListaNumero *lista,int tam)
{
	double tiempo_de_ejecucion;
	int num = 0;
	srand(time(NULL));
	num = rand()%(tam);
	int resultado_busqueda=0;
	clock_gettime(CLOCK_REALTIME,&tInicio);
	resultado_busqueda=buscaNumeroEnListaNumeros(lista,num);
	clock_gettime(CLOCK_REALTIME,&tFin);
	eliminaListaNumero(lista);
	tiempo_de_ejecucion=(tFin.tv_nsec-tInicio.tv_nsec);
	return (tiempo_de_ejecucion);
}

/*-----------------------------------------------------------------*/

void anadir(double promedio)
{
	op=fopen("datosdetiempo.txt","a");	/*abre el archivo en modo anadir*/
	if(op==NULL){
		printf("ERROR!!!!! al buscar archivo\n");
	}else{
		fprintf(op,"%lf,",promedio);	/*anade al archivo sin saltar linea un numero flotante*/
	}
	fclose(op);	
}	

/*-----------------------------------------------------------------*/

void anadir_tam_arreglo_en_el_archivo()
{
	int i = 1;
	op=fopen("datosdetiempo.txt","a");	/*abre el archivo en modo anadir*/
	while(i<=Numero_iteraciones_max){
		if(op==NULL){
			printf("ERROR!!!!! al buscar archivo\n");
		}else{
			fprintf(op,"%i,",(i*tam_promedio));	/*anade al archivo sin saltar linea un numero entero (tamano de los arreglos)*/
		}
		i++;
	}
	fprintf(op,"\n");
	fclose(op);	
}
	
double medir_tiempo_segundos(ListaNumero *lista,int tam)
{
	double tiempo_de_ejecucion;
	int num = 0;
	srand(time(NULL));
	num = rand()%(tam);
	int resultado_busqueda=0;
	clock_gettime(CLOCK_REALTIME,&tInicio);
	resultado_busqueda=buscaNumeroEnListaNumeros(lista,num);
	clock_gettime(CLOCK_REALTIME,&tFin);
	eliminaListaNumero(lista);
	tiempo_de_ejecucion=(tFin.tv_sec-tInicio.tv_sec);
	return (tiempo_de_ejecucion);
}

void mergesort(ListaNumero *lista,int primera,int ultima){
    int mid = 0;
    if(primera!=ultima){
        mid = ((primera+ultima)/2);
        mergesort(lista,primera,mid);
        mergesort(lista,mid+1,ultima);
        ordenar(lista,primera,mid,ultima);
    }
}

void ordenar(ListaNumero *lista,int primera,int mid,int ultima){
    int i = 0 ,j = 0,z = 0;
    int *aux;
    aux = malloc(sizeof(int)*(ultima-primera));//cuidadp tamanos del arreglo
    while(z<=(ultima-primera)){
        if(lista->arreglo[i+primera] <= lista->arreglo[j+(mid+1)]&&(i<=(mid-primera))){   // comprueba que no avanze de mas en el arreglo
            aux[z] = lista->arreglo[i+primera];
            i++;
        }else{
            if(j<=(ultima-(mid+1))){
                aux[z] = lista->arreglo[j+(mid+1)];
                j++;
            }else{
                aux[z] = lista->arreglo[i+primera];
                i++;
            }
        }
        z++;
    }
    z = 0;
    for(z=0;z<= (ultima-primera);z++){
        lista->arreglo[primera+z] = aux[z];
    }
    free(aux);
}


