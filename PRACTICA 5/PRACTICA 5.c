/*
	Nombre:  Ricardo David López Arellano
	Código:  217136143
   Materia:  Seminario de Solución de Problemas de Estructuras de Datos II
   Sección:  D18
   Pofesor:  MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "arches.h"
#include "toma.h"
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);
#define saca_cad(fd,cad) 		write((fd),(cad),strlen(cad));\
						 		write((fd),DELIM_CAD,1);

#define EXITO 1
#define FRACASO 0

hazllave(apellido,nombre,cad)
	char apellido[],nombre[],cad[];
	{
	int longap,longnom;
	longap=cadespac(apellido);/*QUITA LOS ESPACIOS DE APELLIDO*/
	strcpy(cad,apellido);/*LO COLOCA EN LA CADENA DE SALIDA*/
	cad[longap++]=' ';/*LE AGREGA UN ESPACIO AL FINAL*/
	cad[longap]='\0';
	longnom=cadespac(nombre);/*QUITA LOS ESPACIOS DE NOMBRE*/
	strcat(cad,nombre);/*LO AGREGA A LA CADENA*/
	mayusculas(cad,cad);/*CONVIERTE TODO A MAYUSULAS*/
	return(longap+longnom);
}	

cadespac(cad)
	char cad[];
	{
		int i;
		for (i=strlen(cad) - 1;i>=0 && cad[i]==' ';i--)
			;
		/*SE HAN ELIMINADO LOS ESPACIOS, SE PONDRÁ NULO AL FINAL DE LA CADENA*/	
		cad[++i]='\0';
		return(i);
	}

mayusculas(cadent,cadsal)
	char cadent[],cadsal[];
	{
		while(*cadsal++ = (*cadent>='a' && *cadent<='z')?
							*cadent & 0x5F : *cadent)
		cadent++;
	}	

int main(){
	int fd,longitud_registro,pos_bus;
	int opc,mas_registros,cont_reg,cont_campos,n;
	char llave_bus[30],llave_enc[30],apellidoP[15],apellidoM[15],nombre[30],direccion[30],telefono[10],edad[2],horario[10],pago[20];
	char ARCHIVO[15],buscarA[20];
	char buffreg[TAM_MAX_REG+1];
	char campo[TAM_MAX_REG+1];
	char cad[80];
	char* encontro;
	long lseek();
	
	/*printf("\n\t < PRACTICA 5: Solución de colisiones usando la saturación progresiva >\n");
	printf("\nIngrese el nombre del archivo a crear: ");
	printf("\n\n  >>  ");
	gets(ARCHIVO);
	
	if((fd = creat(ARCHIVO,SOLOLECT))<0){
		printf("Error en la apertura del archivo - FIN DEL PROGRAMA\n");
		exit(1);
	}*/
	cont_reg=0;
	pos_bus=0;
	
	do{
		setlocale(LC_CTYPE,"Spanish");//acentos
		system("cls");/* MENU SECUNDARIO PARA SELECCIONAR LA OPCION A REALIZAR */
		printf("\n\t < PRACTICA 5: Solución de colisiones usando la saturación progresiva >\n");
		printf("\nMenú de opciones: \n");
		printf("  1. Añadir cliente a la escuela\n");
		printf("  2. Revisar clientes de la escuela\n");
		printf("  3. Salir\n");
		printf("\nIngrese su opción: ");
		scanf("%d",&opc);
		fflush(stdin);
		switch(opc){
			case 1:
				do{
					system("cls");
					printf("\n\tSeleccionaste 'Añadir cliente a la escuela'\n",164);
					printf("\n\nDigite el apellido paterno: ");/*TOMA LA LLAVE DE BUSQUEDA*/
					gets(apellidoP);
					printf("\nDigite el apellido materno: ");
					gets(apellidoM);
					printf("\nDigite el nombre: ");
					gets(nombre);
					printf("\nDigite la direccion: ");
					gets(direccion);
					printf("\nDigite el telefono: ");
					gets(telefono);
					printf("\nDigite su edad: ");
					gets(edad);
					printf("\nDigite el horario en el que nada: ");
					gets(horario);
					printf("\nDigite la fecha de pago: ");
					gets(pago);
					hazllave(apellidoP,nombre,llave_bus);
					
					printf("\nDesea agregar más registros? Ingrese 1 para 'SI' y 2 para 'NO'\n");
					printf("Ingrese su opción: ");
					scanf("%d",&mas_registros);
					fflush(stdin);
					}while(mas_registros!=2);
			break;
			
			case 2: 
				system("cls");
				printf("\n\tSeleccionaste 'Revisar clientes de la escuela'\n\n");
				printf("Dame el apellido a buscar: ");
				scanf("%d",&encontro);
				
				//encontro=FRACASO;
			 	while (encontro && (longitud_registro = toma_reg(fd,buffreg)) > 0){
					pos_bus=0;
			  		pos_bus=toma_campo(apellidoP,buffreg,pos_bus,longitud_registro);
					pos_bus=toma_campo(nombre,buffreg,pos_bus,longitud_registro);
					hazllave(apellidoP,nombre,llave_enc);
					if (strcmp(llave_enc,llave_bus) == 0){
							encontro=EXITO;
						}
					}
				if(encontro){
					printf("\n\nSe encontro el registro: \n\n");
					pos_bus=0;
					
					//DIVIDE LOS CAMPOS
					while((pos_bus=toma_campo(campo,buffreg,pos_bus,longitud_registro)) > 0)
						printf("\t%s\n",campo);
				}else
				printf("\n\nNo se encontro el registro...\n");
				
				
				
				getch();
			break;
			
			case 3:
			system("cls");/* OPCION PARA SALIR DEL PROGRAMA */
			printf("\n\tHasta la pr%cxima!!!!!!!!\n\n",162);
		break;
		}
	}while(opc!=3);
	close(fd);
}


/*	
	
	encontro=FRACASO;
	while (!encontro && (longitud_registro = toma_reg(fd,buffreg)) > 0){
		pos_bus=0;
		pos_bus=toma_campo(apellidoP,buffreg,pos_bus,longitud_registro);
		pos_bus=toma_campo(nombre,buffreg,pos_bus,longitud_registro);
		hazllave(apellidoP,nombre,llave_enc);
		if (strcmp(llave_enc,llave_bus) == 0){
			encontro=EXITO;
		}
	}
	if(encontro){
		printf("\n\nSe encontro el registro: \n\n");
		pos_bus=0;
		
		//DIVIDE LOS CAMPOS
		while((pos_bus=toma_campo(campo,buffreg,pos_bus,longitud_registro)) > 0)
			printf("\t%s\n",campo);
	}else
	printf("\n\nNo se encontro el registro...\n");	
}*/
