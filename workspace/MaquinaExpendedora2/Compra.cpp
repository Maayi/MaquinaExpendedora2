#include "Compra.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>
#include <string>



Compra::Compra(const char* dni,const char * nombreU,const int id,const char * nombreP)
{
	this->dniU= new char [strlen(dni)+1];
	strcpy(this->dniU, dni);
	this->nombreU= new char [strlen(nombreU)+1];
	strcpy(this->nombreU, nombreU);
	this->idP= id;
	this->nombreP= new char [strlen(nombreP)+1];
	strcpy(this->nombreP, nombreP);

}
Compra::Compra (const Compra &c)
{
	this->dniU= new char [strlen(c.dniU)+1];
	strcpy(this->dniU, c.dniU);
	this->nombreU= new char [strlen(c.nombreU)+1];
	strcpy(this->nombreU, c.nombreU);
	this->idP=  c.idP;
	this->nombreP= new char [strlen(c.nombreP)+1];
	strcpy(this->nombreP, c.nombreP);

}
Compra::~Compra()
{
	delete[] dniU;
	delete [] nombreP;
	delete [] nombreU;

}
	

	char* Compra::getDniU() const
	{
		return dniU;

	}
	char* Compra::getNombreU()const
	{
		return nombreU;
	}
	int Compra::getIDP()const
	{
		return idP;
	}
	char* Compra::getNombreP()const
	{
		return nombreP;
	}

	void Compra::setDniU(const char* dni)
	{
		this->dniU= new char [strlen(dni)+1];
		strcpy(this->dniU, dni);
	}
	void Compra::setNombreU(const char* nombreU)
	{
		this->nombreU= new char [strlen(nombreU)+1];
		strcpy(this->nombreU, nombreU);
	}
	void Compra::setIDP(const int id)
	{
		this->idP= id;
	}	
	void Compra::setNombreP(const char* nombreP)
	{
		this->nombreP= new char [strlen(nombreP)+1];
		strcpy(this->nombreP, nombreP);
	}	
	
istream& operator>>(istream& in, Compra& c)
{
	char a;
	in >> c.dniU >> a >> c.nombreU >> a>> c.idP >> a >>c.nombreP;
	return in;
}
ostream& operator<< (ostream &out, const Compra& c)
{
	out << c.getDniU() << " "<< c.getNombreU() << " " << c.getIDP()<< " "<< c.getNombreP()<<endl;
}