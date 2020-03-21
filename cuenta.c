#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuenta.h"

#define MAX 100

Usuario* inicializarCuenta(){
	Usuario *p;
	int i;
	p=(Usuario *)calloc(1,sizeof(Usuario));
	if(p==NULL){
		printf("No hay espacio disponible\n");
		return NULL;
	}
	p->numeroDeCta=(char *)calloc(9,sizeof(char));
	if(p->numeroDeCta==NULL){
		printf("No hay espacio disponible\n");
		return NULL;
	}
	p->pass=(char *)calloc(15,sizeof(char));
	if(p->pass==NULL){
		printf("No hay espacio disponible\n");
		return NULL;
	}
	for(i=0;i<3;i++){
		p->prestamos[i].nombreLibro=(char *)calloc(30,sizeof(char));
		if(p->prestamos[i].nombreLibro==NULL){
			printf("No hay espacio disponible\n");
		return NULL;
		}
		p->prestamos[i].fechaPrestamo=(char *)calloc(10,sizeof(char));
		if(p->prestamos[i].fechaPrestamo==NULL){
			printf("No hay espacio disponible\n");
		return NULL;
		}
		p->prestamos[i].fechaDevolucion=(char *)calloc(10,sizeof(char));
		if(p->prestamos[i].fechaDevolucion==NULL){
			printf("No hay espacio disponible\n");
		return NULL;
		}
	}
	return p;
}
void capturarDatos(Usuario *p){
	fflush(stdin);
	printf("Ingresa tu numero de cuenta: ");
	gets(p->numeroDeCta);
	//algoritmo de comparacion por si ya existe la cuenta
	fflush(stdin);
	printf("\nIngresa una contraseña: ");
	gets(p->pass);
}
void listarDatos(Usuario p[], int total){
	int i;
	for(i=0;1<total;i++){
		printf("Numero de cuenta: %s\nContraseña: %s\n", p[i].numeroDeCta, p[i].pass);
	}
	
}
int logIn(Usuario *p){
	Usuario *intento;
	int i;
	intento = inicializarCuenta();
	printf("Ingresa tu numero de cuenta: ");
	gets(intento->numeroDeCta);
	for(i=0;i<100;i++){
		if(strcmp(intento->numeroDeCta,p[i].numeroDeCta)==0){
			printf("\nIngresa tu contraseña: ");
			gets(intento->pass);
			while(strcmp(intento->pass,p[i].pass)!=0){
				printf("\nContraseña incorrecta, escribela de nuevo: ");
				gets(intento->pass);
			}
			return i;
		}
	}
	printf("No existe ese número de cuenta nuestra base, quieres ingresar: ");	
}
