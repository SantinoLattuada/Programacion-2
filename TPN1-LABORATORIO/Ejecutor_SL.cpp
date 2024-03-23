#include <iostream>
#include <sstream> //Realizar operaciones E/S
#include <string> //Operaciones con cadenas
#include <ctime> //Funciones y structs para trabajar con tiempos y horas
#include <fstream> 

using namespace std;
// Funciones simuladas para los comandos SVN
void addArchivo(const string& archivo) {
    //Crear archivo y agregar al repositorio
    ofstream nuevoArchivo("nuevoArchivo.txt");
    cout << "Se agregó el archivo '" << archivo << "' al repositorio." << endl;
    nuevoArchivo.close();
}

void deleteArchivo(const string& archivo) {
    //Eliminar archivo del repositorio
    remove("archivo");
    cout << "Se eliminó el archivo '" << archivo << "' del repositorio." << endl;
}

void modifyArchivo(const string& archivo) {
    //Modificar archivo del repositorio
    rename("archivo", "nuevoNombre");
    cout << "Se modificó el archivo '" << archivo << "' en el repositorio." << endl;
}

FILE *abrir(const char *path, const char *mode){
    FILE *file = fopen(path, mode);

    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }
    return file;
};

// Función para generar informes con la fecha actual
    string obtenerFechaActual() {
    time_t ahora = time(0);
    char fecha[50];
    strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M:%S", localtime(&ahora));
    return string(fecha);
}

// Función para generar informes
void generarInforme(const string& comando, const string& archivo) {
    string fecha = obtenerFechaActual();
    //Crear archivo e informar por ese medio
    ofstream nuevoInforme("nuevoInforme.txt");
    cout << "Informe: Se ejecutó '" << comando << "' en el archivo '" << archivo << "' a las " << fecha << "." << endl;
}

// Función para registrar novedades en un archivo de log
void registrarNovedad(const string& comando, const string& archivo) {
    string fecha = obtenerFechaActual();
    ofstream logFile("novedades.log", ios::app);
    logFile << "[" << fecha << "] Comando '" << comando << "' ejecutado en '" << archivo << "'" << endl;
    logFile.close();
}

// Función para procesar el archivo .properties
void procesarProperties(istream& archivo) {
    string linea;

        while (getline(archivo, linea)) {
            // Ignorar comentarios
            if (!linea.empty() && linea[0] == '#') {
                continue;
            }

            // Buscar comandos SVN
            size_t pos = linea.find("svn");
            if (pos != string::npos) {
                string comando, archivo;
                stringstream ss(linea.substr(pos + 3));
                ss >> comando >> archivo;

                // Procesar comandos
                if (comando == "add") {
                    addArchivo(archivo);
                    generarInforme(comando, archivo);
                    registrarNovedad(comando, archivo);
                } else if (comando == "del") {
                    deleteArchivo(archivo);
                    generarInforme(comando, archivo);
                    registrarNovedad(comando, archivo);
                } else if (comando == "modify") {
                    modifyArchivo(archivo); 
                    generarInforme(comando, archivo);
                    registrarNovedad(comando, archivo);
                }
            }
        }
    return;       
}
int main(){
    
    // Abrir el archivo en modo de lectura
    ifstream archivoProperties("archivo.properties");
    procesarProperties(archivoProperties);

    archivoProperties.close();
    


    return 0;
}
