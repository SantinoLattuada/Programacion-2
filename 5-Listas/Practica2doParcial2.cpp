#include <iostream>
using namespace std;

typedef struct Dato {
    char palabra[20];
} STR_DATO;
/* STR_DATO define una estructura llamada Dato que contiene
un campo palabra que es un arreglo de caracteres.*/

typedef struct Nodo {
    STR_DATO dato;
    STR_NODO *ste;
} STR_NODO;
/*STR_NODO define una estructura llamada Nodo que contiene 
un campo dato de tipo STR_DATO y un puntero ste que apunta al siguiente nodo.*/

typedef struct Queue {
    STR_NODO *fte;
    STR_NODO *fin;
} STR_QUEUE;
/*STR_QUEUE define una estructura llamada Queue que contiene 
punteros fte y fin que representan el frente y el final de una cola.*/

STR_DATO remove(STR_QUEUE *queue) {
    STR_NODO *aux = queue->fte;
    STR_DATO dato = aux->dato;
    queue->fte = aux->ste;

    if(queue->fte == NULL) {
        queue->fin = NULL;
    }

    free(aux);
    return dato;
}
bool tieneVocal(const char *palabra) {
    int i = 0;
    while(*(palabra + i) != '\0') {
        if(*(palabra + i) == 'a' || *(palabra + i) == 'e' || *(palabra + i) == 'i' ||
        *(palabra + i) == 'o' || *(palabra + i) == 'u') {
            return true;
        }
        i++;
    }
    return false;
}
void encolarPalabras(STR_QUEUE *queue, STR_NODO **lista) {
    while(!isEmpty(queue)) {
        STR_DATO dato = remove(queue); 
        if(tieneVocal(dato.palabra)) {
            insertAtFront(*lista, dato);
        }
    }
    return;
}

int main(){
    STR_NODO *listaResultado = NULL;
    STR_QUEUE queue;
    create(queue);

    encolarPalabras(&queue, &listaResultado);
    return 0;
}
