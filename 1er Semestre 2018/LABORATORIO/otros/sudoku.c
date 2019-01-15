//Backtracking Recursivo: Sudoku
/*sudoku recursivo entero
- rellenar una cuadricula de 9x9 celdas dividida en subcuadriculas de 3x3 con las cifras del 1 al 9
- no se deben repetir en una misma fila, columna o subcuadricula
- la solucion es unica
- plantilla de entrada (en un archivo Datos.dat) pueda encontrar la solucion
- generar un archivo de salida con la solucion(solucion.dat)
*/

procedure Try(..., solucion){
opc = 1;
solucion = false;

	if(valido){
		//avanzar
		if(final){
			Try(..., solucion);
		}
		else{
			if(not_inicio){
			opc++;
		}
	}
}

plantilla(Datos.dat); //se llama a la plantilla

void Try(..., solucion){
int opc=1;
int solucion=false;
	if(valido){
		//avanzar o asignar valor a una variable
		if(final){
			Try(...,solucion){
		}
		else{
			opc++;
			//retroceder
		}
	}
}


int main(){
	printf("\nIngrese una opcion del siguiente menu: \n");
	printf("\n1.- Crear sudoku\n");
	printf("\n2.- Resolver sudoku"
	scanf("%i", &opc){
	if(opc == 1){
	
