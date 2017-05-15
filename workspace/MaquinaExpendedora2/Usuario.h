#ifndef USUARIO_H_
#define USUARIO_H_

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


	
};
#endif