#include "Compra.h"



Compra::Compra(const char* dni,const char * nombreU,const char * id,const char * nombreP)
{
	this->dniU= new char [strlen(dni)+1];
	strcpy(this->dniU, dni);
	this->nombreU= new char [strlen(nombreU)+1];
	strcpy(this->nombreU, nombreU);
	this->idP= new char [strlen(id)+1];
	strcpy(this->idP, id);
	this->nombreP= new char [strlen(nombreP)+1];
	strcpy(this->nombreP, nombreP);

}
Compra::Compra (const Compra &c)
{
	this->dniU= new char [strlen(c.dniU)+1];
	strcpy(this->dniU, c.dniU);
	this->nombreU= new char [strlen(c.nombreU)+1];
	strcpy(this->nombreU, c.nombreU);
	this->idP= new char [strlen(c.idP)+1];
	strcpy(this->idP, c.idP);
	this->nombreP= new char [strlen(c.nombreP)+1];
	strcpy(this->nombreP, c.nombreP);

}
Compra::~Compra()
{
	delete[] dniU;
	delete [] nombreP;
	delete[] idP;
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
	char* Compra::getIDP()const
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
	void Compra::setIDP(const char* id)
	{
		this->idP= new char [strlen(c.idP)+1];
		strcpy(this->idP, c.idP);
	}	
	void Compra::setNombreP(const char* nombreP)
	{
		this->nombreP= new char [strlen(c.nombreP)+1];
		strcpy(this->nombreP, c.nombreP);
	}	
	
istream& operator>>(istream& in, Compra& c)
{

}
ostream& operator<< (ostream &out, const Compra& c)
{

}