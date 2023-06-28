#include <stdio.h>
#include <string.h>
#include "funciones.h"

int crearArchivo(char nombreArchivo[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL)
    {
        printf("No se puede crear el archivo\n");
        return 0;
    }else
    {
        printf("Se ha creado el archivo, %s\n",nombreArchivo);
        fclose(archivo);
    }   
    return 1;
}

int abrirArchivo(char nombreArchivo[])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return 0;
    }
    fclose(archivo);
    return 1;
}

void guardarNombresArchivo(char nombreArchivo[], char nombres[5][3][50])
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede guardar en el archivo\n");
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            fprintf(archivo, "%s %s %s\n", nombres[i][0], nombres[i][1],  nombres[i][2]);
            
        }
        fclose(archivo);
    }
}

void leerNombresArchivo(char nombreArchivo[])
{
    char id[50];
    char nombre[50];
    float edad;
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        while (!feof(archivo))
        {
            fscanf(archivo, "%s %s %f", &id, &nombre, &edad);
            printf("%s %s %.2f\n", id,nombre,edad);
           
        } 
        fclose(archivo);
    }
}

long buscarNombrePorId(char nombreArchivo[],char id[]){
    FILE *archivo;
    char idBuscado[50];
    char nombreEncontrado[50];
    long posicion;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
        while (!feof(archivo))
        {
            posicion = ftell(archivo);
            fscanf(archivo, "%s %s", &idBuscado, &nombreEncontrado);
            if (strcmp(idBuscado,id)==0)
            {
               printf("Se encontro el id %s con el nombre %s\n", idBuscado,nombreEncontrado);
               break; 
            }
        } 
        fclose(archivo);
    }
    return posicion;
}

void reemplazarNombreEdadPorId(char nombreArchivo[],long posicion, char nombre[], float edad){
    FILE *archivo;
    char id[50];
    char nombreAntiguo[50];
    float edadAntiguo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
         fseek(archivo, posicion, 0);
         fscanf(archivo, "%s %s %f", &id,&nombreAntiguo,&edadAntiguo);
         fseek(archivo, posicion, 0);
         fprintf(archivo, "\n%s %s %.2f", id, nombre, edad);
         fclose(archivo);
    }

}