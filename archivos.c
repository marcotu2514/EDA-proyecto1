#include <stdio.h>
#include "archivo.h"

int main(){
 	FILE *p;
 	int i=0, n, opcion,total;
	do{
		printf("Ingresa la opcion que deseas\n"
		"1. Nueva base de datos\n"
		"2. Agregar datos\n"
		"3. Listar datos\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1://en caso de borrar toda la base e iniciar desde cero
				n=capturarDatos(info);	//recibe la estructura de tipo Datos
				p=abrirArchivoNuevo(p);//crea un nuevo archivo en blanco
				almacenarDatos(p,n);//alamcena los datos en el archivo nuevo
				fclose(p);//cierra el archivo
				break;
			case 2://en caso de solamente añadir nuevos datos
				n=capturarDatos(info);
				if((p=fopen("prueba.txt", "r+"))!=NULL){
					fseek(p,27,0);//para poner el cursor en la linea donde esta el total
					fscanf(p,"%d",&total);//para obtener el valor del total
					fseek(p,27,0);//vuelve q poner el cursor en la linea donde esta el total
					fprintf(p,"%d",(total+n));//modifica el valor del total para colocar el nuevo total
				}
				if((p=fopen("prueba.txt","a"))!=NULL){//abrer el archivo, iniciando el cursor en el final de este
					for(int i=0;i<n;i++){//contador para insertar el numero de datos capturados anteriormente
						fprintf(p,"%s\t%d\t%s\n",info[i].nombre, info[i].edad,info[i].telefono);//coloca los nuevos datos 
					}
				}
				fclose(p);//cierra el archivo
				break;
			case 3:
				p=abrirArchivoLectura(p);//abre el archivo en modo lectura
				fseek(p,27,0);//para poner el cursor en la linea donde esta el total
				fscanf(p,"%d",&total);
				while(!feof(p)){
					fscanf(p, "\n%s%d%s\n",info[i].nombre,&info[i].edad,info[i].telefono);//lee y guarda los datos del archivo en la estructura de acuerdo a como estan ordenados
					i++;
				}
				listarDatos(info,total);//lista los datos que se guardaron en la estructura
				fclose(p);//cierra el archivo
				break;
		}
	printf("Ingresa la opcion que deseas\n"
		"1. Nueva base de datos\n"
		"2. Agregar datos\n"
		"3. Listar datos\n");
 	scanf("%d",&opcion);
	}
 	while(opcion>0 && opcion<=3);
 	return 0;
 }

