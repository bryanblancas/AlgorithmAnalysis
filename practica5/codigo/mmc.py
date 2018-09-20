#	INSTITUTO POLITÉNICO NACIONAL
#
#				ESCOM
#
#		Análisis de Algoritmos
#
#		 Benjamín Luna Benoso
#
#		 	Práctica No. 5
#
#		 	 Strassen (mmc)
#
#	  Blancas Pérez Bryan Israel
#
#	  			3CV1

import numpy as np
import random as r
from time import time

cont=0

def mmc(a,b,n):
	
	global cont
	c=np.zeros((n,n),dtype=np.int16)

	if (n==2):
		cont+=1
		c=np.dot(a,b)
		return c
	
	else:
		a11=np.zeros((n/2,n/2),dtype=np.int16)
		a12=np.zeros((n/2,n/2),dtype=np.int16)
		a21=np.zeros((n/2,n/2),dtype=np.int16)
		a22=np.zeros((n/2,n/2),dtype=np.int16)
		b11=np.zeros((n/2,n/2),dtype=np.int16)
		b12=np.zeros((n/2,n/2),dtype=np.int16)
		b21=np.zeros((n/2,n/2),dtype=np.int16)
		b22=np.zeros((n/2,n/2),dtype=np.int16)
		c11=np.zeros((n/2,n/2),dtype=np.int16)
		c12=np.zeros((n/2,n/2),dtype=np.int16)
		c21=np.zeros((n/2,n/2),dtype=np.int16)
		c22=np.zeros((n/2,n/2),dtype=np.int16)
		
		#primer cuadrante
		for i in range(0,n/2):
			for j in range(0,n/2):
				a11[i,j]=a[i,j]
				b11[i,j]=b[i,j]
		#segundo cuadrante
		k=0
		l=0
		for i in range(0,n/2):
			l=0
			for j in range(n/2,n):	
				a12[k,l]=a[i,j]
				b12[k,l]=b[i,j]
				l=l+1
			k=k+1
		#tercer cadrante
		k=0
		l=0
		for i in range(n/2,n):
			l=0
			for j in range(0,n/2):
				a21[k,l]=a[i,j]
				b21[k,l]=b[i,j]
				l=l+1
			k=k+1
		#cuarto cuadrante
		k=0
		l=0
		for i in range(n/2,n):
			l=0
			for j in range(n/2,n):
				a22[k,l]=a[i,j]
				b22[k,l]=b[i,j]
				l=l+1
			k=k+1

		cont+=1;
		c11=mmc(a11,b11,n/2)+mmc(a12,b21,n/2)
		cont+=1;
		c12=mmc(a11,b12,n/2)+mmc(a12,b22,n/2)
		cont+=1;
		c21=mmc(a21,b11,n/2)+mmc(a22,b21,n/2)
		cont+=1;
		c22=mmc(a21,b12,n/2)+mmc(a22,b22,n/2)

		for i in range(0,n/2):
			for j in range(0,n/2):
				c[i,j]=c11[i,j]
		k=0
		l=0
		for i in range(0,n/2):
			l=0
			for j in range(n/2,n):
				c[i,j]=c12[k,l]
				l=l+1
			k=k+1
		k=0
		l=0
		for i in range(n/2,n):
			l=0
			for j in range(0,n/2):
				c[i,j]=c21[k,l]
				l=l+1
			k=k+1
		k=0
		l=0
		for i in range(n/2,n):
			l=0
			for j in range(n/2,n):
				c[i,j]=c22[k,l]
				l=l+1
			k=k+1

		return c

class main():
	global cont

	o=open("output.txt","a")
	
	n=input("n: ")
	a=np.zeros((n,n),dtype=np.int16)
	b=np.zeros((n,n),dtype=np.int16)
	
	for i in range(0,n):
		for j in range(0,n):
			a[i,j]=r.randrange(0,2,1)
			b[i,j]=r.randrange(0,2,1)

	c=mmc(a,b,n)
	print "a: \n",a
	print "b: \n",b
	print "c: \n",c

	line=str(n)+"\t"+str(cont)+"\n"
	
	o.write(line)
	o.close() 
