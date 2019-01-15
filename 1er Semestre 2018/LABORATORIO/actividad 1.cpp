#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define alumno 5
#define curso 4
#define ano 2

void LlenarNotas(int notas[ano][curso][alumno]);

void Mejor_Prom_ID(int mejor_prom_ID[ano][2], int notas[ano][curso][alumno]);
void ImprimirMejor(int mejor_prom_ID[ano][2]);

void IniciarA71(int peor_prom_ID[ano][2]);
void Peor_Prom_ID(int peor_prom_ID[ano][2], int notas[ano][curso][alumno]);
void ImprimirPeor(int peor_prom_ID[ano][2]);

void ImprimirNotas(int notas[ano][curso][alumno]);

int main()
{
	int notas[ano][curso][alumno], mejor_prom_ID[ano][2] = {{0}}, peor_prom_ID[ano][2];

	LlenarNotas(notas);

	Mejor_Prom_ID(mejor_prom_ID, notas);
	ImprimirMejor(mejor_prom_ID);


	Peor_Prom_ID(peor_prom_ID, notas);
	ImprimirPeor(peor_prom_ID);

	
    ImprimirNotas(notas);
}

void LlenarNotas(int notas[ano][curso][alumno])
{
	int i, j, k;
    
    srand (time(NULL));
    
    i = 0;
    while(i < ano)
	{
    	j = 0;
        while(j < curso)
		{
        	k = 0;
       		while(k < alumno)
			{
        		notas[i][j][k]=rand()%61+10;
                k ++; 
        	}
            j++;
        }
    	i++;
    }
}

void Mejor_Prom_ID(int mejor_prom_ID[ano][2], int notas[ano][curso][alumno])
{
	int promedio;
	
	int i = 0;
	while(i < ano)
	{
		int j = 0;
		while(j < alumno)
		{
			int k = 0;
			while(k < curso)
			{
				promedio = promedio + notas[i][k][j];
				k ++;
			}
			promedio = promedio / curso;

			if(promedio > mejor_prom_ID[i][0])
			{
				mejor_prom_ID[i][0] = promedio;
				mejor_prom_ID[i][1] = j;
			}
			j ++;
		}
		i ++;
	}
}

void ImprimirMejor(int mejor_prom_ID[ano][2])
{
	int i = 0;
	while(i < ano)
	{
		printf("La mejor nota del ano %d es %d y corresponde al ID %d.", i, mejor_prom_ID[i][0], mejor_prom_ID[i][1]);
		printf("\n\n");
		
		i ++;
	}
}

void IniciarA71(int peor_prom_ID[ano][2])
{
	int i = 0;
	while(i < ano)
	{
		peor_prom_ID[i][0] = 71;
		i ++;
	}
}

void Peor_Prom_ID(int peor_prom_ID[ano][2], int notas[ano][curso][alumno])
{
	IniciarA71(peor_prom_ID);
	
	int promedio;
	
	int i = 0;
	while(i < ano)
	{
		int j = 0;
		while(j < alumno)
		{
			int k = 0;
			while(k < curso)
			{
				promedio = promedio + notas[i][k][j];
				k ++;
			}
			promedio = promedio / curso;

			if(promedio < peor_prom_ID[i][0])
			{
				peor_prom_ID[i][0] = promedio;
				peor_prom_ID[i][1] = j;
			}
			j ++;
		}
		i ++;
	}
}

void ImprimirPeor(int peor_prom_ID[ano][2])
{
	int i = 0;
	while(i < ano)
	{
		printf("La peor nota del ano %d es %d y corresponde al ID %d.", i, peor_prom_ID[i][0], peor_prom_ID[i][1]);
		printf("\n\n");
		
		i ++;
	}
}

void ImprimirNotas(int notas[ano][curso][alumno])
{
    int i, j, k; 
    
    i = 0;
    while(i < ano)
	{
   		j = 0;
        while(j < curso)
		{
        	k = 0;
        	while(k < alumno)
			{
                printf("nota del estudiante [%d][%d][%d] = %d \n ",i,j,k,notas[i][j][k]); 
                k ++;
            }
			printf("\n");
            j ++;
        }
        i ++;printf("\n");
    }
	printf("\n");
}


