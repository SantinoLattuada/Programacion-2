# Informe - Simulación de un programa SVN con configuración `.properties` intercambiable

Este programa proporciona una solución sencilla y versátil para gestionar archivos mediante un archivo .properties, permitiendo a los usuarios realizar operaciones específicas de manera fácil y eficiente.

## Funcionamiento del programa

El programa desarrollado en C++ permite gestionar archivos a través de un archivo CSV de entrada (input.csv), realizar operaciones como agregar (add), eliminar (del) y modificar (modify) archivos y luego guardar los resultados en un nuevo archivo CSV de salida (output.csv). Además, el programa genera archivos .dat para los archivos maestros (maestro.dat) y de novedades (novedades.dat).

## Estructura del `.properties`

El archivo .properties es un archivo de configuración que contiene comandos para el programa. La estructura básica del archivo .properties es la siguiente:

```svn
svn operación archivo
```

- operación → Nombre de la operación a realizar. Puede ser:
  - add → Agrega un archivo
  - del → Elimina un archivo
  - modify → Modifica el nombre del archivo

- archivo → Nombre del archivo al que se le aplica la operación

### Ejemplos de uso

```svn
svn add tablaDeAlumnos.csv
svn add tablaDeProfesores.csv
svn modify tablaDeAlumnos.csv tablaDeAlumnxs.csv
svn del tablaDeProfesores.csv
```