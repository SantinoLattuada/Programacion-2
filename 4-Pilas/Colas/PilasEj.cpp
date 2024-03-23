#include <iostream>
using namespace std;

struct STR_NODO{
    int dato;
    STR_NODO *ste;
};
void create(STR_NODO **pila) {
    *pila = NULL;
}
void push(STR_NODO **pila, int valor) {
    //Creamos un nuevo nodo  asignamos memoria dinamicamente con la funcion malloc
    STR_NODO *nodo = (STR_NODO *) malloc(sizeof(STR_NODO));

    //Guardamos el valor en nodo->dato 
    nodo->dato = valor;
    //Asignamos a ste "NULL" para indicar que el nodo sera el ultimo en la pila.
    nodo->ste = NULL;

    //El nuevo nodo apunta al nodo que antes estaba encima de la pila
    nodo->ste = *pila;
    //Actualizamos el puntero de la pila ('pila')
    *pila = nodo;
    return; 
}
//Funcion para eliminar una pila y liberar la memoria asignada a los nodos de la misma
void clear(STR_NODO **pila) {
    while(!isEmpty(*pila)) {
        printf("%d->",pop(pila));
    }
    printf("NULL");
}
int main(){
    STR_NODO *pila = NULL;

    create(&pila);

    push(&pila, 1);
    push(&pila, 2);
    push(&pila, 3);
    push(&pila, 4);
    push(&pila, 5);
    push(&pila, 6);

    clear(&pila);

    system("pause");
    return 0;
}
