#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int euclides(int m, int n){
	int r,cont=1;
	while (n!=0){
				cont++;
		r=m%n;	cont++;
		m=n;	cont++;	
		n=r;	cont++;
	}
	printf("mcd: %d\n",m); cont++;
	//retornar contador (tiempo)
	return cont;
}

int main(int argc, char const *argv[]){
	int suma,a=0,b=1,cont,op,i=0;
	srand(time(NULL));
	FILE *o;o=fopen("output2.txt","a");

	printf("1:Random -- 2:Fibonacci\n");
	scanf("%d",&op);

	if(op==1){
		while(i<=20){
			//elegir dos números al azar
			a=rand()%1001;
			b=rand()%1001;
			//mandar los números a la función euclides
			cont=euclides(a,b);
			//imprimir en archivo
			fprintf(o, "%d\t%d\n",a>b?a:b,cont);
			i++;
		}
	}
	else{
		//serie de fibonacci hasta dígito número 17
		for(int i=0;i<17;i++){
			suma=a+b;
			cont=euclides(a,b);
			fprintf(o, "%d\t%d\t%d\n",a,b,cont);
			a=b;
			b=suma;
		}
	}

	fclose(o);
	return 0;
}