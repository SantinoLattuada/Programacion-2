#include <iostream>
using namespace std;

typedef struct Productos{
    int codigo;
    char descripcion[51];
    float precio;
    int stock;
}STR_PRODUCTOS;
struct Pedidos{
    int fecha;
    int codigo;
    int cantidad;
};
struct Perdidas{
    int codigoProducto;
    float totalFactPerdida;
    int cantPedidosPerdida;
};
typedef struct Nodo{
    STR_PRODUCTOS dato;
    STR_NODO *ste;
}STR_NODO;

typedef struct Dato{
    STR_PRODUCTOS Dato;
}STR_DATO;

int main(){
    
    FILE *archivoProductos = abrir("Productos.dat", "rb");
    Productos producto;
    STR_NODO *lista = NULL;

    leer(&producto, archivoProductos);
    while (!feof(archivoProductos)){    
        insertAtEnd(&lista, producto);
        leer(&producto, archivoProductos);
    }
    fclose(archivoProductos);

    FILE *archivoPedidos = abrir("Pedidos.txt", "rt");
    FILE *archivoPerdidas = abrir("Perdidas.txt", "wt");

    Pedidos pedido;
    Perdidas perdida;

    float maxFactPerdidaDia = -1;
    int diaMesMaxFactPerdida = 0;

    // escribirEncabezado(archivoPerdidas);
    leer(&pedido, archivoPedidos);
    while(!feof(archivoPedidos)){
        int key = pedido.fecha;

        float facturacionPerdidaDia = 0;
        while(!feof(archivoPedidos) && key == pedido.fecha){

            STR_NODO *codigoProducto = search(lista, pedido.codigo);
            if (codigoProducto != NULL){
                if (lista->dato.stock >= pedido.cantidad){
                    codigoProducto->dato.stock -= pedido.cantidad;
                }
                else{ //Si entro aca se considera perdida
                    perdida.codigoProducto = codigoProducto->dato.codigo;
                    perdida.totalFactPerdida = (codigoProducto->dato.precio * pedido.cantidad);
                    perdida.cantPedidosPerdida = pedido.cantidad;
                    escribirPerdida(perdida, archivoPerdidas);

                    facturacionPerdidaDia += (codigoProducto->dato.precio * pedido.cantidad);
                }       
            }
            leer(&pedido, archivoPedidos);
        }
        if (maxFactPerdidaDia < facturacionPerdidaDia){
            diaMesMaxFactPerdida == calcularDia(key);
        }
        
    }
    fclose(archivoPedidos);
    //Imprimir como quedó el stock
    while (lista != NULL){
        
    }
    //Imprimir dia mes mas fact perdida acumuló

    return 0;
}
