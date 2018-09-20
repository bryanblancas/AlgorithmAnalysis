/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 6

	Máximo SubArreglo (Fuerza Bruta)

	  Blancas Pérez Bryan Israel

	  			3CV1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;

int ms(int *a, int n){
	int max=0,suma;			cont++;
	for(int i=0;i<n;i++,cont++){	
		suma=0;			cont++;
		for (int j = i; j < n; j++,cont++){
			suma+=a[j];		cont++;
			if (suma>max){	cont++;	
				max=suma;	cont++;
			}
		}
	}
	cont++;
	return max;
}

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int *a,n;

	FILE *i;
	i=fopen("output4.txt","a");

	printf("n: ");
	scanf("%d",&n);

	a=(int *)malloc(sizeof(int)*n);

	for (int i = 0; i < n; ++i){
		a[i]=rand()%10;
		if(rand()%2)
			a[i]*=-1;
		printf("%d ",a[i]);
	}
	printf("\n");

	printf("%d\n",ms(a,n));
	
	fprintf(i,"%d\t%d\n",n,cont);

	fclose(i);
	free(a);
	return 0;

}