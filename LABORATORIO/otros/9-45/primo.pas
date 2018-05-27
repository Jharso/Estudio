program primer_codigo;


var 
n , auxiliar , contador :integer;
begin
        writeln ('bienvenidos , este programa es para saber si es primo o no lo es');
read (n);
        contador:= 2
while(contador<n)do;
begin
       auxiliar:=n;
       while(auxiliar>=contador)do
              begin
              auxiliar:=auxiliar-contador;
       end;
       if(auxiliar=0)then
       begin
       contador:=n;
       end;      
        contador:=contador+1;
end;
if(auxiliar=0)then
begin
writeln('no es primo');
end
else
writeln('es primo');
begin
end.

   
