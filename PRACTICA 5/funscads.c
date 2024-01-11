cadespac(cad)
	char cad[];
	{
		int i;
		for (i=strlen(cad) - l;i>=0 && cad[i]==' ';i-)
			;
		/*SE HAN ELIMINADO LOS ESPACIOS, SE PONDRÁ NULO AL FINAL DE LA CADENA*/
		
		cad[++i]='\0';
		return(i);
	}

mayusculas(cadent,cadsal)
	char cadent[],cadsal[];
	{
		while(*cadsal++ = (*cadent>='a' && *cadent<='z')?
							*cadent & 0x5F : *cadent)
		cadent++;
	}








