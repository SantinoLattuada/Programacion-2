/*Ejercicio 1
Una empresa desea realizar el resumen mensual de las horas trabajadas
y horas de ausencia de sus empleados. 
Para realizar el cálculo cuenta con un archivo binario “HORAS_DIARIAS.dat” donde cada
registro se compone de los siguientes datos:
● Legajo del empleado: 10 caracteres
● Día del mes: número de 1 a 31
● Horas: número entero de 1 a 24
● Ausencia: 1 o 0 (si es 1: las Horas son horas de ausencia, si es 0: 
las Horas son horas trabajadas)
El archivo se encuentra desordenado y por haber distintos turnos 
puede haber más de un registro por día de un mismo empleado. Se solicita:

a. Definir la estrategia y estructuras necesarias para la lectura del archivo y 
realización de los puntos b. y c.

b. Imprimir por pantalla el listado de las horas imputadas por cada empleado para el
mes, ordenado por legajo en forma creciente. imprimiendo:
Legajo || Hs. Trabajadas || Hs. Ausencia ||  % Ausentismo (HA / HT + HA)

c. Indicar el día del mes con mayor cantidad de Horas de Ausencia

d. Indicar el legajo con mayor Ausentismo*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct Empleados{
    int legajo;
    int dia;
    int horas;
    int ausencia; // 1 SI || O NO
}STR_EMPLEADO;

typedef struct Nodo{
    STR_EMPLEADO dato;
    STR_NODO *ste;
}STR_NODO;

int main(int argc, char const *argv[]){
    FILE *archivoHorasDiarias = abrir("HORAS_DIARIAS.DAT", "rb");

    STR_NODO *lista = NULL;
    int ausenciaXDia[31] = {0};
    Empleados empleado;

    int i = 0;
    leer(&empleado, archivoHorasDiarias);
    while(!feof(archivoHorasDiarias)){
        insertOrdered(&lista, empleado);
        leer(&empleado, archivoHorasDiarias);
    }
    int legajoMaxAus = 0;
    float maxAus = -1;
    while (lista != NULL){
        int keyLegajo = lista->dato.legajo;
        int trabajadas = 0;
        int ausencia = 0;
        while (lista != NULL && keyLegajo == lista->dato.legajo){
            empleado = deleteFirst(&lista);
            if (empleado.ausencia == 1){
                ausenciaXDia[empleado.dia - 1] += empleado.horas;
                ausencia += empleado.horas;
            }
            else{
                trabajadas += empleado.horas;
            }
        }
        float ausentismo = ausencia / (trabajadas + ausencia);
        printf("Legajo \t Trabajadas \t Ausencias \t Ausentismo");
        printf("%d\t%d\t%d%s", keyLegajo, trabajadas, ausencia, ausentismo);
        if (ausentismo > maxAus){
            maxAus = ausentismo;
            legajoMaxAus = keyLegajo;
        }
    }
    printf("LegajoMaxAus = %s", maxAus);
    return 0;
}
