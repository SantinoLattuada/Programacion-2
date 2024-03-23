/*2) Realizar un programa que, dadas dos pilas ya cargadas con números enteros, calcular e 
informar cuál de las dos pilas tiene el número más alto, y mostrar el número más alto de cada 
pila.
Emitir un mensaje que diga (“pila 1 tiene el número más alto, o pila 2 tiene el número más 
alto, o el número más alto es igual en ambas pilas”)*/

#include <iostream>

typedef struct Nodo {
    int dato;
    Nodo* ste;
}STR_NODO;

void create(STR_NODO **pila) {
    *pila = NULL;
}

bool isEmpty(STR_NODO *pila) {
    return pila == NULL;
}

void push(STR_NODO **pila, int valor) {
    STR_NODO *nodo = (STR_NODO *) malloc(sizeof(STR_NODO));
    nodo->dato = valor;
    nodo->ste = NULL;

    nodo->ste = *pila;
    *pila = nodo;
    return; 
}

int pop(STR_NODO **pila) {
    int dato = (*pila)->dato;
    STR_NODO *aux = *pila;
    *pila = (*pila)->ste;

    free(aux);
    return dato;
}


int main () {
    // ya cargadas
    STR_NODO* pila1=NULL;
    STR_NODO* pila2=NULL;

    int maxPila1=0;
    int maxPila2=0;
    while (!isEmpty(pila1)) {
        int valor=pop(&pila1);
        if (valor>maxPila1) {
            maxPila1=valor;
        }
    }

    while (!isEmpty(pila2)) {
        int valor=pop(&pila2);
        if (valor>maxPila2) {
            maxPila1=valor;
        }
    }

    maxPila1 > maxPila2 ? printf("Pila1 tiene el numero mas alto \n") : maxPila2 > maxPila1 ? printf("Pila2 tiene el numero mas alto \n") : printf("El numero mas alto es igual en ambas pilas \n");
    printf("MAYOR PILA 1: %d, MAYOR PILA 2: %d \n", maxPila1, maxPila2);

    return 0;
}