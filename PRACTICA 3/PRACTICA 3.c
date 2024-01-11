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

int main(){
	char buffreg[TAM_MAX_REG + 1];
	char campo[TAM_MAX_REG +1];
	char *solicitud[] = {
	"Ingrese Título de la pelicula o de lo contrario <ENTER> para salir: ",
	"	               Protagonistas: ",
	"	                    Director: ",
	"	       Estudio/Distribuidora: ",
	"	                      Género: ",
	"	              Año de estreno: ",
	"	 Número de premios obtenidos: ",
	"     Calificación otorada a la cinta: ",
	""};/* Cadena nula para terminar el ciclo de solicitud */
	
	setlocale(LC_CTYPE,"Spanish");//acentos
	char respuesta[50];
	char ARCHIVO[15];
	int fd,i,opc,long_reg,cont_reg,cont_campos,pos_bus;
	long lseek();
	
	printf("\n\t < ACTIVIDAD 3:  Registros de longitud variable, utilizando campos de dimensión.   >\n");
	printf("\nIngrese el nombre del archivo a crear: ");
	printf("\n\n  >>  ");
	gets(ARCHIVO);
	if((fd = open(ARCHIVO,LECTESCRIT))<0){
		fd=creat(ARCHIVO,PMODE);
	}
	cont_reg = 0;
	pos_bus = 0;
	
	do{
		system("cls");/* MENU PARA SELECCIONAR LA OPCION A REALIZAR */
		printf("\n\t < ACTIVIDAD 3:  Registros de longitud variable, utilizando campos de dimensión.   >\n");
		printf("\nMenú de opciones: ");
		printf("\n  1. Agregar peliculas\n");
		printf("  2. Revisar peliculas\n");
		printf("  3. Salir \n");
		printf("\nIngrese su opción: ");
		scanf("%d",&opc);
		fflush(stdin);
		switch(opc){
			case 1:
				system("cls");/* OPCION 1 PARA REGISTRAR PELICULAS */
				printf("\n\tSeleccionaste 'Agregar películas'\n");
				lseek(fd,0L,2);
				printf("\n\n%s",solicitud[0]);
				gets(respuesta);
				while(strlen(respuesta) > 0){
					buffreg[0] = '\0';
					campo_a_buffreg(buffreg,respuesta);
					for (i=1; *solicitud[i] != '\0'; ++i){
						printf("%s",solicitud[i]);
						gets(respuesta);
						campo_a_buffreg(buffreg, respuesta);
					}
						
						/* ESCRIBIR LA LONGITUD DEL REGISTR0 Y CONTENIDO DE BUFFER */
					long_reg = strlen(buffreg);
					write(fd,&long_reg,2);
					write(fd,buffreg,long_reg);
						
						/* ESCRIBIR LOS SIG DATOS */
					printf("\n\n%s",solicitud[0]);
					gets(respuesta);
					respuesta[0] = '\0';
					}
			break;
			
			case 2:
				system("cls");/* OPCION PARA MIRAR LAS PELICULAS REGISTRADAS */
				printf("\n\tSeleccionaste 'Revisar películas'\n");
				lseek(fd,0L,0);
				cont_reg = 0;
				pos_bus = 0;
				while((long_reg = toma_reg(fd,buffreg))>0){
					printf("\n\t Película %d:\n",++cont_reg);
					cont_campos = 0;
					while((pos_bus = toma_campo(campo,buffreg,pos_bus,long_reg)) > 0){
						printf("\tCampo %d: %s\n",++cont_campos,campo);
					}
				}
				getch();
			break;
			
			case 3:
				close(fd);
				system("cls");/* OPCION PARA SALIR DEL PROGRAMA */
				printf("\n\tHasta la próxima!!!\n\n",162);
			break;
		}
	}while(opc!=3);
	close(fd);
	return 0;
}
