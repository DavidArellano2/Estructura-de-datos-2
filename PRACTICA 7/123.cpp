#include<stdio.h> 






/* Declaracion de la tabla Hash */



class TablaHash{



public:



TablaHash();



TablaHash(int );



TablaHash(int ,char *);



~TablaHash();



void reportar();        



bool insertar(char *);    



bool insertar2(char *);    



int getDominio();



int hash (char *);



int hash2(char *);    



private:    



	NodoT *celdas;



int numeroNodos;



char *defecto;


        


double secsPrimario;



double secsSecundario;



};









// Constructor 1



// @nElementos: la dimension de la tabla para generarse en memoria



TablaHash::TablaHash(int nElementos)



{



int i=0;    



celdas = new NodoT[nElementos];



numeroNodos = nElementos;



defecto = "nada";



for(i=0; i <numeroNodos; i++ )        



celdas[i] = NodoT(defecto);            



//printf("\nEspacio creado satisfactoriamente...\n");        



secsPrimario=0.0;



secsSecundario=0.0;



}






//Constructor 2



// @defec: Cadena con la que se inicializan todas las



//celdas indicando que esta vacia



TablaHash::TablaHash(int nElementos, char *defec)



{



int i=0;    



celdas = new NodoT[nElementos];



numeroNodos = nElementos;



defecto = defec;



for(i=0; i <numeroNodos; i++)        



celdas[i] = NodoT(defecto);            



//printf("\nEspacio creado satisfactoriamente...\n");    



secsPrimario=0.0;



secsSecundario=0.0;



}






//Destructor



TablaHash::~TablaHash()



{



//delete[] celdas;



//delete celdas;            



NodoT *aux;



NodoT *aux2;



int i=0;    



int cantidadPrimario=0;



int cantidadSecundario=0;



//printf("\nIniciando destruccion\n");



for(i=0; i<numeroNodos; i++) 



{



//Primero verificamos que la celda este vacia para borrarla



//directamente de memoria



//apuntaCelda = apuntaCelda + i;



if(stricmp(celdas[i].valor,defecto)!=0 )



{                        



aux = celdas;



aux = aux + i;    



aux2 = aux->siguiente;        



while(aux2)



{                



cantidadSecundario++;



aux = aux2;



aux2 = aux2->siguiente;                    



delete aux;



aux = NULL;



}



cantidadPrimario++;            



}        



}



printf("\nAccesos primarios: %i",cantidadPrimario);



printf("\nAccesos secundarios: %i",cantidadSecundario);    



printf("\nTiempo: Insercion directa Hash: %.16g ms",



secsPrimario * 1000.0);



printf("\nTiempo: Insercion por colision Hash: %.16g ms\n",



secsSecundario * 1000.0);



aux = NULL;



aux2 = NULL;



delete[] celdas;



delete celdas;



}








//devuelve el dominio de la tabla hash



int TablaHash::getDominio()



{



return numeroNodos;



}








//Reporte de todas las celdas



void TablaHash::reportar()



{    



printf("\nReporte de tabla hash\n");



printf("-----------------------------------------------------\n");


    


int i=0;    


    


for(i=0; i <numeroNodos; i++)        



printf("\nT [%i] = %s",i , celdas[i].valor);                



}









bool TablaHash::insertar2(char *v)



{    



int idNuevo = hash2(v);



bool cortarBucle = false;



NodoT *aux;



//printf("\nID HASH: %i",idNuevo);



//secsPrimario=0.0;



//secsSecundario=0.0;



LARGE_INTEGER t_iniPrim, t_finPrim;



LARGE_INTEGER t_iniSec, t_finSec;     



double secs=0.0;



double secs2=0.0;



if(stricmp(celdas[idNuevo].valor, defecto)==0)    



{                



QueryPerformanceCounter(&t_iniPrim);        



celdas[idNuevo].modificarValor(v);    



QueryPerformanceCounter(&t_finPrim);



secs = performancecounter_diff(&t_finPrim, &t_iniPrim);



secsPrimario = secsPrimario + secs;



return true;



}



else if(stricmp(celdas[idNuevo].valor, v)!=0)



{



QueryPerformanceCounter(&t_iniSec);        



//printf("\nHubo colisión en la posición %i",idNuevo);



aux = celdas;    



aux = aux + idNuevo;



//printf("\nPuntero avanzo: %s",aux->valor);



cortarBucle = false;



while( aux->siguiente && cortarBucle == false)



{



if(stricmp(aux->siguiente->valor, v)==0)



cortarBucle = true;



aux = aux->siguiente;



}        



if(cortarBucle == false)



{



aux->siguiente = new NodoT(v);



aux = NULL;    



QueryPerformanceCounter(&t_finSec);



secs2 = performancecounter_diff(&t_finSec, &t_iniSec);



secsSecundario = secsSecundario + secs2;



return true;



}



QueryPerformanceCounter(&t_finSec);



secs2 = performancecounter_diff(&t_finSec, &t_iniSec);



secsSecundario = secsSecundario + secs2;



//printf("La palabra ya existe en secundario: %s",v);



aux = NULL;                



return false;



}



else



{



//printf("La palabra ya existe en primario: %s",v);



return false;    



}        



}









bool TablaHash::insertar(char *v)



{



int idNuevo = hash2(v);






if(stricmp(celdas[idNuevo].valor, defecto)==0)



{



celdas[idNuevo].modificarValor(v);



return true;



}



else



return false;



}












// Funcion hash que calcula una posicion de la tabla dado



//un valor ingresado como parametro



int TablaHash::hash(char *v)



{



int contador = 0;



int n = strlen(v);    



int i=0;






for(i=0; i<n; i++)   



contador = contador + v[i]*i;



contador = contador % numeroNodos;



return contador;



}






// Funcion hash que calcula una posicion de la tabla dado un



//valor ingresado como parametro



int TablaHash::hash2(char *v)



{



//    int primo = 1009;



// int primo = 500009; 



// int primo = 50021;



//int primo = 500009;



int primo = 200003;



int n = strlen(v);    



const char *d = v;



int h = 0;


    


for(int i=0; i<n; i++,d++  )



h = (h<<2)+ *d;


        


return ((h >= 0) ? (h % primo) : (-h % primo));



}
