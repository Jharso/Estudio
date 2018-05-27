program batallanaval ;
uses crt;
const limite=10;
type map=array [1..limite,1..limite]of char;
procedure jugaras(var jugar:boolean);
var play:integer;
begin
        writeln ('quieres jugar  BATALLA NAVAL vs COMPUTADORA');
        writeln('1 (si quiero jugar) ------- 2 (no quiero jugar) ');
        readln(play);
        while((play<>1)and(play<>2))do
        begin
                writeln('error la respuesta tiene que ser -->1<-- (quiero jugar) o -->2<-- (no quiero jugar)');
                read(play);
        end;
        if(play=1)then
        begin
                jugar:=true;
        end
        else
        begin    
                jugar:=false;
        end;
end;
{------------------------------------------------------------------------------------------------------------}
procedure quien_juega(var primero:boolean);
var quien_juega:integer;
begin
        randomize;
        quien_juega:=random(2)+1;
        if(quien_juega=1)then
        begin
                primero:=true
        end
        else
        begin
                primero:=false
        end;
end;
{------------------------------------------------------------------------------------------------------------}
procedure reincio_mapa(var mapj,mapja,mapm:map);
var a,b:integer;
begin
        a:=0;
        while(a<limite)do
        begin                
                a:=a+1;b:=1;
                while(b<=limite)do
                begin
                        mapj[a,b]:='_'; 
                        b:=b+1;             
                end;
        end;
        a:=0;
        while(a<limite)do
        begin                
                a:=a+1;b:=1;
                while(b<=limite)do
                begin
                        mapja[a,b]:='_'; 
                        b:=b+1;            
                end;
        end;
        a:=0;
        while(a<limite)do
        begin                
                a:=a+1;b:=1;
                while(b<=limite)do
                begin
                        mapm[a,b]:='_'; 
                        b:=b+1;            
                end;
        end;
end;
{-------------------------------------------------------------------------------------------------------------}
procedure escribir_mapas(var mapj,mapja:map);
var a,b:integer;
begin
        a:=0;
        writeln(' a b c d e f g h i j ');
        while(a<limite)do
        begin
                a:=a+1;b:=0;
                while(b<limite)do
                begin
                        b:=b+1;
                        if(mapj[a,b]='_')then
                        begin
                                TextColor(1);
                                write(' ',mapj[a,b]);
                        end;
                        if(mapj[a,b]='x')then
                        begin
                                TextColor(2);
                                write(' ',mapj[a,b]);       
                        end;
                        if(mapj[a,b]='y')then
                        begin
                                textcolor(5);
                                write(' ',mapj[a,b]);       
                        end;
                        if(mapj[a,b]='z')then
                        begin
                                textcolor(6);
                                write(' ',mapj[a,b]);      
                        end;
                        if(mapj[a,b]='q')then
                        begin
                                textcolor(13);
                                write(' ',mapj[a,b]);       
                        end;
                        if(mapj[a,b]='w')then
                        begin
                                textcolor(14);
                                write(' ',mapj[a,b]);       
                        end;
                        if(b=limite)then
                        begin   
                                textcolor(15);
                                if(a=1)then
                                begin
                                        write('<--1)');
                                end;
                                if(a=2)then
                                begin
                                        write('<--2)');
                                end;
                                if(a=3)then
                                begin
                                        write('<--3)');
                                end;
                                if(a=4)then
                                begin
                                        write('<--4)');
                                end;
                                if(a=5)then
                                begin
                                        write('<--5)');
                                end;
                                if(a=6)then
                                begin
                                        write('<--6)');
                                end;
                                if(a=7)then
                                begin
                                        write('<--7)');
                                end;
                                if(a=8)then
                                begin
                                        write('<--8)');
                                end;
                                if(a=9)then
                                begin
                                        write('<--9)');
                                end;
                                if(a=10)then
                                begin
                                        write('<-10)');
                                end;
                        end;                        
                end;
                writeln;   
        end;
        writeln(' * * * * * * * * * ');
        textcolor(15);
        writeln(' a b c d e f g h i j ');
        a:=0;
        while(a<limite)do
        begin
                a:=a+1;b:=0;
                while(b<limite)do
                begin
                        b:=b+1;
                        textcolor(15);
                        write(' ',mapja[a,b]);
                        if(b=limite)then
                        begin   
                                    textcolor(15);
                                    if(a=1)then
                                    begin
                                            write('<--1)');
                                    end;
                                    if(a=2)then
                                    begin
                                            write('<--2)');
                                    end;
                                    if(a=3)then
                                    begin
                                            write('<--3)');
                                    end;
                                    if(a=4)then
                                    begin
                                            write('<--4)');
                                    end;
                                    if(a=5)then
                                    begin
                                            write('<--5)');
                                    end;
                                    if(a=6)then
                                    begin
                                            write('<--6)');
                                    end;
                                    if(a=7)then
                                    begin
                                            write('<--7)');
                                    end;
                                    if(a=8)then
                                    begin
                                            write('<--8)');
                                    end;
                                    if(a=9)then
                                    begin
                                            write('<--9)');
                                    end;
                                    if(a=10)then
                                    begin
                                            write('<-10)');
                                    end;
                           end;
                end; 
                writeln;
        end;
