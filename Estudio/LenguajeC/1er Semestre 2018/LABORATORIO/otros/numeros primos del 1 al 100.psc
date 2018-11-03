Algoritmo primos
	definir a,b,c Como Entero
	a<- 1
	mientras a<= 100 Hacer
		b<- 1;
		c<- 0;
		Mientras b<= a Hacer
			si a%b = 0 Entonces
				c<- c+1;
			FinSi
			b<- b+1
		FinMientras
		si c=2 entonces
			Escribir a;
		FinSi
		a<- a+1;
	FinMientras
FinAlgoritmo
