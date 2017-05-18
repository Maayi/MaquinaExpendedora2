#include "Usuario.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>


using namespace std;

Usuario:: Usuario(const int dni, const string nombre )
{
	this->dni = dni;
	// this->nombre = new char[strlen(nombre)+1];
	// strcpy(this->nombre, nombre);

  this-> nombre =nombre;

}

Usuario:: Usuario (const Usuario &u)
{

this->dni = u.dni;
this->nombre = u.nombre;

}

int Usuario:: getDni() const
{

return this->dni;

}

string Usuario:: getNombre()const
{
	return this->nombre;


}

void Usuario:: setDni(const int dni)
{
this -> dni= dni;

}
void Usuario::setNombre( const string nombre)
{
	this -> nombre = nombre;
}
/* const char* Usuario::LeeNombre() const 
   {
      return nombre;
   }
   int Usuario::LeeEdad() const 
   {
      return edad;
   }
   const char* Usuario:: LeeTelefono() const 
   {
      return telefono;
   }*/

/*Usuario::Usuario(int dni_, char * n) 

 {
   strcpy(nombre, n);
   strcpy(dni, dni_);
}*/

ostream& operator<<(ostream &os,const Usuario& reg)
 {
   os << "Nombre: " << reg.getNombre() << "\nDni: " <<
      reg.getDni() ;

   return os;
}

istream& operator>>(istream& in, Usuario& p) //aqui no hay this, esta fuera de la clase. Esta es funcion friend. Se salta la encapsulacion, por eso puedo hacer p.x y no hace falta p.getX
{
  string nombre;
  int dni;
   cout << "Nombre: ";
   cin >> nombre;
   p.setNombre(nombre);
   cout << "Dni: ";
   cin >> dni;
   p.setDni(dni);
  
   return in;  //siempre return in
}
int  menuLogin()
{
string nombre;
int dni;
    cout << "Nombre:" <<  endl;
    cin>> nombre;

  cout << "Dni:" <<  endl;
  cin>> dni;
 
}

