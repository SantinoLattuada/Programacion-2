/*Ejercicio 1
Se dispone de los siguientes archivos
NotasAprobados.dat (sin orden): Archivo con las notas de los alumnos que aprobaron la
cursada. Hay un registro por cada parcial rendido por alumno.
Legajo Nota
Entero de 6 dígitos Entero de 4 a 10
Asistencias.dat (ordenado por legajo): Registro de las inasistencias de todos 
los alumnos que cursaron la materia, hay un registro por cada clase por cada 
alumno indicando si estuvo presente o no.
Legajo Fecha Presente
Entero de 6 dígitos Entero mmdd 1 sí vino / 0 sí faltó
a- Se solicita realizar el programa que permita generar un archivo Promocionan.dat con los
alumnos en condiciones de promocionar la materia.
Donde cada registro contenga el Legajo, promedio y cantidad de asistencias del alumno
que promociona la materia.
El criterio para promocionar la materia es poseer un promedio de notas mayor a 8 y una
asistencia del 80% a las clases (sabiendo que se dictaron 16 clases).
b- Indicar el porcentaje de promocionados sobre el total del curso (promocionados / total
alumnos)
c- Indicar los nombres de los alumnos que no promocionaron por no cumplir la condición del
80% de asistencia (a pesar que tenían más de 8)
d- Si no se conociera de antemano cuántas clases se dictaron. ¿De qué forma podría
obtenerla?*/

#include <iostream>
using namespace std;

typedef struct Notas{
    int legajo;
    int nota;
}STR_NOTA;

typedef struct Asistencias{
    int legajo;
    int fecha;
    int presente;
}STR_ASISTENCIA;

typedef struct Promocionan{
    int legajo;
    float promedio;
    int cantAsistencias;
}STR_PROMOCIONAN;

typedef struct Nodo{
    STR_NOTA dato;
    STR_NODO *ste;
}STR_NODO;

int main(){
   
    FILE *archivoNotas = abrir("NotasAprobados.dat", "rb");
    FILE *archivoAsistencias = abrir("Asistencias.dat", "rb");
    FILE *archivoPromocionados = abrir("Promocionan.dat", "wb");

    STR_NOTA nota;
    STR_ASISTENCIA asistencia;
    STR_PROMOCIONAN promocionados;

    STR_NODO *lista = NULL;
    leer(&nota, archivoNotas);

    while (!feof(archivoNotas)){
        insertOrdered(&lista, nota);
        leer(&nota, archivoNotas);
    }
    fclose(archivoNotas);

    
    int cantAlumnos = 0;
    int cantPromocionados = 0;

    leer(&asistencia, archivoAsistencias);
    while (!feof(archivoAsistencias)){
        int key = asistencia.legajo;
        int cantAsistencias = 0;

        cantAlumnos++;
        while (!feof(archivoAsistencias) && key == asistencia.legajo){
            cantAsistencias += asistencia.presente;
            leer(&asistencia, archivoAsistencias);
        }

        float sumaNotas = 0;
        int cantNotas = 0;
        while (!isEmpty(lista) && key == lista->dato.legajo){
            sumaNotas += lista->dato.nota;
            cantNotas++;
            lista = lista->ste;
        }
        float promedioNotas = sumaNotas / cantNotas;
        float promedioAsistencias = (cantAsistencias / 16) * 100;

        if (promedioNotas >= 8){
            if (promedioAsistencias >= 80){
                promocionados.legajo = key;
                promocionados.promedio = promedioNotas;
                promocionados.cantAsistencias = cantAsistencias;
                escribir(promocionados, archivoPromocionados);
                leer(&promocionados, archivoPromocionados);
                cantPromocionados++;
            }
            else{
                printf("No cumplen asistencias %s", lista->dato.legajo);
            }
        }
    }
    int totalPromocionados = ((cantPromocionados / cantAlumnos) * 100);   


    fclose(archivoAsistencias);
    fclose(archivoPromocionados);

}