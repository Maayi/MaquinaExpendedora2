#include "Alimento.h"

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
