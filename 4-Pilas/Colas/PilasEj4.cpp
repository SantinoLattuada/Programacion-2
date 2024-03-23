/*6. Dada una pila y dos valores X e Y, desarrollar un procedimiento que reemplace cada
valor igual a X que se encuentre en la pila por el valor Y retornando la pila
modificada. En caso de no haber ningún valor igual a X retornar la pila sin cambio.
(Definir parámetros y codificar).*/

#include <iostream>
#include "string.h"
using namespace std;

typedef struct Nodo{
    int dato;
    STR_NODO *ste;
}STR_NODO;

void push(STR_NODO **pila, int valor) {
    STR_NODO *nodo = (STR_NODO *) malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    nodo->ste = *pila;
    *pila = nodo;
    return; 
}

int main(){
    STR_NODO *pila = NULL;

    push(&pila, 1);
    push(&pila, 2);
    push(&pila, 3);
    push(&pila, 4);
    push(&pila, 5);
    push(&pila, 6);

    int x = 1;
    int y = 2;
    return 0;
}
