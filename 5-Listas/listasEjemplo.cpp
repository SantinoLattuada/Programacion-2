#include <iostream>
using namespace std;

struct Alumno{
    int legajo;
    int dni;
    char apellidoNombre[51];
};
struct Nodo{
    Alumno dato;
    Nodo *ste;
};
Nodo* insertInFront(Nodo **lista, Alumno valor){

}
Nodo* insertAtEnd(Nodo **lista, Alumno valor){

}
Nodo* insertOrdered(Nodo **lista, Alumno valor){
    Nodo* nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo ->dato = valor;
    nodo->ste = NULL;

    Nodo *listaAux = *lista;
    Nodo *nodoAnt = NULL;

    while (listaAux != NULL && listaAux->dato.legajo < valor.legajo){
        nodoAnt = listaAux;
        listaAux = listaAux->ste;
    }
    

    
}

void clearList(Nodo **lista){
    Nodo *aux = NULL;
    while (*lista != NULL){
        aux = *lista;
    }
    
}
Nodo *search(Nodo *lista, Alumno valor){
    Nodo *listaAux = lista;
    while (listaAux) {
        /* code */
    }
    
}
int main(){

    //Creamos lista
    Nodo *lista = NULL;

    Alumno alumno = {11, 11111111, "Leonardo"};
    insertInFront(&lista, alumno);

    Alumno alumno2 = {22, 22222222, "Leonardo"};
    insertAtEnd(&lista, alumno2);

    Alumno alumno3 = {221, 22111, "Leonardo"};
    insertOrdered(&lista, alumno3);

    Nodo *buscado = search(lista, alumno2);
    if (buscado != NULL){
        printf("El alumno se encuentra en la lista %d - %d - %s\n", buscado->dato.legajo, buscado->dato.dni, buscado->dato.apellidoNombre);
    }
    

    clearList(&lista);
    
    system("pause");
    return 0;
}
