#include <iostream>
using namespace std;

int main()
{
    int numero = 50;
    printf("%p\n", &numero);
    char palabra[11] = "Hola mundo";
    float real = 10.34;

    int *ptrNumero = &numero;

    printf("%d\n", *ptrNumero); 


    char *ptroPalabra = &palabra[0];
    printf("%p\t %c\t", ptroPalabra, *(ptroPalabra + 10));


    printf("numero: %d\tpos:%p\n", numero, &numero);
    printf("contenido del ptro: %d\tpos apuntada:%p\tpos de memoria del ptro:%p\n", *ptrNumero, ptrNumero, &ptrNumero);
    printf("palabra:%s\tpos:%p\n", palabra, &palabra);
    printf("float:%.2f\tpos:%p\n", real, &real);

    system("pause");
    return 0;
}