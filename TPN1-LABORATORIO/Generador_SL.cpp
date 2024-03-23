#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Archivo {
    string autor;
    string fecha;
    string nombre;
    int tamano;
    string contenido;
};

const int MAX_ARCHIVOS = 100; 

void leerArchivoCSV(const string& nombreArchivo, Archivo archivos[], int& cantidadArchivos) {
    ifstream archivo(nombreArchivo);
    string linea;

    cantidadArchivos = 0;
    while (getline(archivo, linea) && cantidadArchivos < MAX_ARCHIVOS) {
        istringstream ss(linea);
        getline(ss, archivos[cantidadArchivos].autor, ',');
        getline(ss, archivos[cantidadArchivos].fecha, ',');
        getline(ss, archivos[cantidadArchivos].nombre, ',');
        ss >> archivos[cantidadArchivos].tamano;
        getline(ss, archivos[cantidadArchivos].contenido);
        cantidadArchivos++;
    }

    archivo.close();
}

void escribirArchivoCSV(const string& nombreArchivo, Archivo archivos[], int cantidadArchivos) {
    ofstream archivo(nombreArchivo);
    for (int i = 0; i < cantidadArchivos; ++i) {
        archivo << archivos[i].autor << "," << archivos[i].fecha << "," << archivos[i].nombre << "," << archivos[i].tamano << "," << archivos[i].contenido << endl;
    }
    archivo.close();
}

void generarArchivosPrueba(Archivo archivos[], int cantidadArchivos, const string& nombreArchivo) {
    //Como no se generar archivos aleatorios, lo resuelvo así.
    archivos[cantidadArchivos].autor = "Usuario";
    archivos[cantidadArchivos].fecha = "2023-10-25";
    archivos[cantidadArchivos].nombre = nombreArchivo;
    archivos[cantidadArchivos].tamano = 1024;
    archivos[cantidadArchivos].contenido = "Contenido de ejemplo";
    cantidadArchivos++;
}

int main() {
    
    Archivo archivos[MAX_ARCHIVOS];
    int cantidadArchivos = 0;

    // Leer datos desde el archivo CSV
    leerArchivoCSV("input.csv", archivos, cantidadArchivos);

    // Generar archivos de prueba
    generarArchivosPrueba(archivos, cantidadArchivos, "nuevo_archivo.txt");

    // Escribir datos modificados de vuelta al archivo CSV
    escribirArchivoCSV("output.csv", archivos, cantidadArchivos);

    // Crear archivos .dat
    ofstream maestro("maestro.dat");
    ofstream novedades("novedades.dat");

    for (int i = 0; i < cantidadArchivos; ++i) {
        maestro << archivos[i].autor << "," << archivos[i].fecha << "," << archivos[i].nombre << "," << archivos[i].tamano << "," << archivos[i].contenido << endl;
        novedades << "add," << archivos[i].nombre << endl;
    }

    maestro.close();
    novedades.close();

    cout << "Archivos generados correctamente." << endl;

    return 0;
}

