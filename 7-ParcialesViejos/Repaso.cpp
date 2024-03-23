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
    char palabra[20];
}STR_DATO;

int main(){
    
    //Crear y abrir archivo
    FILE *archivoPrueba = abrir("archivoPrueba.dat", "wb");
    //Recorrer archivo
    while (!feof(archivoPrueba)){}
    
    //Crear Pila
    STR_NODO *pila = NULL;
    //Agregar valores a la pila
    int dato = 5;
    //Invocar funcion push 
    push(&pila, dato);
    //Funcion Push desarrollada
    void push(STR_NODO **head, int dato){
        //Creacion de nodo
        STR_NODO *nodo = (STR_NODO*)(malloc(sizeof(STR_NODO)));
        nodo->dato = dato;
        nodo->ste = NULL;

        //Insertamos el nuevo nodo en la pila
        nodo->ste = *head;
        *head = nodo;
        return;
    }
    //Eliminar valores de la pila
    pop(&pila);
    //Funcion pop desarrollada
    int pop(STR_NODO **head){
        int valor = *head->dato;
        STR_NODO *aux = *head;
        *head = (*head)->ste;
        free(aux);
        return valor;
    }
    //Iterar sobre Pila mientras no sea nula
    while (!isEmpty(pila)){}
    

    //Crear Cola
    STR_QUEUE *cola;
    create(&cola);
    //Agregar valores a la cola
    int dato2 = 5;
    add(&cola, dato2);
    //funcion add desarrollada
    void add(STR_QUEUE *queue. int dato){
        //crear nodo
        STR_NODO *nodo = (STR_NODO*)(malloc(sizeof(STR_NODO)));
        nodo->dato = dato;
        nodo->ste = NULL;

        //insertamos el nuevo nodo en la cola
        if (queue->fte == NULL){
            queue->fte = nodo;
        }
        else{
            queue->fin->ste = nodo;
        }

        queue->fin = nodo;
    }
    //Eliminar valores de la cola
    remove(&cola);
    //Funcion remove desarrollada
    int remove(STR_QUEUE *queue){
        STR_NODO *aux = queue->fte;
        int valor = aux->dato;
        queue->fte = aux->ste;

        if (queue->fte == NULL){
            queue->fin = NULL;
        }
        free(aux);
        return valor;
    }
    //Iterar sobre Cola mientras no sea nula
    while (!isEmpty(&cola)){}

    //Crear Lista
    STR_NODO *lista = NULL;
    //Insertar Nodos en la lista
    int dato3 = 5;
    insertInFront(&lista, dato3);
    insertAtEnd(&lista, dato3);
    insertOrdered(&lista, dato3);
    //Eliminar valores de la lista
    deleteFirst(&lista);
    //DeleteFirst Desarrollada
    int deleteFirst(STR_NODO **list){
        STR_NODO *nodoAux = *list;
        *list = (*list)->ste;
        int dato = nodoAux->dato;
        free(nodoaux);
        return dato;
    }
    //Buscar valores en la lista
    search(&lista, dato);
    //funcion search desarrollada
    STR_NODO * search(STR_NODO * list, int dato){
        STR_NODO *listAux = list;
        while (listAux && listAux->dato != dato){
            listAux = listAux->ste;
        }
        return listAux;
    }
    //Iterar sobre Lista mientras no sea nula
    while (!isEmpty(lista)){}

    return 0;
}
