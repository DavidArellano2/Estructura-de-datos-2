#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>



cadespac(char cad[])
{
	int i;
	for(i=strlen(cad)-1;i>=0 && cad[i]=='\0';i--);
	cad[++i]='\0';
	return(i);
}
mayusculas(char cadent[],char cadsal[])
{
	while(*cadsal++=(*cadent>='a'&&*cadent<='z')?*cadent &0x5F: *cadent)
	cadent++;
}
