#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define alumnos 50
#define curso 40                                       //considerar esta constante  -1, porque almacena en su posición 0 la ID del alumno
#define promocion 20

void gennotas(float [alumnos][curso][promocion]);
void impnotas(float [alumnos][curso][promocion]);
void ordenarnotas(float [alumnos][curso][promocion]);
void detallenotas(float [alumnos][curso][promocion]);

int main(){
    float datos[alumnos][curso][promocion];            //declaro el arreglo como float para controlar los decimales de cada nota.
      
    gennotas(datos);
    impnotas(datos);
    detallenotas(datos);

    return 0;
}

void gennotas(float datos[alumnos][curso][promocion]){
    int i,j,k;
    float id=1800,aux;
    srand(time(NULL));
    i=0;
    while(i<promocion){
        j=0;
        while(j<curso){
            k=0;            
            while(k<alumnos){
                if(j==0){
                    datos[k][j][i]=id+1;
                    id++;                
                }
                else{
                    aux=(rand()%600)+100;
                    datos[k][j][i]=aux/100;                   
                }                
                k++;
            }
            j++;
        }
        i++;
    }
}

void impnotas(float datos[alumnos][curso][promocion]){
    int i,j,k;
    i=0;
    while(i<promocion){
        j=1;
        printf("\n\n\nPromocion %i",i+1);
        while(j<curso){
            k=0;
            printf("\n\nCurso: %i",j);
            while(k<alumnos){
                printf("\nID");
                printf("\n%.0f:  %.2f \n", datos[k][0][i],datos[k][j][i]);
                k++;
            }
            j++;
        }
        i++;
    }
}

void detallenotas(float datos[alumnos][curso][promocion]){
    int i,j,k,z,d=curso-1;
    float ma,maid,mn,mnid,prom1[alumnos][2]={0};
    i=0,    j=1,    k=0;    
    while(i<promocion){
        j=1,        mn=0,        mnid=0;
        while(j<curso){            
            k=0;
            while(k<alumnos){               
                if(datos[k][j][i]>mn){
                    mn=datos[k][j][i];
                    mnid=datos[k][0][i];
                }               
                k++;
            }
            j++;            
        }  

        printf("\nLa mejor nota del año %i es: %.2f del alumno ID: %.0f", i+1, mn, mnid);        
        i++;
    }
    i=0,    j=1,    k=0;    
    while(i<promocion){
        j=1;
        mn=7;
        mnid=7;
        while(j<curso){            
            k=0;
            while(k<alumnos){               
                if(datos[k][j][i]<mn){                                //solo cambia evaluación lógica para buscar el menor
                    mn=datos[k][j][i];
                    mnid=datos[k][0][i];                    
                }              
                k++;
            }
            j++;            
        }           
        printf("\nLa peor nota del año %i es: %.2f del alumno ID: %.0f", i+1, mn, mnid);
        i++;
    }
    
    i=0;   
    while(i<promocion){
        j=1;  z=0;
        while(z<alumnos){
            prom1[z][1]=0;
            prom1[z][0]=0;
            z++;
        }        
        ma=0;
        maid=0;
        while(j<curso){
            k=0;
            while(k<alumnos){
                prom1[k][1]=prom1[k][1]+datos[k][j][i];
                prom1[k][0]=datos[k][0][i];  
                k++;               
                
            }
            j++;        
        }
        
        z=0;
        while(z<alumnos){
            prom1[z][1]=prom1[z][1]/d;
            z++;
        }        
        z=0;
        while(z<alumnos){
            
            if(prom1[z][1]>ma){
                ma=prom1[z][1];
                maid=prom1[z][0];
            }
            z++;
        }   
        printf("\nEl alumno ID:%.0f del año: %i, es el mejor alumno con promedio: %.2f", maid, i+1, ma); 
        i++;                
    }
    i=0;   
    while(i<promocion){
        j=1;  z=0;
        while(z<alumnos){
            prom1[z][1]=0;
            prom1[z][0]=0;
            z++;
        }        
        ma=7;
        maid=7;
        while(j<curso){
            k=0;
            while(k<alumnos){
                prom1[k][1]=prom1[k][1]+datos[k][j][i];
                prom1[k][0]=datos[k][0][i];  
                k++;               
                
            }
            j++;        
        }
        
        z=0;
        while(z<alumnos){
            prom1[z][1]=prom1[z][1]/d;
            z++;
        }        
        z=0;
        while(z<alumnos){
            
            if(prom1[z][1]<ma){                                       //solo cambia evaluación lógica para buscar el menor
                ma=prom1[z][1];
                maid=prom1[z][0];
            }
            z++;
        }   
        printf("\nEl alumno ID:%.0f del año: %i, es el peor alumno con promedio: %.2f", maid, i+1, ma); 
        i++;                
    }                                  
}


/*
Trabajo práctico de arreglos de 3 dimensiones
Rodrigo A. Jaramillo Solar
Rut=17194732-4
01 de octubre del 2018
*/
