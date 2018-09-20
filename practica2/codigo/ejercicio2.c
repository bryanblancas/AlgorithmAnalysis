#include <stdio.h>
#include <stdlib.h>
long int s(int n,int * cont){
	if (n==1){		*cont=(*cont)+1;
					*cont=(*cont)+1;
		return 1;	
	}
	else {		*cont=(*cont)+1;
				*cont=(*cont)+1;
		return s(n-1,cont)+n*n*n;
	}
}

long int si(int n, int * cont){
	long int aux=0;(*cont)++;
	(*cont)++;
	for(int i=1;i<=n;i++,(*cont)++){
		aux+=i*i*i;		(*cont)++;
	}
	(*cont)++;
	return aux;
}
int main(int argc, char const *argv[]){
	int n,cont=0,cont2=0;	
	FILE *i,*i2;

	i=fopen("output3.txt","a");
	i2=fopen("output4.txt","a");


	scanf("%d",&n);
	printf("Recursivo: %li\n",s(n,&cont));
	printf("Iterativo: %li\n",si(n,&cont2));

	fprintf(i, "%d\t%d\n",n,cont);
	fprintf(i2, "%d\t%d\n",n,cont2);
	fclose(i);
	fclose(i2);
	return 0;
}

//Developed by Bryan Blancas