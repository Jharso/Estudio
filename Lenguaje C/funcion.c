#include <stdio.h>

float areatriangulo (void) {
    float base, altura;
    printf("Introduce base: ");
    scanf("%f",&base);
    printf("Introduce altura: ");
    scanf("%f",&altura);
   
    return (base*altura)/2;
}

int main()
{
 
  float area;
 
  area=areatriangulo();
  printf("El área es: %2.2f \n",area);
 
   return 0;
}