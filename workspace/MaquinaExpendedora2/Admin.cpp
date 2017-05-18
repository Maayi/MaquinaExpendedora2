#include "Admin.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <vector>
#include <fstream>

#include <string>
#include <stdlib.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

Admin:: Admin(const char* password, const char* nombreA)
{
	this->nombreA = new char[strlen(nombreA)+1];
	strcpy(this->nombreA, nombreA);
	
	this->password = new char[strlen(password)+1];
	strcpy(this->password, password);
}
	Admin:: Admin (const Admin &u)
	{
		this->password = u.password;
        this->nombreA = u.nombreA;


	}

	void datosUsuarios()
{

	string line;
  ifstream myfile("indices.dat");
  float precio = 0.0;
  int i = 1;
  int total2 = 0;

  
  while (getline(myfile, line)) {
    cout << line << endl;
    if (i % 2 == 0) {
      float aux = atof(line.c_str());
      precio += aux;
      //total++;
    }
    else {
      size_t pos = line.find(" ");
      total2 = atoi(line.substr(pos).c_str());
    }
    i++;
  }
  

  cout << "Price = " << precio << ", total = " << total2 << endl;
  
  cout << "Precio medio de los pedidos: " << precio / (total2) << endl;
  }

