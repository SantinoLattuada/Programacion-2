/*22. Dadas dos listas LISTA y LISTB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere otra lista LISTC por apareo del campo LEGAJO del
registro (define orden creciente en ambas). Nota: LISTA y LISTB dejan de ser útiles
después del apareo).*/

#include <iostream>
#include <string.h>
using namespace std;

typedef struct Dato{
    int legajo;
}STR_DATO;

typedef struct Nodo{
    STR_DATO dato;
    Nodo *ste;
}STR_NODO;

void apareoListas(STR_NODO listaA, STR_NODO listaB){
    STR_NODO listaC = NULL;
    while (listaA != NULL && listaB != NULL){
        if ((*listaA)->dato.legajo < (*listaB)->dato.legajo){
            insertAtEnd(listaC, deleteFirst(listaA))
        }
        else{
            insertAtEnd(listaC, deleteFirst(listaB))
        }       
    }
    while (*listaA != NULL){
        insertAtEnd(listaC, deleteFirst(listaA))
    }
    while (*listaC != NULL){
        insertAtEnd(listaC, deleteFirst(listaB))
    }
    
}
int main(){
    STR_NODO listaA = NULL;
    STR_NODO listaB = NULL;

    //se llenan

    STR_NODO listaC = apareoListas(listaA, listaB);
    return 0;
}
