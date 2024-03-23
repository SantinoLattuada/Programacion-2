/*Ej. 21: Una empresa de aviación realiza 500 vuelos semanales a distintos puntos del país y requiere
desarrollar un programa para la venta de pasajes.
Para ello dispone de un archivo “Vuelos.dat”, con un registro por cada uno de los 500 vuelos que
realiza, sin ningún orden, con el siguiente diseño de registro:
a.1) código de vuelo (6 caracteres) a.2) cantidad de pasajes disponibles (3 dígitos) 

También se dispone de otro archivo “Compradores.dat”, con los potenciales compradores y con el siguiente diseño de registro:
b.1) código de vuelo b. 2) cantidad de pasajes solicitados (3 dígitos)
b.3) DNI del solicitante (8 dígitos) b.4) apellido y nombre del solicitante (25 caracteres)
Se pide:

1) Para los solicitantes a los cuales se les venden pasajes, emitir el siguiente listado:

DNI        Apellido y Nombre        Cantidad de pasajes  Código de Vuelo
99999999  xxxxxxxxxxxxxxxxxxxxxxxx         999                999
99999999  xxxxxxxxxxxxxxxxxxxxxxxx         999                999

2) Al final del proceso emitir el siguiente listado ordenado por código de vuelo
Código de Vuelo Pasajes disponibles Pasajes no vendidos
BUE999 999 999
XXX999 999 999*/

#include <iostream> 
#include "string.h"
#define MAX_VUELOS 500;
using namespace std;

struct Vuelo{
    char codigoVuelo[7];
    short int disponibles;
};
struct Compradores{
    char codigoVuelo[7];
    short int solicitudes;
    int dni;
    char apellidoNombre[26];
};
FILE *abrir(const char *path, const char *mode){
    FILE *file = fopen(path, mode);

    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    return file;
};

void leerComprador(Compradores *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(Compradores), 1, file);
    return;
}
int contarRegistros(FILE *file){
    int posActual = ftell(file);
    fseek(file, 0, SEEK_END);
    int cant = ftell(file) / sizeof(Vuelo);
    fseek(file, posActual, SEEK_SET);

    return cant;
}
Vuelo obtenerVuelo(int pos, FILE *file) {
    Vuelo vuelo;
    fseek(file, pos * sizeof(Vuelo), SEEK_SET);
    fread(&vuelo, sizeof(Vuelo), 1, file);
    return vuelo;
}

int buscarVuelo(char *codVuelo, FILE *file){
    int inicio = 0;
    int fin = contarRegistros(file) - 1;

    while (fin >= inicio){
        int mitad = inicio + (fin - inicio) / 2;

        Vuelo vuelo = obtenerVuelo(mitad, file);
        if (strcmp(vuelo.codigoVuelo, codVuelo) == 0){
            return mitad;
        }
        else if (strcmp(vuelo.codigoVuelo, codVuelo) < 0){
            fin = mitad - 1;
        }
        else{
            inicio = mitad + 1;
        }
    }
    return -1;
}
void imprimirComprador(Compradores comprador) {
    printf("%d", comprador.dni); // Faltan datos
    return;
}
void actualizarVuelo(int pos, Vuelo vuelo, FILE *file) {
    fseek(file, pos * sizeof(Vuelo), SEEK_SET);
    fwrite(&vuelo, sizeof(Vuelo), 1, file);
    return;
}
int main(){
    
    FILE *archivoVuelos = abrir("VUELOS.DAT", "rb");
    FILE *archivoCompradores = abrir("COMPRADORES.DAT", "rb");
    Vuelo vuelos;
    Compradores comprador;

    short int noVendidos[500] = {0};

    leerComprador(&comprador, archivoCompradores);
    while (!feof(archivoCompradores)){
        int posVuelo = buscarVuelo(comprador.codigoVuelo, archivoVuelos);
        vuelos = obtenerVuelo(posVuelo, archivoVuelos);

        if(vuelos.disponibles >= comprador.solicitudes){
            imprimirComprador(comprador);
            vuelos.disponibles -= comprador.solicitudes;
            actualizarVuelo(posVuelo, vuelos, archivoVuelos);
        }
        else{
            noVendidos[posVuelo] += comprador.solicitudes;
        }
        leerComprador(&comprador, archivoCompradores);
    }
    fclose(archivoCompradores);


    
    return 0;
}
