#include <iostream>
#include "string.h" 
using namespace std;
 
FILE *abrir(const char *path, const char *mode){
    FILE *file = fopen(path, mode);

    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    return file;
}

int main(){
    
    int legajo;
    int nota1;
    int nota2;

    FILE *archivo = abrir("Alumnos.txt", "r");
    
    printf("Legajo: ");
    scanf("%d", &legajo);
    while (legajo >= 0){
        printf("Nota 1: ");
        scanf("%d", &nota1);
        printf("Nota 2: ");
        scanf("%d", &nota2);

        fprintf(archivo, "%d %.2f\n", legajo, (nota1 + nota2) / 2.0 );
        printf("Legajo: ");
        scanf("%d", &legajo);
    }   
    
    fclose(archivo);

    return 0;
}
