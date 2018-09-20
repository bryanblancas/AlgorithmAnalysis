/*
	INSTITUTO POLITÉNICO NACIONAL

				ESCOM
		
		Análisis de Algoritmos
	
		 Benjamín Luna Benoso

		 	Práctica No. 10

		  Ciclo Hamiltoniano

	  Blancas Pérez Bryan Israel

	  			3CV1
*/

#include <stdio.h>
#include <stdlib.h>

int contador=0;

typedef struct {
	int ini,fin;
}LA;

int verificacion_hamilton(LA *la,LA *asol,int a,int as,int p){
	int i,j,cont,fre_nodo[p][2];

	/*Verificar que los nodos de las solución existan en el grafo*/
	for(int i=0;i<as;i++,contador++)
		if((asol[i].ini > p || asol[i].fin > p) || (asol[i].ini <= 0 || asol[i].fin <= 0)){
			printf("Nodo inexistente\n");
			return 0;
		}

	/*Verificar que exista la arista por la que pasa*/
	for(i=0;i<as;i++,contador++){
		cont=0;
		for(j=0;j<a;j++,contador++){
			if(asol[i].ini == la[j].ini){
				if(asol[i].fin == la[j].fin)
					break;
				cont++;
			}
			else if(asol[i].ini == la[j].fin){
				if(asol[i].fin == la[j].ini)
					break;
				cont++;
			}
			else
				cont++;
		}
		if(cont==a){
			printf("Arista inexistente\n");
			return 0;
		}
	}
	
	/*Verificar que visite cada nodo una y sólo una vez*/
	for (i=0;i<p;++i,contador++)
		for(j=0;j<2;j++)
			fre_nodo[i][j]=0;
	
	j=0;
	for(i=0;i<p;i++,contador++)
		fre_nodo[i][0]=asol[j++].ini;


	for(i=0;i<as;i++,contador++){
		for(j=0;j<p;j++,contador++){
			if(asol[i].ini==fre_nodo[j][0])
				fre_nodo[j][1]++;
			if(asol[i].fin==fre_nodo[j][0])
				fre_nodo[j][1]++;
		}
	}

	for(i=0;i<p;i++,contador++){
		if(fre_nodo[i][1]<2){
			printf("NO es un circuito\n");
			return 0;
		}
		else if(fre_nodo[i][1]>2){
			printf("Nodo visitado más de una vez\n");
			return 0;
		}
	}

	return 1;
}

int main(int argc, char const *argv[]){
	
	FILE *sol,*o;
	sol=fopen("solucion.txt","r");
	o=fopen("output.txt","a");
	int p,a,i=0,as;
	scanf("%d",&p);
	scanf("%d",&a);

	LA la[a];
	while(i<a){
		scanf("%d",&(la[i].ini));
		scanf("%d",&(la[i++].fin));
	}
	fscanf(sol,"%d",&as);
	LA asol[as];
	i=0;
	while(i<as){
		fscanf(sol,"%d",&(asol[i].ini));
		fscanf(sol,"%d",&(asol[i++].fin));
	}
	
	printf("%s\n",verificacion_hamilton(la,asol,a,as,p)?"Es un ciclo hamiltoniano":"No es un ciclo hamiltoniano");

	fprintf(o, "%d\t%d\n",p,contador);

	fclose(o);
	fclose(sol);
	return 0;
}