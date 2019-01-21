#include<stdio.h>
#include<stdlib.h>

int imprimir(char direccion[]);

int main()
{
    FILE *archivo;
    char ch,direccion[]="basedatos.doc";
    archivo=fopen(direccion,"a");
    printf("\nesto es una prueba %d\n",EOF);
    while((ch=getchar())!=EOF)
    {
        fputc(ch,archivo);
        printf("\nesto es una prueba %d\n",EOF);
    }
    fclose(archivo);    
    imprimir(direccion);
    return 0;
}
int imprimir(char direccion[])
{
    FILE *archivo;
    archivo=fopen(direccion,"r");
    char ch;
    while((ch=fgetc(archivo))!=EOF)
    {
        printf("%c",ch);                
    }
    fclose(archivo);
    printf("\nesto es una prueba %d\n",EOF);
    return 0;
}