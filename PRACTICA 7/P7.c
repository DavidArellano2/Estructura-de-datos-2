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
#include <unistd.h>
#include <conio.h>
#include "Arches.h"
#include "funscads.h"
#include "Tomar.h"
#define LONG_REG 64
#define campo_a_buffreg(br,cad)     strcat(br,cad);strcat(br,DELIM_CAD);

struct Agenda
{
    char apellidoP[20];
    char apellidoM[20];
    char nombre[40];
    char direccion[40];
    int telefono[10];
    char tipo[20];
    char marca[20];
    char placas[7]
};

int main()
{
	setlocale(LC_CTYPE,"Spanish");//acentos
	char respuesta[50];
	char ARCHIVO[15];
	long lseek();
    struct Agenda AgendaPersona[50];
    int edadBuscar,i,opcion,j=0,opc;
    char n,apellido_buscar;
    
	printf("\n\t < PRACTICA 7: Solución de colisiones usando la saturación progresiva   >\n");
	printf("\nIngrese el nombre del archivo a crear: ");
	printf("\n\n  >>  ");
	gets(ARCHIVO);
	if((fd = open(ARCHIVO,LECTESCRIT))<0){
		fd=creat(ARCHIVO,PMODE);
	}
	
	do{
		system("cls");
		printf("\n\t\t <  Agenda de Taller Automotriz  >\n");
		printf("\nMenú de opciones: \n");
		printf("   1. Agregar un cliente\n");
		printf("   2. Buscar cliente por Apellido Paterno\n");
		printf("   3. Buscar cliente mediante las placas\n");
		printf("   4. Buscar cliente mediante telefono\n");
	    printf("   5. salir\n");
		printf("\nIngrese su opcion: ");
		scanf("%d",&opc);
		fflush(stdin);
		switch(opc){
		case 1:
			system("cls");/* OPCION 1 PARA REGISTRAR CORREDORES */
			printf("\n\tSeleccionaste 'Agregar Clientes'\n\n");
			for (i=0; i<50; i++)
		    {
		        printf("Apellido Paterno: ");
		        gets(AgendaPersona[i].apellidoP);
		        j++;
		        if (strcmp(AgendaPersona[i].apellidoP,"")==0)
		            break;
		        printf("Apellido Materno: ");
		        gets(AgendaPersona[i].apellidoM);
		        //getchar();
		        printf("Nombre: ");
		        gets(AgendaPersona[i].nombre);
		        printf("Direccion: ");
		        gets(AgendaPersona[i].direccion);
		        printf("Telefono: ");
		        gets(AgendaPersona[i].telefono);
		        printf("Tipo de vehiculo: ");
		        gets(AgendaPersona[i].tipo);
		        printf("Marca: ");
		        gets(AgendaPersona[i].marca);
		        printf("Placas: ");
		        gets(AgendaPersona[i].placas);
		    }
			break;
		case 2:
			
			system("cls");
			printf("\n\tSeleccionaste 'Buscar por apellido Paterno'\n\n");
			printf("Ingrese el apellido a buscar: ");
			scanf("%d",&apellido_buscar);
			for (i=0; i<j; i++)
			{
               	if(AgendaPersona[i].apellidoP==apellido_buscar)
				//puts(AgendaPersona[i].apellidoP);
				printf("%s\n",AgendaPersona[i].tipo);
               	system("pause");
            }
			break;
		
			
		case 3:
			system("cls");
			printf("\n\tSeleccionaste 'Buscar por apellido placas'\n\n");
			/*for (i=0; i<j; i++)
                puts(AgendaPersona[i].);
			break;*/
			
		case 4:
			system("cls");/* OPCION 1 PARA REGISTRAR CORREDORES */
			printf("\n\tSeleccionaste 'Buscar por telelfono'\n\n");
			for (i=0; i<j; i++)
                puts(AgendaPersona[i].telefono);
			break;	
		}
	}while(opc!=5);
	close(fd);
	return 0;
}

