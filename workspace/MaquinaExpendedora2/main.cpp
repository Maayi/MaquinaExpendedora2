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
#include "sqlite3.h"
#include <stdio.h>
#include <iostream>

#include "Admin.h"

using namespace std;
void RegistroUsuario(vector<Usuario> & VectUsuarios);
void guardoCompra(int id);
int MenuIncial();
void IngresoAdmin(vector<Usuario> & VectUsuarios);
void MenuAdmin(vector<Usuario> & VectUsuarios);
void Capturar(vector<Usuario> & VectUsuarios);
void GuardarEnFichero(vector<Usuario> & VectUsuarios);
void LeerFichero(vector<Usuario> & VectUsuarios);
int  IngresoCliente(vector<Usuario> & VectUsuarios);
int eliminarUsuario(vector<Usuario> & VectUsuarios);


int main (int argc, const char * argv[])
{
  vector <Usuario> VectUsuarios;
  LeerFichero(VectUsuarios);

  sqlite3 *db;
sqlite3_open("user.db", & db);



  std:: string createQuery = "CREATE TABLE IF NOT EXISTS items (id TEXT PRIMARY KEY, nombre TEXT, ape1 TEXT,  ape2 TEXT, tele INTEGER NOT NULL DEFAULT (NOW()));";
   sqlite3_stmt *createStmt;
  cout << "Creating Table Usuaio" << endl;
  sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
   cout << "Stepping Table Usuario" << endl;
   if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "Didn't Create Table!" << endl;

   string insertQuery = "INSERT INTO items (id,nombre, ape1 , ape2, tele) VALUES ('123', 'anne','idigoras','pagola','123');"; // WORKS!


   sqlite3_stmt *insertStmt;
   cout << "Creating Insert Statement" << endl;
   sqlite3_prepare(db, insertQuery.c_str(), insertQuery.size(), &insertStmt, NULL);
   cout << "Stepping Insert Statement" << endl;
   if (sqlite3_step(insertStmt) != SQLITE_DONE) cout << "Didn't Insert Item!" << endl;

  cout << "Success!" << endl;
 
  int opcion;
  do  
  {   
    opcion = MenuIncial();

    switch (opcion)
    {
      case 1: system("cls");
              RegistroUsuario(VectUsuarios);
              break;

      case 2: LeerFichero(VectUsuarios);
              IngresoCliente(VectUsuarios);
              break;
    
      case 3: IngresoAdmin(VectUsuarios);                             
            break;

      case 4: break;                                   // Fin del Programa

      default: printf("\nError, Ingrese una de las siete opciones\n\n");
              system("pause");
              break;     
     }
  }while(opcion!=4);

return 0;
}
void RegistroUsuario(vector<Usuario> & VectUsuarios)
{
  int result =0;
  Capturar(VectUsuarios); //Guardo en vectUsuario
  GuardarEnFichero(VectUsuarios); //Guardo en Fichero Usuario.txt
  result =menuUsuario(); //Llamo al menu del usuario
  int id = result;
  if (id != -1) {guardoCompra(id);}

}

void guardoCompra(int id)
{
  printf("Producto comprado: %s Precio: %i\n",getNombre(id), getPrecio(id) );
}

void IngresoAdmin(vector<Usuario> & VectUsuarios)
{
string name;
string pass;
cout<< "Enter username:"<< endl;
cin >> name;
cout << "Enter password:"<< endl;
cin>> pass;
if (name == "Admin"&& pass== "pass")
{
  cout << "Access granted" <<endl;
  MenuAdmin(VectUsuarios);
}
else cout <<"Access denied" << endl;
}

