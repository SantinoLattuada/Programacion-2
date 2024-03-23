/*Desarrolle la función myStrCmp que permita comparar 2 cadenas. Esta función deberá devolver un
entero con los siguientes valores:

● 0: en caso de que las cadenas sean iguales
● 1: si la segunda cadena es mayor que la primera
● -1: si la segunda cadena es menor que la primera.
a. Escriba una invocación que demuestre el uso de la función.

Consideraciones y restricciones:
1. La función desconoce la longitud de las cadenas.
2. En la función debe manejar ambas cadenas utilizando sintaxis de punteros.*/

#include <iostream>
#include <string.h>
using namespace std;

int myStrCmp(const char *palabra1, const char *palabra2){
    int i = 0;

    while (*(palabra1 + i) != '\0'|| *(palabra2 + i) != '\0'){
        if (*(palabra1 + i) == *(palabra2 + i)){
            return 0;
        }
        if (*(palabra1 + i) < *(palabra2 + i)){
            return 1;
        }
        else{
            return -1;
        }
        i++;
    }
    return 1;
}

int main(int argc, char const *argv[]){
    
    const char *palabra1 = "abcdef\0";
    const char *palabra2 = "abcdefg\0";

    int resultado = myStrCmp(palabra1, palabra2);
    
    return 0;
}
