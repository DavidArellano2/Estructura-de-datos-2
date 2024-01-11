#include <iostream>

using namespace std;

struct Alumno{
	char nombre[50];
	int nota;
	int estado = 0;
	int clave;
};

int insertar (Alumno* A, Alumno* B, int, int);
int buscaHash(Alumno* A, int, int);

int main()
{
	int op = 0,n,clave,x;
	do{
		cout<<"Ingrese la cantidad de alumnos: ";
		cin>>n;
	}while (n<=0);
	Alumno* A = new Alumno[n];
	Alumno* B = new Alumno[n];
	system("cls");
	do{
		cout<<"\t\t METODO DE BUSQUEDA - HASH - \n";
		cout<<"\t 1. Insertar\n";
		cout<<"\t 2. Buscar\n";
		cout<<"\t 3. Salir\n";
		cout<<"   >> Ingrese la opcion: ";
		cin>>op;
		system("cls");
		switch(op)
		{
			case 1:
				for (int i = 0; i < n; i++)
				{
					cout<<" DATOS DEL ALUMNO: " << i + 1 << endl;
					fflush(stdin);
					cout<<"Nombre: ";
					cin.getline(A[i].nombre,50);
					do{
						cout<<"Nota: ";
						cin >>A[i].nota;
					}while (A[i].nota<0||A[i].nota>20);
					A[i].clave=insertar(A,B,i,n);
					cout<<"Clave: ";
					cout<< A[i].clave<<endl;
				}
				break;
				
			case 2:
				cout<<"Introduzca el códigon que desea buscar: ";
				fflush(stdin);
				cin>>clave;
				x=buscaHash(A,n,clave);
				if(x == -1){
					cout<<"Número NO encontrado..."<<endl;
				}else{
					cout<<"Numero encontrado :)\n";
					cout<<"Nombre: "<<B[x].nombre<<endl;
					cout<<"Nota: "<<B[x].nota<<endl;
				}
				break;
			
			case 3:
				cout<<"GRACIAS :)";
				return 0;
			
			default:
				cout << "Ingrese una opcion valida \n\n";
				system("pause");
		}
	}while (op != 3);
	return 0;
}

int insertar(Alumno * A,Alumno * B, int i, int n)
{
	int j=(A[i].nota + 1) % n;
	do{
		if (A[j].estado == 0){
			B[j] = A[j];
			A[j].estado = 1;
		}
		else{
			j++;
		}
	}while (j>n);
	return j;
}

int buscaHash(Alumno * A,int n,int clave){
	int j=0;
	while (j<n){
		if(A[j].clave == clave){
				return j;
		} else{
			j++;
		}
	}
	return -1;
}