static menu(){
	int eleccion;
	char respuesta[10];
	system("cls");
	printf("\n\t\t <  Agenda de Taller Automotriz  >\n");
	printf("\nMenú de opciones: \n");
	printf("   1. Agregar un cliente\n");
	printf("   2. Buscar cliente por Apellido Paterno\n");
	printf("   3. Buscar cliente mediante las placas\n");
	printf("   3. Buscar cliente mediante telefono\n");
    printf("   4. salir\n");
	printf("\nIngrese su opcion: ");
	gets(respuesta);
	eleccion=atoi(respuesta);
	return(eleccion);
};
/*
static pide_nrr()
{
	int nrr;
	char respuesta[10];
	system("cls");
	printf("\n\tSeleccionaste 'Buscar registro para actualizarlo'\n\n");
	printf("Digite el NRR del registro a modificar: ");
	gets(respuesta);
	nrr=atoi(respuesta);
	return(nrr);
}

static muestra()
{
	int nrr;
	char respuesta[10];
	system("cls");
	printf("\n\tSeleccionaste 'Mostar registros para actualizarlos'\n\n");
	printf("Digite el NRR del registro a mostrar: ");
	gets(respuesta);
	nrr=atoi(respuesta);
	return(nrr);
}

static lee_y_muestra()
{
	char buffreg[TAM_MAX_REG + 1], campo[TAM_MAX_REG + 1];
    int pos_busca, long_reg;
    pos_busca = 9;
    read(fd,buffreg,LONG_REG);
    printf("Registros existentes: \n");
    buffreg[LONG_REG] = '\0';
    long_reg = strlen(buffreg);
    int i=2;
    int j =0;
    printf("\t%s",solicitud[0]," :");
    for(j=0; j<4; j++)
    {
    	
        printf("%c",buffreg[j]);
    }
    printf("\n\t%s",solicitud[1]," :");
    printf("%c%s%c%c%s%c%c",buffreg[4],":",buffreg[5],buffreg[6],":",buffreg[7],buffreg[8]);
    printf("\n");


    while ((pos_busca = toma_campo(campo,buffreg,pos_busca,long_reg)) >0)
    {   	
        printf("\t%s%s\n",solicitud[i],campo);
        ++i;
    }	
}

static cambio(){
	char respuesta[10];
	printf("\n\nDesea modificar este registro?\n");
	printf("Conteste S o N, seguido por <ENTER>: ");
	gets(respuesta);
	mayusculas(respuesta,respuesta);
	return((respuesta[0]=='S') ? 1:0);	
}


    /*
    for (i=0; i<50; i++)
    {
        printf("Apellido Paterno: ");
        gets(AgendaPersona[i].apellidoP);
        j++;
        if (strcmp(AgendaPersona[i].apellidoP,"")==0)
            break;
        printf("Apellido Materno: ");
        gets(AgendaPersona[i].apellidoM);
        //getchar();
        printf("Nombre: ");
        gets(AgendaPersona[i].nombre);
        printf("Direccion: ");
        gets(AgendaPersona[i].direccion);
        printf("Telefono: ");
        gets(AgendaPersona[i].telefono);
        printf("Tipo: ");
        gets(AgendaPersona[i].tipo);
        printf("Marca: ");
        gets(AgendaPersona[i].marca);
        printf("Placas: ");
        gets(AgendaPersona[i].placas);
    } 
    
    do
    {
        printf("\n");
        printf("1. Mostrar por apellido Paterno\n");
        printf("2. Buscar personas por edad\n");
        printf("3. Buscar personas cuya inicial se indique\n");
        printf("4. Salir\n");
        printf("\nSeleccione opcion::");
        scanf("%d",&opcion);
        switch (opcion)
        {
            case 1:
                for (i=0; i<j; i++)
                    puts(AgendaPersona[i].apellidoP);
                break;
            /*case 2:
                printf("ingrese edad a buscar::");
                scanf("%d",&edadBuscar);
                for (i=0; i<j; i++)
                {
                    if (AgendaPersona[i].edad==edadBuscar)
                        printf("%s\n",AgendaPersona[i].nombre);
                }
                break;
            case 3:
                printf("indique inicial del nombre para buscar::");
                n=getchar();
                getchar();
                for (i=0; i<j; i++)
                {
                    if (AgendaPersona[0].nombre[i]==n)
                        printf("%s\n",AgendaPersona[i].nombre);
                }
                break;
        }
    }
    while (opcion != 4);   
    return 0;
}*/
