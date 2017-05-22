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


int MenuIncial();
void Capturar(vector<Usuario> & VectUsuarios);
void GuardarEnFichero(vector<Usuario> & VectUsuarios);
void LeerFichero(vector<Usuario> & VectUsuarios);
int  menuLogin(vector<Usuario> & VectUsuarios);

int main ()
{
  vector <Usuario> VectUsuarios;
  LeerFichero(VectUsuarios);
  
  int opcion;
  do  
  {   
    opcion = MenuIncial();

    switch (opcion)
    {
      case 1: Capturar(VectUsuarios); //Guardo en vectUsuario
              GuardarEnFichero(VectUsuarios); //Guardo en Fichero Usuario.txt
              menuUsuario(); //Llamo al menu del usuario
              break;

      case 2: LeerFichero(VectUsuarios);
              menuLogin(VectUsuarios);
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
void Capturar(vector<Usuario> & VectUsuarios) 
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
void LeerFichero(vector<Usuario> & VectUsuarios)
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
          VectUsuarios.push_back(u);
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
void GuardarEnFichero(vector<Usuario> & VectUsuarios)
{
  ofstream ofs("Usuarios.txt");
  for (vector< Usuario>:: iterator i= VectUsuarios.begin(); i!= VectUsuarios.end(); i++)
  {
    ofs << *i ;
  }
  
  ofs.close();
}

int  menuLogin(vector<Usuario> & VectUsuarios)
{
string nombre;
string dni;
    cout << "Nombre:" <<  endl;
    cin>> nombre;

    cout << "Dni:" <<  endl;
    cin>> dni;
/*
    for (vector< Usuario>:: iterator i= VectUsuarios.begin(); i!= VectUsuarios.end(); i++)
    {
      cout<< **i->getNombre() <<**i->getDni();

  
    string nomU = *i->getNombre();
    String dniU= *i->getDni();
    if (nomU == nombre && dniU == dni)
    {
      cout << '\t'<<"Bienvenido " << i*.getNombre()<< " " << i*.getApe1()<< endl;
    }
    else
    {
      cout <<"El dni o el nombre son incorrectos... Pruebe de nuevo:" <<endl;
      menuLogin();
    }
    }*/
    for (int i = 0; i<VectUsuarios.size(); i++)
    {
      string nomU = VectUsuarios[i].getNombre();
      string dniU= VectUsuarios[i].getDni();
      
    if (nomU != nombre || dniU != dni)
    {
      cout <<"El dni o el nombre son incorrectos... Pruebe de nuevo:" <<endl;
      menuLogin(VectUsuarios);
    }
    if ( nomU == nombre || dniU == dni)
    {
      cout << '\t'<<"Bienvenido " << VectUsuarios[i].getNombre()<< " " << VectUsuarios[i].getApe1()<< endl;
      menuUsuario();
      
    }
    }
  



 
}
