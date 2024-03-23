#include <iostream>
#include "string.h"
using namespace std;

struct Alumno
{
    int legajo;
    int dni;
    char apellidoNombre[51];
};

struct Nodo
{
    Alumno dato;
    Nodo *ste;
};

Alumno crearAlumno(){

}
void create(Nodo **head)
{
    *head = NULL;
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
void push1erEjercicio(Nodo **pila, Alumno valor){
    pop(pila);
    pop(pila);
    push(pila, valor);
}

int main(){

    Nodo *head;
    create(&head);
    
    char nombre[] = "Leo";
    push(&head, crearAlumno(1111, 11, nombre));
    push(&head, crearAlumno(1111, 11, nombre));
    push(&head, crearAlumno(1111, 11, nombre));
    return 0;
}
