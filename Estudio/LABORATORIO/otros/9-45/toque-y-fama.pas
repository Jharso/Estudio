program toque_y_fama ;
var d,c,b,a,x,y,z,w,famas,flag,toques,numero,intentos,aux,aux2:integer;
begin
    famas:=0;
    intentos:=0;
    randomize;{inicio de numero maquina}
    a:=random(8)+1;{a=unidad de mil}
    randomize;
    b:=random(8)+1;
    while(a=b)do
    begin 
        randomize;
        b:=random(8)+1;{b=centena}
        end;
    randomize; 
    c:=random(8)+1;{c=decena}
    while ((a=c)or(b=c))do
    begin
        randomize;
        c:=random(8)+1;
        end;
    randomize;
    d:=random(8)+1;{d=unidad}
    while ((a=d)or(b=d)or(c=d))do
    begin
        randomize;
        d:=random(8)+1;
        end;
    while((intentos<=4)and(famas<4))do{ciclo de juego}
    begin
        if(famas<>4)then
        begin
            flag:=0;intentos:=intentos+1;famas:=0;toques:=0;
            end;
        while(flag=0)do{solo si el numero esta bien ingresado flag cambiara a 1 }
        begin
             writeln('ingrese numero porfabor :) ..... ');
             readln(numero);
             x:=trunc(numero/1000);
             aux:=numero-(x*1000);
             y:=trunc(aux/100);
             aux2:=numero-((x*1000)+(y*100));
             z:=trunc(aux2/10);
             w:=(numero mod 10);
             if(w=z)or(w=y)or(w=x)or(z=y)or(z=x)or(y=x)then
             begin       
                 writeln('los digitos del numero ingresado no deben repetirse');
                 end
             else
             begin
                if((x=0)or(y=0)or(z=0)or(w=0))then
                begin
                    writeln('el numero no debe contener 0')
                    end
                else
                begin
                     flag:=1;
                     end;
                 end;
             end;
        if(a=x)then{comparaciones de los digitos ingresado con los de la maquina}
        begin
            famas:=famas+1;
            end;
        if(b=y)then
        begin
            famas:=famas+1;
            end;
        if(c=z)then
        begin
            famas:=famas+1;
            end;
        if(d=w)then
        begin
            famas:=famas+1;
            end;
        if(famas<>4)then
        begin
            if((a=y)or(a=z)or(a=w))then
            begin
                toques:=toques+1;
                end; 
            if((b=x)or(b=z)or(b=w))then
            begin
                toques:=toques+1;
                end; 
            if((c=x)or(c=w)or(c=y))then
            begin
                toques:=toques+1;
                end;    
           if((d=y)or(d=z)or(d=x))then
           begin
                toques:=toques+1;
                end; 
            writeln('las famas son' , famas , 'los toques', toques);{tablero}
            end;
        end;
    if(famas>=4)then
    begin
        writeln('ganaste en el turno....' , intentos );{cartel de victorio}
        end
    else
    begin
        writeln('perdiste wujajajaj >.<');{cartel de derrota}
        end;
    end.
