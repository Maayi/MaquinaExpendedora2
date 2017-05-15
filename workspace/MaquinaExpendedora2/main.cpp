#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include "Expende.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int main ()
{
  int opcion;  
int total = 0;
  
  Usuario usuario[10];

do  
{
  //system("cls");   
  cout << "Maquina Expendedora" <<  endl;
  cout << "1. Introducir usuario" <<  endl;
   cout << "2. Datos usuarioo" <<  endl;
  cout << "3.Sacar producto" <<  endl;
  cout << "4. Reponer productos" <<  endl;
  cout << "5. Inventario valorado" <<  endl;
  cout << "6. Mostrar cambio" <<  endl;
  cout << "6. Mostrar cambio" <<  endl;
  cout << "7. Reponer cambio" <<  endl;
  cout << "8. Retirar cambio" <<  endl;
  cout << "9. Salir" <<  endl;

 
  scanf("%i",&opcion);                              // Capturo opcion del Menu
  switch (opcion)
  {
    case 1: introUsuario(&usuario[total], total);
    break;
    case 2: datosUsuarios();
    break;
   case 3: refresco();                              // Compro Productos
           //guardar();
           break;
   case 4: reponer_retirar(1);                      // Repongo Productos
           //guardar();
           break;
   case 5: invent_val_din(1);                       // Imprimo el Inventario de Productos
           break;
   case 6: invent_val_din(2);                       // Imprimo el Inventario de Dinero
           break;
   case 7: reponer_retirar(2);                      // Repongo Monedas
           break;
   case 8: reponer_retirar(3);                      // Retiro Monedas
           break;
   case 9: break;                                   // Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
          
            break;     
  }
}while(opcion!=9);


	/*Producto p1 (1,"Mayi", 2.0, 10);
	p1.ReduceNum();
	cout << "Producto : "<<p1.getNum() <<endl;*/ // esto ya no se puede hacer por que ahora la clase persona es abstracta

	Alimento a1 (2, "Lorea", 2.0,15, 33);
	//cout << "Alimento : "<< a1.getGramos() << endl;
	cout<< a1;

	Bebida b1 (2, "Marcos", 5.0, 5, 100, "cucu");
	//b1.setMiliL(200);
	cout<< b1;

	a1.Print();
	b1.Print();



	string line;
  ifstream myfile("Productos.txt");
  float precio = 0.0;
  int i = 1;
  int total2 = 0;

  
  while (getline(myfile, line)) {
    cout << line << endl;
    if (i % 2 == 0) {
      float aux = atof(line.c_str());
      precio += aux;
      //total++;
    }
    else {
      size_t pos = line.find(" ");
      total2 = atoi(line.substr(pos).c_str());
    }
    i++;
  }
  

  cout << "Price = " << precio << ", total = " << total2 << endl;
  
  cout << "Precio medio de los pedidos: " << precio / (total2) << endl;

	


	return 0;
}