/*3) Declarar un puntero miPuntero de char[10], asignar dinámicamente espacio en memoria, asignarle
el valor “hola” y luego ...
a) Imprimir por pantalla el puntero con el formateador %s.
b) Imprimir la dirección de memoria del puntero. (donde esta apuntado el puntero)
c) Imprimir el valor del puntero.
d) Imprimir la dirección de memoria miPuntero[0] y relaciónelo con el punto anterior.
e) Imprimir el valor miPuntero[0], luego ejecute miPuntero++ y vuelva a imprimir miPuntero[0].
Analice el resultado y concluya.*/

#include <iostream>
using namespace std;

int main(){
    char *miPuntero;
    miPuntero = (char *)malloc(sizeof(char) * 10);
    
    *miPuntero = 'H';
    *(miPuntero + 1) = 'O';
    *(miPuntero + 2) = 'L';    
    *(miPuntero + 3) = 'A';    
    *(miPuntero + 4) = '\0';

    //A) 
    printf("%s\n", miPuntero);

    //B) Imprimo la direccion de memoria de 'H'. miPuntero --> 'H'
    printf("%p\n", miPuntero);

    //B"1) Imprimo la direccion de memoria de miPuntero
    printf("%p\n", &miPuntero);

    //C)
    printf("%c\n", miPuntero[0]);
    printf("%c\n", miPuntero[1]);
    printf("%c\n", miPuntero[2]);
    printf("%c\n", miPuntero[3]);

    //D)Imprimo la direccion de memoria de 'H' y en el punto anterior la letra 'H' 
    printf("Direccion memoria: %p\n", &miPuntero[0]);

    /*E)En el primer Printf imprimo el primer valor de miPuntero y luego
    al aumentar el valor de mi puntero imprimo la segunda*/
    printf("%c\n", miPuntero[0]);
    miPuntero++;
    printf("%c\n", miPuntero[0]);

    return 0;
}
