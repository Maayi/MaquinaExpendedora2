#ifndef ALIMENTO_H_
#define ALIMENTO_H_

#include <string>
#include "Producto.h"

class Alimento: public Producto
{
private:
	int gramos;

public:
	Alimento(const int id, const char* nombreP, const float precioP, const int num, const int gramos);
	//~Alimento(); ¿Tampoco lo necesitamos no?

	int getGramos()const ;
	void setGramos(const int gr);
	

};


#endif