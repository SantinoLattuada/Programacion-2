#include <iostream>
#include "string.h" 
using namespace std;

struct Inscripcion{
    char apellidoNombre[26];
    int legajo;
    int codMateria;
    int diaExam;
    int mesExam;
    int anioExam;
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

    FILE *archivo = abrir("DIAFINALES.DAT ", "wb"); 
    Inscripcion inscripciones;

    printf("Apellido  nombre");
    scanf("%s", inscripciones.apellidoNombre);

    while (strcmp(inscripciones.apellidoNombre, "Fin" != 0)){
        printf("Legajo");
        scanf("%d", inscripciones.legajo);
        printf("Codigo materia");
        printf("%d", inscripciones.codMateria);
        printf("dia examen");
        scanf("%d", inscripciones.diaExam);
        printf("mes examen");
        scanf("%d", inscripciones.mesExam);
        printf("anio examen");    
        scanf("%d", inscripciones.anioExam);

        fwrite(&inscripciones, sizeof(inscripciones), 1, archivo);
        
        printf("Apellido  nombre");
        scanf("%s", inscripciones.apellidoNombre);
    }
    fclose(archivo);
    archivo = abrir("DIAFINALES.DAT", "rb");
    FILE *archivoTxt = fopen("DIAFINALES.TXT", "wt");
    fread(&inscripciones, sizeof(inscripciones), 1, archivo);

    while (!feof(archivo)){
        fprintf(archivoTxt, "%s\n%d\n%d\n%d/%d/%d\n",inscripciones.apellidoNombre, inscripciones.codMateria, inscripciones.legajo, inscripciones.diaExam, inscripciones.mesExam, inscripciones.anioExam);
        fread(&inscripciones, sizeof(inscripciones), 1, archivo);
    }
    fclose(archivo);
    fclose(archivoTxt);
    system("pause");

    return 0;
}
