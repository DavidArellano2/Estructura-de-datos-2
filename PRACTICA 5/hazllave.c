/*
	Funcion que hace una llave a apartir del nombre y del
	apellido pasados por los argumentos de la función. Devuelve 
	la llave en forma canonica a traves de la direccion pasada 
	por el argumento cad. La rutina que llama es responsable
	de asegurarse de que cad sea lo suficientemente grande para
	guardar la cadena que se devuelve.
	
	El valor devueto por medio del nombre de la funcion es la
	longitud de la cadena devuelta a traves de cad.
*/

hazllave(apellido,nombre,cad)
	char apellido[],nombre[],cad[];
	{
	int longap,longnom;
	
	longap=cadespac(apellido);/*QUITA LOS ESPACIOS DE APELLIDO*/
	strcpy(cad,apellido);/*LO COLOCA EN LA CADENA DE SALIDA*/
	cad[longap++]=' ';/*LE AGREGA UN ESPACIO AL FINAL*/
	cad[longap]='\0';
	longnom=cadespac(nombre);/*QUITA LOS ESPACIOS DE NOMBRE*/
	strcat(cad,nombre);/*LO AGREGA A LA CADENA*/
	mayusculas(cad,cad);/*CONVIERTE TODO A MAYUSULAS*/
	return(longap+longnom);
}
