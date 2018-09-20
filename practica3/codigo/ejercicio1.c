/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 3

		 	 Ejercicio 1

	  Blancas Pérez Bryan Israel

	  			3CV1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cont=0;

void merge(int a[],int p, int q, int r){
	int n1=q-p+1;		cont++;		
	int n2=r-q;			cont++;
	int i,j,k;			cont++;
	int l[n1]; 			cont++;
	int right[n2];		cont++;

	cont++;
	for (i = 0; i < n1; i++,cont++){	
		l[i]=a[p+i];	cont++;
	}
	cont++;
	for (j = 0; j < n2; j++,cont++){
		right[j]=a[q+1+j];		cont++;
	}
	i=0;	cont++;
	j=0;	cont++;
	cont++;
	for (k = p; k <= r; k++,cont++){
		if(i<n1 && j<n2){		cont++;	
			if(l[i] <= right[j]){	cont++;
				a[k]=l[i];		cont++;
				i++;			cont++;
			}
			else{				cont++;
				a[k]=right[j];	cont++;
				j++;			cont++;
			}
		}
		else{					cont++;
			if(i==n1){			cont++;
				while(j<n2){	cont++;
					a[k]=right[j];	cont++;
					j++;		cont++;
					k++;		cont++;
				}
			}
			else if(j==n2){		cont++;
				while(i<n1){	cont++;
					a[k]=l[i];	cont++;
					i++;		cont++;
					k++;		cont++;
				}
			}
		}
	}
}

void mergesort(int a[],int p,int r){
	int q;  cont++;
	if(p<r){	cont++;
		q=int((p+r)/2);	cont++;
		mergesort(a,p,q);	cont++;
		mergesort(a,q+1,r);	cont++;
		merge(a,p,q,r);	cont++;
	}
}

int main(int argc, char const *argv[]){
	int n;
 	srand(time(NULL));
	FILE *q;q=fopen("output2.txt","a");

	scanf("%d",&n);
	int a[n];

	for (int i=0; i<n;i++){
		a[i]=rand()%10;	
		printf("%d,",a[i]);
	}

	printf("\n");

	mergesort(a,0,n-1);
	fprintf(q, "%d\t%d\n",n,cont);
	
	printf("\n");
	for (int i=0;i<n;i++)
		printf("%d,",a[i]);

	printf("\n");
	fclose(q);
	return 0;
}