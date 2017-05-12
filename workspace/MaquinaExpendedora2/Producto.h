#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <string>

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

	int getID() const;
	string getNombre()const;
	float getprecioP()const;
	int getNum()const;

	void setID(const int id);
	void setNombre(const string nombre);
	void setprecioP(const float precio);
	void setNum(const int num);

};


#endif

