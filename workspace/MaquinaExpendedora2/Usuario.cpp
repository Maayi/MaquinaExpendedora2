#include "Usuario.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>
#include <string>


using namespace std;


Usuario:: Usuario(const char* dni,const char * nombre,const char * ape1,const char * ape2 ,const long telef )
{
	this->dni= new char [strlen(dni)+1];
	strcpy(this->dni, dni);
	this->nombre= new char [strlen(nombre)+1];
	strcpy(this->nombre, nombre);
	this->ape1= new char [strlen(ape1)+1];
	strcpy(this->ape1, ape1);
	this->ape2= new char [strlen(ape2)+1];
	strcpy(this->ape2, ape2);
	this->telefono = telef;


}

Usuario::Usuario (const Usuario &u)
{

this->dni= new char [strlen(u.dni)+1];
	strcpy(this->dni, u.dni);
this->nombre= new char [strlen(u.nombre)+1];
	strcpy(this->nombre, u.nombre);
this->ape1= new char [strlen(u.ape1)+1];
	strcpy(this->ape1, u.ape1);
	this->ape2= new char [strlen(u.ape2)+1];
	strcpy(this->ape2, u.ape2);
this->telefono = u.telefono;
}
Usuario::~Usuario()
{
	delete [] dni;
	delete [] nombre;
	delete [] ape1;
	delete [] ape2;
}
char* Usuario::getDni() const
{

return this->dni;

}

char* Usuario::getNombre()const
{
	return this->nombre;

}
char* Usuario::getApe1()const
{
	return this->ape1;
}
char* Usuario::getApe2()const
{
	return this->ape2;
}
long Usuario::getTelefono() const
{
	return this->telefono;
}

void Usuario::setDni(const char * dni)
{
this->dni= new char [strlen(dni)+1];
	strcpy(this->dni, dni);

}
void Usuario::setNombre( const char* nombre)
{
	this->nombre= new char [strlen(nombre)+1];
	strcpy(this->nombre, nombre);
}
void Usuario::setApe1(const char* ape1)
{
	this->ape1= new char [strlen(ape1)+1];
	strcpy(this->ape1, ape1);
}
void Usuario::setApe2(const char* ape2)
{
	this->ape2= new char [strlen(ape2)+1];
	strcpy(this->ape2, ape2);

}	
void Usuario::setTelefono( const long telef)
{
	this ->telefono = telef;

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
ostream& operator<< (ostream &out, const Usuario &u)
{/*
	out << u.getDni()<< ": "<< u.getNombre() << " " <<  u.getApe1()<<" "<<u.getApe2()<<endl;
	out << "Telefono: " << u.getTelefono()<< endl;
*/
	out << u.getDni()<< " "<< u.getNombre() << " " <<  u.getApe1()<<" "<<u.getApe2()<<" "<<u.getTelefono()<<endl;
}



istream& operator>>(istream& in, Usuario& p) //aqui no hay this, esta fuera de la clase. Esta es funcion friend. Se salta la encapsulacion, por eso puedo hacer p.x y no hace falta p.getX
{
	char c;
	in >> p.dni>>c >> p.nombre >> c>> p.ape1 >> c>>p.ape2>>c >> p.telefono;
	return in;
  /*string nombre;
  int dni;
   cout << "Nombre: ";
   cin >> nombre;
   p.setNombre(nombre);
   cout << "Dni: ";
   cin >> dni;
   p.setDni(dni);
  
   return in;  //siempre return in*/
}

