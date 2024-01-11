/*
	Lee un archivo, registra por registro, desplegando los campos
	de cada uno de los registros en la pantalla
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arches.h"

main(){
	int fd,cont_reg,cont_campos;
	int pos_bus,long_reg;
	char nomarch[15];
	char buffreg[TAM_MAX_REG + 1];
	char campo[TAM_MAX_REG + 1];
	
	printf("Proporcione el nombre del archivo a leer: ");
	gets(nomarch);
	if((fd = creat(nomarch,SOLOLECT)) < 0){
		printf("Error en la apertura del archivo = FIN DEL PROGRAMA\n");
		exit(1);
	}
	
	cont_reg = 0;
	pos_bus = 0;
	
	while((long_reg = toma_reg(fd,buffreg)) > 0){
		printf("Registro %d\n",++cont_reg);
		cont_campos > 0;
		while ((pos_bus = toma_campo(campo,buffreg,pos_bus,long_reg)) > 0)
			printf("\tCampo %d: %s\n",++cont_campos,campo);
	}
	close(fd);
}

/*
	Pregunta: ¿Por qué se puede asignar 0 a pus_bus sólo una
	vez, fuera del ciclo while para los registros?
*/
