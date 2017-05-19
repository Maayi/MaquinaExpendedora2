#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include "Expende.h"
#include "Usuario.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

#include "Admin.h"

using namespace std;

vector <Usuario> VectUsuarios;
int MenuIncial();
void Capturar();
void GuardarEnFichero();
void LeerFichero();

int main ()
{
  int opcion;
  do  
  {   
    opcion = MenuIncial();

    switch (opcion)
    {
      case 1: Capturar();
              GuardarEnFichero();
              LeerFichero();
              menuUsuario();
              break;

      case 2: 
              //menuLogin();
              break;
    
      case 3: ingresoAdmin();                             
            break;

      case 4: break;                                   // Fin del Programa

      default: printf("\nError, Ingrese una de las siete opciones\n\n");
              system("pause");
              break;     
     }
  }while(opcion!=4);

return 0;
}

int MenuIncial()
{
  int opcion;
  cout << "Maquina Expendedora" <<  endl;
  cout << "1. Registro de usuario" <<  endl;
  cout << "2. Log in de usuario" <<  endl;
  cout << "3. Ingreso de Administrador" <<  endl;
  cout << "4. Salir" <<  endl;
  cin>>opcion;

  return opcion;
}

// Permite que el usuario introduzca un registro por pantalla
void Capturar() 
{

   char* id= new char [34];
   char* nom= new char [34];
   char* ape1 = new char [34];
   char* ape2 = new char [34];
   long telef;

   system("cls");
   cout << "Leer registro" << endl<<endl;

   cout << "ID: ";
   cin >> id;

   cout << endl<<"Nombre: ";
   cin >> nom; 
   
   cout <<endl<< "Primer apellido: ";
   cin >>ape1;
   
   cout << endl <<"Segundo apellido: ";
   cin >> ape2;
  
   cout << endl << "Telefono: ";
   cin >>telef;
  
   
   Usuario u (id, nom, ape1, ape2, telef);
    cout<< u;
   VectUsuarios.push_back(u);
} 
void LeerFichero()
{
   string id, nom, ape1, ape2,telef;
   //int telef;
   //Usuario *u;
  string line;
  string usuario;
  ifstream ifs("Usuarios.txt");

  int i=0;
  while(getline(ifs, line))
  {
    
    usuario += line;
   // usuario.push_back('\n');
    cout<< "Usuario "<< i << ": "<<usuario<< endl;
    usuario ="";
    i++;
  }
  //for (string line;getline(ifs, line ); )
  

    //ifs>>id>>nom >> ape1 >> ape2>> telef;

    
    //ifs>> id;
    //cout<< id;//<< " "<< nom << " " << ape1 << " "<< ape2 << " "<< telef<< endl;
    //Usuario u (id, nom, ape1, ape2, telef);
   // cout << u;
  // VectUsuarios.push_back(u);

  ifs.close();

}
void GuardarEnFichero()
{
  ofstream ofs("Usuarios.txt");
  for (vector< Usuario>:: iterator i= VectUsuarios.begin(); i!= VectUsuarios.end(); i++)
  {
    ofs << *i ;
  }
  
  ofs.close();
}