end;     
{-------------------------------------------------------------------------------------------------------------}
procedure tablero_maquina(var mapm:map);
var contador,sentido,a,b:integer;correcto:boolean;
begin
        randomize;
        sentido:=random(2);
        if(sentido=1)then
        begin
                a:=random(limite)+1;
                b:=random(5)+1;
                contador:=1;
                while(contador<=5)do
                begin
                       mapm[a,b]:='X';
                       b:=b+1;
                       contador:=contador+1;         
                end;      
        end
        else
        begin
                a:=random(5)+1;
                b:=random(limite)+1;
                contador:=1;
                while(contador<=5)do
                begin
                       mapm[a,b]:='X';
                       a:=a+1;
                       contador:=contador+1;         
                end; 
        end;
        sentido:=random(2);
        if(sentido=1)then
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(6)+1;
                        b:=random(10)+1;
                        if((mapm[a,b]='_')and(mapm[a+1,b]='_')and(mapm[a+2,b]='_')and(mapm[a+3,b]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=4)do
                                begin
                                                mapm[a,b]:='Y';
                                                a:=a+1;
                                                contador:=contador+1;         
                                end;       
                        end;
                end;
        end
        else
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(10)+1;
                        b:=random(6)+1;
                        if((mapm[a,b]='_')and(mapm[a,b+1]='_')and(mapm[a,b+2]='_')and(mapm[a,b+3]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=4)do
                                begin
                                        mapm[a,b]:='Y';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;                
        end;
        sentido:=random(2);
        if(sentido=1)then
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(7)+1;
                        b:=random(10)+1;
                        if((mapm[a,b]='_')and(mapm[(a+1),b]='_')and(mapm[(a+2),b]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=3)do
                                begin
                                        mapm[a,b]:='Z';
                                        a:=a+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;        
        end
        else
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(10)+1;
                        b:=random(7)+1;
                        if((mapm[a,b]='_')and(mapm[a,(b+1)]='_')and(mapm[a,(b+2)]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=3)do
                                begin
                                        mapm[a,b]:='Z';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;
        end;
        sentido:=random(2);
        if(sentido=1)then
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(7)+1;
                        b:=random(10)+1;
                        if((mapm[a,b]='_')and(mapm[(a+1),b]='_')and(mapm[(a+2),b]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=3)do
                                begin
                                        mapm[a,b]:='W';
                                        a:=a+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;
        end
        else
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(10)+1;
                        b:=random(7)+1;
                        if((mapm[a,b]='_')and(mapm[a,b+1]='_')and(mapm[a,b+2]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=3)do
                                begin
                                        mapm[a,b]:='W';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;
        end;
        sentido:=random(2);
        if(sentido=1)then
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(8)+1;
                        b:=random(10)+1;
                        if((mapm[a,b]='_')and(mapm[a+1,b]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=2)do
                                begin
                                        mapm[a,b]:='Q';
                                        a:=a+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;
        end
        else
        begin
                correcto:=false;
                while(correcto=false)do
                begin
                        a:=random(10)+1;
                        b:=random(8)+1;
                        if((mapm[a,b]='_')and(mapm[a,b+1]='_'))then
                        begin
                                contador:=1;
                                correcto:=true;
                                while(contador<=2)do
                                begin
                                        mapm[a,b]:='Q';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;        
                        end;
                end;
        end;
end;
{-------------------------------------------------------------------------------------------------------------}
procedure confirmar_primera_cordenada(var a:integer);
begin
        writeln('primera cordenada (numero) ');
        readln(a);
        while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6)and(a<>7)and(a<>8)and(a<>9)and(a<>10))do
        begin
                writeln ('solo se aseptan estos valores de primera cordenada 1,2,3,4,5,6,7,8,9,10');
                readln(a);
        end;
end;
procedure confirmar_segunda_cordenada(var b:integer);
var c:char;z:integer;
begin
        c:='k';
        z:=0;
        writeln('segunda cordenada (letra) ');
        while(z=0)do
        begin
                readln(c);
                if(c='a')then
                begin
                        b:=1;z:=1;
                end;
                if(c='b')then
                begin
                        b:=2;z:=1;
                end;
                if(c='c')then
                begin
                        b:=3;z:=1;
                end;
                if(c='d')then
                begin
                        b:=4;z:=1;
                end;
                if(c='e')then
                begin
                        b:=5;z:=1;
                end;
                if(c='f')then
                begin
                        b:=6;z:=1;
                end;
                if(c='g')then
                begin
                        b:=7;z:=1;
                end;
                if(c='h')then
                begin
                        b:=8;z:=1;
                end;
                if(c='i')then
                begin
                        b:=9;z:=1;
                end;
                if(c='j')then
                begin
                        b:=10;z:=1;
                end;
                if(z=0)then
                begin
                        writeln(b,'......',z,c);
                        writeln('la segunda cordenada es incorrecta');
                        writeln('reingrese la segunda cordenada');
                        readln(c);
                end;
        end;                   
end; 
{------------------------------------------------------------------------------------------------------------}
procedure mapa_fichas_jugador(var mapj,mapja,mapm:map);
var direccion,contador,a,b:integer;barco_construido:boolean;
begin   
        writeln('escoja direccion de su  portaaviones  1 (horizontal >) 2(vertical v)');
        readln(direccion);
        while((direccion<>1)and(direccion<>2))do
        begin
                writeln('la direccion no existe escriba 1 (horizontal >) o 2 (vertical v)');
                readln(direccion);
        end;
        if(direccion=1)then
        begin
                confirmar_primera_cordenada(a);
                confirmar_segunda_cordenada(b);
                writeln(b);
                while((b<>1)and(b<>2)and(b<>3)and(b<>4)and(b<>5)and(b<>6))do
                begin
                        writeln('error se paso de casillas');
                        confirmar_segunda_cordenada(b);
                        writeln(b);
                end;
                contador:=1;
                while(contador<=5)do
                begin
                        mapj[a,b]:='x';
                        b:=b+1;
                        contador:=contador+1;
                end;
        end
        else
        begin
                confirmar_primera_cordenada(a);
                confirmar_segunda_cordenada(b);
                writeln(b);
                while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6))do
                begin                        
                        writeln('error se paso de casillas');
                        confirmar_primera_cordenada(a);

                end;
                contador:=1;
                while(contador<=5)do
                begin
                        mapj[a,b]:='x';
                        a:=a+1;
                        contador:=contador+1;
                end;
        end;
        escribir_mapas(mapj,mapja);
        barco_construido:=false;
        while(barco_construido=false)do
        begin
                writeln('coloque el buque de guerra');
                writeln('escoja direccion , 1 (horizontal >) 2(vertical v)');
                readln(direccion);
                while((direccion<>1)and(direccion<>2))do
                begin
                        writeln('la direccion no existe escriba 1(horizontal >) o 2(vertical v)');
                        readln(direccion);
                end;
                if(direccion=1)then
                begin   
                        confirmar_primera_cordenada(a);
                        confirmar_segunda_cordenada(b);
                        writeln(a , b);
                        while((b<>1)and(b<>2)and(b<>3)and(b<>4)and(b<>5)and(b<>6)and(b<>7))do
                        begin
                                writeln('error se paso de casillas');
                                confirmar_segunda_cordenada(b);
                                writeln;
                        end;
                        if((mapj[a,b]='_')and(mapj[a,b+1]='_')and(mapj[a,b+2]='_')and(mapj[a,b+3]='_'))then
                        begin
                                contador:=1;
                                barco_construido:=true;
                                while(contador<=4)do
                                begin
                                        mapj[a,b]:='y';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;
                        end
                        else
                        begin
                                writeln('error la posicion no es valida');        
                        end;
                end
                else
                begin
                        confirmar_primera_cordenada(a);
                        confirmar_segunda_cordenada(b);
                        while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6)and(a<>7))do
                        begin
                                writeln('error se paso de casillas');
                                confirmar_primera_cordenada(a);
                        end;
                        if((mapj[a,b]='_')and(mapj[a+1,b]='_')and(mapj[a+2,b]='_')and(mapj[a+3,b]='_'))then
                        begin
                                contador:=1;
                                barco_construido:=true;
                                while(contador<=4)do
                                begin
                                        mapj[a,b]:='y';
                                        a:=a+1;
                                        contador:=contador+1;         
                                end;
                        end
                        else
                        begin
                                writeln('error la posicion no es valida');        
                        end;
                end;
                escribir_mapas(mapj,mapja);
                barco_construido:=false;
                while(barco_construido=false)do
                begin
                        writeln('coloque el destructor');
                        writeln('escoja direccion del destructor, 1 (horizontal >) 2(vertical v)');
                        readln(direccion);
                        while((direccion<>1)and(direccion<>2))do
                        begin
                                writeln('la direccion no existe escriba 1(horizontal >) o 2(vertical >)');
                                readln(direccion);
                        end;
                        if(direccion=1)then
                        begin   
                                confirmar_primera_cordenada(a);
                                confirmar_segunda_cordenada(b);
                                while((b<>1)and(b<>2)and(b<>3)and(b<>4)and(b<>5)and(b<>6)and(b<>7)and(b<>8))do
                                begin
                                        writeln('error se paso de casillas');
                                        confirmar_segunda_cordenada(b);
                                end;
                                if((mapj[a,b]='_')and(mapj[a,b+1]='_')and(mapj[a,b+2]='_'))then
                                begin
                                        contador:=1;
                                        barco_construido:=true;
                                        while(contador<=3)do
                                        begin
                                                mapj[a,b]:='z';
                                                b:=b+1;
                                                contador:=contador+1;         
                                        end;
                                end
                                else
                                begin
                                        writeln('error la posicion no es valida');        
                                end;
                        end
                        else
                        begin
                                confirmar_primera_cordenada(a);
                                confirmar_segunda_cordenada(b);
                                while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6)and(a<>7)and(a<>8))do
                                begin
                                        writeln('error se paso de casillas');
                                        confirmar_primera_cordenada(a);
                                end;
                                if((mapj[a,b]='_')and(mapj[a,b+1]='_')and(mapj[a,b+2]='_'))then
                                begin
                                        contador:=1;
                                        barco_construido:=true;
                                        while(contador<=3)do
                                        begin
                                                mapj[a,b]:='z';
                                                b:=b+1;
                                                contador:=contador+1;         
                                        end;
                                end
                                else
                                begin
                                        writeln('error la posicion no es valida');        
                                end;
                        end;
                end;
        end;
        escribir_mapas(mapj,mapja);
        barco_construido:=false;
        while(barco_construido=false)do
        begin
                writeln('coloque el submarino');
                writeln('escoja direccion , 1 (horizontal > ) 2(vertical v )');
                readln(direccion);
                while((direccion<>1)and(direccion<>2))do
                begin
                        writeln('la direccion no existe escriba 1(horizontal >) o 2(vertical v)');
                        readln(direccion);
                end;
                if(direccion=1)then
                begin   
                        confirmar_primera_cordenada(a);
                        confirmar_segunda_cordenada(b);
                        while((b<>1)and(b<>2)and(b<>3)and(b<>4)and(b<>5)and(b<>6)and(b<>7)and(b<>8))do
                        begin
                                writeln('error se paso de casillas');
                                confirmar_segunda_cordenada(b);
                        end;
                        if((mapj[a,b]='_')and(mapj[a,b+1]='_')and(mapj[a,b+2]='_'))then
                        begin
                                contador:=1;
                                barco_construido:=true;
                                while(contador<=3)do
                                begin
                                        mapj[a,b]:='w';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;
                        end
                        else
                        begin
                                writeln('error la posicion no es valida');        
                        end;
                end                    
                else
                begin
                        confirmar_primera_cordenada(a);
                        confirmar_segunda_cordenada(b);
                        while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6)and(a<>7)and(a<>8))do
                        begin
                                writeln('error se paso de casillas');
                                confirmar_primera_cordenada(a);
                        end;
                        if((mapj[a,b]='_')and(mapj[a,b+1]='_')and(mapj[a,b+2]='_'))then
                        begin
                                contador:=1;
                                barco_construido:=true;
                                while(contador<=3)do
                                begin
                                        mapj[a,b]:='w';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;
                        end
                        else
                        begin
                                writeln('error la posicion no es valida');        
                        end;
                end;
        end;
        escribir_mapas(mapj,mapja);
        barco_construido:=false;
        while(barco_construido=false)do
        begin
                writeln('coloque el patrullero');
                writeln('escoja la direccion  1 (horizontal > ) 2(vertical v )');
                readln(direccion);
                while((direccion<>1)and(direccion<>2))do
                begin
                        writeln('la direccion no existe escriba 1( horizontal > ) o 2( vertical v )');
                        readln(direccion);
                end;
                if(direccion=1)then
                begin   
                        confirmar_primera_cordenada(a);
                        confirmar_segunda_cordenada(b);
                        while((b<>1)and(b<>2)and(b<>3)and(b<>4)and(b<>5)and(b<>6)and(b<>7)and(b<>8))do
                        begin
                                writeln('error se paso de casillas');
                                confirmar_segunda_cordenada(b);
                        end;
                        if((mapj[a,b]='_')and(mapj[a,b+1]='_'))then
                        begin
                                contador:=1;
                                barco_construido:=true;
                                while(contador<=2)do
                                begin
                                        mapj[a,b]:='q';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;
                        end
                        else
                        begin
                                writeln('error la posicion no es valida');        
                        end;
                end
                else
                begin
                        confirmar_primera_cordenada(a);
                        confirmar_segunda_cordenada(b);
                        while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6)and(a<>7)and(a<>8))do
                        begin
                                writeln('error se paso de casillas');
                                confirmar_primera_cordenada(a);
                        end;
                        if((mapj[a,b]='_')and(mapj[a,b+1]='_'))then
                        begin
                                contador:=1;
                                barco_construido:=true;
                                while(contador<=2)do
                                begin
                                        mapj[a,b]:='q';
                                        b:=b+1;
                                        contador:=contador+1;         
                                end;
                        end
                        else
                        begin
                                writeln('error la posicion no es valida');        
                        end;
                 end;
        end;
        escribir_mapas(mapj,mapja);                        
