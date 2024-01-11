/* LEESEC.C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arches.h"

main(){
	int fd,n;
	char cad[30];
	char nomarch[15];
	int cont_campos;
	
	printf("Proporcione el nombre del archivo a leer: ");
	gets(nomarch);
	if((fd = creat(nomarch,SOLOLECT)) < 0){
		printf("Error en la apertura del archivo = FIN DEL PROGRAMA\n");
		exit(1);
	}
	
/*Ciclo del programa principal (llama a leecampo() hasta que se
	leen todos los campos)*/
	cont_campos = 0;
	while((n = leecampo(fd,cad)) > 0){
		printf("\t Campo # %3d: %s\n",++cont_campos,cad);
	}
	close(fd);
}
	
leecampo(fd,cad)
	int fd;
	char cad[];
	{	
	int i = 0;
	char c;
	
	while(read(fd,&c,1) > 0 && c != DELIM_CAR)
		cad[i++] = c;
		cad[i] = '\0'; /*Agrega un caracter nulo al final de la cadena*/
		return (i);
	}	

