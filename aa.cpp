
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#define max 2 

struct enlace{
	char nomEnlace [1][40];
	int frecuencia;
	int potencia;
}Enlace[max];



void Mostrar(struct enlace Enlace[max],int P){
	int i;
	
	
	for(i=0;i<max;i++){	
		
		if (Enlace[i].potencia=P  ) {
			
			printf("\n nombre del enlace: %s\n frecuencia: %i\n Potencia: %i",Enlace[i].nomEnlace,Enlace[i].frecuencia,Enlace[i].potencia);
			
		}
	
	}
}



int main(int argc, char *argv[]) {
	int i,P,opcion;
	char nenlace[2][40];
	
	
	for(i=0;i<max;i++){								
		printf("Ingrese el nombre del enlace:\n");
		scanf("%s",&Enlace[i].nomEnlace);
		printf("\nIngrese la frecuencia\n");
		scanf("%i",&Enlace[i].frecuencia);
		printf("\nIngrese la potencia: ");
		scanf("%i",&Enlace[i].potencia);
	}
	
	printf("Ingrese la potencia solicita:\n");
	scanf("%i",&P);
	Mostrar(Enlace,P);
	
	////
	do{
		printf("\n 1 buscar enlace por su nombre \n 2 6 Salir");
		scanf("%i",&opcion);
		
		switch(opcion)
		{
		case 1:
			printf("\nIngrese el enlace a buscar:\n");
			scanf("%s",&nenlace);
			for(i=0;i<max;i++)
			{
				if ( strcmp(Enlace[i].nomEnlace[0],nenlace[0]) == 0 )
				{                                              // en el siguiente print vamos mostrando las coincidencias
					printf("\n nombre del enlace: %s\n frecuencia: %i\n Potencia: %i",Enlace[i].nomEnlace,Enlace[i].frecuencia,Enlace[i].potencia);
				}
			}
			break;
			
			
		}
	}while(opcion!=6);
	
	
	
	
	return 0;
}

