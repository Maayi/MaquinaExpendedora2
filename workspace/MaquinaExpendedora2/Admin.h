#ifndef Admin_H_
#define Admin_H_

class Admin
{
private:
char *password;
char *nombreA;

public:
	Admin(const char* password, const char* nombreA);
	Admin (const Admin &u);
	

	void datosUsuarios();



	
};
#endif