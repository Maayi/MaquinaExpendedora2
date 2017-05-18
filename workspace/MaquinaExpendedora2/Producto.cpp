#include "Producto.h"
#include <iostream>
#include <string.h>

using namespace std;

Producto:: Producto(const int id, const char* nombreP, const float precioP, const int num)
{
	this->id =id;
	this->nombreP= new char [strlen(nombreP)+1];
	strcpy(this->nombreP, nombreP);
	this ->precioP = precioP;
	this ->num = num;
}

Producto::Producto(const Producto& p)
{
	this->id =p.id;
	//this->nombreP= p.nombreP;
	this ->precioP = p.precioP;
	this ->num = p.num;
}

int Producto::getID() const
{
	return this ->id;
}
char* Producto::getNombre() const
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

void Producto::setNombre( char* nombre)
{
	//this -> nombreP = nombre;
}

void Producto::setprecioP( const float precio)
{
	this -> precioP = precio;
}
void Producto::ReduceNum()
{
	num--;
}

void Producto::Print() const
{

	cout << id << ": "<< nombreP <<  '\t' <<"Precio: " << precioP <<endl;
	cout << '\t' <<'\t' <<"Stock: " << num<< endl;
}