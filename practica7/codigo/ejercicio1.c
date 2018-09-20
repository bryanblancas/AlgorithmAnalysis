/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 7

		 Secuencia de Matrices

	  Blancas Pérez Bryan Israel

	  			3CV1
*/

#include <stdio.h>
#include <stdlib.h>
#define verde "\x1B[32m"
#define rojo "\x1B[31m"
#define cerrar "\x1B[00m"

typedef struct {
	int **m;
	int **s;
} retorno;

retorno sm(int *p, int tam){
	int n=tam-1;
	int **m,**s,l,j,i,k,q;
	retorno r;

	m=(int **)malloc(sizeof(int *)*(n+1));
	for(int i=0;i<(n+1);i++)
		m[i]=(int *) malloc(sizeof(int)*(n+1));

	s=(int **)malloc(sizeof(int *)*(n+1));
	for(int i=0;i<(n+1);i++)
		s[i]=(int *) malloc(sizeof(int)*(n+1));
	
	for(int i=0 ; i<n+1 ; i++)
		m[i][i]=0;

	for( l=2 ; l<=n ; l++)
		for( i=1 ; i<=(n-l+1);i++){
			 j=i+l-1;
			m[i][j]=0x7fffffff;
			for( k=i; k<j ; k++){
				 q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if (q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}

	r.m=m;
	r.s=s;

	free(m);
	free(s);
	return r;
}

void IPO(int **s, int i, int j){
	if (i==j)
		printf(" A%d ",i);
	else{
		printf(rojo"("cerrar);
		IPO(s,i,s[i][j]);
		IPO(s,s[i][j]+1,j);
		printf(rojo")"cerrar);
	}
}

int main(int argc, char const *argv[]){
	int tam,num;
	int *p;

	scanf("%d",&tam);
	printf("%d : ",tam);

	p=(int *)malloc(sizeof(int)*tam);
	for(int i=0;i<tam;i++){
		scanf("%d",&num);
		*(p+i)=num;
	}

	for(int i=1;i<tam;i++)
		printf(verde"A%d:(%d,%d) "cerrar,i,*(p+i-1),*(p+i));

	printf("\n");
	retorno r=sm(p,tam);

	IPO(r.s,1,tam-1);

	printf("\n");
	free(p);
	return 0;
}