end;
{------------------------------------------------------------------------------------------------------------}
procedure turno_jugador(var a,b:integer);
var c:char;
begin
        writeln('escribir cordenada primera (numero)');
        readln(a);
        writeln('escribir cordenada segunda (letra)');
        read(c);
        while((a<>1)and(a<>2)and(a<>3)and(a<>4)and(a<>5)and(a<>6)and(a<>7)and(a<>8)and(a<>9)and(a<>10))do
        begin
                writeln('escribir cordenada primera (numero)');
                readln(a);
        end;
        while((c<>'i')and(c<>'j')and(c<>'b')and(c<>'a')and(c<>'c')and(c<>'d')and(c<>'e')and(c<>'f')and(c<>'g')and(c<>'h'))do
        begin 
               	writeln('escribir cordenada segunda (letra)');
                readln(c);
        end;
        if(c='a')then
        begin
                b:=1;
        end;
        if(c='b')then
        begin
                b:=2;
        end;
        if(c='c')then
        begin
                b:=3;
        end;
        if(c='d')then
        begin
                b:=4;
        end;
        if(c='e')then
        begin
                b:=5;
        end;
        if(c='f')then
        begin
                b:=6;
        end;
        if(c='g')then
        begin
                b:=7;
        end;
        if(c='h')then
        begin
                b:=8;
        end;
        if(c='i')then
        begin
                b:=9;
        end;
        if(c='j')then
        begin
                b:=10;
        end;
