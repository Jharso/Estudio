program gatete_opi;
uses Crt;
type vector=array[1..9]of char;  
Procedure fichas(var ficha_jugador,ficha_maquina:char);
begin
        writeln('............bienvenido al juego del gato');
        writeln;
        writeln('porfabor elegir ficha ya sea X / O');{inicio modulo 1 elegir ficha}
	read (ficha_jugador) ;
        while((ficha_jugador<>'X')and(ficha_jugador<>'O'))do
        begin
                writeln ('error solo se permite ingresar X / O');
    		read (ficha_jugador);
        end;{fin while}
	if(ficha_jugador='X')then
        begin
		ficha_maquina:='O' ;
        end
        else
        begin
		ficha_maquina:='X' ;	
        end;
end;{fin modulo 1 elegir ficha}
{---------------------------------------------------------------------------------}
procedure turno(var flag:integer);
var turno:Integer;
begin
        writeln ('elija turno en el cual empesar  1 o 2');{inicio modulo 2 elegir turno}
        read (turno);
        while((turno<>1)and(turno<>2))do
        begin 
	        writeln ('ingrese turno 1 si quiere empezar o  2 si quiere el segundo turno');
		readln (turno);
	end;
        if (turno=1)then
        begin
                flag:=1 ;
        end
	else
	begin
	        flag:=0 ;
        end;
end;{fin modulo 2 elegir quien inicia}  
{----------------------------------------------------------------------------------}
procedure gato(var vec:vector);
var i:integer; 
begin
        i:=1;
	while(i<10)do
        begin
	        vec[i]:='_';i:=i+1;
        end;
end;
procedure tablero(vec:vector);
begin
	writeln();
	writeln(vec[1],' | ',vec[2],' | ',vec[3]);
	writeln('__|___|__');
	writeln(vec[4],' | ',vec[5],' | ',vec[6]);
	writeln('__|___|__');
	writeln(vec[7],' | ',vec[8],' | ',vec[9]);
	writeln('  |   |  ');
        writeln;
        writeln('--------------------------------------');
        writeln;
        writeln();
                writeln(' 1 | 2 | 3 ');
                writeln('___|___|___');
	 	writeln(' 4 | 5 | 6 ');
	        writeln('___|___|___');
	        writeln(' 7 | 8 | 9 ');
	        writeln('   |   |   ');
end;
procedure turno_jugador(var flag:integer ; var vec:vector;  ficha_jugador:char);
var   i,casilla:integer;
begin
        while(flag=1)do
        begin
                i:=1;
                writeln('ingrese casilla del 1 al 9');
                readln(casilla);
                while((casilla>9)or(casilla<1))do
                begin
                        writeln('error la casilla tiene que ser del 1 al 9');
                        readln (casilla);
                end;
                while(i<=9)do
                begin
                    if(casilla=i)then
                    begin
                            if(vec[i]='_')then
                            begin
                                    vec[i]:=ficha_jugador;flag:=0;
                            end
                            else
                            begin
                                    writeln('las casillas no tienen que repetirse');
                                    writeln('ingrese una casilla en blanco');
                            end;
                    end;
                    i:=i+1;
                end;
    end; 
   tablero(vec);           
end;
{---------------------fin del turno jugador---------------------------------------}
procedure turno_maquina(var flag:integer; var vec:vector; var ficha_maquina:char);
var i :integer;
begin
        i:=1;
        while (i<10)do
        begin
        	if (vec[i]='_')then
        	begin
               	vec[i]:=ficha_maquina;i:=10;flag:=1;
        	end
        	else
        	begin
                	i:=i+1
        	end;
        end; 
    tablero(vec);                   
