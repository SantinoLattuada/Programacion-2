/*2) Dadas dos colas COLA y COLB, desarrollar y codificar un procedimiento 
que genere una pila a partir de ellas. 
(Primero los nodos de COLA en orden inverso y luego los de COLB). 
COLA y COLB no son necesarias luego de la ejecución del procedimiento. 
Ejemplo: Si recibimos 
COLA = fte-> 1, 2, 3, 4 <- fin y COLB = fte-> 5, 6, 7, 8 <-fin => 
PILA =head-> 8, 7, 6, 5, 1, 2, 3, 4*/

#include <iostream>
using namespace std;

typedef struct Queue{
    STR_QUEUE *fte;
    STR_QUEUE *fin;
}STR_QUEUE;
typedef struct Nodo{
    STR_DATO dato;
    STR_NODO *ste;
}STR_NODO;


STR_QUEUE procedimiento(STR_QUEUE *colaA, STR_QUEUE *colaB, STR_NODO **pilaResultante){
    STR_NODO *pilaAux = NULL;
    
    while (!isEmpty(*colaA)){
        push(&pilaAux, remove(colaA))
    }
    while (!isEmpty(pilaAux)){
        push(pilaResultante, pop(&pilaAux))
    }
    while (!isEmpty(*colaB)){
        push(pilaResultante, remove(colaB))
    }

    return;
}
int main(){
    STR_QUEUE colaA; // 4 3 2 1
    create(&colaA);
    STR_QUEUE colaB; // 5 6 7 8
    create(&colaB);

    STR_NODO pilaResultante = NULL; // 5 6 7 8 1 2 3 4
    procedimiento(&colaA, &colaB, &pilaResultante);

    return 0;
}
