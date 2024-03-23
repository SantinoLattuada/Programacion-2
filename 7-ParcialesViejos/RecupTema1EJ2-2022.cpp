/*Realizar un procedimiento que reciba una pila de enteros de 5 dígitos 
y llene una lista de los números que no sean capicúas.*/

#include <iostream>
using namespace std;

/*typedef struct Queue{
    STR_QUEUE *fte;
    STR_QUEUE *fin;
}STR_QUEUE;*/

typedef struct Nodo{
    STR_DATO dato;
    STR_NODO *ste;
}STR_NODO;

typedef struct Dato{
    int numero;
}STR_DATO;
void isEmpty(STR_NODO *pila);

bool esCapicua(int numero){

    
    
    
}
void procedimiento(STR_NODO *pila, STR_NODO **lista){
    while (!isEmpty(&pila)){
        int dato =  pop(&pila);

        if(esCapicua(dato) == false){
            insertAtEnd(&lista, dato);
        }
    }
    
}
int main(){
    
    STR_NODO *pila = NULL;
    STR_NODO *lista = NULL;

    push(&pila, 12345);
    push(&pila, 12121);
    push(&pila, 98789);
    push(&pila, 55555);
    push(&pila, 12321);

    procedimiento(&pila, &lista);

    return 0;
}
