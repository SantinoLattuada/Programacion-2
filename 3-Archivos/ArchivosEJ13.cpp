/*Ej. 13: Se dispone un archivo binario de inscripción de alumnos a exámenes finales
MAESTROFINALES.DAT y otro con las inscripciones del día de hoy DIAFINALES.DAT, ambos
ordenados ascendente por código de materia y con el siguiente diseño:
a.1Nro de legajo (8 dígitos) a.2 Código de materia (6 dígitos) a.3 ApellidoNombre(25caract)

Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales
FINALESACT.DAT resultante del apareo de los dos archivos anteriores, con el mismo orden y diseño.
Estrategia:
 Asignar y abrir archivos
 Leer registro archivo maestro con control de EOF
 Leer registro archivo finales del día con control de EOF
 Mientras no sea fin de archivo de ninguno de los dos archivos o Si el código de materia del registro del maestro es menor al código de materia del registro del archivo del día
 Grabar registro archivo maestro en archivo de finales actualizado
 Leer registro archivo maestro con control de EOF o De lo contrario
 Grabar registro archivo finales del día en archivo de finales actualizado
 Leer registro archivo finales del día con control de EOF
 Por fin de archivo del maestro mientras no sea fin de archivo de finales del día o 
Grabar registro archivo finales del día en archivo de finales actualizado o Leer registro archivo finales del día con control de EOF
 Por fin de archivo finales del día mientras no sea fin de archivo maestro o 
Grabar registro archivo maestro en archivo de finales actualizado o Leer registro archivo maestro con control de EOF
 Cerrar archivos*/

#include <iostream>
#include "string.h" 
using namespace std;

struct Inscripciones{
    int legajo;
    int codigoMateria;
    char apellidoNombre[26];
};
FILE *abrir(const char *path, const char *mode){
    FILE *file = fopen(path, mode);

    if (file == NULL){
        fprintf(stderr, "No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    return;
}
void leer(Inscripciones *ptregistro, FILE *file){
    fread(ptregistro, sizeof(Inscripciones), 1, file);
    return;
}
void escribir(Inscripciones *ptregistro, FILE *file){
    fwrite(&ptregistro, sizeof(Inscripciones), 1, file);
    return;
}
int main(){
    FILE *archivoMaestroFinales = abrir("MAESTROFINALES.DAT", "rb");
    FILE *archivoDiaFinales = abrir("DIAFINALES.DAT", "rb");
    FILE *finalesActualizados = abrir("FINALESACT.DAT", "wb");

    Inscripciones registroMaestro;
    Inscripciones registroDia;


    leer(&registroMaestro, archivoMaestroFinales);
    leer(&registroDia, archivoDiaFinales);

    while (!feof(archivoMaestroFinales) && !feof(archivoDiaFinales)){
        if (registroMaestro.legajo < registroDia.legajo){
            escribir(&registroMaestro, finalesActualizados);
            leer(&registroMaestro, archivoMaestroFinales);
        }
        else{
            escribir(&registroDia, finalesActualizados);
            leer(&registroDia, archivoDiaFinales);
        }
    }
    while (!feof(archivoMaestroFinales)){
        escribir(&registroMaestro, finalesActualizados);
        leer(&registroMaestro, archivoMaestroFinales);
    }
    while (!feof(archivoDiaFinales)){
        escribir(&registroDia, finalesActualizados);
        leer(&registroDia, archivoDiaFinales);
    }
    fclose(archivoMaestroFinales);
    fclose(archivoDiaFinales);
    fclose(finalesActualizados);

    //Imprimir datos
    abrir("finalesActualizados", "rb");
    leer(&registroMaestro, finalesActualizados);
    while (!feof(finalesActualizados)){
        printf("Legajo: %d\t codigo materia: %d\t nombre: %s\t" 
        , registroMaestro.legajo, registroMaestro.codigoMateria, registroMaestro.apellidoNombre);
        leer(&registroMaestro, finalesActualizados);
    }
    fclose(finalesActualizados);

    return 0;
}
