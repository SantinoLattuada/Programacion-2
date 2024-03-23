/*24. Dado un archivo de registros de alumnos ARCHA sin ningún orden donde cada
registro contiene: a) Apellido y Nombre del alumno (34 caracteres) b) Número de
legajo (6 dígitos) c) División asignada (3 dígitos) Se debe desarrollar el algoritmo y
codificación del programa que imprima el listado de alumnos por división ordenado
por división y número de legajo crecientes, a razón de 55 alumnos por hoja.*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct Alumnos{
    char apellidoNombre[35];
    int legajo;
    int division;
}STR_ALUMNO;
typedef struct Nodo{
    STR_ALUMNO dato;
    STR_NODO *ste;
}STR_NODO;

int main(int argc, char const *argv[]){
    FILE *archivoArcha = abrir("Archa.dat", "rb");

    STR_NODO *lista = NULL;
    Alumnos alumno;

    leer(&alumno, archivoArcha);
    while (!feof(archivoArcha)){
        insertOrdered(&lista, alumno);
        leer(&alumno, archivoArcha);
    }
    while (lista != NULL){
        int key = lista->dato.division;
        int i = 0;
        printf("DIVISION: %d\n", key);
        printf("Legajo\tNombre Apellido\t");
        while (!feof(archivoArcha) && key = lista->dato.division){
            alumno = deleteFirst(&lista);
            printf("%d\t%s\n", alumno.legajo, alumno.apellidoNombre);
            i++;
            if (i % 55 == 0){
                printf("\n----SALTO DE HOJA----\n");
            }
        }
        printf("Alumnos: %d, i");
        
    }
    fclose(archivoArcha);

    system("pause");
    return 0;
}
