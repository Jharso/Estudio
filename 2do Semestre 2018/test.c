
#include <stdio.h>
#include <stdlib.h>
int main() {
    int dato[3]; dato[0] = 322; dato[1]= 112; dato[2]=567;    // 3 datos numerados del 0 al 2
    int datoExtraido[3]; char textoExtraido [50];
    FILE* fichero;
    //ESCRITURA
    fichero = fopen("misdatos.txt", "wt");
    fprintf (fichero, "%s", "Datos de pesos en kgs");  fprintf (fichero, "%c", '\n');
    fprintf (fichero, "%d %c", dato[0], '\n');
    fprintf (fichero, "%d %c", dato[1], '\n');
    fprintf (fichero, "%d %c", dato[2], '\n');
    fclose(fichero);
    printf("Proceso de escritura completado \n");

    //LECTURA
    fichero = fopen("misdatos.txt", "rt");
    fgets (textoExtraido, 50, fichero);
    fscanf (fichero, "%d", &datoExtraido[0] );
    fscanf (fichero, "%d", &datoExtraido[1] );
    fscanf (fichero, "%d", &datoExtraido[2] );
    printf ("Texto extraido es: %s", textoExtraido);
    printf ("Dato extraido indice 0 vale %d \n", datoExtraido[0]);
    printf ("Dato extraido indice 1 vale %d \n", datoExtraido[1]);
    printf ("Dato extraido indice 2 vale %d \n", datoExtraido[2]);
    fclose(fichero);
    printf("Proceso de lectura completado");
    return 0; // Ejemplo curso C aprenderaprogramar.com
}