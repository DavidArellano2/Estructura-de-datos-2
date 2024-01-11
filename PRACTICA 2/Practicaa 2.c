/*
	Nombre:  Ricardo David López Arellano
	Código:  217136143
   Materia:  Estructuras de Datos II
   Sección:  D09
   Pofesor:  MIGUEL ANGEL GUERRERO SEGURA RAMIREZ
*/

/*LIBRERIAS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arches.h"	
#define saca_cad(fd,cad) 		write((fd),(cad),strlen(cad));\
						 		write((fd),DELIM_CAD,1);

int main(){
	/* DECLARACION DE VARIABLES */
	char nombre[30],direccion[20],ciudad[20],estado[20],cp[7],ramo[20];
	char nomarch[20];
	int fd,opc,n,mas_registros,i,contador_campos;
	char cad[80];
	long lseek();
	/* MENU INICIAL PARA DAR NOMBRE AL ARCHIVO */
	printf("\n\t < ACTIVIDAD 2: Introducci%cn a los conceptos b%csicos de archivos  >\n",162,160);
	printf("\nIngrese el nombre del archivo a crear o abrir: ");
	printf("\n\n  >>  ");
	gets(nomarch);
	
	if((fd = open(nomarch,LECTESCRIT))<0){
		fd=creat(nomarch,PMODE);
	}
	
	do{
		system("cls");/* MENU SECUNDARIO PARA SELECCIONAR LA OPCION A REALIZAR */
		printf("\n\t < ACTIVIDAD 2: Introducci%cn a los conceptos b%csicos de archivos  >\n",162,160);
		printf("\nMen%c de opciones: ",163);
		printf("\n  1. A%cadir cliente a la agenda\n",164);
		printf("  2. Revisar agenda\n");
		printf("  3. Salir de la agenda\n");
		printf("\nIngrese su opci%cn: ",162);
		scanf("%d",&opc);
		fflush(stdin);
		switch(opc){
			case 1:
				do{
					system("cls");/* OPCION 1 PARA REGISTRAR AL CLIENTE */
					printf("\n\tSeleccionaste 'A%cadir cliente a la agenda'\n",164);
					printf("\nIngrese el nombre del cliente o raz%cn social: ",162);
					gets(nombre);
					printf("Ingrese la direcci%cn de la empresa: ",162);
					gets(direccion);
					printf("Ingrese la ciudad: ");
					gets(ciudad);
					printf("Ingrese el estado: ");
					gets(estado);
					printf("Ingrese el c%cdigo postal: ",162);
					gets(cp);
					printf("Ingrese el ramo al que se dedica: ",162);
					gets(ramo);
					lseek(fd,0L,2);
					saca_cad(fd,nombre);
					saca_cad(fd,direccion);
					saca_cad(fd,ciudad);
					saca_cad(fd,estado);
					saca_cad(fd,cp);
					saca_cad(fd,ramo);
					printf("\nDesea agregar m%cs registros? Ingrese 1 para 'SI' y 2 para 'NO'\n",160);
					printf("Ingrese su opci%cn: ",162);
					scanf("%d",&mas_registros);
					fflush(stdin);
				}while(mas_registros!=2);
			break;
			
			case 2:
				system("cls");/* OPCION PARA MIRAR LOS CLIENTES REGISTRADOS */
				printf("\n\tSeleccionaste 'Revisar agenda'\n\n");
				lseek(fd,0L,0);
				contador_campos = 0;
				while((n=leecampo(fd,cad))>0)
					printf("\t Campo # %3d: %s\n",contador_campos++,cad);
					printf("\n");
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
