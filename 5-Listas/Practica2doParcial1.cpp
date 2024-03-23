/*Ejercicio 1
Una vinoteca desea un sistema que le permita conocer mejor la performance de sus variedades en venta. Para
esto cuenta con dos archivos:
ventas.txt
Cod. Producto Fecha Precio unitario Cantidad
Entero de 1 a 1000 AAAAMMDD Real Entero de 0 a 100

vinos.dat
Cod. Producto Nombre Bodega Mejor marca
Entero de 1 a 1000 Hasta 50 caracteres Hasta 50 caracteres Real

El archivo vinos.dat se encuentra ordenado por Cod. Producto y tiene la información del tipo de vino y el
récord de facturación mensual hasta el momento. El archivo ventas.txt posee solo las ventas del mes en curso y
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

struct Ventas{
    int codProducto;
    int fecha;
    float precioUnit;
    int cant;
};
struct Vinos{
    int codProducto;
    char nombre[51];
    char bodega[51];
    float mejorMarca;
};
struct STR_DATO
{
    int codigoProducto
};
struct STR_NODO
{
    STR_DATO dato;
    STR_NODO *ste;
};
// Crear un nodo
void create(STR_NODO **list)
{
    *list = NULL;
}
void abrir(){

}
void leer(){

}
STR_NODO *insertOrdered(STR_NODO **list, int dato);
int main(){
    
    FILE *archivoVentas = abrir("Ventas.txt", "rt");
    FILE *archivoVinos = abrir("Vinos.dat", "wb");
    
    float facturacionVino[1000] = {0};
    float facturacionFecha[30] = {0}; 
    float facturacion;

    Ventas venta;
    leer(&venta, archivoVentas);
    

    STR_NODO *listaVentas;
    STR_NODO *listaAuxiliar = listaVentas;
    while (!feof(archivoVentas)){
        facturacionVino[venta.codProducto - 1] += venta.precioUnit * venta.cant;
        facturacionFecha[(venta.fecha % 100) - 1] += venta.precioUnit * venta.cant;

        insertOrdered(venta, &listaVentas);

        leer(&venta, archivoVentas);
    }
    
    while (!isEmpty(listaVentas)){
        int key = listaVentas ->dato.codigoProducto;
    
        Vinos vino;

        leerVino(&vino, archivoVinos, key);

        fprintf("Código de producto %d\t Bodega %s \t Nombre %s \t Mejor facturación %s\n", key, vino.nombre, vino.bodega, vino.mejorMarca);
        if (vino.mejorMarca < facturacionVino[key - 1]){
            vino.mejorMarca = facturacionVino[key - 1];
            actualizarVino(&vino, archivoVinos, key);
        }
        while (!isEmpty(listaVentas && key == listaVentas ->dato.codigoProducto)){
            fprintf("%d\t%.2f\t%d\n", listaAuxiliar->dato.fecha, listaAuxiliar->dato.precio, listaAuxiliar->dato.cantidad);
            facturacion += listaVentas->dato.precio * listaVentas->dato.cantidad;
            listaVentas = listaAuxiliar->ste;
        }
        if (facturacionVino[key - 1] < mejorVinoFacturacion)
        {
            
        }
        
    }
    
    


    return 0;
}
STR_NODO *insertOrdered(STR_NODO **list, int dato)
{
    // Crea el nodo
    STR_NODO *nodo = (STR_NODO *)(malloc(sizeof(STR_NODO)));
    nodo->dato = dato;
    nodo->ste = NULL;

    // Avanza hasta encontrar el nodo mayor
    STR_NODO *listAux = *list;
    STR_NODO *nodoAnt = NULL;
    while (listAux != NULL && dato < listAux->dato)
    {
        nodoAnt = listAux;
        listAux = listAux->ste;
    }
    if (nodoAnt == NULL)
    {
        *list = nodo;
    }
    else
    {
        nodoAnt->ste = nodo;
    }

    nodo->ste = listAux;
    return nodo;
}