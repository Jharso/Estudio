#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ij=0, im=0, bdt[9], i=0;  //ij=marcadorjugador; im:marcador maquina; bdt: movimientos guardados; i: posicion de bdt;
int ct=1, g;   // contador de turno y ganador
int r=0;
char p[9];  //posición

void maquina();
void jugador();
void tablero();
void evaluar();

int main(){

    tablero();
    while((ct<=9) && (g==0)){      
        
        jugador();
        evaluar();  
        if(g==0){              
        maquina();
        evaluar();
        }
    }
    return 0;
}
//**************************************************************************************************************************
void maquina(void){

    srand (time(NULL));
    p[im];
    while(im==bdt[0] ||  im==bdt[1] ||  im==bdt[2] || im==bdt[3] || im==bdt[4] || im==bdt[5] || im==bdt[6] || im==bdt[7]){   

        im = (rand() % 9) + 1;
        } 
    p[im]='O';
    bdt[i]=im;  
    i=i+1;  
    ct=ct+1;
    tablero();
}
void jugador(void){

    p[ij];
    ut=ij;              
   while(ij==bdt[0] ||  ij==bdt[1] ||  ij==bdt[2] || ij==bdt[3] || ij==bdt[4] || ij==bdt[5] || ij==bdt[6] || ij==bdt[7]){
   
        printf("ingrese la posición en el tablero \n");
        scanf("%d", &ij);    
       }
    bdt[i]=ij;
    p[ij]='X';
    i=i+1;
    ct=ct+1;
    tablero();
}
void tablero(void){
         system("clear");
        //printf("valor de ut %d,   valor de ij %d valor de im %d\n",ut,ij, im);
        printf("posiciones        Tablero\n");
        printf("                         últimas jugadas: %d - %d - %d - %d - %d - %d - %d - %d - %d \n",bdt[0],bdt[1],bdt[2],bdt[3],bdt[4],bdt[5],bdt[6],bdt[7],bdt[8]);
        printf(" 7│ 8 │9          %c│ %c │%c\n", p[7],p[8],p[9]);
        printf(" 4│ 5 │6          %c│ %c │%c\n", p[4],p[5],p[6]);
        printf(" 1│ 2 │3          %c│ %c │%c\n", p[1],p[2],p[3]);
}
void evaluar(void){

    if((p[1]=='X' && p[2]=='X' && p[3]=='X')||(p[4]=='X' && p[5]=='X' && p[6]=='X')||(p[7]=='X' && p[8]=='X' && p[9]=='X')||(p[1]=='X' && p[4]=='X' && p[7]=='X')||(p[2]=='X' && p[5]=='X' && p[8]=='X')||(p[3]=='X' && p[6]=='X' && p[9]=='X')||(p[1]=='X' && p[5]=='X' && p[9]=='X')||(p[7]=='X' && p[5]=='X' && p[3]=='X')) {    //#1

        printf("\n¡¡¡¡¡¡¡¡¡¡¡HAS GANADO!!!!!!!!!!!  \n");
        g=1;
    }

    if((p[1]=='O' && p[2]=='O' && p[3]=='O')||(p[4]=='O' && p[5]=='O' && p[6]=='O')||(p[7]=='O' && p[8]=='O' && p[9]=='O')||(p[1]=='O' && p[4]=='O' && p[7]=='O')||(p[2]=='O' && p[5]=='O' && p[8]=='O')||(p[3]=='O' && p[6]=='O' && p[9]=='O')||(p[1]=='O' && p[5]=='O' && p[9]=='O')||(p[7]=='O' && p[5]=='O' && p[3]=='O')) {   //#2

        printf("\n¡¡¡¡¡¡¡¡¡¡¡HAS PERDIDO!!!!!!!!!!!  \n");
        g=1;
   
    }    
}