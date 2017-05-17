#include "Usuario.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

Usuario:: Usuario(const int dni, const char* nombreU )
{
	this->dni = dni;
	this->nombreU = new char[strlen(nombreU)+1];
	strcpy(this->nombreU, nombreU);

}

Usuario:: Usuario (const Usuario &u)
{

this->dni = u.dni;
this->nombreU = u.nombreU;

}

int Usuario:: getDni() const
{

return this->dni;

}

char* Usuario:: getNombre()const
{
	return this->nombreU;


}

void Usuario:: setDni(const int dni)
{
this -> dni= dni;

}
void Usuario::setNombre( char* nombreU)
{
	this -> nombreU = nombreU;
}

/*void Usuario::Capturar(stRegistro &reg)
{
	int i;
   char numero[6];

  // system("cls");
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
}
void Usuario::Insertar(FILE *fa, stRegistro &reg)
{
	// Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(stRegistro), 1, fa);
   ReconstruirIndices(fa);
}
void Usuario:: EliminarRetornoLinea(char *cad)
{
	 int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}
void Usuario:: ReconstruirIndices(FILE *fa)
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
void Usuario::QuickSort(FILE *fi, long inicio, long final)
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
char *Usuario::LeeCampo(FILE *fi, long n, char *buf)
{
	 stIndice ind;

   fseek(fi, n*sizeof(stIndice), SEEK_SET);
   fread(&ind, sizeof(stIndice), 1, fi);
   strcpy(buf, ind.telefono);
   return buf;
}
void Usuario::Intercambia(FILE *fi, long iz, long de)
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
}*/