/*Dado el archivo binario libros.dat, que posee datos desordenados 
sobre libros valiosos con la siguiente estructura:
ISBN || Nombre || Año edición || Valor
Entero (10 dígitos) || Char(40) || Entero (1600 - 1700) || Float (2 decimales)
Se desea obtener un listado agrupado por ISBN ordenado por año 
indicando: ISBN, Nombre y Valor Promedio.
Restricciones:
● No posee memoria estática suficiente para almacenar el archivo en memoria.
● No dispone de espacio suficiente en disco para duplicar el archivo.*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct Libros{
    int ISBN;
    char nombre[41];
    int anioEdicion;
    float valor;
}STR_LIBROS;

typedef struct Nodo{
    STR_LIBROS dato;
    STR_NODO *ste;
}STR_NODO;
void leer(){

}
int main(){
    FILE *archivoLibros = abrir("libros.dat", "r");

    STR_NODO *lista = NULL;
   
    STR_LIBROS libro;

    leer(&libro, archivoLibros);
    while(!feof(archivoLibros)){
        insertOrdered(&lista, libro);
        leer(&libro, archivoLibros);
    }
    
    fclose(archivoLibros);
    return 0;
}