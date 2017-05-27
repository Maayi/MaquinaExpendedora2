#ifndef EXPENDE_H_
#define EXPENDE_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct 
{	
int id;
int cantidad;
char *nombres;
int precio;     
} inventario;

struct cambio
{
int valor;
int monedas;
};

char* getNombre(int id); //Para obtener el nombre de un producto del inventario pasandole su id
int getPrecio(int id); //Para obtener el precio de un producto del inventario pasandole su id

void invent_val_din(int caso);                      // Imprime los Inventarios de Bebidas y Monedas

void reponer_retirar(int caso);                     // Repone Cantidad de Bebidas y Monedas y Retira Monedas
inventario* refresco();                                    // Saca el Refresco y Entrega el Cambio Devuelve el producto que se ha retirado.
void guardarProductos();
void guardar();                                     //Guardar los datos en un fichero
void clear_if_needed(char *str);
int menuUsuario();

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif

#endif