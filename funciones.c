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

void guardarNombresArchivo(char nombreArchivo[], char nombres[5][4][50])
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
            fprintf(archivo, "%s %s %s %s\n", nombres[i][0], nombres[i][1], nombres[i][2], nombres[i][3]);
            
        }
        fclose(archivo);
    }
}

void leerNombresArchivo(char nombreArchivo[])
{
    char id[50];
    char nombre[50];
    float edad;
    int estado;
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
            fscanf(archivo, "%s %s %f %d", &id, &nombre, &edad, &estado);
            printf("%s %s %.2f %d\n", id,nombre,edad, estado);
           
        } 
        fclose(archivo);
    }
}

long buscarNombrePorId(char nombreArchivo[],char id[]){
    FILE *archivo;
    char idBuscado[50];
    char nombreEncontrado[50];
    float edad;
    int estado;
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
            fscanf(archivo, "%s %s %f %d", &idBuscado, &nombreEncontrado, &edad, &estado);
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
    int estadoAntiguo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
         fseek(archivo, posicion, 0);
         fscanf(archivo, "%s %s %f %d", &id,&nombreAntiguo,&edadAntiguo,&estadoAntiguo);
         fseek(archivo, posicion, 0);
         fprintf(archivo, "\n%s %s %.2f %d", id, nombre, edad, estadoAntiguo);
         fclose(archivo);
    }

}

void cambiarEstado(char nombreArchivo[],long posicion, int estado){
    FILE *archivo;
    char id[50];
    char nombreAntiguo[50];
    float edadAntiguo;
    int estadoAntiguo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
         fseek(archivo, posicion, 0);
         fscanf(archivo, "%s %s %f %d", &id,&nombreAntiguo,&edadAntiguo,&estadoAntiguo);
         fseek(archivo, posicion, 0);
         fprintf(archivo, "\n%s %s %.2f %d", id, nombreAntiguo, edadAntiguo, estado);
         fclose(archivo);
    }

}

void ingresarRegistro(char nombreArchivo[],char id[], char nombre[], float edad, int estado){
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL)
    {
        printf("No se puede leer el archivo\n");
    }
    else
    {
         fseek(archivo, 0, 2);
         fprintf(archivo, "\n%s %s %.2f %d", id,nombre,edad,estado);
         fclose(archivo);
    }

}