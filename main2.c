#include <stdio.h>
void leerNombresArchivo(FILE *archivo);
int main (int argc, char *argv[]) {
    FILE *archivo;
    archivo=fopen("Nombre.txt","r+");
    if (archivo==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    for (int i = 0; i < 5; i++)
    {
        leerNombresArchivo(archivo);
    }
   fclose(archivo);
    return 0;
}

void leerNombresArchivo(FILE *archivo){
    char id[50];
    char nombre[50];
    fscanf(archivo,"%s %s",&id,&nombre);
    printf("%s\n",id);
    printf("%s\n",nombre);
}