#include "Producto.h"
#include "Alimento.h"
#include "Bebida.h"
#include "Expende.h"
#include "Usuario.h"
#include "Compra.h"
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
#include <stdio.h>
#include <iostream>

#include "Admin.h"

using namespace std;
void LeerCompras();
void LeerFichero();
void guardoCompra(int id,Usuario& u);
void eliminarUsuario();
void Capturar();
void GuardarEnFichero();
void RegistroUsuario();
int  IngresoCliente();
void MenuUsuario(Usuario &u);
int MenuIncial();
void IngresoAdmin();
void MenuAdmin();


 static vector <Compra> VectCompras;
 static vector <Usuario> VectUsuarios;
 
int main (int argc, const char * argv[])
{
  
  FicheroProyecto();

  LeerCompras();

  LeerFichero();
 
  int opcion;
  do  
  {   
    opcion = MenuIncial();

    switch (opcion)
    {
      case 1:
              RegistroUsuario();
              break;

      case 2: IngresoCliente();
              break;
    
      case 3: IngresoAdmin();                             
              break;

      case 4: break;                                   // Fin del Programa

      default: cout<<"Error, Ingrese una de las cuatro opciones"<<endl;
    
              break;     
     }
  }while(opcion!=4);

return 0;
}

void RegistroUsuario()
{

  Capturar();
  GuardarEnFichero(); //Guardo en Fichero Usuario.txt
  Usuario u = VectUsuarios.back();
  MenuUsuario(u); //Llamo al menu del usuario
}

void guardoCompra(int id, Usuario& u)
{

  Compra c (u.getDni(), u.getNombre(), id, getNombre(id));
  VectCompras.push_back(c);


  ofstream ofs("Ficheros/Compras.txt");

  for (vector<Compra>:: iterator i= VectCompras.begin(); i!= VectCompras.end(); i++)
  {
    cout<< *i;
    ofs << *i ;
  }
  
  ofs.close();


}

void IngresoAdmin()
{


string name;
string pass;
cout<< "Nombre admin:"<< endl;
cin >> name;
cout << "Password:"<< endl;
cin>> pass;
if (name == "Admin"&& pass== "pass")
{
  cout << "Access valido" <<endl;
  MenuAdmin();
}
else cout <<"Access denegado" << endl;
}

void MenuAdmin()
{

  int opcion;  
  int total = 0;

do  
{
	cout<< "1) Datos usuarios"<< endl;
	cout<< "2) Reponer Productos"<< endl;
	cout<< "3) Inventario Valorado"<< endl;
	cout<< "4) Fichero txt de productos"<< endl;
	cout<< "5) Reponer Cambio"<< endl;
	cout<< "6) Retirar Cambio"<< endl;
	cout<< "7) Eliminar Usuario"<< endl;
	cout<< "8) Compras registradas"<< endl;
	cout<< "9) Salir"<< endl;

	cout<< endl;
	cout<<endl;


 cout<< " Seleccione una opcion:"<< endl;

   cin>> opcion;
 // scanf("%i",&opcion);                              // Capturo opcion del Menu
  switch (opcion)
  {
    case 1: LeerFichero(); 
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
    case 7 : LeerFichero();
            eliminarUsuario();
            break;

    case 8: LeerCompras();
    break;


   case 9: system("cls");
            break;                                   // Fin del Programa
   default: cout<<"Error, Ingrese una de las siete opciones"<<endl;
            
            break;     
  }
}while(opcion!=9);

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
void LeerCompras()
{

 cout << endl <<"_________________________FICHERO Compras.TXT____________________"<< endl<< endl;
  VectCompras.clear();
  vector<string> atributos;
  const char* dniU= new char [34];
  const char* nomU= new char [34];
  int idP = 0;
  const char* nombreP = new char [34]; 

  string line;
  string compra;
  ifstream ifs("Ficheros/Compras.txt");
  if(ifs==NULL)
  {
    cout << '\t' <<"No hay ninguna compra registrada"<< endl;
  }
  else
  {

  int i=0;
  while(getline(ifs, line))
  {
    
    compra += line;

          istringstream iss(compra);
          string s;
          while ( getline( iss, s, ' ' ) ) 
          {
              atributos.push_back(s);
          }
          if(atributos.size()<5)
          {

          dniU = atributos[0].c_str();
          nomU=atributos[1].c_str();
          idP = atoi( atributos[2].c_str());
          nombreP = atributos[3].c_str();
          
          Compra c (dniU, nomU, idP, nombreP);
          cout<<'\t'<< '\t'<< c;
          VectCompras.push_back(c);
          }
          else if (atributos.size()<6) 
          {
            
          dniU = atributos[0].c_str();
          nomU=atributos[1].c_str();
          idP = atoi( atributos[2].c_str());
          string nomP1 = atributos[3];
          string nomP2 = atributos[4];
          string nom= nomP1.append(" ").append(nomP2);
          nombreP = nom.c_str();
          Compra c (dniU, nomU, idP, nombreP);
          cout<<'\t'<< '\t'<< c;
          VectCompras.push_back(c);
          }
          else cout<< "Compras MAL REGISTRADAS"<< endl;

          atributos.clear();
                    
    compra ="";
    i++;
  }

  }
  
  ifs.close();
  cout << "___________________________________________________________________" << endl<< endl;




}
void LeerFichero()
{
  cout << endl <<"__________________________ FICHERO USUARIOS.TXT____________________"<< endl<< endl;
  VectUsuarios.clear();
  vector<string> atributos;
  const char* id= new char [34];
  const char* nom= new char [34];
  const char* ape1 = new char [34];
  const char* ape2 = new char [34];
  long telefono=0;

  string line;
  string usuario;
  ifstream ifs("Ficheros/Usuarios.txt");
 if(ifs==NULL)
  {
    cout << '\t' <<"No hay ningun usuario registrado"<< endl;
  }
  else
  {
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

    usuario ="";
    i++;
  }
}
  ifs.close();
  cout << "___________________________________________________________________" << endl<< endl;

}

void GuardarEnFichero()
{
  ofstream ofs("Ficheros/Usuarios.txt");
  for (vector< Usuario>:: iterator i= VectUsuarios.begin(); i!= VectUsuarios.end(); i++)
  {
    ofs << *i ;
  }
  
  ofs.close();
}

int  IngresoCliente()
{
  Usuario *u;
  bool correcto= false;
  string nombre;
  string apellido;
  string dni;
  LeerFichero();

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
      *u = VectUsuarios[i];
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
      int result =0;
      MenuUsuario(*u); //Llamo al menu del usuario
    

    }  
     
}

void eliminarUsuario ()
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

      GuardarEnFichero();

      break;
      
       }
    else  correcto = false;
     }
    if (correcto == false)
    { 
      cout <<"El dni o el nombre son incorrectos... " <<endl<< endl;
     }
    

    }
    void MenuUsuario(Usuario &u)
    {

    int opcion;  
    int total = 0;
    int idP; //id del producto comprado en caso de que exista una compra;
    
    do  
    {
     printf("\t1) Comprar producto\n");
    printf("\t2) Salir\n\n"); 
  
     printf("     Seleccione una opcion: ");
      scanf("%i",&opcion);                              // Capturo opcion del Menu

  switch (opcion)
  {
    
   case 1: idP = refresco(); 
           if (idP != -1) {guardoCompra(idP, u);}                  
           break;

   case 2: system ("cls");
            break;                                   // Fin del Programa

   default: printf("\nError, Ingrese una de las dos opciones\n\n");
            
            break;     
  }
}while(opcion!=2);

}

