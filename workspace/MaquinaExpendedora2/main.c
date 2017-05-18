#include <stdio.h>
#include <stdlib.h>
#include "Expende.h"



int main()
{
 guardarProductos();
  FILE *f;
  f =fopen("ReadMe.txt","w");
  fprintf(f, "------------------------------------------------------\n Autoras:Anne Idigoras, Mayi Echeveste y Paula Elosegui\n");  
  fprintf(f, "------------------------------------------------------\n ");
  fprintf(f, "Bienvenidos a la maquina expendedora!\n\n");
  fprintf(f, "A continuacion le vamos a explicar su funcionamiento:\n\n");
  fprintf(f, "Nuestra maquina expendedora consta de 7 operaciones; \n 1) Coger el producto que quiera de entre los que disponemos; primero elegira el producto y despues introducira las monedas necesarias (en caso de se pase le devolveremos el cambio)\n");
  fprintf(f, " 2) Reponer el stock de productos\n 3) Saca una lista de la valoracion del inventario\n 4) Muestra la cantidad que tenemos para dar el cambio \n 5) Reponer el cambio \n 6) Retirar el cambio\n 7)Salir del programa");
  fprintf(f, "\n\n------------------------------------------------------\n ");
  fprintf(f, "\n Si tiene cualquier duda/ruego o sugerencia, pongase en contacto con: anneidigoras@opendeusto.es\n");
  fprintf(f, "------------------------------------------------------\n ");

int opcion;  
int total = 0;
  
  Usuario usuario[10];

do  
{
  //system("cls");   
  printf("\n   Maquina Expendedora\n\n");
  printf("\t1) Introducir usuario\n");
  printf("\t2) Datos usuarios\n");
  printf("\t3) Sacar un Producto\n");

  printf("\t4) Mostrar Cambio\n");
  
  printf("\t5) Retirar Cambio\n");
  printf("\t6)Ingreso Admin\n");

  printf("\t7) Salir\n\n");
  printf("     Seleccione una opcion: ");
  scanf("%i",&opcion);                              // Capturo opcion del Menu
  switch (opcion)
  {
    case 1: introUsuario(&usuario[total], total);
    break;
    case 2: datosUsuarios();
    break;
   case 3: refresco();                              // Compro Productos
           //guardar();
           break;
 
   case 4: invent_val_din(2);                       // Imprimo el Inventario de Dinero
           break;

   case 5: reponer_retirar(3);                      // Retiro Monedas
           break;
   case 6: ingresoAdmin();                             
           
           break;

   case 7: break;                                   // Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
            system("pause");
            break;     
  }
}while(opcion!=7);
fclose(f);
return 0;  
}



