#include<stdio.h>
#include<stdlib.h>

int producto(int *,int *);

void main(){
    int a,b;
    printf("\nIngresar número 1 :");
    scanf("%d",&a);
    printf("\nIngresar número 2 :");
    scanf("%d",&b);
    printf("\nEl resultado es %i",producto(&a,&b));

}

int producto(int *x,int *y){
    int res;
    res=*x**y;

    return res;
}