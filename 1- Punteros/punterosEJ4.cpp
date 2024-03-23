/*4) Declarar un struct que defina una variable del tipo vector de caracteres, llamada nombre, y otra
que sea del tipo entero, llamada edad y ...
a) En la función main, asigne el valor “Kokumo” y “30” para nombre y edad respectivamente.
b) Luego, invoque una función que reciba el struct por parámetro y que imprima el valor de
ambas variables del struct.
c) Dentro de esa misma función, cambie los valores de las variables en cuestión y muestre
nuevamente sendos valores.
d) De regreso en el main, e inmediatamente después de la llamada a la función, imprima los
valores del struct; analice qué valores se imprimieron en pantalla.

#include <iostream>
using namespace std;

struct Alumno{
    char nombre[100];
    int edad;
};


int main(){
    
    //A)
    Alumno nombre[100] = 'Kokumo';
    Alumno edad = 30;



    return 0;
}
*/