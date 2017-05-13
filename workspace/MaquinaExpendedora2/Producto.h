#ifndef PRODUCTO_H_
#define PRODUCTO_H_

//#include <string>

class Producto
{
private:
	int id;
	char * nombreP;
	float precioP;
	int num; //Cuantos quedan en la maquina

public:
	Producto(const int id, const char* nombreP, const float precioP, const int num);
	Producto (const Producto &p);
	//virtual ~Producto(); ¿No lo necesitamos no?

	int getID() const;
	char* getNombre()const;
	float getprecioP()const;
	int getNum()const;

	void setID(const int id);
	void setNombre( char* nombre);
	void setprecioP(const float precio);
	void ReduceNum();

};


#endif

