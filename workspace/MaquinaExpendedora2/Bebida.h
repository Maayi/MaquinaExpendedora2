#ifndef BEBIDA_H_
#define BEBIDA_H_

#include "Producto.h"

class Bebida: public Producto
{
private:
	int miliL;
	char* car; //característica

public:
	Bebida();
	Bebida(const int id, const char* nombreP, const float precioP, const int num, const int miliL, const char* car);
	virtual ~Bebida(); 

	int getMiliL()const;
	void setMiliL(const int miliL);

	char* getCar()const;
	void setCar(const char* car);
	
	virtual void escribirEnFichero(const char* fichero); //esta clase no es abstracta
};


#endif