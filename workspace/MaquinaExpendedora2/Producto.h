#include <string>
#ifndef PRODUCTO_H_
#define PRODUCTO_H_

class Producto
{
private:
	int id;
	string nombreP;
	float precioP;
	int num; //Cuantos quedan en la maquina

public:
	Producto(const int id, const string nombreP, const float precioP, const int num);
	//~Producto(); ¿No lo necesitamos no?

	int getID();
	string getNombre();
	float getprecioP();
	int getNum();

	void setID();
	void setNombre();
	void setprecioP();
	void setNum();

};


#endif

