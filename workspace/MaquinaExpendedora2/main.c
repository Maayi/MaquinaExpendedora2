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
  printf("\t4) Reponer Productos\n");
  printf("\t5) Inventario Valorado\n"); 
  printf("\t6) Mostrar Cambio\n");
  printf("\t7) Reponer Cambio\n");
  printf("\t8) Retirar Cambio\n");
  printf("\t9) Salir\n\n");
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
   case 4: reponer_retirar(1);                      // Repongo Productos
           //guardar();
           break;
   case 5: invent_val_din(1);                       // Imprimo el Inventario de Productos
           break;
   case 6: invent_val_din(2);                       // Imprimo el Inventario de Dinero
           break;
   case 7: reponer_retirar(2);                      // Repongo Monedas
           break;
   case 8: reponer_retirar(3);                      // Retiro Monedas
           break;
   case 9: break;                                   // Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
            system("pause");
            break;     
  }
}while(opcion!=9);
fclose(f);
return 0;  
}

/*void guardar ()
{
 
}*/

/*void guardarProductos ()
{
//------------------------------------
FILE* f;
  
  //abrir fichero para escritura "w"
  f = fopen("Productos.txt", "w");
  int a;
  for (a=0;a<10;a++)
    fprintf(f, "%2i)\t%s\t\t %i\n",a+1,datos[a].nombres,datos[a].precio );
  
  //cerrar fichero
  fclose(f);
}
void refresco()
{
 
int a,producto=0,ingreso=0,mon_tabla[10],cambio[10],total=0,saldo=0;   

system("cls");
for (a=0;a<10;a++)
  mon_tabla[a]=cambio[a]=0;                         // Reseteo las Monedas Ingresadas por el Cliente y las que se le Entregaran por Cambio

printf("\t  Producto\t\tPrecio\n\n");



for (a=0;a<10;a++)                                 // Imprimo el Inventario de Productos
 { printf("%2i)\t%s\t\t %i\n",a+1,datos[a].nombres,datos[a].precio);}



while (producto<1||producto>10)
{     
  printf("\nIngrese el codigo del refresco que desea comprar: ");
  scanf("%i",&producto);                                // Escojo producto

 

  if (producto<1||producto>10)
   printf("\nError, Ingrese una de las diez opciones\n"); 
} 
if (datos[producto-1].cantidad==0)                   
  printf("\n\t\tProducto Agotado");
else
{
  printf("\n\tValor\n\n");
  for (a=0;a<10;a++)                                // Imprimo los Valores de las Monedas
   printf("%2i)\t%5i\n",a+1,dinero[a].valor); 
  printf("11) Fin de Ingreso de Monedas\n");    
  while(ingreso!=11)
  {
   printf("\nIngrese el codigo de la moneda a ingresar (11 para volver al inicio): ");
   scanf("%i",&ingreso);
   if (ingreso<1||ingreso>11)
    printf("\nError, Ingrese una de las 11 opciones\n");
   else if (ingreso!=11)
   {
    mon_tabla[ingreso-1]++;                         // Guardo Cada Moneda
    total+=dinero[ingreso-1].valor;                 // Guardo la Cantidad Total Ingresada
   } 
  }
  for (a=0;a<10;a++)
   mon_tabla[a]+=dinero[a].monedas;                 // Tengo la Cantidad Total de Monedas: Maquina+Cliente 
  printf("\nCantitad Total Ingresado: %i\n",total);
  if (total<datos[producto-1].precio)
   printf("\nImporte Insuficiente\n\n");             
  else                                              // Si el Dinero es Suficiente, Procede a Entregar Cambio y Producto
  {
   saldo=total-datos[producto-1].precio;                // Saldo a entregar
   for(a=9;a>=0;a--)
   {
    if ((dinero[a].valor<=saldo)&&mon_tabla[a]>0)
    {                           
     saldo-=dinero[a].valor;                        // Disminuyo el Saldo
     mon_tabla[a]--;                                // Disminuyo la Cantidad de Monedas Disponibles 
     cambio[a]++;                                   // Aumento el Cambio
     a++;                            
    }                                         
   }
   if (saldo!=0)
    printf("\nIntroduzca Importe Exacto\n\n");
   else
   {
    printf("\nCambio: %i\n\n",total-datos[producto-1].precio);  
    for (a=0;a<10;a++)
    {
     dinero[a].monedas=mon_tabla[a];                // Guardo la Cantidad de Monedas en la Maquina
     if (cambio[a]>0)                               // Imprimo el Cambio  
     printf("%i monedas de %i\n",cambio[a],dinero[a].valor);                       
    } 
    datos[producto-1].cantidad--;                       // Entrego el producto                                 
    printf("\n");   

   }                                                                    
  }      
}    

system("pause");                  //con system ( pause), el programa no hara nada hasta que el usuario presione alguna tecla.
}

void reponer_retirar(int caso)
{
int a,producto=0,canrep=0; 
system("cls");
if (caso==1)
{
  printf("\t  Refresco\t     Cantidad\n\n");
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de Productos
   printf("%2i)\t%s\t\t%2i\n",a+1,datos[a].nombres,datos[a].cantidad);
}
else
{
  printf("\tValor\t     Cantidad\n\n");
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de Monedas
   printf("%2i)\t%4i\t\t%2i\n",a+1,dinero[a].valor,dinero[a].monedas);  
} 
while (producto<1||producto>10)
{  
  if (caso==3)
   printf("\nIngrese el codigo de la moneda que desea retirar: ");
  else  
   printf("\nIngrese el codigo del producto que desea reponer: ");
  scanf("%i",&producto);                                // Capturo el producto a Reponer o la Moneda a Retirar 
  if (producto<1||producto>10)
   printf("\nError, Ingrese una de las diez opciones\n"); 
}
while (canrep<1)
{ 
  if (caso==3)
   printf("\nIngrese la cantidad de monedas a retirar: ");
  else     
   printf("\nIngrese la cantidad a reponer: ");
  scanf("%i",&canrep);                              // Capturo la Cantidad a Reponer o Retirar 
  if (canrep<1)
  {
   if (caso==3) 
    printf("\nError, La cantidad minima de monendas a retirar es de 1\n");      
   else  
    printf("\nError, La cantidad minima a reponer es de 1\n");
  }  
}
if (caso==1)
{
  datos[producto-1].cantidad+=canrep;                   // Repongo la Cantidad de Bebidas
  printf("\n\n       Nuevo inventario de Producto\n");
  printf("\n\t%s\t\t%2i\n\n",datos[producto-1].nombres,datos[producto-1].cantidad);
}
else
{
  if (caso==2)  
   dinero[producto-1].monedas+=canrep;                  // Repongo la Cantidad de Monedas
  else
  {
   if (dinero[producto-1].monedas==0||dinero[producto-1].monedas<canrep)
    printf("\nNo hay suficientes monedas de %i para retirar",dinero[producto-1].valor);
   else
    dinero[producto-1].monedas-=canrep;                 // Retiro Monedas
  }     
  printf("\n\n     Nuevo inventario de Moneda\n");  // Imprimo Nueva Cantidad de Monedas
  printf("\n\t%i\t\t%2i\n\n",dinero[producto-1].valor,dinero[producto-1].monedas);  
} 
system("pause");
}

void invent_val_din(int caso)
{
int a,total=0; 
system("cls");
if (caso==1)
{ 
  printf("\n\t\t\tInventario Valorado\n\n");
  printf("\tRefresco\tCantidad\tPrecio\t\tImporte\n\n");
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de productos
  {
   printf("%2i)\t%s\t   %2i\t\t %2i\t\t %2i\n",a+1,datos[a].nombres,datos[a].cantidad,datos[a].precio,datos[a].cantidad*datos[a].precio);  
   total+=datos[a].cantidad*datos[a].precio;         // Obtengo el Importe Total de productos                                                                              
  }
  printf("\n\t\t\tTotal Inventario:\t\t %i\n\n",total);
}
else
{
  printf("\n\t\tTabla de Cambio\n\n");
  printf("\tValor\t\tCantidad\tImporte\n\n");
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de Monedas
  {
   printf("%2i)\t%4i\t\t   %i\t\t %5i\n",a+1,dinero[a].valor,dinero[a].monedas,dinero[a].valor*dinero[a].monedas);  
   total+=dinero[a].valor*dinero[a].monedas;         // Obtengo el Importe Total de Monedas                                                                                
  }
  printf("\n\t\tTotal de Cambio:\t %i\n\n",total);   
}   
system("pause");  } */