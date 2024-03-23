#include <iostream> 
#include 
using namespace std;

struct Alumno{
    int legajo;
    char domicilio[21];
    char apellidoNombre[31];
    char telefono[11];
    int codigoPostal;
    int anioIngreso;
};
struct Novedad{
    Alumno alumno;
    char operacion;
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
void leer(Alumno *ptrRegistro, FILE *file){
    fread(ptrRegistro, sizeof(Alumno), 1, file);
    return;
}
void escribir(Alumno alumno, FILE *file){
    fwrite(&alumno, sizeof(Alumno), 1, file);
    return;
}
int main(int argc, char const *argv[]){
    FILE *alumnos = abrir("ALUMNOS.dat", "rb");
    FILE *novedades = abrir("NOVEDADES.dat", "rb");
    FILE *actualizados = abrir("ALUMACTU.dat", "wb");

    Alumno alumno;
    Novedad novedad;

    leer(&alumno, alumnos);
    leer(&novedad, novedades);

    while (!feof(alumnos) && !feof(novedades)){
        if (alumno.legajo < novedad.alumno.legajo){
            escribir(alumno, actualizados);
            leer(&alumno, alumnos);
        }
        else if (alumno.legajo > novedad.alumno.legajo || ){
            escribir(novedad.alumno, actualizados);
            leer(&novedad, novedades);
        }
        else if (novedad.operacion == 'M'){
            escribir(novedad.alumno, actualizados);
            leer(&novedad, novedades);
        }
        leer(&alumno, alumnos);
        leer(&novedad, novedades);
    }
    while (!feof(alumnos)){
        escribir(alumno, actualizados);
        leer(&alumno, alumnos);
    }
    while (!feof(novedades)){
        escribir(novedad.alumno, actualizados);
        leer(&novedad, novedades);
    }
    fclose(alumnos);
    fclose(novedades);
    fclose(actualizados);
    
    return 0;
}
