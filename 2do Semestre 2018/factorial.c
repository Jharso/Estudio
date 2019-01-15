#include<stdio.h>
#include<stdlib.h>
int factorial(int);

int main(){
    int n, factor;
    printf("\ningrese un número\n");
    scanf("%d", &n);
    factor=factorial(n);
    printf("\n Factorial de %d = %d",n,factor);

    return 0;
}

int factorial(int n){
    int r;
    printf("\n Factor %d", n);
    if(n==0){
        return 1;
    }else{
        if(n>0){
            r= n * factorial(n-1);
        }
    }
 
}