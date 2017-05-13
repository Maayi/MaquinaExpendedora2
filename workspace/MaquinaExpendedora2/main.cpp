#include "Producto.h"
#include "Alimento.h"
#include <iostream>
using namespace std;

int main ()
{

	Producto p1 (1,"Mayi", 2.0, 10);
	p1.ReduceNum();
	cout << p1.getNum() <<endl;

	Alimento a1 (2, "Lorea", 2.0,15, 33);
	cout << a1.getGramos() << endl;


	


	return 0;
}