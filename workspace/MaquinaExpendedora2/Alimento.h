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
	//virtual ~Alimento(); ¿Tampoco lo necesitamos no?

	int getGramos()const ;
	void setGramos(const int gr);

	virtual void Print() const;
	
	virtual void escribirEnFichero(const char* fichero); //esta clase no es abstracta
};


#endif