#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "arches.h"
//#include "LEESEC.C"
#define saca_cad(fd,cad)


main(){

char nombre[30], apellido[30], direccion[30], ciudad[20];
char estado[15], cp[9];
char nomarch[15];
int fd;

printf("Proporsione el nombre del archivo que quiere crear: ");
gets(nomarch);
if ((fd= creat(nomarch,PMODE))<0){
	printf("Error en la apertura del archivo --- Fin del programa\n"); exit(1);
}
printf("\n\nDigite un apellido, o <CR> para salir\n>>>");
gets(apellido);
while (strlen(apellido)>0){//DBMS RELACIONAL
	printf("\n Nombre: ");
	gets(nombre);
	printf("Direccion: ");
	gets(direccion);
	printf("Ciudad: ");
	gets(ciudad);
	printf("Estado: ");
	gets(estado);
	printf("Cod. postal: ");
	gets(cp);
	
	saca_cad(fd,apellido);
	saca_cad(fd,nombre);
	saca_cad(fd,direccion);
	saca_cad(fd,ciudad);
	saca_cad(fd,estado);
	saca_cad(fd,cp);
	
	printf("\n\nDigite un apellido, o <CR> para salir\n>>>");
	gets(apellido);
	}
	
}
