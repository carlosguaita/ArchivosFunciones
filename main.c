#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[])
{

    char nombres[5][4][50] = {{"a01", "Carlos", "36.00", "1"}, 
                              {"a02", "Luis", "30.00", "1"}, 
                              {"a03", "Ana", "20.00", "1"}, 
                              {"a04", "Maria", "50.00", "1"}, 
                              {"a05", "Juan", "40.00", "1"}};
    
    char nombreArchivo[20] = "productos.txt";
    long posicion;
    if (abrirArchivo(nombreArchivo))
    {
        printf("Lista todos los datos en el archivo\n");
        leerNombresArchivo(nombreArchivo);
        
        printf("Encuentra un registro en el archivo en funcion del ID\n");
        posicion = buscarNombrePorId(nombreArchivo,"a05");
        printf("reemplaza el nombre y edad en funcion del ID\n");
        reemplazarNombreEdadPorId(nombreArchivo,posicion,"Carlos",34);
        printf("Lista los nuevos datos los datos en el archivo\n");
        leerNombresArchivo(nombreArchivo);

        printf("Encuentra un registro en el archivo en funcion del ID\n");
        posicion = buscarNombrePorId(nombreArchivo,"a02");
        printf("Cambiar estado de registro\n");
        cambiarEstado(nombreArchivo,posicion,0);
        leerNombresArchivo(nombreArchivo);
        
        printf("Ingresar registro\n");
        ingresarRegistro(nombreArchivo,"a06", "Esteban", 52.00, 1);
        leerNombresArchivo(nombreArchivo);

    }
    else
    {
        crearArchivo(nombreArchivo);
        guardarNombresArchivo(nombreArchivo,nombres);
    }

return 0;
}