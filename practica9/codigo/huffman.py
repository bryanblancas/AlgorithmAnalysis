# -*- coding: utf-8 -*-#

#	INSTITUTO POLITÉCNICO NACIONAL
#
#				ESCOM
#
#		Análisis de Algoritmos
#
#		 Benjamín Luna Benoso
#
#		 	Práctica No. 9
#
#    Estrategia Greedy - Huffman
#
#	  Blancas Pérez Bryan Israel
#
#	  			3CV1

import sys
from heapq import heapify,heappop,heappush

def existLetter(letters, char):
	k=0
	for node in letters:
		if (node[1]==char):
			return k 
		k+=1
	return -1

def getFrecuency(i):
	letters=[]
	k=0
	for line in i:
		for char in line:
			k=existLetter(letters,char)
			if (k==-1):
				letters.append([1,char])
			else:
				aux=letters[k]
				aux[0]+=1
				letters[k]=aux
	return letters

def encode(letters):
	heap=[[frecuence,[char, '']] for frecuence, char in letters]
	heapify(heap)

	while (len(heap)>1):
		x=heappop(heap)
		y=heappop(heap)

		for i in x[1:]:
			i[1]='0'+i[1]
		for i in y[1:]:
			i[1]='1'+i[1]

		heappush(heap,[x[0]+y[0]]+x[1:]+y[1:])

	return heappop(heap)

class main():
	i=open("original.txt",'r')
	frecuence=open("frecuencias.txt",'w')
	fencode=open("codificacion.txt",'w')
	encodeFile=open("archivo_codificado.txt",'w')

	letters=getFrecuency(i)
	letters.sort()

	for node in letters:
		frecuence.write(str(node[1])+"\t"+str(node[0])+"\n")

	ec=encode(letters)
	code=[]
	for node in ec[1:]:
		code.append([node[1],node[0]])
		fencode.write(node[0]+"\t"+node[1]+"\n")

	i.close()
	i=open("original.txt",'r')

	txt=""
	bto=0
	for line in i:
		for char in line:
			bto+=1
			k=existLetter(code,char)
			aux=code[k]
			txt+=aux[0]

	encodeFile.write(txt)

	print "Tam del archivo original: "+str(bto)+" bytes\nTam del archivo codificado: "+str(len(txt)/8.0)+" bytes"

	i.close()
	frecuence.close()
	fencode.close()
	encodeFile.close()