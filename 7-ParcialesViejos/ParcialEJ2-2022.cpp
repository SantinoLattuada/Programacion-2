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

void create(STR_QUEUE *queue);

bool tieneVocal(const char *palabra){
    int i = 0;
    while (*(palabra + i) != '\0'){
        if (*(palabra + i) == 'a' || *(palabra + i) == 'e' || *(palabra + i) == 'i' 
        || *(palabra + i) == 'o' || *(palabra + i) == 'u'){
            return true;
        }
        i++;
    }
    return false;
}

void encolarPalabras(STR_QUEUE *queue, STR_NODO **lista){
    while (!isEmpty(*queue)){
        STR_DATO dato = remove(queue);
        if (tieneVocal(dato.palabra)){
            insertAtEnd(&lista, dato)
        }
        
    }
    return;
}
int main(){
    STR_NODO *listaResultante = NULL;
    STR_QUEUE queue;
    create(&queue);

    encolarPalabras(&queue, &listaResultante);

    return 0;
}
