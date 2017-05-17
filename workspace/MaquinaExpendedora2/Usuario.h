#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <fstream>
using namespace std;


 
class Usuario
{



public:
	Usuario(const int dni,const char* nombre);
	Usuario (const Usuario &u);
	~Usuario();
	int dni;
char *nombre;

	
   /*const char* LeeNombre() const: 
 
   int LeeDni() const 
   {return dni;}*/


	int getDni() const;
	char * getNombre()const;
	void setDni(const int dni);
	void setNombre(char *nombreU);	

};

int menuLogin();
ostream& operator<< (ostream &out, const Usuario& reg);


#endif