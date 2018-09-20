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
#Estrategia Greedy - Decodificación Huffman 
#
#	  Blancas Pérez Bryan Israel
#
#	  			3CV1

def findEncode(encode,word):
	k=0
	for node in encode:
		if word==node[1]:
			return k
		k+=1
	return -1

def decode(encode,i):
	word=""
	txt=""
	for line in i:
		for char in line:
			word+=char
			k=findEncode(encode,word)
			if k!=-1:
				node=encode[k]
				txt+=node[0]
				word=""

	return txt

class main():
	i=open("archivo_codificado.txt",'r')
	fencode=open("codificacion.txt",'r')
	decoding=open("archivo_decodificado.txt",'w')

	encode=[]
	for line in fencode:
		encode.append([line[0],line[2:-1]])

	txtDecode=decode(encode,i)

	decoding.write(txtDecode)

	i.close()
	fencode.close()
	decoding.close()