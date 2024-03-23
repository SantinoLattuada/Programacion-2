#include <iostream> 
using namespace std;

struct Juego{
    int consola;
};
struct juegoXConsola{
    
};

int main(){

    FILE *juegos = abrir("JUEGOS.dat", "rb");
    FILE *juegosXConsola = abrir("JUEGOSPORCONSOLA.dat", "wb");
    char key[11];
    int cantJuegos = 0;
    Juego juego;

    leer(&juego, juegos);
    while (!feof(juegos)){
        
        strcpy(key, juego.consola);
        cantJuegos = 0;
        while (feof(juegos) && strcmp(key, juego.consola) == 0){
            cantJuegos++;
            leer(&juego, juegos);

        }
        juegoXConsola jxc;
        strcpy(jxc, consola, key);
        jxc.cantidad = cantJuegos;
        escribir(jxc, juegosXConsola); 
    }
    fclose(juegos);
    fclose(juegosXConsola);
    return 0;
}
