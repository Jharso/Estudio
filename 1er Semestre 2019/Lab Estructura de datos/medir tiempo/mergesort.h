                    /*modulos en .h*/

void mergesort(int arreglo[],int primera,int ultima);
void ordenar(int arreglo[],int primera,int mid,int ultima);


 /*primera indica la primera posicion del arreglo
    ultima indica la ultima posicion del arreglo */

void mergesort(int arreglo[],int primera,int ultima){
    int mid = 0;
    if(primera!=ultima){
        mid = ((primera+ultima)/2);
        mergesort(arreglo,primera,mid);
        mergesort(arreglo,mid+1,ultima);
        ordenar(arreglo,primera,mid,ultima);
    }
}



   /* i j z indices  de los arreglos para poder
    avanzar sin modificar posiciones primera mid ultima*/

void ordenar(int arreglo[],int primera,int mid,int ultima){
    int i = 0 ,j = 0,z = 0;
    int *aux;
    aux = malloc(sizeof(int)*(ultima-primera));//cuidadp tamanos del arreglo
    while(z<=(ultima-primera)){
        if(arreglo[i+primera] <= arreglo[j+(mid+1)]&&(i<=(mid-primera))){   // comprueba que no avanze de mas en el arreglo
            aux[z] = arreglo[i+primera];
            i++;
        }else{
            if(j<=(ultima-(mid+1))){
                aux[z] = arreglo[j+(mid+1)];
                j++;
            }else{
                aux[z] = arreglo[i+primera];
                i++;
            }
        }
        z++;
    }
    z = 0;
    for(z=0;z<= (ultima-primera);z++){
        arreglo[primera+z] = aux[z];
    }
    free(aux);
}
