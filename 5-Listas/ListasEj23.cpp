/*23. Dado un archivo de registros de alumnos ARCHA sin ningún orden, donde cada
registro contiene: a) Apellido y Nombre del alumno (34 caracteres) b) Número de
legajo (6 dígitos) c) División asignada (1 a 100) Se debe desarrollar el algoritmo y
codificación del programa que genere un archivo ARCHL igual al anterior pero
ordenado por número de legajo. Nota: Memoria estática 64 Kb; dinámica suficiente si
ningún nodo ocupa más de 12 bytes.*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct Alumnos{
    char apellidoNombre[35];
    int legajo;
    int division;
}STR_ALUMNO;
typedef struct Dato{
    int legajo;
    int posicion;
}STR_DATO;
typedef struct Nodo{
    int dato;
    STR_NODO *ste;
}STR_NODO;
void leer(){

}
void abrir(){

}
void escribir(){

}
void insertOrdered(){

}
void deleteFirst(){
    
}
int main(){
    FILE *archivoArcha = abrir("Archa.dat", "rb");
    FILE *archivoARCHL = abrir("archl.dat", "wb");

    STR_NODO *lista = NULL;
    Alumnos alumno;
    leer(&alumno, archivoArcha);
    STR_DATO indice;
    int i = 0;

    while (!feof(archivoArcha)){
        indice.legajo = alumno.legajo;
        indice.posicion = i;
        insertOrdered(&lista, indice);
        i++;
        leer(&alumno, archivoArcha);
    }
    while (lista != NULL){
        indice = deleteFirst(&lista);
        leer(&alumno, archivoArcha, indice.posicion);
        escribir(alumno, archivoARCHL);
    }
    fclose(archivoArcha);
    fclose(archivoARCHL);


    return 0;
}