end;
procedure imp_portaaviones(var mapm,mapja:map;var a,b,contador_portaaviones:integer;var porta_aviones_destruido:boolean);
begin      
        if(mapm[a,b]='X')then
        begin
                writeln('a impactado en su porta aviones');
                contador_portaaviones:=contador_portaaviones+1;
                mapm[a,b]:='D';
                mapja[a,b]:='A';
                if(contador_portaaviones=5)then
                begin
                        porta_aviones_destruido:=true;
                        writeln('5to impacto');
                        writeln('a destruido al porta aviones rival');
                end;
        end;
end;
procedure imp_buquedeguerra(var mapm,mapja:map;var a,b,contador_buquedeguerra:integer;var buquedeguerra_destruido:boolean);
begin        
        if(mapm[a,b]='Y')then
        begin
                writeln('a impactado a su buque de guerra');
                contador_buquedeguerra:=contador_buquedeguerra+1;
                mapm[a,b]:='D';
                mapja[a,b]:='A';
                if(contador_buquedeguerra=4)then
                begin
                        buquedeguerra_destruido:=true;
                        writeln('5to impacto');
                        writeln('a destruido al porta aviones rival');
                end;
        end;
end;
procedure imp_destructor(var mapm,mapja:map;var a,b,contador_destructor:integer;var destructor_destruido:boolean);
begin        
        if(mapm[a,b]='Z')then
        begin
                writeln('a impactado a su destructor');
                contador_destructor:=contador_destructor+1;
                mapm[a,b]:='D';
                mapja[a,b]:='A';
                if(contador_destructor=3)then
                begin
                        destructor_destruido:=true;
                        writeln('3to impacto');
                        writeln('a destruido al destructor rival');
                end;
                
        end;
