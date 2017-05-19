#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


 
class Usuario
{
private:
	char*  dni;
	char * nombre;
	char * ape1;
	char * ape2;
	long telefono;
 

public:
	
	Usuario(const char* dni,const char * nombre,const char * ape1,const char * ape2, const long telef );
	Usuario (const Usuario &u);
	~Usuario();
	

	char* getDni() const;
	char* getNombre()const;
	char* getApe1()const;
	char* getApe2()const;
	long getTelefono() const;

	void setDni(const char* dni);
	void setNombre(const char* nombre);	
	void setApe1(const char* ape1);	
	void setApe2(const char* ape2);	
	void setTelefono( const long telef);
	friend istream& operator>>(istream& in, Usuario& p);

};

int menuLogin();
ostream& operator<< (ostream &out, const Usuario& u);


#endif