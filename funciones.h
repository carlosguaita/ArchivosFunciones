int abrirArchivo(char nombreArchivo[]);
int crearArchivo(char nombreArchivo[]);
void guardarNombresArchivo(char nombreArchivo[], char nombres[5][3][50]);
void leerNombresArchivo(char nombreArchivo[]);
long buscarNombrePorId(char nombreArchivo[],char id[]);
void reemplazarNombreEdadPorId(char nombreArchivo[],long posicion, char nombre[], float edad);