/*Ej. 15: El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el
depósito, para realizar las compras del mes.
Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el local, con el siguiente diseño:
a.1) Código de libro ( 4 dígitos )
a.3) Autor (20 caracteres)
a.6) Stock en el local (char)
a.2) Título del libro (30 caracteres)
a.4) Editorial (20 caracteres)
a.7) Genero ( 10 caracteres)
b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se
encuentra en el depósito, con el siguiente diseño:
b.1) Código de libro ( 4 dígitos ) b.2) Stock en depósito (unsigned char)
Se pide desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por
código de libro, con un renglón por cada libro que tenga faltante en stock sea en depósito, local o en
ambos lugares, con el siguiente formato:*/

#include <iostream>
#include "string.h" 
using namespace std;

struct StockLocal{
    int codigoLibro;
    char autor[21];
    char stockLocal;
    char tituloLibro[31];
    char editorial[21];
    char genero[11];
};
struct StockDeposito{
    int codigoLibro;
    unsigned char stockDeposito;
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
int leerLocal(FILE *file, StockLocal *registro)
{
    return fread(registro, sizeof(StockLocal), 1, file);
}

int leerDepo(FILE *file, StockDeposito *registro)
{
    return fread(registro, sizeof(StockLocal), 1, file);
}


int main(){

    FILE *archivoLocal = abrir("STOCKENLOCAL.DAT", "rb");
    FILE *archivoDeposito = abrir("STOCKENDEPOSITO.DAT", "rb");

    StockLocal local;
    StockDeposito deposito;
    leerLocal(archivoLocal, &local);
    leerDepo(archivoDeposito, &deposito);

    int faltantes = 0;
    printf("Libros Faltantes");
    printf("COD LIBRO \t OBSERVACION"); 
    while (!feof(archivoLocal) && feof(!archivoDeposito)){
        if (local.codigoLibro < deposito.stockDeposito){
            if (local.stockLocal == 0){
                printf("%d\t%s\n", local.codigoLibro, "FALTA EN LOCAL");
                faltantes++;
            }
            leerLocal(archivoLocal, &local);
        }
        else if (local.codigoLibro > deposito.codigoLibro){
            if (deposito.stockDeposito == 0){
                printf("%d\t%s\n", "FALTA EN DEPOSITO");
                faltantes++;
            }
            leerDepo(archivoDeposito, &deposito);
        }
        else{
            if (local.stockLocal == 0 && deposito.stockDeposito == 0){
                printf("%d\t%s\n", local.codigoLibro, "FALTA EN LOCAL Y DEPOSITO");
                faltantes++;
            }
            else if (local.stockLocal == 0){
                printf("%d\t%s\n", local.codigoLibro, "FALTA EN LOCAL");
                faltantes++;
            }
            else if(deposito.stockDeposito == 0){
                printf("%d\t%s\n", "FALTA EN DEPOSITO");
                faltantes++;
            }
            leerLocal(archivoLocal, &local);
            leerDepo(archivoDeposito, &deposito);
        }
    }
    while(!feof(archivoLocal)) {
        printf("%d\t%s\n",local.codigoLibro, "FALTA EN LOCAL");
        faltantes++;
        leerLocal(archivoLocal, &local);
    }

    while(!feof(archivoDeposito)) {
        printf("%d\t%s\n",local.codigoLibro, "FALTA EN DEPOSITO");
        faltantes++;
        leerLocal(archivoDeposito, &local);
    }

    printf("Total de faltantes: %d", faltantes);

    fclose(archivoLocal);
    fclose(archivoDeposito);

    return 0;
}
