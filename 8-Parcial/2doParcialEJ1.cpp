#include <iostream>
using namespace std;

typedef struct Notas{
    int legajo;
    char parcial;
    float nota;
};
typedef struct Asistencias{
    int legajo;
    int fecha;
    int presente;
};
typedef struct Aprobados{
    int legajo;
    int cantAsistencias;
}STR_APROBADOS;

typedef struct Nodo{
    STR_APROBADOS dato;
    STR_NODO *ste;
}STR_NODO;

int main(){
    
    Notas nota;
    STR_APROBADOS aprobado;
    STR_NODO *lista = NULL;

    FILE *archivoNotas = abrir("archivoNotas.dat", "rb");
    leer(&nota, archivoNotas);
    while (!feof(archivoNotas)){
        int keyLegajo = nota.legajo;

        int cantNotasAprobadas = 0;
        while (!feof(archivoNotas) && keyLegajo = nota.legajo){
            if (nota.nota >= 6){
                cantNotasAprobadas++;
            }
            leer(&nota, archivoNotas);
        }
        if (cantNotasAprobadas == 2){
            aprobado.legajo = keyLegajo;
            aprobado.cantAsistencias = 0;
            insertAtEnd(&lista, aprobado);
        }
    }
    fclose(archivoNotas);    

    Asistencias asistencia;
    FILE *archivoAsistencias = abrir("archivoAsistencias.dat", "rb");
    leer(&asistencia, archivoAsistencias);

    while (!feof(archivoAsistencias)){
        if (asistencia.presente == 1){
            STR_NODO *ptrAprob = search(lista, asistencia.legajo);
            if (ptrAprob != NULL){
                ptrAprob->dato.cantAsistencias++;
            }
            
        }
        leer(&asistencia, archivoAsistencias);
    }
    fclose(archivoAsistencias);

    FILE *archivoAprobados = abrir("archivoAprobados.dat", "wb");
    FILE *archivoFaltaron = abrir("archivoFaltaron.txt", "wt");

    escribirEncabezado(archivoFaltaron);

    while (!isEmpty(lista)){
        aprobado = deleteFirst(&lista);
        float presentismo = ((aprobado.cantAsistencias / 16) * 100);
        if (presentismo >= 75){
            escribirAprobado(aprobado, archivoAprobados);
        }
        else{
            escribirFaltaron(aprobado.legajo, presentismo, archivoFaltaron);
        }
    }
    fclose(archivoAprobados);
    fclose(archivoFaltaron);
    return 0;
}
