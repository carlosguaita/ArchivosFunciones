#include <stdio.h>
void guardarNombresArchivo(FILE *archivo, char id[], char nombre[]);

int main (int argc, char *argv[]) {

    char nombres[5][2][50]={{"a01","Carlos"},{"a02","Luis"},{"a03","Ana"},{"a04","Maria"},{"a05","Juan"}};
    FILE *archivo;
    archivo=fopen("Nombre.txt","w+");
    if (archivo==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    for (int i = 0; i < 5; i++)
    {
        guardarNombresArchivo(archivo, nombres[i][0],nombres[i][1]);
    }

    fclose(archivo);
    


    return 0;
}

void guardarNombresArchivo(FILE *archivo, char id[], char nombre[]){
    fprintf(archivo, "%s %s\n",id,nombre);
}