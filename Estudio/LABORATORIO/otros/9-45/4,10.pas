program desea_continuar;
var n,S,N:char;
begin
read (n) ;
while('n'<>'S')or('n'<>'N')do
begin
writeln ('desea continuar S o N');
read (n) ;
end;
if (n=N)then
begin
while('n'<>'N')do
begin
if('n'='S')then
begin
writeln('desea continuar S o N') ;
read (n) ;
end;
end;
writeln ('cierre de bucle');
end.
