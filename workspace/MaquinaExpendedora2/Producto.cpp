#include "Producto.h"
#include <iostream>

using namespace std;

Producto:: Producto(const int id, const string nombreP, const float precioP, const int num)
{
	this->id =id;
	this->nombreP= nombreP;
	this ->precioP = precioP;
	this ->num = num;
}

int Producto::getID() const
{
	return this ->id;
}
string Producto::getNombre() const
{
	return this ->nombreP;
}

float Producto::getprecioP() const
{
	return this ->precioP;
}

int Producto::getNum() const
{
	return this -> num;
}

void Producto::setID(const int id)
{
	this -> id = id;
}

void Producto::setNombre(const string nombre)
{
	this -> nombreP = nombre;
}

void Producto::setprecioP( const float precio)
{
	this -> precioP = precio;
}
void setNum(const int num)
{
	this -> num = num;
}