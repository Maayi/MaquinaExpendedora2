#ifndef EXPENDE_H_
#define EXPENDE_H_

struct inventario
{
	
int id;
int cantidad;
char *nombres;
int precio;     
} ;

struct cambio
{
int valor;
int monedas;
};

/*struct inventario datos[10]=                        // Inventario Inicial de Bebidas y Alimentos
{
10,"Coca Cola",2,
10,"Pepsi Cola",2,
10,"Bifrutas",3,
10,"Red Bull",4,
10,"Heineken",3,
10,"KitKat   ",1,
10,"Oreo    ",2,
10,"Snickers",2,
10,"Principe",3,
10,"Nestea    ",3     
};

struct cambio dinero[10]=                     // Inventario Inicial de Monedas
{
0,10,        // valor, cantidad
1,10,
2,10,
5,10,
10,10,
15,10,
20,10,
25,10,
50,10,
100,10
};    */

void invent_val_din(int caso);                      // Imprime los Inventarios de Bebidas y Monedas
void reponer_retirar(int caso);                     // Repone Cantidad de Bebidas y Monedas y Retira Monedas
void refresco();                                    // Saca el Refresco y Entrega el Cambio
void guardarProductos();
void guardar();                                     //Guardar los datos en un fichero


#endif