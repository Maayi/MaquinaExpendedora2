#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include <iostream>
using namespace std;

ostream& operator<< (ostream &out, const Producto &p)
{
	out << p.getID()<< ": "<< p.getNombre() <<  '\t' <<"Precio: " << p.getprecioP() << " Stock" << p.getNum()<< endl;
	
}

ostream& operator<< (ostream &out, const Alimento &a) //: Producto (stream &out, const Alimento &a )
{
	out << a.getID()<< ": "<< a.getNombre() <<  '\t' <<"Precio: " << a.getprecioP() <<endl;
	out << '\t' <<'\t' <<"Stock: " << a.getNum()<< endl;
	out <<'\t' <<'\t' <<"Gramos: " << a.getGramos()<< endl;
	
}
/*ostream& operator<< (ostream &out, const Bebida &b)
{
	out << "Capacidad= " << a.getCapacity() << '\t' <<"Valores: " << endl;
	for (int i =0; i< a.getCapacity(); i++)
	{
		out << a.getValue(i) << endl;
	}
}
*/
int main ()
{

	/*Producto p1 (1,"Mayi", 2.0, 10);
	p1.ReduceNum();
	cout << "Producto : "<<p1.getNum() <<endl;*/ // esto ya no se puede hacer por que ahora la clase persona es abstracta

	Alimento a1 (2, "Lorea", 2.0,15, 33);
	//cout << "Alimento : "<< a1.getGramos() << endl;
	cout<< a1;

	Bebida b1 (2, "Marcos", 5.0, 5, 100, "cucu");
	//b1.setMiliL(200);


	cout << "Bebida : "<< b1.getMiliL() << endl;

	


	return 0;
}