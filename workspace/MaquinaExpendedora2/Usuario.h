#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <fstream>
using namespace std;


 
class Usuario
{
private:
	int dni;
    string nombre;



public:
	Usuario(const int dni,const string nombre);
	Usuario (const Usuario &u);
	~Usuario();
	

	int getDni() const;
	string getNombre()const;
	void setDni(const int dni);
	void setNombre(const string nombreU);	

};

int menuLogin();
ostream& operator<< (ostream &out, const Usuario& reg);


#endif