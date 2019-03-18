/*Para los alumnos que no fueron a clases el lunes y que están preguntando por la tarea del mes de febrero....

Tarea del lunes 21 de enero, implementación del TDA lista con estructura estática y dinámica....

Tarea del lunes 4 de febrero, implementación de ejercicios que utilizan el TDA, 3 ejemplos y 4 ejercicios propuestos (estos ejercicios aparecen a continuación de la implementación del TDA).

Tarea del lunes 11 de febrero, implementación del TDA pila y TDA cola con estructura estática (ver libro).

Tarea del lunes 18 de febrero, implementación del TDA pila y TDA cola con estructura dinámica (ver libro).

Tarea del lunes 25 de febrero, implementación de operaciones que utilizan el TDA pila y el TDA cola, 14 ejercicios. 7 para las pilas y 7 para las colas. Mismo esquema que para las listas, 3 ejemplos y 4 ejercicios propuestos (ver libro).

Esta tarde se publicará en la Moodle los contenidos de las tareas más completo.

Respecto del concepto de recursividad, este será evaluado en la prueba 3.

Al 15 de febrero se publicarán todas las notas.*/
#include "conj.h"
#include <stdio.h>
#include <stdlib.h>
void main( void )
{ int com, elem, i;
Conjunto conj;
conj = crear( 1, 100 );
while( 1 )
{ /* Presenta el menú de opciones */
printf( "0. Salir\n" );
printf( "1. Adicionar un elemento\n" );
printf( "2. Eliminar un elemento\n" );
scanf( "%d", &com );
switch( com )
{ case 0: /* Salida del programa */
return;
case 1: /* Operación de inserción */
printf( "Elemento: " );
scanf( "%d", &elem );
insertar( conj, elem );
break;
case 2: /* Operación de supresión */
printf( "Elemento: " );
scanf( "%d", &elem );
eliminar( conj, elem );
break;
}
/* Presenta por pantalla el conjunto */
printf( "\n{ " );
for( i = inferior( conj ); i <= superior( conj ); i++ )
if( esta( conj, i ) )
printf( "%d ", i );
printf( "}\n" );
}
}