#include<stdio.h>
#include<stdlib.h>

int burbuja(int *,int);
int imprimir(int *);

int main(){
    int n=11,data[11]={6,5,4,8,7,78,45,12,3,2,1};
    imprimir(data);
    burbuja(data, n);    
    imprimir(data);

    return 0;
}

int imprimir(int *data){
    int i;
    for(i=0;i<11;i++){
        printf(" %d \n",data[i]);
    }
    printf("\n");
}

int burbuja(int *data,int n){
    int temp, i=0;
    if (n > 0) {
                for (i=1;i<n;i++) {
                        if (data[i-1]>data[i]){
                                temp=data[i];
                                data[i]=data[i-1];
                                data[i-1]=temp;
                                imprimir(data);
                        }
                }
                printf("\n valor de n = %d\n", n);
                burbuja(data,n-1);
        }
    return 0;    
}

//Rodrigo Jaramillo S.
//Ingeniería en computación.