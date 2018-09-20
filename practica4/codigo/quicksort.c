/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 4

		 	 QuickSort

	  Blancas Pérez Bryan Israel

	  			3CV1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;
void exchange(int a[], int j, int i);
int partition(int a[], int p, int r);
void quicksort(int a[], int p, int r);

int main(int argc, char const *argv[]){
	int n;
	srand(time(NULL));
	FILE *out;out=fopen("output3.txt","a");

	scanf("%d",&n);
	int a[n];

	for (int i = 0; i < n; i++){
		a[i]=rand()%101;
		printf("%d,", a[i]);
	}

	quicksort(a,0,n-1);

	printf("\n");
	for (int i = 0; i < n; ++i){
		printf("%d,", a[i]);
	}
	printf("\n");

	fprintf(out, "%d\t%d\n",n,cont);

	fclose(out);

	return 0;
}

void exchange(int a[], int j, int i){
	int aux=a[j];	cont++;
	a[j]=a[i];		cont++;
	a[i]=aux;		cont++;
}

int partition(int a[], int p, int r){
	int x=a[r];		cont++;
	int j=p-1;		cont++;
	int i;			cont++;
	cont++;

	/*printf("\nOriginal: \n");
	for(int k=p;k<=r;k++)
		printf("%d,",a[k]);
	printf("\n");*/

	for(i=p; i<r; i++,cont++){
		if(a[i]<x){		cont++;
			j++;		cont++;
			exchange(a,j,i);	cont++;
		}
	}
	j++;	cont++;
	exchange(a,j,r);	cont++;
	cont++;
	/*printf("final privote %d: \n",j);
	for(int k=p;k<=r;k++)
		printf("%d,",a[k]);
	printf("\n");*/
	return j;
}

void quicksort(int a[], int p, int r){
	int q;
	if(p<r){		cont++;
		q=partition(a,p,r);		cont++;
		/*printf("%d < %d\n",q,r);
		printf("%d < %d\n",p,q);*/
		quicksort(a,p,q-1);			cont++;
		if(q<r){
			quicksort(a,q+1,r);			cont++;
		}
	}
}
