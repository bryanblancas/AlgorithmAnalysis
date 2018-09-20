#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int suma(int a[],int b[],int n);

int main(int argc, char const *argv[])
{
	int n,cont;
	FILE *o;o=fopen("output.txt","a");
	srand(time(NULL));
	scanf("%d",&n);

	//declaración de los arreglos
	int a[n];
	int b[n];

	//llenado de arreglos con 0 y 1
	for(int i=0;i<n;i++){
		a[i]=rand()%2;
		b[i]=rand()%2;
	}

	//mandar arreglos a la función de suma
	cont=suma(a,b,n);

	fprintf(o, "%d\t%d\n",n,cont);
	fclose(o);
	return 0;
}

int suma(int a[],int b[],int n){
	int c[n],cont=1,i,acarreo=0;

	cont++;
	
	for(i=n-1;i>=0;i--,cont++){
		//suma
		c[i]=a[i]+b[i]+acarreo;	cont++;
		//verificación de suma
		if(c[i]==2){ 			cont++;
			c[i]=0;				cont++;
			acarreo=1;			cont++;
		}
		else if (c[i]==3){		cont++;
			c[i]=1;				cont++;
			acarreo=1;			cont++;
		}
		else{					cont++;
			acarreo=0;			cont++;
		}
	
		printf("%d %d = %d\n",a[i],b[i],c[i]);
	}
	//retornar contador(tiempo)
	return cont;
}
