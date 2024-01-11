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
#include <locale.h>
#include "arches.h"
#include "toma.h"
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);

struct Atleta{
	char numero[4];
	char nombre[20];
	char direccion[20];
	char ciudad[9];
	char nacionalidad[3];
	char tiempo[8]
};

void llenar_campo(int len_campo, char campo[], char input[]){
	int len_input = strlen(input);
	/*for (int i = 0; i < len_campo-1; i++)
	{
		if(i< len_input) {
			campo[i] = input[i];
		}else {
			campo [i] = ' ';
		}
	}*/
	campo[len_campo-1] = '\0';
}

int main(){
	/* DECLARACION DE VARIABLES */
	char campo[TAM_MAX_REG +1];
	char buffreg[TAM_MAX_REG + 1] = {0x0};
	char *solicitud[15] = {
	"Para terminar de registrar atletas presiona 'enter' cuando te pida el número de participación.\n\n"
	"            Número de participación: ",
	"	          Nombre del atleta: ",
	"	       Dirección del atleta: ",
	"	                     Ciudad: ",
	"	               Nacionalidad: ",
	"     Tiempo último de clasificación: ",
	""};/* Cadena nula para terminar el ciclo de solicitud */
	setlocale(LC_CTYPE,"Spanish");//acentos
	char respuesta[64];
	char ARCHIVO[15];
	int fd,i,opc,long_reg,cont_reg,cont_campos,pos_bus;
	long lseek();
	
	/* MENU INICIAL PARA DAR NOMBRE AL ARCHIVO */
	printf("\n\t < PRACTICA 4: Registros de longitud fija con encabezado.   >\n");
	printf("\nIngrese el nombre del archivo a crear: ");
	printf("\n\n  >>  ");
	gets(ARCHIVO);
	fd = open(ARCHIVO,LECTESCRIT);
	if(fd < 0) {
		fd=creat(ARCHIVO,PMODE);
	}
	cont_reg = 0;
	pos_bus = 0;
	
	do{
		system("cls");/* MENU PARA SELECCIONAR LA OPCION A REALIZAR */
		printf("\n\t\t <  Maratón 2022  >\n");
		printf("\nMenú de opciones: \n");
		printf("  1. Agregar un corredor (al final del archivo)\n");
		printf("  2. Buscar corredor dentro del maraton\n");
		printf("  3. Buscar corredores por nacionalidad\n");
		printf("  4. Buscar corredores por ciudad\n");
		printf("  5. Buscar corredores por nombre\n");
		printf("  6. Ingresar sus tiempos de clasificación\n");
		printf("  7. Buscar tiempo de clasificación\n");
		printf("  8. Imprimir corredores")
		printf("  9. Salir \n");
		printf("\nIngrese su opcion: ");
		scanf("%d",&opc);
		fflush(stdin);
		switch(opc){
			case 1:
				/*system("cls"); OPCION 1 PARA REGISTRAR CANCIONES */
				printf("\n\tSeleccionaste 'Agregar un corredor'\n");
				lseek(fd,0L,0);
				printf("\n\n%s",solicitud[0]);
				gets(respuesta);
				while(strlen(respuesta) > 0){
					struct Atleta atleta;
				
					int len_campo = sizeof(atleta.numero)/ sizeof(char);
					llenar_campo(len_campo, atleta.numero, respuesta);
					for (i=1; *solicitud[i] != '\0'; ++i){
						printf("%s",solicitud[i]);
						gets(respuesta);
						switch (i)
						{
						case 1:
							len_campo = sizeof(atleta.nombre)/ sizeof(char);
							llenar_campo(len_campo, atleta.nombre, respuesta);
							break;
						case 2:
							len_campo = sizeof(atleta.direccion)/ sizeof(char);
							llenar_campo(len_campo, atleta.direccion, respuesta);
							break;
						case 3:
							len_campo = sizeof(atleta.direccion)/ sizeof(char);
							llenar_campo(len_campo, atleta.ciudad, respuesta);
							break;
						case 4:
							len_campo = sizeof(atleta.nacionalidad)/ sizeof(char);
							llenar_campo(len_campo, atleta.nacionalidad, respuesta);
							break;
						case 5:
							len_campo = sizeof(atleta.tiempo)/ sizeof(char);
							llenar_campo(len_campo, atleta.tiempo, respuesta);
							break;
						}
					}
						
						/* ESCRIBIR LA LONGITUD DEL REGISTR0 Y CONTENIDO DE BUFFER */
					long_reg = strlen(buffreg);
					if(long_reg > 64) {
						long_reg = 64;
					}
					char tempLong[2] = {0x0};
					sprintf(tempLong,"%d",long_reg);
					write(fd,tempLong,sizeof(tempLong));

					write(fd,buffreg,64);
						
						/* ESCRIBIR LOS SIG DATOS */
					printf("\n\n%s",solicitud[0]);
					gets(respuesta);
					respuesta[0] = '\0';
					}
			break;
			
			case 2:
				system("cls");/* OPCION PARA MIRAR LAS CANCIONES REGISTRADAS */
				printf("\n\tSeleccionaste 'Buscar corredor dentro del marat?n'\n\n");
				lseek(fd,0L,0);
				cont_reg = 0;
				pos_bus = 0;
				while((long_reg = toma_reg(fd,buffreg))>0){
					printf("\t Registro %d:\n",++cont_reg);
					cont_campos = 0;
					while((pos_bus = toma_campo(campo,buffreg,pos_bus,long_reg)) > 0){
						printf("\tCampo %d: %s\n",++cont_campos,campo);
					}
				}
				getch();
			break;
			
			case 9:
				close(fd);
				system("cls");/* OPCION PARA SALIR DEL PROGRAMA */
				printf("\n\tHasta la pr?xima!!!\n\n",162);
			break;
		}
	}while(opc!=8);
	close(fd);
	return 0;
}
