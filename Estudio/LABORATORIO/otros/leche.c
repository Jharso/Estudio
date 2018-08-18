#include <stdio.h>
#include <stdlib.h>

void dibujo()
{

	printf("	  _______________________\n");
        printf("	 /	                /|\n");
	printf("	/______________________/ |\n");
        printf("	|		       | |\n");
	printf("	|   ___	   ____	       | |\n");
        printf("	|   | |   |    |       | |\n");
	printf("	|   | |__ | __ |       | |\n");
        printf("	|   |___| ||  ||       | |\n");
	printf("	|    ___   _   _       | |\n");
        printf("	|   |  _| | |_| |      | |\n");
	printf("	|   | |_  |  _  |      | |\n");
        printf("	|   |___| |_| |_|      | |\n");
	printf("	|     ___________      | |\n");
        printf("	|    |	         |     | |\n");
	printf("	|    |		 |     | |\n");
        printf("	|    |___________|     | /\n");
	printf("	|______________________|/\n");
        
}

void main()
{
	int estas;
	int leche;
	leche=1;
	system("clear");
	dibujo();	
	printf("\n¿tienes leche?(SI/1)(NO/2)\n");	
	scanf("%d",&leche);
	while((leche<1)||(leche>2))
	{
		printf("Error presione 1 para si o 2 para no\n");
		scanf("%d",&leche);	
	}	
	while(leche==1)
	{
		
		printf("\n¿Estas en publico?(si/1)(no/2)\n");
		scanf("%d",&estas);
		if (estas==1){
			printf("\nagitando leche...\n\n");
					
		}		
		else{
			printf("\ninflando caja de leche...\n\n");	
		}
		printf("presione una tecla para continuar---->");		
		getchar();
		getchar();
		system("clear");
		dibujo();
		printf("\n¿tienes leche?(SI/1)(NO/2)\n");	
		scanf("%d",&leche);
		while((leche<1)||(leche>2))
		{
		printf("Error presione 1 para si o 2 para no\n");
		scanf("%d",&leche);	
		}	
	}
}
