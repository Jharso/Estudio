#include <stdio.h>

void areatriangulo (void) {
    float base, altura;
    printf("Introduce base: ");
    scanf("%f",&base);
    printf("Introduce altura: ");
    scanf("%f",&altura);
   
    printf("El área es: %2.2f \n",(base*altura)/2);
}

int main()
{
 
  areatriangulo();
 
   return 0;
}