#include <iostream>
#include <string.h>
#define MAX_BUFFER 255
using namespace std;

struct Entregas{
    char identificador[31];
    float peso;
    bool entregado;
    int calificacion;
};
struct Identificador{
    int horaRegistro;
    int codigoRepartidor;
    int dni;
};
struct Repartidor{
    int codigoRepartidor;
    char apellido[26];
    char nombre[26];
    int fechaNacimiento;
    float califPromedio;
    int paquetesEntregados;
};
struct AcumuladorRepartidor{
    int paquetes;
    int calificaciones;
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
void leer(Entregas *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(Entregas), 1, file);
    return;
}
void procesarIdentificador()
int main(){
    
    FILE *archivoEntregasDiarias = abrir("DIARIAS.DAT", "rb");
    FILE *archivoRepartidores = abrir("NOMINA.TXT", "r");
    FILE *nominaActualizada = abrir("NOMINAACT.TXT", "rb");

    AcumuladorRepartidor acumulador;
    Entregas entrega;
    leer(&entrega, archivoEntregasDiarias);

    while (!feof(archivoEntregasDiarias)){
        Identificador Identificador = procesarIdentificador(entrega.identificador);

    }
    

    return 0;
}

