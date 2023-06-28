#include <stdio.h>

int main(int argc, char *argv[])
{

    char nombres[5][3][50] = {{"a01", "Carlos", "36"}, 
                              {"a02", "Luis", "30"}, 
                              {"a03", "Ana", "20"}, 
                              {"a04", "Maria", "50"}, 
                              {"a05", "Juan", "40"}};
    
    char nombreArchivo[20] = "productos.txt";

    if (abrirArchivo(nombreArchivo))
    {
        leerNombresArchivo(nombreArchivo);
        long posicion = buscarNombrePorId(nombreArchivo,"a05");
        reemplazarNombreEdadPorId(nombreArchivo,posicion,"Carlos",34);
        leerNombresArchivo(nombreArchivo);
    }
    else
    {
        crearArchivo(nombreArchivo);
        guardarNombresArchivo(nombreArchivo,nombres);
    }

return 0;
}