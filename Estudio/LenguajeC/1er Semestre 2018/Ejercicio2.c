//Construya un algoritmo que dado tres números ingresados por teclado busque el mayor de los tres
#include <stdio.h>

void mayor(int num[]);

int main(){
    int num[2], i=0, tras;
       while(i<3){
        printf("ingrese 1 número  cualquiera\n");   
        scanf("%d", &tras);
        num[i]=tras;
        i+=1;
        
    }
    mayor(num);

    return 0;
}

void mayor(int num[]){
    printf("estoy acá\n");
    int i=0, j=0, temp, TAM=3,tras;

    while(i < TAM){
        printf("while de i\n");

        while(j<TAM-1 ){

            printf("while de j\n");

           if(num[j] > num[j+1]){
            
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            
            }

            j+=1;
        }
        i+=1;

    }
    i=0;
    while(i<TAM){
        tras=num[i];
        printf("%d\n",tras);
        i=i+1;
    }

}