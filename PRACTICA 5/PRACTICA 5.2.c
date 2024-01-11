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
#include "arches.h"	
#define saca_cad(fd,cad) 		write((fd),(cad),strlen(cad));\
						 		write((fd),DELIM_CAD,1);

int main(){
	/* DECLARACION DE VARIABLES */
	char llave_bus[30],llave_enc[30],apellidoP[15],apellidoM[15],nombre[30],direccion[30],telefono[10],edad[2],horario[10],pago[20];
	char nomarch[20];
	int fd,opc,n,mas_registros,i,contador_campos,cont_reg;
	char cad[80];
	long lseek();
	/* MENU INICIAL PARA DAR NOMBRE AL ARCHIVO */
	printf("\n\t < PRACTICA 2: Introducci%cn a los conceptos b%csicos de archivos  >\n",162,160);
	printf("\nIngrese el nombre del archivo a crear o abrir: ");
	printf("\n\n  >>  ");
	gets(nomarch);
	
	if((fd = open(nomarch,LECTESCRIT))<0){
		fd=creat(nomarch,PMODE);
	}
	
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
					system("cls");/* OPCION 1 PARA REGISTRAR AL CLIENTE */
					printf("\n\tSeleccionaste 'Añadir cliente a la escuela'\n");
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
					//hazllave(apellidoP,nombre,llave_bus);
				
					lseek(fd,0L,2);
					saca_cad(fd,apellidoP);
					saca_cad(fd,apellidoM);
					saca_cad(fd,nombre);
					saca_cad(fd,direccion);
					saca_cad(fd,telefono);
					saca_cad(fd,edad);
					saca_cad(fd,horario);
					saca_cad(fd,pago);
					printf("\nDesea agregar más registros? Ingrese 1 para 'SI' y 2 para 'NO'\n");
					printf("Ingrese su opción: ");
					scanf("%d",&mas_registros);
					fflush(stdin);
				}while(mas_registros!=2);
			break;
			
			case 2:
				system("cls");/* OPCION PARA MIRAR LOS CLIENTES REGISTRADOS */
				printf("\n\tSeleccionaste 'Revisar clientes de la escuela'\n\n");
				lseek(fd,0L,0);
				contador_campos = 0;
				cont_reg = 0;
				while((n=leecampo(fd,cad))>0)
					printf("\t DATOS CLIENTE: %s\n",cad);
				system("pause");
			break;
			
			case 3:
				system("cls");/* OPCION PARA SALIR DEL PROGRAMA */
				printf("\n\tHasta la pr%cxima!!!!!!!!\n\n",162);
			break;
		}
	}while(opc!=3);
	close(fd);
}
/* FUNCION PARA MOSTRAR LOS CIENTES */
leecampo(int fd, char cad[]){
    int i;
    char c;
    i = 0;
    while(read(fd, &c, 1) > 0 && c != DELIM_CAR)
    {
        cad[i++] = c;
    }
    cad[i] = '\0';
    return(i);
}
