#include "Alimento.h"
#include <iostream>


using namespace std;

Alimento::Alimento(const int id, const char* nombreP, const float precioP, const int num, const int gramos) : Producto (id, nombreP, precioP, num)
{
	this->gramos = gramos;
}
int Alimento::getGramos() const
{
	return gramos;
}
void Alimento::setGramos(const int gr)
{
	this -> gramos = gr;
}
void Alimento::escribirEnFichero(const char* fichero)
{
	//cout << "Escribiendo en " << fichero << endl;
}

void Alimento::Print() const
{
	Producto::Print();
	cout <<'\t' <<'\t' <<"Gramos: " << gramos<< endl;
}
