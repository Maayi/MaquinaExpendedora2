#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <fstream>


 
class Usuario
{
private:
int dni;
char *nombreU;


public:
	Usuario(const int dni, const char* nombreU);
	Usuario (const Usuario &u);
	~Usuario();

	int getDni() const;
	char * getNombre()const;
	void setDni(const int dni);
	void setNombre(char *nombreU);
/*	std::ofstream file;


void Capturar(stRegistro &reg);
void Insertar(FILE *fa, stRegistro &reg);
void EliminarRetornoLinea(char *cad);
void ReconstruirIndices(FILE *fa);
void QuickSort(FILE *fa, long inicio, long final);
char *LeeCampo(FILE *fa, long n, char *buf);
void Intercambia(FILE *fa, long iz, long de);*/
	


	
};


#endif