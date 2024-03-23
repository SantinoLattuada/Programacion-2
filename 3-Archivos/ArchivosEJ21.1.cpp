#include <iostream> 
using namespace std;

struct Comprador{
    
};

struct Vuelo{
    
};

struct VuelosAux{
    int codigo;
    int disponibles;
    int noVendidos;
};
void abrir(){

}
void ordenarPorCodigo(VuelosAux vuelo[], int num){

}

int main(){
    
    FILE *vuelosArch = abrir("Vuelo.dat", "rb");
    FILE *compradores = abrir("Compradores.dat", "rb");
    
    VuelosAux vuelos[500];
    Vuelo vuelo;

    leer(&vuelo, vuelosArch);

    int i = 0;
    while (!feof(vuelosArch)){
        strcpy(vuelos[i].codigo, vuelo.codigo);
        vuelos[i].disponibles = vuelo.disponibles;
        vuelos[i].noVendidos = 0;
        leer(&vuelo, vuelosArch);
    }
    fclose(vuelosArch);
    ordenarPorCodigo(vuelos, 500);
    Comprador comprador;
    leer(&comprador, compradores);
    imprimirEncabezado();
    while (!feof(compradores)){
        int posVuelo = buscar(vuelos, comprador.codigo, 500);
        if (vuelos[posVuelo].disponibles >= comprador.cantidad){
            imprimirCompraOk(comprador);
            vuelos[posVuelo].disponibles -= comprador.cantidad;
        }
        else{
            vuelos[posVuelo].noVendidos += comprador.cantidad;
        }
        leer(&comprador, compradores);
    }
    for (int i = 0; i < 500; i++){
        cout << vuelos[i].codigo << vuelos[i].disponibles << vuelos[i].noVendidos;
    }
    
    
    return 0;
}
