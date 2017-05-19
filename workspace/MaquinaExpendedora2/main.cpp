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

      case 2: LeerFichero();
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
  cout << "___________________LEYENDO FICHERO USUARIOS.TXT____________________"<< endl<< endl;
  VectUsuarios.clear();
  vector<string> atributos;
  const char* id= new char [34];
  const char* nom= new char [34];
  const char* ape1 = new char [34];
  const char* ape2 = new char [34];
  long telefono=0;

  string line;
  string usuario;
  ifstream ifs("Usuarios.txt");

  int i=0;
  while(getline(ifs, line))
  {
    
    usuario += line;

          istringstream iss(usuario);
          string s;
          while ( getline( iss, s, ' ' ) ) 
          {
              atributos.push_back(s);
          }
          if(atributos.size()<6)
          {

          id = atributos[0].c_str();
          nom =atributos[1].c_str();
          ape1 = atributos[2].c_str();
          ape2=  atributos[3].c_str();
          telefono = atol(atributos[4].c_str());
          Usuario u (id, nom, ape1, ape2, telefono);
          cout<< u;
          }
          else 
          {
            cout<< "USUARIO MAL REGISTRADO"<< endl;
          }

          atributos.clear();
                    
    //cout<< "Usuario "<< i << ": "<<usuario<< endl;
    usuario ="";
    i++;
  }

  ifs.close();
  cout << "_________________________________________" << endl;

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

