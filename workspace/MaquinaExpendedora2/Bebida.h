#ifndef BEBIDA_H_
#define BEBIDA_H_

#include <string>
#include "Producto.h"

class Bebida: public Producto
{
private:
	int miliL;
	string car; //característica

public:
	Bebida();
	Bebida(const int id, const string nombreP, const float precioP, const int num, const int gramos);
	//~Alimento(); ¿Tampoco lo necesitamos no?

	int getMiliL();
	void setMiliL();

	string getCar();
	void setCar();
	

};


#endif