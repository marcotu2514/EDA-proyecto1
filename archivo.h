#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#define MAX 50

struct Datos{
 	char nombre[30];
 	int edad;
 	char telefono[20];
};

struct Datos info[MAX];

int capturarDatos(struct Datos *q);
void listarDatos(struct Datos *q, int n);
FILE* abrirArchivoNuevo(FILE *q);
FILE* abrirArchivoLectura(FILE *q);
void almacenarDatos(FILE *q, int tope);

#endif
