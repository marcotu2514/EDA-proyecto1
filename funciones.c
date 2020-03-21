#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

int capturarDatos(struct Datos *q){
	int i,n;
	printf("¿Cuantos datos deseas ingresar?\n");
	scanf("%d", &n);
	for(i=0 ; i<n ; i++){
	 	printf("Ingresa tu nombre\n");
	 	scanf("%s", info[i].nombre);
	 	printf("Ingresa tu edad\n");
	 	scanf("%d", &info[i].edad);
	 	printf("Ingresa tu telefono\n");	
	 	scanf("%s", info[i].telefono);
	}
	return n;
}
void listarDatos(struct Datos *q, int n){
	for(int i=0 ; i<n ; i++){
	 	printf("Nombre: %s\n",info[i].nombre);
	 	printf("Edad: %d\n",info[i].edad);
	 	printf("Telefono: %s\n",info[i].telefono);	

	 }
}
FILE* abrirArchivoNuevo(FILE *q){
	if((q=fopen("prueba.txt","wb+"))==NULL){
		printf("No se pudo crear o abrir el archivo");
	}
	else 
		return q;
}
FILE* abrirArchivoLectura(FILE *q){
	if((q=fopen("prueba.txt","r"))==NULL){
		printf("No se pudo crear o abrir el archivo");
	}
	else
		return q;
}
void almacenarDatos(FILE *q, int tope){
	fprintf(q,"Nombre\tEdad\tTelefono\tTOTAL:%d\n",tope);
	for(int i=0;i<tope;i++){
		fprintf(q, "%s\t%d\t%s\n",info[i].nombre, info[i].edad,info[i].telefono);
	}
	fclose(q);
	
}
	
