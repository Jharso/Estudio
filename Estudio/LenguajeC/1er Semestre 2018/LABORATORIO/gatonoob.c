#include <stdio.h>
#include <stdlib.h>
//Bienvenido al juego del gato
void ImprimirTablero(char tablero[]){
  int indice = 1;
  system("cls"); 
  while(indice < 10){ 
    if(indice%3 != 0){
      printf("\t%c",tablero[indice-1]); 
    }else{
      printf("\t%c\n",tablero[indice-1]);
    }
    indice++;
	}

  
}
             
int PedirNumero(char tablero[]){
  
  int numero = -1;
  int seguir = 1;
  
  while(seguir){
    if(numero <= 0 || numero >= 10){
  		printf("Ingrese un numero entre 1 y 9 => "); 
  		scanf("%i",&numero);
      if(tablero[numero-1] == '.'){
        seguir = 0;
      }else{
        printf("Espacio ocupado, seleccione otro numero ...\n");
        numero = -1;
      }
    }
  }
  
  return numero;
 
}             
 
void TurnoJugador(char tablero[],int numero, int turno){  
  	
  	if(turno%2 == 0){ 
      
        if(numero == 1){ 
          tablero[0] = 'x';
        }else if(numero == 2){				
          tablero[1] = 'x';
        }else if(numero == 3){
          tablero[2] = 'x';
        }else if(numero == 4){
          tablero[3] = 'x';	 
        }else if(numero == 5){
          tablero[4] = 'x';
        }else if(numero == 6){
          tablero[5] = 'x';
        }else if(numero == 7){
          tablero[6] = 'x';
        }else if(numero == 8){
          tablero[7] = 'x';
        }else if(numero == 9){
          tablero[8] = 'x';		
        }                                             
    }else{
        if (numero == 1){
          tablero[0]='o';
        }else if (numero == 2){
          tablero[1]='o';
        }else if (numero == 3){
          tablero[2]='o';
        }else if (numero == 4){
          tablero[3]='o';
        }else if (numero == 5){
          tablero[4]='o';
        }else if (numero == 6){
          tablero[5]='o';
        }else if (numero == 7){
          tablero[6]='o';
        }else if (numero == 8){
          tablero[7]='o';
        }else if (numero == 9){
          tablero[8]='o';
      	} 
      } 
}    

int VerificarGanador(char tablero[]){
  int numero;
			if(((tablero[0] == 'x')&&(tablero[1] == 'x')&&(tablero[2] == 'x'))||
         ((tablero[3] == 'x')&&(tablero[4] == 'x')&&(tablero[5] == 'x'))||
         ((tablero[6] == 'x')&&(tablero[7] == 'x')&&(tablero[8] == 'x'))|| 
         ((tablero[0] == 'x')&&(tablero[3] == 'x')&&(tablero[6] == 'x'))||        
         ((tablero[1] == 'x')&&(tablero[4] == 'x')&&(tablero[7] == 'x'))||        
         ((tablero[2] == 'x')&&(tablero[5] == 'x')&&(tablero[8] == 'x'))||				
       	 ((tablero[0] == 'x')&&(tablero[4] == 'x')&&(tablero[8] == 'x'))||               
         ((tablero[6] == 'x')&&(tablero[4] == 'x')&&(tablero[2] == 'x'))){              
      		printf("bien hecho,ha ganado x \n\n");
        	numero = 1;
      }else if(((tablero[0] == 'o')&&(tablero[1] == 'o')&&(tablero[2] == 'o'))|| 
         ((tablero[3] == 'o')&&(tablero[4] == 'o')&&(tablero[5] == 'o'))|| 
         ((tablero[6] == 'o')&&(tablero[7] == 'o')&&(tablero[8] == 'o'))|| 
         ((tablero[0] == 'o')&&(tablero[3] == 'o')&&(tablero[6] == 'o'))||        
         ((tablero[1] == 'o')&&(tablero[4] == 'o')&&(tablero[7] == 'o'))||        
         ((tablero[2] == 'o')&&(tablero[5] == 'o')&&(tablero[8] == 'o'))||			
       	 ((tablero[0] == 'o')&&(tablero[4] == 'o')&&(tablero[8] == 'o'))||              
         ((tablero[6] == 'o')&&(tablero[4] == 'o')&&(tablero[2] == 'o'))){
        	printf("bien hecho,ha ganado o \n\n"); 
        	numero = 1;
      }//esta funcion contorla la manera de conocer alganador del juego
  return(numero);
}
           
void JugarGato(char tablero[]){
  int numero;
  int seguir = 1;
  int turno = 1;
	int finJuego;
  
 	while(seguir){
     numero = PedirNumero(tablero); 
		 TurnoJugador(tablero,numero,turno); 
     ImprimirTablero(tablero);
     finJuego = VerificarGanador(tablero);
     turno++;
     if(turno == 10 || finJuego == 1){
       if(turno == 10){
         printf("EMPATE \n\n");
         seguir = 0;//Cuando se empato
       }
       seguir = 0;//Cuando hubo ganador
     }
  }
  
}

void IniciarTablero(char tablero[]){
  int indice = 0;
  while(indice < 9){
    tablero[indice] = '.';
    indice++;
  }
}						

int main(){
  int volver = 1; 
  char tablero[9];
  while(volver == 1){
    IniciarTablero(tablero);
  	ImprimirTablero(tablero); // Esta funcion imprime el tablero del juego
  	JugarGato(tablero);
			printf("\n\ndesea volver al menu\n1.SI\n2.terminar proceso\n...");
			scanf("%d",&volver);
  }
  return 0;
}
