/*Ejercicio 1
Una vinoteca desea un sistema que le permita conocer mejor la performance de sus variedades en venta. Para
esto cuenta con dos archivos:
ventas.txt
Cod. Producto Fecha Precio unitario Cantidad
Entero de 1 a 1000 AAAAMMDD Real Entero de 0 a 100

vinos.dat
Cod. Producto Nombre Bodega Mejor marca
Entero de 1 a 1000 Hasta 50 caracteres Hasta 50 caracteres Real

El archivo vinos.dat se encuentra ordenado por Cod. Producto y tiene 
la información del tipo de vino y el récord de facturación mensual hasta el momento. 
El archivo ventas.txt posee solo las ventas del mes en curso y
está ordenado cronológicamente (por fecha ascendente) y sus campos se separan por ‘ ; ’
Realizar diagrama y codificación del sistema que permita:
a. Procesar las ventas registradas y actualizar el archivo vinos.dat para que al finalizar refleje los nuevos
récords de facturación.
b. Generar el archivo reporte.txt que imprima los datos de cada vino en venta, seguidos de todas sus
ventas registradas:
Cod. Producto: 9999 Bodega: Nombre: Mejor facturación: $120.000
01-01-2020 $100 1
02-01-2020 $60.70 3
El listado debe estar ordenado por Vino y cada grupo de ventas por fecha.
c. Informar por pantalla:
i. La facturación mensual total
ii. Cuál es el vino que más vendió este mes.
iii. El día del mes que menos se vendió.*/

#include <iostream>
using namespace std;

typedef struct Ventas{
    int codProducto;
    int fecha;
    float precio;
    int cant;
}STR_VENTAS;
typedef struct Dato{
    int codProducto;
}STR_DATO;

typedef struct Vinos{
    int codProducto;
    char nombre[51];
    char bodega[51];
    float mejorMarca; 
}STR_VINOS;

typedef struct Nodo{
    STR_DATO dato;
    STR_NODO *ste;
}STR_NODO;
FILE abrir();

int main(){
    FILE *archivoVentas = abrir("ArchivoVentas.txt ", "rt");
    FILE *archivoVinos = abrir("ArchivoVinos.dat ", "wb");

    STR_NODO *lista = NULL;

    STR_VENTAS venta;
    
    leer(&venta, archivoVentas);
    while (!feof(archivoVentas)){
        
    }
    

    return 0;
}