end;
procedure imp_submarino(var mapm,mapja:map;var a,b,contador_submarino:integer;var submarino_destruido:boolean);
begin        
        if(mapm[a,b]='W')then
        begin
                writeln('a impactado a su submarino');
                contador_submarino:=contador_submarino+1;
                mapm[a,b]:='D';
                mapja[a,b]:='A';
                if(contador_submarino=3)then
                begin
                        submarino_destruido:=true;
                        writeln('3to impacto');
                        writeln('a destruido al submarino rival');
                end;
        end;
end;
procedure imp_patrullero(var mapm,mapja:map;var a,b,contador_patrullero:integer;var patrullero_destruido:boolean);
begin
        if(mapm[a,b]='Q')then
        begin
                writeln('a impactado a su submarino');
                contador_patrullero:=contador_patrullero+1;
                mapm[a,b]:='D';
                mapja[a,b]:='A';
                writeln ('el contador lleva',contador_patrullero);
                if(contador_patrUllero=2)then
                begin
                        patrullero_destruido:=true;
                        writeln('2to impacto');
                        writeln('a destruido al patrullero rival');
                end;
        end;
        if(mapm[a,b]='_')then
        begin
                mapja[a,b]:='F';
        end;
end;
procedure turno_maquina(var porta_aviones_destruidoj,buquedeguerra_destruidoj,destructor_destruidoj,submarino_destruidoj,patrullero_destruidoj:boolean; contador_buquedeguerraj,contador_portaavionesj,contador_destructorj,contador_submarinoj,contador_patrulleroj:integer; mapja,mapj:map);
var a,b:integer;
begin
        a:=random(10)+1;
        b:=random(10)+1;
        if(mapj[a,b]<>'_')then
        begin
                if(mapj[a,b]='x')then
                begin
                        writeln('te han dado , portaaviones dañado ');
                        contador_portaavionesj:=contador_portaavionesj+1;
                        mapj[a,b]:='O';
                        if(contador_portaavionesj=5)then
                        begin
                                porta_aviones_destruidoj:=true;
                                writeln('5to impacto');
                                writeln('han destruido tu portaaviones ');
                        end;
                end;
        end;
        if(mapj[a,b]='y')then
        begin
                writeln('han impactado a tu buque de guerra');
                contador_buquedeguerraj:=contador_buquedeguerraj+1;
                mapj[a,b]:='O';
                if(contador_buquedeguerraj=4)then
                begin
                        buquedeguerra_destruidoj:=true;
                        writeln('5to impacto');
                        writeln('han destruido a tu buque de guerra ');
                end;
        end;
        if(mapj[a,b]='z')then
        begin
                writeln('a impactado a su destructor');
                contador_destructorj:=contador_destructorj+1;
                mapj[a,b]:='O';
                if(contador_destructorj=3)then
                begin
                        destructor_destruidoj:=true;
                        writeln('3to impacto');
                        writeln('a destruido al destructor rival');
                end;
        end;
        if(mapj[a,b]='w')then
        begin
                writeln('han impactado a su submarino');
                contador_submarinoj:=contador_submarinoj+1;
                mapj[a,b]:='O';
                if(contador_submarinoj=3)then
                begin
                        submarino_destruidoj:=true;
                        writeln('3to impacto');
                        writeln('han destruido a tu submarino ');
                end;
        end;
        if(mapj[a,b]='q')then
        begin
                writeln('a impactado a tu patrullero');
                contador_patrulleroj:=contador_patrulleroj+1;
                mapj[a,b]:='O';
                if(contador_patrUlleroj=2)then
                begin
                        patrullero_destruidoj:=true;
                        writeln('2to impacto');
                        writeln('han destruido a tu  patrullero ');
                end;
        end;
