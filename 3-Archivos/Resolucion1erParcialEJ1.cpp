/*1) Una cadena de venta de ropa con dos locales dispone de un archivo de stock 
de sus productos por cada sucursal con lossiguientes datos:
● Codigo de producto: numero entero
● Descripción: Cadena de 50 caracteres
● Stock: numero entero
Sabiendo que el archivo de stock de cada sucursal es binario y se 
encuentra ordenado por código de producto en forma
ascendente, y que pueden haber productos que estén en una sucursal y no en otra.
a. Realizar un procedimiento que permita unificar el stock de dos locales y generar un archivo de texto
STOCK_TOTAL.txt ordenado por código y con el siguiente diseño:
CODIGO DESCRIPCION STOCK
999999 XXXXXXXXXX 99999

b. Generar un archivo FALTANTES.DAT con mismo diseño que el archivo de stock con los productos que no tengan
stock en ninguno de los locales.*/

#include <iostream>
#include <string.h>
using namespace std;

struct Stock{
    int codProducto;
    char descripcion[51];
    int stock;
};
void leer(Stock *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(Stock), 1, file);
    return;
}
void leer(Stock *registro, FILE *ile){
    fread(registro, sizeof(Stock), 1, file);
    return;
}
void escribirFaltante(Stock registro, FILE *faltante){
    fwrite(&registro, sizeof(Stock), 1, faltante);
    return;
}
void escribirTotal(Stock registro, FILE *total){
    fprintf(total, "%d\t%s\t%d\n", registro.codProducto, registro.descripcion, registro.stock);
}
void escribir(Stock registro, FILE *total, FILE *faltante){
    escribirTotal(registro, total);
    if (registro.stock == 0){
        escribirFaltante(registro, faltante);
    }
    return;
}
void escribirTitulos(FILE *total){
    fprintf(total, "CODIGO\tDESCIPCION\tSTOCK\n");
}
void stockTotal(FILE *stock1, FILE *stock2, FILE *total, FILE *faltantes){
    Stock local1;
    leer(&local1, stock1);

    Stock local2;
    leer(&local2, stock2);

    while (!feof(stock1) && !feof(stock2)){
        if (local1.codProducto < local2.codProducto){
            escribir(local1, total, faltantes);
            leer(&local1, stock1);
        }
        else if (local2.codProducto < local1.codProducto){
            escribir(local2, total, faltantes);
            leer(&local2, stock2);
        }
        else{
            local1.stock += local2.stock;
            escribir(local1, total, faltantes);
            leer(&local1, stock1);
            leer(&local2, stock2);
        }
    }
    while (!feof(stock1)){
        escribir(local1, total, faltantes);
        leer(&local1, stock1);
    }
    while (!feof(stock2)){
        escribir(local2, total, faltantes);
        leer(&local2, stock2);
    }
    
}
int main(){
    
    void stockTotal(FILE *stock1, FILE *stock2, FILE *total, FILE *faltantes);


    return 0;
}
