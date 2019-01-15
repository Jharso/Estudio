#include<stdio.h>
void proceso1(int *);
void proceso2(int);
int continuar();
void main(){
	int a,c,flag=1;
	while(flag){
		a =9;c = 9;
		printf("valor de a y c antes %d %d\n",a,c);
		proceso1(&a);
		proceso2(c);
		printf("valor de a y c despues %d %d\n",a,c);
		flag = continuar();
	}
}
void proceso1(int *b){
	printf("proceso 1 parametro enviado %i \n",*b);
	*b = 150;
	printf("parametro enviado %i \n",*b);
}
void proceso2(int b){
	printf("proceso 2 parametro enviado %i \n",b);
	b = 150;
	printf("parametro enviado %i \n",b);
}
int continuar(){
//para una explicación del fflush ver
//http://www.carlospes.com/curso_de_lenguaje_c/01_11_la_funcion_fflush.php
	char respuesta, falso;
	respuesta ='c';
	while((respuesta != 'n')&&(respuesta !='N')&&(respuesta != 's')&&(respuesta !='S')){
		printf("Desea continuar S/N????\n");fflush(stdin);
		scanf("%c",&respuesta);scanf("%c",&falso);
		if ((respuesta != 'n')&&(respuesta !='N')&&(respuesta != 's')&&(respuesta !='S')){
			printf("Por favor ingrese S o N.....Enter para continuar..\n");
			fflush(stdin);
			scanf("%c",&falso);
		}		
	}
	if((respuesta == 'n')||(respuesta =='N')){
		return(0);
	}
	return(1);
}

