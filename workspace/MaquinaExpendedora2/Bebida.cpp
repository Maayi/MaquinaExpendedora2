#include "Bebida.h"
#include <string.h>
#include <iostream>
using namespace std;



Bebida::Bebida(const int id, const char* nombreP, const float precioP, const int num, const int miliL, const char* car) : Producto (id, nombreP, precioP, num)
{
	this->miliL = miliL;
	this -> car = new char [strlen(car) + 1];
	strcpy(this->car, car);
}
Bebida::Bebida(const Bebida &b) : Producto (b)
{
	this->miliL = b.miliL;
	this -> car = new char [strlen(b.car) + 1];
	strcpy(this->car, b.car);

}
Bebida::~Bebida()
{
	delete []car;
}
int Bebida::getMiliL() const
{
	return miliL;
}
void Bebida::setMiliL(const int miliL)
{
	this->miliL =miliL;
}

char* Bebida::getCar() const
{
	return car;
}
void Bebida::setCar(const char* car)
{
	//this-> car = car;
}
void Bebida::escribirEnFichero(const char* fichero)
{
	//cout << "Escribiendo en " << fichero << endl;
}
void Bebida::Print() const
{
	Producto::Print();
	cout <<'\t' <<'\t' <<"Mililitros: " << miliL<< endl;
	cout <<'\t' <<'\t' <<"Caracteristicas: " << car << endl;
}
	
ostream& operator<< (ostream &out, const Bebida &b)
{
	out << b.getID()<< ": "<< b.getNombre() <<  '\t' <<"Precio: " << b.getprecioP() <<endl;
	out << '\t' <<'\t' <<"Stock: " << b.getNum()<< endl;
	out <<'\t' <<'\t' <<"Mililitros: " << b.getMiliL()<< endl;
	out <<'\t' <<'\t' <<"Caracteristicas: " << b.getCar()<< endl;
	
}