end;
{------------final turno maquina --------------------------------------------------}
procedure empate_ganar(var ganador,empate:integer; vec:vector); 
begin
        if((vec[1]=vec[2])and(vec[2]=vec[3])and(vec[1]<>'_')and(vec[1]=vec[3]))then 
        begin
               ganador:=1;
        end;
        if((vec[4]=vec[5])and(vec[5]=vec[6])and(vec[4]<>'_')and(vec[4]=vec[6]))then 
        begin
               ganador:=1;
        end;
        if((vec[7]=vec[8])and(vec[8]=vec[9])and(vec[7]<>'_')and(vec[7]=vec[9]))then 
        begin
               ganador:=1;
        end;
        if((vec[1]=vec[4])and(vec[4]=vec[7])and(vec[1]<>'_')and(vec[1]=vec[7]))then 
        begin 
               ganador:=1;
        end;
        if((vec[2]=vec[5])and(vec[5]=vec[8])and(vec[5]<>'_')and(vec[2]=vec[8]))then 
        begin
               ganador:=1;
        end;          
        if((vec[3]=vec[6])and(vec[6]=vec[9])and(vec[3]<>'_')and(vec[3]=vec[9]))then 
        begin
               ganador:=1;
        end;
        if((vec[1]=vec[5])and(vec[5]=vec[9])and(vec[1]<>'_')and(vec[1]=vec[9]))then 
        begin
               ganador:=1;
        end;
        if((vec[3]=vec[6])and(vec[5]=vec[7])and(vec[3]<>'_')and(vec[3]=vec[7]))then 
        begin
               ganador:=1;
        end;
        if(ganador=0)then
        begin         
               if((vec[1]<>'_')and(vec[2]<>'_')and(vec[3]<>'_')and(vec[4]<>'_')and(vec[5]<>'_')and(vec[6]<>'_')and(vec[7]<>'_')and(vec[8]<>'_')and(vec[9]<>'_'))then
               begin
                    empate:=1;
               end;
        end;
end;  
var empate , ganador, flag :integer; vec:vector;ficha_jugador,ficha_maquina:char;         
begin {inicio programa}
	empate:=0; ganador:=0; 
	fichas(ficha_jugador,ficha_maquina);
	turno(flag); 
	gato(vec);
while((empate=0) and (ganador=0))do
begin
        turno_jugador(flag,vec,ficha_jugador);
        empate_ganar(ganador,empate ,vec);
        turno_maquina(flag,vec,ficha_maquina);
        empate_ganar(ganador,empate , vec);
end;
     if(ganador>0)or(empate>0)then
     begin{inicio de condiciones de victorio o empate}
          if((vec[1]=ficha_jugador)and(vec[2]=ficha_jugador)and(vec[3]=ficha_jugador))or((vec[1]=ficha_jugador)and(vec[4]=ficha_jugador)and(vec[7]=ficha_jugador))or((vec[4]=ficha_jugador)and(vec[5]=ficha_jugador)and(vec[6]=ficha_jugador))or((vec[2]=ficha_jugador)and(vec[5]=ficha_jugador)and(vec[8]=ficha_jugador))or((vec[3]=ficha_jugador)and(vec[6]=ficha_jugador)and(vec[9]=ficha_jugador))or((vec[7]=ficha_jugador)and(vec[8]=ficha_jugador)and(vec[9]=ficha_jugador))or((vec[1]=ficha_jugador)and(vec[5]=ficha_jugador)and(vec[9]=ficha_jugador))or((vec[7]=ficha_jugador)and(vec[5]=ficha_jugador)and(vec[3]=ficha_jugador))then{condiciones de victorio}
          begin
               writeln('ganaste');     
               end
          else
          begin
               if(((vec[1]=ficha_maquina)and(vec[2]=ficha_maquina)and(vec[3]=ficha_maquina))or((vec[1]=ficha_maquina)and(vec[4]=ficha_maquina)and(vec[7]=ficha_maquina))or((vec[4]=ficha_maquina)and(vec[5]=ficha_maquina)and(vec[6]=ficha_maquina))or((vec[2]=ficha_maquina)and(vec[5]=ficha_maquina)and(vec[8]=ficha_maquina))or((vec[3]=ficha_maquina)and(vec[6]=ficha_maquina)and(vec[9]=ficha_maquina))or((vec[7]=ficha_maquina)and(vec[8]=ficha_maquina)and(vec[9]=ficha_maquina))or((vec[1]=ficha_maquina)and(vec[5]=ficha_maquina)and(vec[9]=ficha_maquina))or((vec[7]=ficha_maquina)and(vec[5]=ficha_maquina)and(vec[3]=ficha_maquina)))then{condiciones de derrota}
               begin
                    writeln('perdiste');
                    end
               else
               begin
                    writeln('empate');
                    end;
              end;
          end;
end.
