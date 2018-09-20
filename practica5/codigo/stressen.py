
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
#		 	   Strassen
#
#	  Blancas Pérez Bryan Israel
#
#	  			3CV1


import numpy as np
import random as r
from time import time

cont=0

def stressen(a,b,n):
	
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

		#asignacion de s
		cont+=1
		s1=stressen((a12-a22),(b21+b22),n/2)
		cont+=1
		s2=stressen((a11+a22),(b11+b22),n/2)
		cont+=1
		s3=stressen((a11-a21),(b11+b12),n/2)
		cont+=1
		s4=stressen((a11+a12),b22,n/2)
		cont+=1
		s5=stressen(a11,(b12-b22),n/2)
		cont+=1
		s6=stressen(a22,(b21-b11),n/2)
		cont+=1
		s7=stressen((a21+a22),b11,n/2)
		
		cont+=1
		c11=s1+s2-s4+s6
		cont+=1
		c12=s4+s5
		cont+=1
		c21=s6+s7
		cont+=1
		c22=s2-s3+s5-s7

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
	o=open("output2.txt","a")

	n=input("n: ")
	a=np.zeros((n,n),dtype=np.int16)
	b=np.zeros((n,n),dtype=np.int16)
	
	for i in range(0,n):
		for j in range(0,n):
			a[i,j]=r.randrange(1,3,1)
			b[i,j]=r.randrange(1,3,1)
	
	c=stressen(a,b,n)
	print "a: \n",a
	print "b: \n",b
	print "c: \n",c

	line=str(n)+"\t"+str(cont)+"\n"
	
	o.write(line)
	o.close() 