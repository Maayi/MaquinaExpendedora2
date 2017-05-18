#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <fstream>
using namespace std;


 
class Usuario
{
private:
	int dni;
	char * nombre;
	char * ape1;
	char * ape2;
	int telefono;
 

public:
	Usuario(const int dni,const char * nombre,const char * ape1,const char * ape2, const int telef );
	Usuario (const Usuario &u);
	~Usuario();
	

	int getDni() const;
	char* getNombre()const;
	char* getApe1()const;
	char* getApe2()const;
	int getTelefono() const;

	void setDni(const int dni);
	void setNombre(const char* nombre);	
	void setApe1(const char* ape1);	
	void setApe2(const char* ape2);	
	void setTelefono( const int telef);

};

int menuLogin();
ostream& operator<< (ostream &out, const Usuario& u);
//istream& operator>>(istream& in, Usuario& p);

#endif