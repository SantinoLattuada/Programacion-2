/**
 * Dado el archivo binario generado en el ejercicio 7, desarrolle un programa que solicitando por
 * teclado un código de materia permita seleccionar todos los registros que se anotaron para rendirla y los
 * grabe en otro archivo (MATFINALES.DAT), con el mismo diseño.
 * 
 * Abrimos el archivo DIAFINALES.DAT en modo lectura
 * Abtimos el archivo MATFINALES.DAT en modo escritura
 * Solicitamos al usuario el codigo de materia 
 * Recorremos secuencialmente el archivo DIAFINALES.DAT
 *   - Por cada registro preguntamos si el codigo de materia es igual al ingresado
 *      Si coincide escribimos en el archivo MATFINALES.DAT
 * Cerramos los archivos
 * 
*/
#include <iostream>
#include "string.h" 
using namespace std;

struct Inscripcion {
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
int main(){
    
    FILE *diaFinales = abrir("DIAFINALES.DAT ", "rb"); 
    FILE *matFinales = abrir("MATFINALES.DAT", "wb");


    int codigoMateria;
    printf("Indique codigo de materia a buscar: ");
    scanf("%d", &codigoMateria);

    Inscripcion registro;
    fread(&registro, sizeof(registro), 1, diaFinales);

    while (!feof(diaFinales)){
        //Proceso el registro
        if (codigoMateria == registro.codMateria){
            fwrite(&registro, sizeof(registro), 1, matFinales);
        }
        fread(&registro, sizeof(registro), 1, diaFinales);
    }

    
    fclose(diaFinales);
    fclose(matFinales);
    system("pause");
    return 0;
}
