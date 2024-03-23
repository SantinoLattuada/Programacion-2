/*2) Declarar una variable que sea puntero a un número entero y luego ...
a) Imprimir por pantalla la dirección de memoria.
b) Imprimir su valor.
c) Asignar dinámicamente espacio en memoria.
d) Imprimir nuevamente su valor.
e) Imprimir el valor que se encuentra en el espacio asignado dinámicamente.*/

#include <iostream>
using namespace std;

/*Breve recordatorio
El operador & se utiliza para obtener la direccion de memoria de una variable

El operador * se utiliza para acceder al valor almacenado en la direccion de memoria apuntada por el ptro
*/
int *crearEntero(int valor){
    //Ptro a nro entero
    int *ptrNro = NULL;

    //A) imprimo por pantalla la direccion &ptrNro  
    //B) Imprimo su valor actual ptrNro
    printf("%p %p\n", &ptrNro, ptrNro);

    //C asigno dinamicamente espacio en memoria, ptrNro apunta a la direccion de memoria recien asignada
    ptrNro = new(int);

    //D Con &ptrNro imprimo la direccion de memoria del propio ptrNro
    //  Con ptrNro imprimo la direccion de memoria a la que está apuntando el ptrNro
    //E Con *ptro imprimo el valor que se encuentra en la posicion de memoria 
    printf("%p %p %d\n", &ptrNro, ptrNro, *ptrNro);

    return ptrNro;
}

int main(){
    
    int *ptrNumero = crearEntero(100);


    return 0;
}
