/*Git init (crear repositorio)
Git status
Git log
Git add (para meter a caja)
Git commit (sellar caja)
Git Push subir a la nube 
Git Pull traer de la nube a la compu

# Archivo .propeties

<!-- # esta linea no se toma en cuenta
svn add miejercicio.csv
svn delete miejercicio.
#svn info otro.cpp  -->

## Idea del módulo 2

abro archivo properties

    parseo linea, si tiene #, parseo la que sigue

    encuentro svn
    leo la siguiente palabra y abro switch (podría ser comando = **leo palabra**, y después switch(comando):
        case add {
            <!-- leer la palabra que sigue, y agregarlo a el repositorio -->
            archivo = leerPalabra("cadena")
            addArchivo(archivo)
            generarInforme(add, archivo)
            <!-- "se agregó el archivo "archivo.csv al repositorio a las 17.33hs del 23/10" -->
            registrarNovedad(add, archivo)
            <!-- esto cumple con el 3? punto del primer m´doulo, de tener un archivo con registros de modificaciones -->
        }

        case del {
            <!-- leer la palabra que sigue, y eliminarlo a el repositorio -->
            archivo = leerPalabra("cadena")
            deleteArchivo(archivo)
            generarInforme(del, archivo)
            <!-- "se eliminó el archivo "archivo.csv al repositorio a las 17.33hs del 23/10" -->
            registrarNovedad(add, archivo)
        }

        ...

cierro archivo .properties
*/