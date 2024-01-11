/*
	Crea el archivo de nombres y direcciones empleando un campo
	de longitud fija adelante de cada registro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arches.h"
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);

char buffreg[TAM_MAX_REG + 1];
char *solicitud[] = {
	"Digite apellido, o <CR> para salir: ",
	"		Nombre: ",
	"		Direccion: ",
	"		Ciudad: ",
	"		Estado: ",
	"		CP: "};
	//" "};/*Cadena nula para terminar el ciclo de solicitud*/

main(){
	char respuesta[50];
	char nomarch[15];
	int fd,i;
	int long_reg;
	
	printf("Proporcione el nombre del archivo a leer: ");
	gets(nomarch);
	if((fd = creat(nomarch,SOLOLECT)) < 0){
		printf("Error en la apertura del archivo = FIN DEL PROGRAMA\n");
		exit(1);
	}
	
	printf("\n\n%s ",solicitud[0]);
	gets(respuesta);
	while(strlen(respuesta) > 0){
		buffreg[0] = '\0';
		campo_a_buffreg(buffreg,respuesta);
		for (i=1; *solicitud[i] != '\0'; i++){
			printf("%s ",solicitud[i]);
			gets(respuesta);
			campo_a_buffreg(buffreg,respuesta);
		}
		
/*Escribe la longitud del registro y el contenido del buffer*/
	long_reg = strlen(buffreg);
	write(fd,&long_reg,2);
	write(fd,buffreg,long_reg);
	
/*Se prepara para los sig datos */
	printf("\n\n%s ",solicitud[0]);
	gets(respuesta);
	}
	close(fd);
}
