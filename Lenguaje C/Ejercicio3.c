//genere e imprima los primeros n números primos
#include <stdio.h>

void main(){
        int a,b,c;
        a=1;
        while ( a<=100 ){
   		b=1;
   		c=0;
   		while (b<=a){
   			if (a%b==0){
   				c=c+1;	
   			}
   			b=b+1;
   		}
	   	if(c==2){ 
	 		printf("\n%d",a);
		}
		a=a+1;
	}
}   