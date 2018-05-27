#include <stdio.h>

void main(){    
        int contador,num;
	contador = 0;
	printf("\nIngrese un nùmero cualquiera\n");
	scanf("%d",&num);
	while(num != 0){
		printf("\nel numero leido es ---> %d esto va a sobrar\n",num);
                contador = contador +1;
		scanf("%d",&num);		
	}
	printf("\nla cantidad de numeros leidos es %d.....eso es todo\n",contador);
}	
/*BEGIN
CONT = 1
WHILE(CONT <= 100)DO
IF(CONT ES PRIMO)THEN
WRITE(CONT, 'ES PRIMO');
ENDIF
CONT = CONT+1
ENDWHILE
END.*/

