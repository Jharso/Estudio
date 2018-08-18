#include <stdio.h>

void valor(int, int);

int main (){
    int a=20, b=30;
    valor(a,b);
    printf("a=%d \t b=%d ",a,b);

    return 0;
}
void valor(int x, int y){

    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("x= %d \t y=%d ", x, y);
}