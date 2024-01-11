#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include "ARCHES.h"
#include "funscads.h"
#include "Tomar.h"
#define LONG_REG 64
#define campo_a_buffreg(br,cad)     strcat(br,cad);strcat(br,DELIM_CAD);

static char * solicitud[]={ "   apellido: "
"    Nombre: ",
"    Direccion: ",
"    Ciudad: ",
"    Estado: ",
"    Cod. Post: ",
""};



static struct{
     short cont_reg;
     char relleno[30];
}encabezado;

main()
{
	int i,menu_elec,nrr;
	int byte_pos;
	char nomarch[15];
	long Iseek();
	char buffreg[TAM_MAX_REG+1];
	
	printf("Proporcione el nombre del archivo ");
	gets(nomarch);
	if((fd=open(nomarch,LECTESCRIT))<0)
	{
		fd=creat(nomarch,PMODE);
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
			printf("Proporcione la informacion del registro nuevo\n\n");
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


menu(){
	int eleccion;
	char respuesta[10];
	
	printf("\n\n\n Programa de actualizacion del archivo\n");
	printf("\n\n Ud. Puede elegir:\n\n");
	printf("\n1. Agregar un registro al final del archivo\n");
	printf("\n2. Extraer un registro para actualizarlo\n");
	printf("\n3. Salir del programa\n\n");
	printf("Proporcione el numero de su eleccion: ");
	gets(respuesta);
	eleccion=atoi(respuesta);
	return(eleccion);
};

pide_info(char buffreg[])
{
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

pide_nrr()
{
	int nrr;
	char respuesta[10];
	
	printf("\n\nDigite el numero relativo del registro\n");
	printf("\tque desee actualizar: ");
	gets(respuesta);
	nrr=atoi(respuesta);
	return(nrr);
}

lee_y_muestra()
{
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

cambio()
{
	char respuesta[10];
	
	printf("\n\nDesea mnodificar este registro\n");
	printf("conteste S o N , seguido por <ENTER>==>");
	gets(respuesta);
	mayusculas(respuesta,respuesta);
	return((respuesta[0]=='S') ? 1:0);	
}	
