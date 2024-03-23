/*Ej. 17: El dueño de un local de venta de juegos para distintas consolas necesita desarrollar un algoritmo
que grabe un archivo, JuegosPorConsola.dat, ordenado por consola, con un solo registro por consola
según el siguiente diseño:
a) Consola (10 caracteres) b) Cantidad de juegos ( 4 dígitos )
Para obtener la información solicitada se cuenta con el archivo Juegos.dat, ordenado por consola, con un
registro por cada juego que se encuentra en el local, con el siguiente diseño:
1) Código del juego ( 6 dígitos )
3) Stock en el local (char)
2) Titulo del Juego (30 caracteres)
4) Consola (10 caracteres)*/


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
};

struct JuegosXConsola{
    char consola[11];
    int cantJuegos;
};
struct Juego{
    int codigo;
    char stock;
    char titulo[31];
    char consola[11];
};
void leerJuego(Juego *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(Juego), 1, file);
    return;
}
void leerJuegoXConsola(JuegosXConsola *ptrRegistro, FILE * file) {
    fread(ptrRegistro, sizeof(JuegosXConsola), 1, file);
    return;
}
void escribirJuego(Juego *ptrRegistro, FILE *file) {
    fwrite(ptrRegistro, sizeof(Juego), 1, file);
    return;
}
void escribirJuegoXConsola(char consola[], int cantJuegos, FILE *file) {
    JuegosXConsola jxc;
    jxc.cantJuegos = cantJuegos;
    strcpy(jxc.consola, consola);
    fwrite(&jxc, sizeof(JuegosXConsola), 1, file);
    return;
}
int main(){
    
    JuegosXConsola juegosXConsola;
    Juego juego;

    FILE *archivoXConsola = abrir("JUEGOSPORCONSOLA.DAT", "wb");
    FILE *archivoXJuego = abrir("JUEGOS.DAT", "rb");

    char keyJuegos[11];
    int cantJuegos;
    while (!feof(archivoXJuego)){
        strcpy(keyJuegos, juego.consola);
        cantJuegos = 0;
        while (feof(archivoXJuego) && strcmp(keyJuegos, juego.consola) == 0){
            if (juego.stock > 0){
                cantJuegos++;
            }
            leerJuego(&juego, archivoXJuego);
        }
        escribirJuegoXConsola(keyJuegos, cantJuegos, archivoXConsola);
    }
    fclose(archivoXConsola);
    fclose(archivoXJuego);
    
    return 0;
}
