#ifndef EXPENDE_H_
#define EXPENDE_H_

#ifdef __cplusplus
extern "C" {
#endif

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

/*typedef struct 
{
	int dni;
	char *nombre;

}Usuario;
*/


void invent_val_din(int caso);                      // Imprime los Inventarios de Bebidas y Monedas
void reponer_retirar(int caso);                     // Repone Cantidad de Bebidas y Monedas y Retira Monedas
void refresco();                                    // Saca el Refresco y Entrega el Cambio
void guardarProductos();
void guardar();                                     //Guardar los datos en un fichero
//void introUsuario(Usuario *u, int total);
//void liberarMemoria(Usuario *u, int total);
void clear_if_needed(char *str);
//void introUsuario(Usuario *u, int total);

void ingresoAdmin();

int menuUsuario();

int menuAdmin();

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif

#endif