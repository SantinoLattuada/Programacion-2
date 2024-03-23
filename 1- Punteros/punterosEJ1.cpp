/*1) Declarar una variable entera, un vector de caracteres de diez posiciones y una variable con
soporte de decimales y ...
a) Asignarle valores.
b) Imprimir el valor de cada una.
c) Imprimir la dirección de memoria de cada una.*/

#include <iostream>
using namespace std;

int main(){
    
    int numero = 50;
    char vector[11] = "Hola Mundo";
    float decimal = 10.2;

    printf("Valor de la variable entera: %d\n", numero);    
    printf("Valor de la variable caracter: %s\n", vector);
    printf("Valor de la variable decimal: %f\n", decimal);

    int *ptrNumero = &numero;

    printf("Direccion de memoria de la variable entera %p\n", &numero);
    printf("Direccion de memoria de la variable caracter %p\n", &vector);
    printf("Direccion de memoria de la variable decimal %p\n"), &decimal;


    system("pause");
    return 0;
}

