#ifndef Admin_H_
#define Admin_H_

class Admin
{
private:
char *password;
char *nombreA;

public:
	Admin(const char* password, const char* nombreU);
	Admin (const Admin &u);
	~Admin();

	char * getDni() const;
	char * getNombre()const;
	void setDni(char *password);
	void setNombre(char *nombreU);


	
};
#endif