void MenuAdmin(vector<Usuario> & VectUsuarios)
{

  int opcion;  
  int total = 0;

do  
{
  printf("\t1) Datos usuarios\n");
  printf("\t2) Reponer Productos\n");
  printf("\t3) Inventario Valorado\n"); 
  printf("\t4) Fichero txt de productos\n"); 
  printf("\t5) Reponer Cambio\n");
  printf("\t6) Retirar Cambio\n");
  printf("\t7)Eliminar Usuario\n");


  printf("\t8) Salir\n\n");
  printf("     Seleccione una opcion: ");
  scanf("%i",&opcion);                              // Capturo opcion del Menu
  switch (opcion)
  {
    case 1: LeerFichero(VectUsuarios); 
    break;
    
   case 2: reponer_retirar(1);                      // Repongo Productos
           //guardar();
           break;
   case 3: invent_val_din(1);                       // Imprimo el Inventario de Productos
           break;
   case 4: guardarProductos();
            break;
   case 5: reponer_retirar(2);                       // Repongo monedas
           break;
   case 6: reponer_retirar(3);                      // Retiro Monedas
           break;
    case 7 : eliminarUsuario(VectUsuarios);
    break;


   case 8: system("cls");
            break;                                   // Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
            system("pause");
            break;     
  }
}while(opcion!=8);

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
   bool repetido; 
   char* id= new char [34];
   char* nom= new char [34];
   char* ape1 = new char [34];
   char* ape2 = new char [34];
   long telef;

  do
  {
   repetido = false;
   
   cout << "Leer registro" << endl<<endl;

   cout << "ID: ";
   cin >> id;



   for (int i = 0; i<VectUsuarios.size(); i++)
    {
     
      string dniU= VectUsuarios[i].getDni();
      
      if (  dniU == id)
      {
        repetido = true;
        break;
      }
    }
    if (repetido == true)
    {
      cout << endl <<"El ID que has introducido pertencen al de otra persona dada de alta en nuestro sistema, prueba con otros datos por favor"<<endl << endl;
    }
    else
    {

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
   

    
  }while (repetido ==true);
} 
void LeerFichero(vector<Usuario> & VectUsuarios)
{
  cout << endl <<"___________________LEYENDO FICHERO USUARIOS.TXT____________________"<< endl<< endl;
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
          cout<<'\t'<< '\t'<< u;
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
  cout << "___________________________________________________________________" << endl<< endl;





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

int  IngresoCliente(vector<Usuario> & VectUsuarios)
{
  bool correcto= false;
string nombre;
string apellido;
string dni;
    cout << "Nombre:" <<  endl;
    cin>> nombre;

    cout << "Dni:" <<  endl;
    cin>> dni;

    for (int i = 0; i<VectUsuarios.size(); i++)
     {
      string nomU = VectUsuarios[i].getNombre();
      string dniU= VectUsuarios[i].getDni();
      
    if ( nomU == nombre && dniU == dni)
       {
      correcto = true;
      apellido = VectUsuarios[i].getApe1();
      break;
      
       }
    else  correcto = false;
    }
    if (correcto == false)
    { 
      cout <<"El dni o el nombre son incorrectos... " <<endl<< endl;
     }
    else 
    {
      cout << '\t'<<"Bienvenido " << nombre << " " << apellido<< endl;
      menuUsuario();

    }  
     
}

int eliminarUsuario (vector<Usuario> & VectUsuarios)
{
   bool correcto= false;
string nombre;
string apellido;
string dni;
    cout << "Nombre:" <<  endl;
    cin>> nombre;

    cout << "Dni:" <<  endl;
    cin>> dni;

    for (int i = 0; i<VectUsuarios.size(); i++)
    {
      string nomU = VectUsuarios[i].getNombre();
      string dniU= VectUsuarios[i].getDni();
      
    if ( nomU == nombre && dniU == dni)
      {
      correcto = true;
      apellido = VectUsuarios[i].getApe1();
       cout << '\t'<<"Eliminando...." << nombre << " " << apellido<< endl;
      
      VectUsuarios.erase(VectUsuarios.begin()+i);

      GuardarEnFichero(VectUsuarios);

      break;
      
       }
    else  correcto = false;
     }
    if (correcto == false)
    { 
      cout <<"El dni o el nombre son incorrectos... " <<endl<< endl;
     }
 

    



  return 0;
    

    }

