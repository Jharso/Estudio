#include <stdio.h>

void referencia(int *, int *);

int main (){
    int a=20, b=30;
    referencia(&a,&b);
    printf("a=%d \t b=%d ",a,b);

}

void referencia(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("*a=%d \t *b=%d\t",*a,*b);
    }               