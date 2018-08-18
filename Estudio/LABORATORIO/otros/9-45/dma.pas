program mi_primera_vez;
var dia, mes, ano, dd, mm ,aa ,flag: integer;

begin{inicio programa principal}
	writeln('ingrese dia, mes, año');
	read(dia,mes,ano);
	while((dia>=1) and (dia<=31)and(mes>=1) and (mes<=12))do
	begin
		flag:=0;
		if((mes=12) and (dia=31))then
		begin
			aa:=ano+1; mm:=1; dd:=1; flag:=1;
		end;
		if((dia=31) and (mes<>12))then
		begin
			aa:=ano; mm:=mes+1; dd:=1; flag:=1;
		end;
		if((dia=30) and ((mes=4)or(mes=6)or(mes=9)or(mes=11)))then
		begin
			aa:=ano+1; mm:=1; dd:=1; flag:=1;
		end;
		if((mes=2) and (dia=28)and(ano mod 4 <>0))then
		begin
			aa:=ano; mm:=mes+1; dd:=1; flag:=1;
		end;
		if((mes=2) and (dia=29))and(ano mod 4=0)then
		begin
			aa:=ano; mm:=mes+1; dd:=1; flag:=1;
		end;
		if(flag=0)then
		begin
			aa:=ano; mm:=mes; dd:=dia+1;
		end;
		writeln;writeln;
		writeln('Fecha original:',' ',dia,'/',mes,'/',ano);
		writeln(' ');
		writeln('Fecha dia siguiente:',' ',dd,'/',mm,'/',aa);
	end;
	writeln('Ingrese una fecha valida');
end.{fin programa principal}
