#include <stdio.h>
#include <stdlib.h>

long int fibonacciIte(int n, FILE *o){
	long int cont=1,a=0,b=1,aux=0;
	if (n<2){ 	cont++;
				cont++;
		aux=1;
	}
	cont++;
	for (int i = 2; i<=n; i++,cont++){
		aux=a+b;	cont++;
		a=b;		cont++;
		b=aux;		cont++;
	}
	cont++;
	fprintf(o, "%d\t%li\n",n,cont);
	return aux;
}

long fibonacciRec(long n, int * cont){
	if (n<2){		*cont=(*cont)+1;
		return n;	*cont=(*cont)+1;
	}
	*cont=(*cont)+1;
	return fibonacciRec(n-1,cont)+fibonacciRec(n-2,cont);	
}

int main(int argc, char const *argv[]){
	int n,cont=0;
	scanf("%d",&n);
	FILE *i,*i2;
	i=fopen("output1.txt","a");
	i2=fopen("output2.txt","a");
	
	printf("Iterativo: %li\n",fibonacciIte(n,i));

	printf("Recursivo: %li\n",fibonacciRec(n,&cont));
	fprintf(i2, "%d\t%d\n",n,cont);

	fclose(i);
	fclose(i2);

	return 0;
}

//developed by Bryan Blancas