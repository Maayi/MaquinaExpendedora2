
 
#include <stdio.h>
#include <stdlib.h>

void invent_val_din(int caso);                      // Imprime los Inventarios de Bebidas y Monedas
void reponer_retirar(int caso);                     // Repone Cantidad de Bebidas y Monedas y Retira Monedas
void refresco();                                    // Saca el Refresco y Entrega el Cambio

struct inventario
{
int cantidad;
char *nombres;
int precio;     
};

struct inventario datos[10]=                        // Inventario Inicial de Bebidas y Alimentos
{
10,"Coca Cola",3,
10,"Pepsi Cola",3,
10,"Bifrutas",6,
10,"Red Bull",8,
10,"Heineken",12,
10,"KitKat",16,
10,"Oreo",23,
5,"Snickers",88,
5,"Principe",109,
5,"Nestea",251     
};

struct tabla_cambio
{
int valor;
int monedas;
};

struct tabla_cambio dinero[10]=                     // Inventario Inicial de Monedas
{
1,10,
2,10,
5,10,
10,10,
20,10,
50,10,
100,10,
200,10,
500,10,
1000,10
};      
      
int main()
{
int opcion;  
do  
{
  system("cls");   
  printf("\n     La Super Maquina Expendedora\n\n");
  printf("\t1) Sacar un Producto\n");
  printf("\t2) Reponer Productos\n");
  printf("\t3) Inventario Valorado\n"); 
  printf("\t4) Mostrar Cambio\n");
  printf("\t5) Reponer Cambio\n");
  printf("\t6) Retirar Cambio\n");
  printf("\t7) Salir\n\n");
  printf("     Seleccione una opcion: ");
  scanf("%i",&opcion);                              // Capturo opcion del Menu
  switch (opcion)
  {
   case 1: refresco();                              // Compro Productos
           break;
   case 2: reponer_retirar(1);                      // Repongo Productos
           break;
   case 3: invent_val_din(1);                       // Imprimo el Inventario de Productos
           break;
   case 4: invent_val_din(2);                       // Imprimo el Inventario de Dinero
           break;
   case 5: reponer_retirar(2);                      // Repongo Monedas
           break;
   case 6: reponer_retirar(3);                      // Retiro Monedas
           break;
   case 7: break;                                   // Fin del Programa
   default: printf("\nError, Ingrese una de las siete opciones\n\n");
            system("pause");
            break;     
  }
}while(opcion!=7);
return 0;  
}

void refresco()
{
int a,item=0,ingreso=0,mon_tabla[10],cambio[10],total=0,saldo=0;   
system("cls");
for (a=0;a<10;a++)
  mon_tabla[a]=cambio[a]=0;                         // Reseteo las Monedas Ingresadas por el Cliente y las que se le Entregaran por Cambio
printf("\t  Refresco\t\tPrecio\n\n");
for (a=0;a<10;a++)                                 // Imprimo el Inventario de Productos
  printf("%2i)\t%s\t\t%5i\n",a+1,datos[a].nombres,datos[a].precio);
while (item<1||item>10)
{     
  printf("\nIngrese el codigo del refresco que desea comprar: ");
  scanf("%i",&item);                                // Escojo producto
  if (item<1||item>10)
   printf("\nError, Ingrese una de las diez opciones\n"); 
} 
if (datos[item-1].cantidad==0)                   
  printf("\n\t\tProducto Agotado");
else
{
  printf("\n\tValor\n\n");
  for (a=0;a<10;a++)                                // Imprimo los Valores de las Monedas
   printf("%2i)\t%5i\n",a+1,dinero[a].valor); 
  printf("11) Fin de Ingreso de Monedas\n");    
  while(ingreso!=11)
  {
   printf("\nIngrese el codigo de la moneda a ingresar (11 para concluir): ");
   scanf("%i",&ingreso);
   if (ingreso<1||ingreso>11)
    printf("\nError, Ingrese una de las once opciones\n");
   else if (ingreso!=11)
   {
    mon_tabla[ingreso-1]++;                         // Guardo Cada Moneda
    total+=dinero[ingreso-1].valor;                 // Guardo la Cantidad Total Ingresada
   } 
  }
  for (a=0;a<10;a++)
   mon_tabla[a]+=dinero[a].monedas;                 // Tengo la Cantidad Total de Monedas: Maquina+Cliente 
  printf("\nCantitad Total Ingresado: %i\n",total);
  if (total<datos[item-1].precio)
   printf("\nImporte Insuficiente\n\n");             
  else                                              // Si el Dinero es Suficiente, Procede a Entregar Cambio y Producto
  {
   saldo=total-datos[item-1].precio;                // Saldo a entregar
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
    printf("\nCambio: %i\n\n",total-datos[item-1].precio);  
    for (a=0;a<10;a++)
    {
     dinero[a].monedas=mon_tabla[a];                // Guardo la Cantidad de Monedas en la Maquina
     if (cambio[a]>0)                               // Imprimo el Cambio  
     printf("%i monedas de %i\n",cambio[a],dinero[a].valor);                       
    } 
    datos[item-1].cantidad--;                       // Entrego el producto                                 
    printf("\n");   
   }                                                                    
  }      
}    
system("pause");
}

void reponer_retirar(int caso)
{
int a,item=0,canrep=0; 
system("cls");
if (caso==1)
{
  printf("\t  Refresco\t     Cantidad\n\n");
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de Bebidas
   printf("%2i)\t%s\t\t%2i\n",a+1,datos[a].nombres,datos[a].cantidad);
}
else
{
  printf("\tValor\t     Cantidad\n\n");
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de Monedas
   printf("%2i)\t%4i\t\t%2i\n",a+1,dinero[a].valor,dinero[a].monedas);  
} 
while (item<1||item>10)
{  
  if (caso==3)
   printf("\nIngrese el codigo de la moneda que desea retirar: ");
  else  
   printf("\nIngrese el codigo del item que desea reponer: ");
  scanf("%i",&item);                                // Capturo el Item a Reponer o la Moneda a Retirar 
  if (item<1||item>10)
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
  datos[item-1].cantidad+=canrep;                   // Repongo la Cantidad de Bebidas
  printf("\n\n       Nuevo inventario de Producto\n");
  printf("\n\t%s\t\t%2i\n\n",datos[item-1].nombres,datos[item-1].cantidad);
}
else
{
  if (caso==2)  
   dinero[item-1].monedas+=canrep;                  // Repongo la Cantidad de Monedas
  else
  {
   if (dinero[item-1].monedas==0||dinero[item-1].monedas<canrep)
    printf("\nNo hay suficientes monedas de %i para retirar",dinero[item-1].valor);
   else
    dinero[item-1].monedas-=canrep;                 // Retiro Monedas
  }     
  printf("\n\n     Nuevo inventario de Moneda\n");  // Imprimo Nueva Cantidad de Monedas
  printf("\n\t%i\t\t%2i\n\n",dinero[item-1].valor,dinero[item-1].monedas);  
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
  for (a=0;a<10;a++)                                 // Imprimo el Inventario de Bebidas
  {
   printf("%2i)\t%s\t   %2i\t\t %4i\t\t %4i\n",a+1,datos[a].nombres,datos[a].cantidad,datos[a].precio,datos[a].cantidad*datos[a].precio);  
   total+=datos[a].cantidad*datos[a].precio;         // Obtengo el Importe Total de Bebidas                                                                                
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
system("pause");  } 