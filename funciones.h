int abrirArchivo(char nombreArchivo[]);
int crearArchivo(char nombreArchivo[]);
void guardarNombresArchivo(char nombreArchivo[], char nombres[5][4][50]);
void leerNombresArchivo(char nombreArchivo[]);
long buscarNombrePorId(char nombreArchivo[],char id[]);
void reemplazarNombreEdadPorId(char nombreArchivo[],long posicion, char nombre[], float edad);
void cambiarEstado(char nombreArchivo[],long posicion, int estado);
void ingresarRegistro(char nombreArchivo[],char id[], char nombre[], float edad, int estado);