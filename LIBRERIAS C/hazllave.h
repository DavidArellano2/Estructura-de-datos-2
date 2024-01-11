#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>


hazllave(char apellido[],char nombre[],char cad[])
{
	int longap,longnom;
	longap=cadespac(apellido);
	strcpy(cad,apellido);
	cad[longap++]='\0';
	cad[longap]='\0';
	longnom=cadespac(nombre);
	strcat(cad,nombre);
	mayusculas(cad,cad);
	return (longap+longnom);
}
