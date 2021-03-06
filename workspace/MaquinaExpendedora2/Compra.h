#ifndef COMPRA_H_
#define COMPRA_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


 
class Compra
{
private:
	char*  dniU;
	char* nombreU;
	int idP;
	char* nombreP;
 

public:
	
	Compra(const char* dni,const char * nombreU,const int  id,const char * nombreP);
	Compra (const Compra &c);
	~Compra();
	

	char* getDniU() const;
	char* getNombreU()const;
	int getIDP()const;
	char* getNombreP()const;

	void setDniU(const char* dni);
	void setNombreU(const char* nombreU);	
	void setIDP(int id);	
	void setNombreP(const char* nombreP);	
	
	friend istream& operator>>(istream& in, Compra& c);

};

ostream& operator<< (ostream &out, const Compra& c);


#endif