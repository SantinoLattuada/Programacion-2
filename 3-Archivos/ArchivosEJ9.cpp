/**
 * Dado el archivo binario generado en el ejercicio 7, que contiene todas las inscripciones del día, y
otro con el mismo diseño que contiene las inscripciones anteriores (FINALES.DAT), desarrolle un programa
que agregue al archivo de inscripciones anteriores el contenido del archivo del día. Al final del
proceso emita un listado del archivo de los registros agregados al archivo.

Abrir archivo Finales.DAT en modo append o lectura/escritura
Posicionarnos al final del archivo
Abrir archivo del dia DIAFINALES.DAT en modo lectura

Recorrer secuencialmente DIAFINALES.DAT
 - Escribir cada registro en FINALES.DAT

Cerrar archivos


*/

#include <iostream>
#include "string.h" 
using namespace std;
struct Inscripcion
{
    int legajo;
    int codMateria;
    int dia;
    int mes;
    int anio;
    char nombre[26];
};

FILE *abrir(const char *path, const char *mode){
    FILE *file = fopen(path, mode);

    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    return file;
}
void leer(Inscripcion *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(Inscripcion), 1, file);
    return;
}
void escribir(Inscripcion *ptrRegistro, FILE *file) {
    fwrite(ptrRegistro, sizeof(Inscripcion), 1, file);
    return;
}
int main(){
    
    FILE *finales = abrir("FINALES.DAT", "wb");
    FILE *diaFinales = abrir("DIAFINALES.DAT", "rb");

    //Nos posicionamos al final del archivo finales.dat
    fseek(finales, 0, SEEK_END);
    int posEscritura = ftell(finales);

    Inscripcion registro;   
    leer(&registro, diaFinales);

    while (!feof(diaFinales)){
        escribir(&registro, finales);
        leer(&registro, diaFinales);
    }

    fseek(finales, posEscritura, SEEK_SET);
    leer(&registro, finales);
    
    while(!feof(finales)) {
        printf("%d;%d;%2d/%2d/%4d;%s\n", registro.legajo, registro.codMateria, registro.dia, registro.mes,registro.anio, registro.nombre);
        leer(&registro, finales);
    }

    fclose(diaFinales);
    fclose(finales);

    system("pause"); 

    return 0;
}
