program gato_completado;
var casilla,flag,ganador,empate:integer;{variable en entero}
var A,B,C,D,E,F,G,H,I,ficha_jugador,ficha_maquina,turno:char;{variables en caracter}
begin
     writeln('............bienvenido al juego del gato');
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
          end;{fin modulo 1 elegir ficha}
     writeln ('elija turno en el cual empesar  1 o 2');{inicio modulo 2 elegir turno}
     read (turno);
     while((turno<>'1')and(turno<>'2'))do
	begin 
		writeln ('ingrese turno 1 si quiere empezar o  2 si quiere el segundo turno');
		readln (turno);
	     end;
     if (turno='1')then
     begin
          flag:=1 ;
	     end
	else
	begin
	     flag:=0 ;
	     end;{fin modulo 2 elegir quien inicia}     
     A:='_';B:='_';C:='_';D:='_';E:='_';F:='_';G:='_';H:='_';I:='_';{asiganacion de las casillas vacias}
     ganador:=0;empate:=0;
     while((ganador=0)and(empate=0))do{modulo 3 jugar mientras}
     begin
          writeln('tablero es..', A , '/' , B , '/' , C ,'-----1/2/3');{tablero de juego}
          writeln('............', D , '/' , E , '/' , F ,'-----4/5/6');
          writeln('............', G , '/' , H , '/' , I ,'-----7/8/9');
          while(flag=1)and(empate=0)and(ganador=0)do
          begin
               writeln('ingrese casilla del 1 al 9');
               readln(casilla);
               while((casilla>9)or(casilla<1))do
               begin
                    writeln('error la casilla tiene que ser del 1 al 9');
                    readln (casilla);
                    end;
               if(casilla=1)then
               begin
                    if(A='_')then
                    begin
                         A:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end;
               if(casilla=2)then
               begin
                    if(B='_')then
                    begin
                         B:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end;
               if(casilla=3)then
               begin
                    if(C='_')then
                    begin
                         C:=ficha_jugador;flag:=0;
                         end
                    else
                         begin
                         writeln('error casilla repetida');
                         end;
               end;
               if(casilla=4)then
               begin
                    if(D='_')then
                    begin
                         D:=ficha_jugador;flag:=0;
                         end
                     else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end;
               if(casilla=5)then
               begin
                    if(E='_')then
                    begin
                         E:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end;
               if(casilla=6)then
               begin
                    if(F='_')then
                    begin
                         F:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end; 
               if(casilla=7)then
               begin
                    if(G='_')then
                    begin
                         G:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end;
               if(casilla=8)then
               begin
                    if(H='_')then
                    begin
                         H:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                    end;
               if(casilla=9)then
               begin
                    if(I='_')then
                    begin
                         I:=ficha_jugador;flag:=0;
                         end
                    else
                    begin
                         writeln('error casilla repetida');
                         end;
                        readln(casilla);
                   end;
               end;{fin turno de jugador}
          writeln('tablero es.', A , '/' , B , '/' , C ,'-----1/2/3');
          writeln('...........', D , '/' , E , '/' , F ,'-----4/5/6');
          writeln('...........', G , '/' , H , '/' , I ,'-----7/8/9');
          if((A=B)and(B=C)and(A<>'_')and(A=C))then{inicio de juego de la maquina modulo 3-2} 
          begin
               ganador:=1;
               end;
          if((D=E)and(E=F)and(D<>'_')and(D=F))then 
          begin
               ganador:=1;
               end;
          if((G=H)and(H=I)and(G<>'_')and(I=G))then 
          begin
               ganador:=1;
               end;
          if((A=D)and(D=G)and(A<>'_')and(A=G))then 
          begin 
               ganador:=1;
               end;
          if((B=E)and(E=H)and(E<>'_')and(B=H))then 
          begin
               ganador:=1;
               end;          
          if((C=F)and(F=I)and(C<>'_')and(C=I))then 
          begin
               ganador:=1;
               end;
          if((A=E)and(E=I)and(A<>'_')and(A=I))then 
          begin
               ganador:=1;
               end;
          if((C=E)and(E=G)and(C<>'_')and(C=G))then 
          begin
               ganador:=1;
               end;
          if(ganador=0)then
          begin         
               if((A<>'_')and(B<>'_')and(C<>'_')and(D<>'_')and(E<>'_')and(F<>'_')and(G<>'_')and(H<>'_')and(I<>'_'))then
               begin
                    empate:=1;
                    end;
               end;
          while(flag=0)and(empate=0)and(ganador=0)do
          begin
                 if(A='_')and(flag=0)then
               begin
                    A:=ficha_maquina;flag:=1;
                    end;
               if(B='_')and(flag=0)then
               begin
                    B:=ficha_maquina;flag:=1;
                    end;
               if(C='_')and(flag=0)then
               begin
                    C:=ficha_maquina;flag:=1;
                    end;
               if(D='_')and(flag=0)then
               begin
                    D:=ficha_maquina;flag:=1;
                    end;
               if(E='_')and(flag=0)then
               begin
                    E:=ficha_maquina;flag:=1;
                    end;
               if(F='_')and(flag=0)then
               begin
                    F:=ficha_maquina;flag:=1;
                    end;
               if(G='_')and(flag=0)then
               begin
                    G:=ficha_maquina;flag:=1;
                    end;
               if(H='_')and(flag=0)then
               begin
                    H:=ficha_maquina;flag:=1;
                    end;
               if(I='_')and(flag=0)then
               begin
                    I:=ficha_maquina;flag:=1;
                    end;
               end;{fin while maquina}
          if((A=B)and(B=C)and(A<>'_')and(A=C))then{verificar si se terminaron los turnos o si gano maquina} 
          begin
               ganador:=1;
               end;
          if((D=E)and(E=F)and(D<>'_')and(D=F))then 
          begin
               ganador:=1;
               end;
          if((G=H)and(H=I)and(G<>'_')and(G=I))then 
          begin
               ganador:=1;
               end;
          if((A=D)and(D=G)and(A<>'_')and(A=G))then 
          begin 
               ganador:=1;
               end;
          if((B=E)and(E=H)and(E<>'_')and(B=H))then 
          begin
               ganador:=1;
               end;          
          if((C=F)and(F=I)and(C<>'_')and(C=I))then 
          begin
               ganador:=1;
               end;
          if((A=E)and(E=I)and(A<>'_')and(A=I))then 
          begin
               ganador:=1;
               end;
          if((C=E)and(E=G)and(C<>'_')and(C=G))then 
          begin
               ganador:=1;
               end;
          if(ganador=0)then
          begin         
               if((A<>'_')and(B<>'_')and(C<>'_')and(D<>'_')and(E<>'_')and(F<>'_')and(G<>'_')and(H<>'_')and(I<>'_'))then
               begin
                    empate:=1;
                    end;
               end;{fin de cambio de la variable ganador o empate}               
          end;{fin de  ciclo empate o ganar/jugar}
     if(ganador>0)or(empate>0)then
     begin{inicio de condiciones de victorio o empate}
          if((A=ficha_jugador)and(B=ficha_jugador)and(C=ficha_jugador))or((A=ficha_jugador)and(D=ficha_jugador)and(G=ficha_jugador))or((D=ficha_jugador)and(E=ficha_jugador)and(F=ficha_jugador))or((B=ficha_jugador)and(E=ficha_jugador)and(H=ficha_jugador))or((C=ficha_jugador)and(F=ficha_jugador)and(I=ficha_jugador))or((G=ficha_jugador)and(H=ficha_jugador)and(I=ficha_jugador))or((A=ficha_jugador)and(E=ficha_jugador)and(I=ficha_jugador))or((G=ficha_jugador)and(E=ficha_jugador)and(C=ficha_jugador))then{condiciones de victorio}
          begin
               writeln('ganaste');     
               end
          else
          begin
               if(((A=ficha_maquina)and(B=ficha_maquina)and(C=ficha_maquina))or((A=ficha_maquina)and(D=ficha_maquina)and(G=ficha_maquina))or((D=ficha_maquina)and(E=ficha_maquina)and(F=ficha_maquina))or((B=ficha_maquina)and(E=ficha_maquina)and(H=ficha_maquina))or((C=ficha_maquina)and(F=ficha_maquina)and(I=ficha_maquina))or((G=ficha_maquina)and(H=ficha_maquina)and(I=ficha_maquina))or((A=ficha_maquina)and(E=ficha_maquina)and(I=ficha_maquina))or((G=ficha_maquina)and(E=ficha_maquina)and(C=ficha_maquina)))then{condiciones de derrota}
               begin
                    writeln('perdiste');
                    end
               else
               begin
                    writeln('empate');
                    end;
               end;
          end;
       writeln('___________', A , '/' , B , '/' , C ,'  -----1/2/3');{tablero final}
       writeln('___________', D , '/' , E , '/' , F ,'  -----4/5/6');
       writeln('___________', G , '/' , H , '/' , I ,'  -----7/8/9');         
end.
