/*20. Dadas dos listas LISTA y LISTB (nodo = registro + puntero), 
desarrollar y codificar
un procedimiento que genere una única lista LISTC a partir de ellas. (Primero los
nodos de LISTA y luego los de LISTB).*/
#include <iostream>
#include "string.h"
using namespace std;

typedef struct Alumno{
    char apellidoNombre[36];
    int legajo;
    char division;
}STR_DATO, STR_ALUMNO;

typedef struct Nodo{
    STR_DATO dato;
    Nodo *siguiente;
}STR_NODO;

void leer(STR_ALUMNO *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(STR_ALUMNO), 1, file);
    return;
}
STR_NODO *insertOrdered(STR_DATO valor, STR_NODO **lista);
FILE *abrir(const char *fileName, const char *modo)
{
    FILE *file = fopen(fileName, modo);
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo: %s", fileName);
        exit(EXIT_FAILURE);
    }

    return file;
}

int main(){
    FILE *alumnostxt = abrir("Alumnostxt", "r");

    STR_NODO *listaA = NULL;
    STR_NODO *listaB = NULL;
    STR_NODO *listaC = NULL;

    STR_ALUMNO alumno;
    leer(&alumno, alumnostxt);
    while (!feof(alumnostxt)){
        insertOrdered(alumno, &listaA);
        leer(&alumno, alumnostxt);
    }
    


    return 0;
}


STR_NODO *insertOrdered(STR_DATO valor, STR_NODO **lista){
    STR_NODO *nodo = (STR_NODO *)malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->siguiente = NULL;

    STR_NODO *listaAux = *lista;
    STR_NODO *nodoAnt = NULL;
    while (listaAux != NULL && listaAux->dato.division < valor.division)
    {
        nodoAnt = listaAux;
        listaAux = listaAux->siguiente;
    }
}