end;          
var jugar,ganador,porta_aviones_destruidoj,buquedeguerra_destruidoj,destructor_destruidoj,submarino_destruidoj,patrullero_destruidoj,porta_aviones_destruido,buquedeguerra_destruido,destructor_destruido,submarino_destruido,patrullero_destruido,primero:boolean;a,b,contador_patrullero,contador_portaaviones,contador_destructor,contador_submarino,contador_buquedeguerra,contador_buquedeguerraj,contador_portaavionesj,contador_destructorj,contador_submarinoj,contador_patrulleroj:integer; mapja,mapj,mapm:map;
begin
        jugaras(jugar); 
        while(jugar=true)do
        begin
        	writeln('1');
                ganador:=false;
                writeln('2');
                reincio_mapa(mapj,mapja,mapm);
                writeln('3');
                tablero_maquina(mapm);
                writeln('4');
                escribir_mapas(mapj,mapja);
       		writeln('5');
                mapa_fichas_jugador(mapj,mapja,mapm);
                quien_juega(primero);
                porta_aviones_destruidoj:=false;buquedeguerra_destruidoj:=false;destructor_destruidoj:=false;submarino_destruidoj:=false;patrullero_destruidoj:=false;               porta_aviones_destruido:=false;buquedeguerra_destruido:=false;destructor_destruido:=false;submarino_destruido:=false;patrullero_destruido:=false;        contador_patrullero:=0;contador_portaaviones:=0;contador_destructor:=0;contador_submarino:=0;contador_buquedeguerra:=0;contador_patrulleroj:=0;contador_portaavionesj:=0;contador_destructorj:=0;contador_submarinoj:=0;contador_buquedeguerraj:=0;
                while(ganador=false)do
                begin
                        if(primero=true)then
                        begin
                                escribir_mapas(mapj,mapja);
                                writeln('ataque','--->',':v:V;v;V:v:V','<---');
                                turno_jugador(a,b);
                                imp_portaaviones(mapm,mapja,a,b,contador_portaaviones,porta_aviones_destruido);
                                imp_buquedeguerra(mapm,mapja,a,b,contador_buquedeguerra,buquedeguerra_destruido);
                                imp_destructor(mapm,mapja,a,b,contador_destructor,destructor_destruido);
                                imp_submarino(mapm,mapja,a,b,contador_submarino,submarino_destruido);
                                imp_patrullero(mapm,mapja,a,b,contador_patrullero,patrullero_destruido);
                                writeln(contador_portaaviones,'/',contador_buquedeguerra,'/',contador_destructor,'/',contador_submarino,'/',contador_patrullero);
                                primero:=false;
                        end
                        else
                        begin
                                turno_maquina(porta_aviones_destruidoj,buquedeguerra_destruidoj,destructor_destruidoj,submarino_destruidoj,patrullero_destruidoj, contador_buquedeguerraj,contador_portaavionesj,contador_destructorj,contador_submarinoj,contador_patrulleroj,mapja,mapj);
                                primero:=true;
                        end;
                        if((porta_aviones_destruidoj=true)and(buquedeguerra_destruidoj=true)and(destructor_destruidoj=true)and(submarino_destruidoj=true)and(patrullero_destruidoj=true))then
                        begin
                                ganador:=true;
                                writeln ('PERDEDOR');
                        end;
                        if((porta_aviones_destruido=true)and(buquedeguerra_destruido=true)and(destructor_destruido=true)and(submarino_destruido=true)and(patrullero_destruido=true))then
                        begin
                                ganador:=true;
                                writeln ('GANASTE!!');
                        end;
                        
                end;
        jugaras(jugar);     
        end;
end.
