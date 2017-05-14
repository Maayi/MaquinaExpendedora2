#ifndef PRODUCTO_H_
#define PRODUCTO_H_

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

	virtual void Print() const; // es para enseñar por pantalla los productos por pantalla

	virtual void escribirEnFichero(const char* fichero) = 0; //metodo abstracto que hace que la clase sea abstracta)
	

};


#endif

