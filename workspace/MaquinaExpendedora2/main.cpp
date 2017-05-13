#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include <iostream>

#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
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


ostream& operator<< (ostream &out, const Bebida &b)
{
	out << b.getID()<< ": "<< b.getNombre() <<  '\t' <<"Precio: " << b.getprecioP() <<endl;
	out << '\t' <<'\t' <<"Stock: " << b.getNum()<< endl;
	out <<'\t' <<'\t' <<"Mililitros: " << b.getMiliL()<< endl;
	out <<'\t' <<'\t' <<"Caracteristicas: " << b.getCar()<< endl;
	
}

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
	cout<< b1;

	cout << "Bebida : "<< b1.getMiliL() << endl;

	string line;
  ifstream myfile("Productos.txt");
  float precio = 0.0;
  int i = 1;
  int total = 0;

  
  while (getline(myfile, line)) {
    cout << line << endl;
    if (i % 2 == 0) {
      float aux = atof(line.c_str());
      precio += aux;
      //total++;
    }
    else {
      size_t pos = line.find(" ");
      total = atoi(line.substr(pos).c_str());
    }
    i++;
  }
  

  cout << "Price = " << precio << ", total = " << total << endl;
  
  cout << "Precio medio de los pedidos: " << precio / (total) << endl;

	


	return 0;
}