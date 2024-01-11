#include<stdio.h>
#include<string.h>
#include "Arches.h"
#include "funscads.h"
#include "Tomar.h"
#include "hazllave.h"
#define EXITO    1
#define FRACAS 0

int fd,long_reg,pos_bus;
int encontro;

char llave_bus[30],llave_enc[30],apellido[30],nombre[30];
char nomarch[15];
char buffreg[TAM_MAX_REG+1];
char campo[TAM_MAX_REG+1];

main()
{
	printf("Proporcione el nombre del archivo en donde buscar: ");
	gets(nomarch);
	if((fd=open(nomarch,SOLOLECT))<0)
	{
		printf("Error en la apertura del archivo din del programa\n");
		exit(1);
	}
	printf("\n\nDigite el apellido: ");
	gets(apellido);
	printf("\n\nDigite el Nombre: ");
	gets(nombre);
	hazllave(apellido,nombre,llave_bus);
	
	encontro=FRACAS;
	while(!encontro&&(long_reg=toma_reg(fd,buffreg))>0)
	{
		pos_bus=0;
		pos_bus=toma_campo(apellido,buffreg,pos_bus,long_reg);
		pos_bus=toma_campo(nombre,buffreg,pos_bus,long_reg);
		hazllave(apellido,nombre,llave_enc);
		if(strcmp(llave_enc,llave_bus)==0)
		encontro=EXITO;
	}
if(encontro)
{
	printf("\n\nSe encontro el registro:\n\n");
	pos_bus=0;
	
	while((pos_bus=toma_campo(campo,buffreg,pos_bus,long_reg)));
	printf("\t%s\n",campo);
}
else 
{
printf("\n\nNo se encontro el registro.\n");
}
}
