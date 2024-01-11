#ifndef TOMAR_H
#define TOMAR_H
#include "Arches.h"

int fd;
char buffreg[TAM_MAX_REG + 1];
char campo[TAM_MAX_REG + 1];

toma_reg(int fd, char buffreg[]){
    int long_reg;

    if(read(fd, &long_reg, 2) == 0){              //Toma la longitud del registro
        return(0);                                       //Devuelve 0 si EOF
    }
        long_reg = read(fd, buffreg, long_reg);  //Lee el registro
        return(long_reg);
}

toma_campo(char campo[], char buffreg[], int pos_busca, int long_reg){
    short cpos=0; //Posicion en el arreglo "campo"
    if(pos_busca == long_reg) //Si no hay mas campos que leer
        return(0);//Devuelve pos_buscar de 0
    while(pos_busca < long_reg && (campo[cpos++] = buffreg[pos_busca++]) != DELIM_CAR);//Ciclo de recoleccion
    if(campo[cpos -1] == DELIM_CAR)//Si el ultimo caracter es un campo
        campo[--cpos] = '\0';//Delimitador, reemplacese con nulo
    else
         campo[cpos] = '\0';//En otro caso, solo asegurarse de que el campo no termina con nulo
    return(pos_busca); //Devuelve la posicion de inicio del siguiente campo
}

#endif // TOMARC_H
