#include<stdio.h>
#include<stdlib.h>
#define alumnos 1
#define datos 6


void ingresarnotas(float [alumnos][datos]);
void calcularponderado(float [alumnos][datos]);
void imprimirarreglo(float [alumnos][datos]);
void detallenotas(float [alumnos][datos]);
void busqueda(float [alumnos][datos]);

int main(){
    int id;
    float notas[alumnos][datos];
    ingresarnotas(notas);
    calcularponderado(notas);
    imprimirarreglo(notas);

    return 0;
}

void ingresarnotas(float notas[alumnos][datos]){
  int i=0,j=1,iden=1800;
  printf("\nIngrese los datos de los %i alumnos\n", alumnos);
  while(i<alumnos){
      notas[i][0]=iden+1;
      printf("\nIngrese las notas para el alumno ID: %f\n", notas[i][0]);
      printf("Lenguaje: ");
      scanf("%f", &notas[i][j]);
      printf("Matemáticas: ");
      scanf("%f", &notas[i][j+1]);
      printf("Ciencias: ");
      scanf("%f", &notas[i][j+2]);
      printf("Nem: ");
      scanf("%f", &notas[i][j+3]);
      i++;
      iden++; 
    }

}

void calcularponderado(float notas[alumnos][datos]){
    int i=0,j=1,k=0;
    float ponderados[4]={25,35,10,30};
    while(j<datos-1){                                      
        
        while(i<alumnos){
            notas[i][5]=((notas[i][j]*ponderados[k])/100)+notas[i][5];
            i++;
        }
        i=0; 
        j++;
        k++;
    }

}

void imprimirarreglo(float notas[alumnos][datos]){
    int i=0,j,k;
        printf("\n#ID    # Lenguaje # Mate  # Ciencia # Nem   # Ponderado \n");
    while(i<alumnos){
        printf("%.1f - %.1f    - %.1f - %.1f   - %.1f - %.1f  \n",notas[i][0],notas[i][1],notas[i][2],notas[i][3],notas[i][4],notas[i][5]);
        i++;
    }
}

void detallenotas(float notas[alumnos][datos]){
    int i=0,j=0;
    //esta funcion se encarga de seleccionar entre todos los alumnos los 10 mejores y 10 peores ponderados, el mejor y peor en cada prueba
    
}

void busqueda(float notas[alumnos][datos]){
//hacer busqueda binaria para arrojar notas buscando por ID
}