#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include <iostream>
using namespace std;

int main ()
{

	Producto p1 (1,"Mayi", 2.0, 10);
	p1.ReduceNum();
	cout << "Producto : "<<p1.getNum() <<endl;

	Alimento a1 (2, "Lorea", 2.0,15, 33);
	cout << "Alimento : "<< a1.getGramos() << endl;

	Bebida b1 (2, "Marcos", 5.0, 5, 100, "cucu");
	b1.setMiliL(200);

	cout << "Bebida : "<< b1.getMiliL() << endl;

	


	return 0;
}