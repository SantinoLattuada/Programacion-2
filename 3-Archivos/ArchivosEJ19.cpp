#include <iostream> 
using namespace std;

struct Producto{
    /* data */
};

int main(int argc, char const *argv[]){
    FILE *productos = abrir("PRODUCTOS.dat", "rb");
    FILE *factXPrducto = abrir("FACTXPROUCTO.txt", "w");

    Producto producto;
    leer(&producto, productos);
    Producto prodAux[100];


    while (!feof(productos)){
        prodAux[producto.codigo - 1] = producto;
        leer(&producto, productos);

    }
    fclose(productos);
    int codigo, unidades;
    float facturacion[100] = {0};
    leer("Ingrese codigo de producto: ", &codigo);

    while (codigo != 0){
        leer("Ingrese la cantidad: ", &unidades);
        float precio = prodAux[codigo - 1].precio;
        float importe = precio * unidades;
        facturacion[codigo - 1] += importe;
        cout << codigo << unidades << precio << importe << endl;
        leer("Ingrese codigo de producto", &codigo);
    }
    for (int i = 0; i < 100; i++){
        if (facturacion[i] == 0){
            printf("Producto no vendido ", i + 1);
        }
        else{
            escribir(i + 1, facturacion[i]);
        }
    }
    fclose(factXPrducto);
    
    return 0;
}
