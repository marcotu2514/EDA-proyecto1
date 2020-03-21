#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED


typedef struct{
	char *nombreLibro;
	char *fechaPrestamo;
	char *fechaDevolucion;
}Libro;


typedef struct{
	char *numeroDeCta;
	char *pass;
	Libro prestamos[3];
}Usuario;

Usuario* inicializarCuenta();
void capturarDatos(Usuario *p);
void listarDatos(Usuario p[], int total);
int logIn(Usuario *p);


#endif

