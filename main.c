#include <stdio.h>
#include <stdlib.h>
#include "cuenta.h"


int main(int argc, char *argv[]) {
	int opcion=0,totalCta=-1;
	Usuario *cuentas;
	do{
		printf("Ingresa la opcion\n1. Crear cuenta\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				cuentas = inicializarCuenta();
				totalCta++;
				capturarDatos(&cuentas[totalCta]);
			break;
			case 2:
				listarDatos(cuentas, totalCta);
			break;
		}
	
	}
	while(opcion >0 && opcion <= 4);
	
	
	
	
	
	return 0;
}
