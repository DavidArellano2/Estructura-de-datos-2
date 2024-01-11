
/*
	Nombre:  Ricardo David López Arellano
	Código:  217136143
   Materia:  Estructuras de Datos II
   Sección:  D09
   Pofesor:  MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/

/*LIBRERIAS*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arches.h"	
#define saca_cad(fd,cad) 		write((fd),(cad),strlen(cad));\
						 		write((fd),DELIM_CAD,1);*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ARCHES.h"
#include "funscads.h"
#include "Tomar.h"
#define LONG_REG 64
#define campo_a_buffreg(br,cad)     strcat(br,cad);strcat(br,DELIM_CAD);

static struct{
     short cont_reg;
     char relleno[30];
}encabezado;

static char * solicitud[]={ 
	"Para terminar de registrar atletas presiona 'enter' cuando te pida el número de participación.\n\n"
	"            Número de participación: ",
	"	          Nombre del atleta: ",
	"	       Dirección del atleta: ",
	"	                     Ciudad: ",
	"	               Nacionalidad: ",
	"     Tiempo último de clasificación: ",
	""};/* Cadena nula para terminar el ciclo de solicitud */

menu(){
	int eleccion;
	char respuesta[10];
	system("cls");
	printf("\n\t\t <  Maratón 2022  >\n");
	printf("\nMenú de opciones: \n");
	printf("  1. Agregar un corredor (al final del archivo)\n");
	printf("  2. Extraer un registro para actualizarlo\n");
	printf("  3. Salir del programa\n\n");
	printf("\nIngrese su opcion: ");
	gets(respuesta);
	eleccion=atoi(respuesta);
	return(eleccion);
};

pide_info(char buffreg[]){
	int cont_campos,i;
	char respuesta[50];
	
	//limpia el buffer del registro
	for(i=0;i<LONG_REG;buffreg[i++]='\0');
	//toma campos
	for(i=0;*solicitud[i] !='\0';i++);
	{
		printf("%s",solicitud[i]);
		gets(respuesta);
		campo_a_buffreg(buffreg,respuesta);	
	}
}

pide_nrr(){
	int nrr;
	char respuesta[10];
	
	printf("\n\nDigite el numero relativo del registro\n");
	printf("\tque desee actualizar: ");
	gets(respuesta);
	nrr=atoi(respuesta);
	return(nrr);
}

lee_y_muestra(){
	char buffreg[TAM_MAX_REG+1],campo[TAM_MAX_REG+1];
	int pos_busca,long_datos;
	
	pos_busca=0;
	read(fd,buffreg,LONG_REG);
	
	printf("\n\n\n Contenido del registro existente\n");
	
	buffreg[LONG_REG]='\0';
	
	long_datos=strlen(buffreg);
	while((pos_busca=toma_campo(campo,buffreg,pos_busca,LONG_REG))>0)
	printf("\t%s\n",campo);
}

cambio(){
	char respuesta[10];
	
	printf("\n\nDesea mnodificar este registro\n");
	printf("conteste S o N , seguido por <ENTER>==>");
	gets(respuesta);
	mayusculas(respuesta,respuesta);
	return((respuesta[0]=='S') ? 1:0);	
}
	
int main(){
	setlocale(LC_CTYPE,"Spanish");//acentos
	int i,menu_elec,nrr;
	int byte_pos;
	char ARCHIVO[20];
	long Iseek();
	char buffreg[TAM_MAX_REG+1];
	
	/* MENU INICIAL PARA DAR NOMBRE AL ARCHIVO */
	printf("\n\t < PRACTICA 4: Registros de longitud fija con encabezado.   >\n");
	printf("\nIngrese el nombre del archivo a crear: ");
	printf("\n\n  >>  ");
	gets(ARCHIVO);
	fd = open(ARCHIVO,LECTESCRIT);
	if((fd=open(ARCHIVO,LECTESCRIT))<0)
	{
		fd=creat(ARCHIVO,PMODE);
		encabezado.cont_reg=0;
		write(fd,&encabezado,sizeof(encabezado));		
	}
	else
	read(fd,&encabezado,sizeof(encabezado));
	
	while((menu_elec=menu())<3)
	{
		switch(menu_elec)
		{
			case 1:
			system("cls");
			printf("Proporcione la informacion del corredor nuevo\n\n");
			pide_info(buffreg);
			byte_pos=encabezado.cont_reg *LONG_REG+sizeof(encabezado);
			lseek(fd,(long)byte_pos,0);
			write(fd,buffreg,LONG_REG);
			encabezado.cont_reg++;
			break;
			
			case 2:
			nrr=pide_nrr();
			if(nrr>=encabezado.cont_reg)
			{
				printf("El numero de registro es demasiado grande");
				printf("...se vuelve al menu...");
				break;
			}
			case 3:
			byte_pos=nrr*LONG_REG*sizeof(encabezado);
			lseek(fd,(long)byte_pos,0);
			lee_y_muestra();
			if(cambio())
			{
				printf("\n\nProporcione los valores revisados:\n\n");
				pide_info(buffreg);
				lseek(fd,(long)byte_pos,0);
				write(fd,buffreg,LONG_REG);
			}
			break;
		}
	}
lseek(fd,0L,0);
write(fd,&encabezado,sizeof(encabezado));
close(fd);	
}
