/*Ej. 16: Una aplicación para descargas de Series posee la información en un archivo binario,
Episodios.dat, con un registro por cada episodio, ordenado ascendente por Id_Serie y Número de
temporada, con el siguiente diseño:
1) Id_Serie ( 9 dígitos )
3) Número de temporada (1..12)
5) Cantidad de descargas (long)
2) Título del episodio (20 caracteres)
4) Número de episodio (unsigned char)
6) Fecha de última descarga (aaaammdd)
Se pide desarrollar la metodología necesaria para escribir un algoritmo emita el siguiente listado:*/


#include <iostream>
#include "string.h" 
using namespace std;

struct Episodio{
    int idSerie;
    char nroTemporada;
    long int descargas;
    char titulo[21];
    unsigned char numEpisodio;
    int fechaUltimaDescarga; 
};
FILE *abrir(const char *path, const char *mode){
    FILE *file = fopen(path, mode);

    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    return file;
};

int main(){
    
    FILE *archivoEpisodios = abrir("EPISODIOS.DAT", "rb");
    Episodio episodios;

    int cantEpisodiosTotal = 0;
    int cantDescargasTotal = 0;
    int keySerie;
    int keyTemporada;

    int cantEpisodiosXSerie;
    int cantDescargasXSerie;
    int cantEpisodiosXTemporada;
    int totalDescargasTemporada;
    while (!feof(archivoEpisodios)){
        
        keySerie = episodios.idSerie;
        printf("Serie: %d\t", keySerie);
        
        cantEpisodiosXSerie = 0;
        cantDescargasXSerie = 0;
        while (!feof(archivoEpisodios) && keySerie == episodios.idSerie){
            keyTemporada = episodios.nroTemporada;
            printf("Temporada: %d\t", keyTemporada);


            cantEpisodiosXSerie++;
            cantDescargasXSerie++;
            cantEpisodiosXTemporada = 0;
            totalDescargasTemporada = 0;

            printf("N. de Episodio \n Título del Episodio \n Cant. descargas \n Fecha de última descarga");
            while (!feof(archivoEpisodios) && keySerie == episodios.idSerie && keyTemporada == episodios.nroTemporada){
                printf("%s\n%s\n%d\n%d\n", episodios.numEpisodio, episodios.titulo, episodios.descargas, episodios.fechaUltimaDescarga);
                cantEpisodiosXTemporada++;
                totalDescargasTemporada++;
                // leer(&episodios, archivoEpisodios);
            }
            
        }
        
    }
    
    return 0;
}
