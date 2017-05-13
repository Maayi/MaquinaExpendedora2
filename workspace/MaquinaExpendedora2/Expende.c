#include "Expende.h"
#include <stdio.h>
#include <stdlib.h>

//inventario *datos;
//cambio *dinero;

struct inventario datos[10]=                        // Inventario Inicial de Bebidas y Alimentos
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
};    
void guardarProductos ()
{
//------------------------------------
FILE* f;

  
  //abrir fichero para escritura "w"
  f = fopen("Productos.txt", "w");
  int a;

for (a=0;a<10;a++)                                 
 { printf("%2i)\t%s\t\t %i\n",a+1,datos[a].nombres,datos[a].precio);}
  
  //cerrar fichero
  fclose(f);
}
void refresco()
{
 
int a,producto=0,ingreso=0,mon_tabla[10],cambio[10],total=0,saldo=0;   

//system("cls");
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

//system("pause");                  //con system ( pause), el programa no hara nada hasta que el usuario presione alguna tecla.
}

void reponer_retirar(int caso)
{
int a,producto=0,canrep=0; 
//system("cls");
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
//system("pause");
}

void invent_val_din(int caso)
{
int a,total=0; 
//system("cls");
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
}   }
//system("pause");  } 