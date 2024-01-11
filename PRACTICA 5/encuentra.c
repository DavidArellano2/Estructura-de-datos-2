/*
	Busca un registro con una llave en particular, en forma
	secuencial a lo largo de un archivo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "toma.h"
//#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);

#include "arches.h"
#define EXITO 1
#define FRACASO 0

main(){
	int fd,long_reg,pos_bus;
	int encontro;
	char llave_bus[30],llave_enc[30],apellido[30],nombre[30];
	char nomarch[15];
	char buffreg[TAM_MAX_REG+1];
	char campo[TAM_MAX_REG+1];
	
	printf("\nIngrese el nombre del archivo a crear: ");
	printf("\n\n  >>  ");
	gets(nomarch);
	
	if((fd = creat(nomarch,SOLOLECT))<0){
		printf("Error en la apertura del archivo - FIN DEL PROGRAMA\n");
		exit(1);
	}
	
	printf("\n\nDigite el apellido: ");/*TOMA LA LLAVE DE BUSQUEDA*/
	gets(apellido);
	printf("\n\nDigite el nombre: ");
	gets(nombre);
	hazllave(apellido,nombre,llave_bus);
	
	encontro=FRACASO;
	while (!encontro && (long_reg = toma_reg(fd,buffreg)) > 0){
		pos_bus=0;
		pos_bus=toma_campo(apellido,buffreg,pos_bus,long_reg);
		pos_bus=toma_campo(nombre,buffreg,pos_bus,long_reg);
		hazllave(apellido,nombre,llave_enc);
		if (strcmp(llave_enc,llave_bus) == 0){
			encontro=EXITO;
		}
	}
	if(encontro){
		printf("\n\nSe encontro el registro: \n\n");
		pos_bus=0;
		
		/*DIVIDE LOS CAMPOS*/
	while((pos_bus=toma_campo(campo,buffreg,pos_bus,long_reg)) > 0)
		printf("\t%s\n",campo);
		
	}else
	printf("\n\nNo se encontro el registro...\n");	
}
