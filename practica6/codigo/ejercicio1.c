/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 6

		   Máximo SubArreglo

	  Blancas Pérez Bryan Israel

	  			3CV1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;

typedef struct {
	int min;
	int max;
	int suma;
}retorno;

retorno msc(int *a,int bajo, int medio,int alto){
	int sumaizq=a[medio],suma=0,min_izq=medio; cont++;
	int sumader=a[medio+1],suma1=0,max_der=medio+1; cont++;

	retorno m;

	for(int i=medio;i>=bajo;i--,cont++){
		suma+=a[i]; 		cont++;
		if(suma>sumaizq){ 	cont++;
			sumaizq=suma; 	cont++;
			min_izq=i;		cont++;
		}
	}
	for(int i=medio+1;i<=alto;i++,cont++){
		suma1+=a[i];		cont++;
		if(suma1>sumader){	cont++;
			sumader=suma1;	cont++;
			max_der=i;		cont++;
		}
	}

	m.min=min_izq;
	m.max=max_der;
	m.suma=sumaizq+sumader;

	cont++;
	return m;
}

retorno ms(int *a, int bajo, int alto){
	retorno m,m1,m2; 	cont++;
	if(bajo==alto){		cont++;
		m.min=bajo;		cont++;
		m.max=alto;		cont++;
		m.suma=a[bajo];	cont++;
						cont++;
		return m;
	}
	else{							cont++;
		int medio=(bajo+alto)/2;	cont++;	
		m=ms(a,bajo,medio);			cont++;
		m1=ms(a,medio+1,alto);		cont++;
		m2=msc(a,bajo,medio,alto);	cont++;

		if(m.suma >= m1.suma && m.suma >= m2.suma){
			cont++;cont++;
			return m;
		}
		else if(m1.suma >= m.suma && m1.suma >= m2.suma){
			cont++;cont++;
			return m1;
		}
		else{
			cont++;cont++;
			return m2;
		}
	}
}

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int *a,n;

	FILE *i;
	i=fopen("output2.txt","a");

	printf("n: ");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; ++i){
		a[i]=(rand()%10);
		if(rand()%2)
			a[i]*=-1;
		printf("%d ",a[i]);
	}
	printf("\n");
	retorno m=msc(a,0,n/2,n-1);

	printf("min_izq: %d\n", m.min);
	printf("max_der: %d\n", m.max);
	printf("suma: %d\n",m.suma);

	fprintf(i,"%d\t%d\n",n,cont);

	fclose(i);
	free(a);
	return 0;
}