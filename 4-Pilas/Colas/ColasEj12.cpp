/*12. Dadas dos colas COLA y COLB (nodo = registro + puntero), desarrollar y codificar
un procedimiento que genere una única cola COLAB a partir de ellas. (Primero los
nodos de COLA y luego los de COLB).*/

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
typedef struct Dato{
    int num;
}STR_DATO;
int main(int argc, char const *argv[]){
    
    STR_QUEUE *colaA;
    create(&colaA);
    STR_QUEUE *colaB;
    create(&colaB);

    STR_NODO *pilaAux = NULL;
    while (!isEmpty(&colaB)){
        int dato = remove(&colaB);
        push(&pilaAux, dato);
    }
    while (!isEmpty(&colaA)){
        int dato2 = remove(&colaA);
        add(&colaB, dato2);
    }
    while (!isEmpty(&pilaAux)){
        int dato3 = pop(&pilaAux);
        add(&colaB, dato3);
    }
    
    return 0;
}
