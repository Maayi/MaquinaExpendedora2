#include "Usuario.h"
#include <iostream>
#include <string.h>

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