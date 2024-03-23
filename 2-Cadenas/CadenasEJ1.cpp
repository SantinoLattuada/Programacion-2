/*1) Dado una cadena, cuya longitud máxima es de 80 caracteres, y utilizando sólo sintaxis de
punteros, determinar si la cadena es o no un palíndromo. Ejemplo:
NEUQUEN → verdadero
CHUBUT → falso*/

#include <iostream>
#include <ctype.h>
#include "stdio.h"
#include "string.h"
using namespace std;

bool esPalindromo(const char *palabra){
    int cantLetras = strlen(palabra);
    for (int i = 0; i < cantLetras / 2; i++){
        if (toupper(*(palabra + i)) != toupper(*(palabra + cantLetras - 1 - i))){
            return false;
        }
    }
    return true;
}

int main(){
    //Creo la cadena de 80 caracteres
    char palabra[81];

    //Pido una palabra
    printf("Ingrese una palabra para verificar si es palindromo o no");
    gets(palabra);

    //Creo un booleano y llamo una funcion para verificar si es palindromo o no
    bool palindromo = false;
    esPalindromo(palabra);

    return 0;
}
