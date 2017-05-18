#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include "Expende.h"
#include "Usuario.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Admin.h"

using namespace std;

  vector <Usuario> VectUsuarios;
  struct stRegistro {
   char valido;  // Campo que indica si el registro es valido S->Válido, N->Inválido
   char nombre[34];
   char apellido[2][34];
   char telefono[10];
};

struct stIndice {
   char telefono[10];
   long indice;
};

void Capturar(stRegistro &reg);
void Insertar(FILE *fa, stRegistro &reg);
void EliminarRetornoLinea(char *cad);
void ReconstruirIndices(FILE *fa);
void QuickSort(FILE *fa, long inicio, long final);
char *LeeCampo(FILE *fa, long n, char *buf);
void Intercambia(FILE *fa, long iz, long de);
void GuardarEnFichero();

int main ()
{
  vector <Usuario> VectUsuarios; 
  stRegistro reg;
   FILE *fa;
   int opcion;
   char telefono[10];

   fa = fopen("indices.txt", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("indices.txt", "w+b");  // si el fichero no existe, lo crea.

 
int total = 0;
  
  //Usuario usuario[10];

do  
{
  //system("cls");   
  cout << "Maquina Expendedora" <<  endl;

  cout << "1. Registro de usuario" <<  endl;
  cout << "2. Log in de usuario" <<  endl;
  cout << "3. Ingreso de Administrador" <<  endl;
  cout << "4. Salir" <<  endl;

 
  scanf("%i",&opcion);                              // Capturo opcion del Menu
 switch (opcion)
  {
    case 1: Capturar(reg);
            Insertar(fa, reg);
    break;

    case 2: menuLogin();
    break;
    
   case 3: ingresoAdmin();                             
           //guardar();
           break;

   case 4: break;                                   // Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
            system("pause");
            break;     
  }
}while(opcion!=4);





	/*Producto p1 (1,"Mayi", 2.0, 10);
	p1.ReduceNum();
	cout << "Producto : "<<p1.getNum() <<endl;*/ // esto ya no se puede hacer por que ahora la clase persona es abstracta

	Alimento a1 (2, "Lorea", 2.0,15, 33);
	//cout << "Alimento : "<< a1.getGramos() << endl;
	cout<< a1;

	Bebida b1 (2, "Marcos", 5.0, 5, 100, "cucu");
	//b1.setMiliL(200);
	cout<< b1;

	a1.Print();
	b1.Print();



	string line;
  ifstream myfile("indices.dat");
  float precio = 0.0;
  int i = 1;
  int total2 = 0;

  
  while (getline(myfile, line)) {
    cout << line << endl;
    if (i % 2 == 0) {
      float aux = atof(line.c_str());
      precio += aux;
      //total++;
    }
    else {
      size_t pos = line.find(" ");
      total2 = atoi(line.substr(pos).c_str());
    }
    i++;
  }
  

  cout << "Price = " << precio << ", total = " << total2 << endl;
  
  cout << "Precio medio de los pedidos: " << precio / (total2) << endl;

	


	return 0;
}

// Permite que el usuario introduzca un registro por pantalla
void Capturar(stRegistro &reg) 
{

   int id;
   char* nom= new char [34];
   char* ape1 = new char [34];
   char* ape2 = new char [34];
   int telef;

   char numero[6];

   system("cls");
   cout << "Leer registro" << endl<<endl;
   //reg.valido = 'S';

   cout << "ID(num): ";
   cin >> id;

   cout << endl<<"Nombre: ";
   cin >> nom; 
   
   //fgets(reg.nombre, 34, stdin);
     
   //EliminarRetornoLinea(reg.nombre);

   cout <<endl<< "Primer apellido: ";
   //fgets(reg.apellido[0], 34, stdin);
   cin >>ape1;
   //EliminarRetornoLinea(reg.apellido[0]);

   cout << endl <<"Segundo apellido: ";
   //fgets(reg.apellido[1], 34, stdin);
   cin >> ape2;
   //EliminarRetornoLinea(reg.apellido[1]);

   cout << endl << "Telefono: ";
   //fgets(reg.telefono, 10, stdin);
   cin >>telef;
   //EliminarRetornoLinea(reg.telefono);

   Usuario u (id, nom, ape1, ape2, telef);
   cout << u;
   VectUsuarios.push_back(u);
   GuardarEnFichero();
   menuUsuario();
} 

void GuardarEnFichero()
{
  ofstream ofs("Usuarios.txt");
  for (vector< Usuario>:: iterator i= VectUsuarios.begin(); i!= VectUsuarios.end(); i++)
  {
    ofs << *i << endl;
  }
  
  ofs.close();

}

/* // comento el anterior por si necesitamos recuperar algo de aqui
void Capturar(stRegistro &reg)
{
   int i;
   char numero[6];

   system("cls");
   printf("Leer registro:\n\n");
   reg.valido = 'S';
   printf("Nombre: ");
   fgets(reg.nombre, 34, stdin);
   EliminarRetornoLinea(reg.nombre);
   printf("Primer apellido: ");
   fgets(reg.apellido[0], 34, stdin);
   EliminarRetornoLinea(reg.apellido[0]);
   printf("Segundo apellido: ");
   fgets(reg.apellido[1], 34, stdin);
   EliminarRetornoLinea(reg.apellido[1]);
   printf("Teléfono: ");
   fgets(reg.telefono, 10, stdin);
   EliminarRetornoLinea(reg.telefono);

   menuUsuario();
}

*/

// Añade un registro al archivo de datos y reconstruye los índices
void Insertar(FILE *fa, stRegistro &reg)
{
   // Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(stRegistro), 1, fa);
   ReconstruirIndices(fa);
}

// Elimina los caracteres de retorno de línea al final de cadena
void EliminarRetornoLinea(char *cad)
{
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}

// Reconstruye el archivo de índices
void ReconstruirIndices(FILE *fa)
{
   long n=0;
   FILE *fi;
   stRegistro reg;
   stIndice ind;
   
   // Crea el fichero de índices a partir del archivo de datos:
   fi = fopen("indices.ind", "w+b");
   rewind(fa);
   while(fread(&reg, sizeof(stRegistro), 1, fa)) {
      strcpy(ind.telefono, reg.telefono);
      ind.indice = n++;
      fwrite(&ind, sizeof(stIndice), 1, fi);
   }
   // Ordena usando el algoritmo Quicksort:
   QuickSort(fi, 0, n-1);
   fclose(fi);
}


// Implementación del algoritmo Quicksort para fichero de índices
void QuickSort(FILE *fi, long inicio, long final)
{
   long iz, de;
   char mitad[10];
   static char cad[10];

   iz = inicio;
   de = final;
   strcpy(mitad, LeeCampo(fi, (iz+de)/2, cad));
   do {
      while(strcmp(LeeCampo(fi, iz, cad), mitad) < 0 && iz < final) iz++;
      while(strcmp(mitad, LeeCampo(fi, de, cad)) < 0 && de > inicio) de--;
      if(iz < de) Intercambia(fi, iz, de);
      if(iz <= de) {
         iz++;
         de--;
      }
   } while(iz <= de);
   if(inicio < de) QuickSort(fi, inicio, de);
   if(iz < final) QuickSort(fi, iz, final);
}

char *LeeCampo(FILE *fi, long n, char *buf)
{
   stIndice ind;

   fseek(fi, n*sizeof(stIndice), SEEK_SET);
   fread(&ind, sizeof(stIndice), 1, fi);
   strcpy(buf, ind.telefono);
   return buf;
}

void Intercambia(FILE *fi, long iz, long de)
{
   stIndice reg1, reg2;

   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fread(&reg1, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fread(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fwrite(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fwrite(&reg1, sizeof(stIndice), 1, fi);
}