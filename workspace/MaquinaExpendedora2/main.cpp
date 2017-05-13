#include "Producto.h"
#include <iostream>
using namespace std;

int main ()
{

	Producto p1 (1,"Mayi", 2.0, 10);
	p1.ReduceNum();
	cout << p1.getNum() <<endl;


	


	return 0;
}