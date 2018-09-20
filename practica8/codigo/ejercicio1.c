/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 8

	 Subsecuencia común más larga.

	  Blancas Pérez Bryan Israel

	  			3CV1
*/

#include <stdio.h>
#include <stdlib.h>
#define verde "\x1B[32m"
#define rojo "\x1B[31m"
#define cerrar "\x1B[00m"
#define tam 500
char array[tam];
int k=0;

int max(int a, int b){
	return a>b?a:b;
}

int ** lcs(char *a,int la, char *b, int lb){
	int **c;
	c=(int **)malloc(sizeof(int *)*(la+1));
	for (int i=0; i<=la; ++i)
		c[i]=(int *) malloc(sizeof(int)*lb+1);

	for (int i=1 ; i<=la ; i++)
		for(int j=1 ; j<=lb ; j++){
			if (a[i-1]==b[j-1])
				c[i][j]=c[i-1][j-1] + 1;
			else
				c[i][j]=max(c[i][j-1], c[i-1][j]);
		}
	
	return c;
}

void flcs(int **c,char *a,char *b,int i,int j){
	if(i==0 || j==0)
		return;
	else if(a[i-1]==b[j-1]){
			flcs(c,a,b,i-1,j-1);
			array[k++]=a[i-1];
		}
	else{
		if(c[i][j-1] > c[i-1][j])
			return flcs(c,a,b,i,j-1);
		else
			return flcs(c,a,b,i-1,j);
	}
}

int main(int argc, char const *argv[]){

	FILE *i1,*i2;
	i1=fopen(argv[1],"r");
	if(i1==NULL) {printf("ERROR AL ABRIR ARCHIVO: %s\n",argv[1]);exit(1);}
	i2=fopen(argv[2],"r");
	if(i2==NULL) {printf("ERROR AL ABRIR ARCHIVO: %s\n",argv[2]);exit(1);}

	int la,lb,i,j;
	char a[tam],ca[tam];
	char b[tam],cb[tam];

	fgets(a,tam,i1);
	fgets(b,tam,i2);

	for(i=0,j=0;a[i]!='\0';i++)
		if(a[i]!=' ')
			ca[j++]=a[i];
	ca[j]='\0';
	la=j;
	for(i=0,j=0;b[i]!='\0';i++)
		if(b[i]!=' ')
			cb[j++]=b[i];
	cb[j]='\0';
	lb=j;
	
	printf("Contenido Archivo 1: "verde"%s\n"cerrar,a);
	printf("Contenido Archivo 2: "verde"%s\n"cerrar,b);

	int **c=lcs(ca,la,cb,lb);
	flcs(c,ca,cb,la,lb);

	printf("LCS (sin considerar espacios): ");
	for(i=0;i<k;i++)
		printf(rojo"%c",array[i]);
	printf("\n"cerrar);
	
	double m=la>lb?la:lb;
	printf("Porcentaje de semejanza: %.2f \n",(double)(k/m)*100);

	free(c);
	fclose(i1);
	fclose(i2);

	return 0;
}
