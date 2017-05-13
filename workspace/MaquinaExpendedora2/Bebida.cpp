#include "Bebida.h"
#include <string.h>
using namespace std;


Bebida::Bebida(const int id, const char* nombreP, const float precioP, const int num, const int miliL, const char* car) : Producto (id, nombreP, precioP, num)
{
	this->miliL = miliL;
	this -> car = new char [strlen(car) + 1];
	strcpy(this->car, car);
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

	
