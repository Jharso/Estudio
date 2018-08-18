program matiz_intento_1 ;
type 
	vec=array[1..4] of char;
	var indice:integer;vect:vec;
begin
	indice:=0;
	vect[1]:='a';
	vect[2]:='b';
	vect[3]:='c';
	vect[4]:='d';
	while (indice<4)do
	begin
		indice:=indice+1;
		writeln ('el vector ' , indice ,'tiene la cadena  ', vect[indice]);
	end;
end.
