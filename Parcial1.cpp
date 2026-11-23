
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

typedef struct enlace{
	char nomEnlace[40];
	int frecuencia;
	int potencia;
}enlace;

void Buscar_E(enlace** Enlaces, int * cantidad){
	char nenlace[40];
	int i;
	printf("\nIngrese el enlace a buscar:\n");
	scanf("%s",&nenlace);
	for(i=0;i<(*cantidad);i++)
	{
		if ( strcmp((*Enlaces)[i].nomEnlace,nenlace) == 0 )
		{                                              // en el siguiente print vamos mostrando las coincidencias
			printf("\n nombre del enlace: %s\n frecuencia: %i\n Potencia: %i",(*Enlaces)[i].nomEnlace,(*Enlaces)[i].frecuencia,(*Enlaces)[i].potencia);
		}
	}
}



void Agregar_E(enlace** Enlaces, int * cantidad){
	
	(*cantidad)++;   
	
	*Enlaces = (enlace*)realloc(*Enlaces, (*cantidad) * sizeof(enlace));
	
	printf("\nIngrese el nombre del enlace: ");
	scanf("%39s", (*Enlaces)[*cantidad - 1].nomEnlace);
	
	printf("\nIngrese la frecuencia: ");
	scanf("%d", &(*Enlaces)[*cantidad - 1].frecuencia);
	
	printf("\nIngrese la potencia: ");
	scanf("%d", &(*Enlaces)[*cantidad - 1].potencia);
	
}
	
	
	void Mostrar_E(enlace** Enlaces, int * cantidad){
		int i;
		
		
		/*Mostrar enlaces*/
		for(i=0;i<(*cantidad);i++){	
			
			printf("\n nombre del enlace: %s\n frecuencia: %i\n Potencia: %i",(*Enlaces)[i].nomEnlace,(*Enlaces)[i].frecuencia,(*Enlaces)[i].potencia);
			
		}
	}
		
		
		
		
void Mostrar_P(enlace** Enlaces, int * cantidad){
	
			int i;
			int P;
			int porcentaje;
			
			int margen;
			int minimo;
			int maximo;
			
			printf("Ingrese la potencia solicitada:\n");
			scanf("%d", &P);
			
			printf("Ingrese el porcentaje de cercania:\n");
			scanf("%d", &porcentaje);
			
			margen = P * porcentaje / 100;  //ejemplo p=100 margen 10
			
			minimo = P - margen;
			maximo = P + margen;
			
			
			
			/*Mostrar enlaces*/
			for(i=0;i<(*cantidad);i++){
				
				if((*Enlaces)[i].potencia >= minimo && (*Enlaces)[i].potencia <= maximo){
					
				
				printf("\n nombre del enlace: %s\n frecuencia: %i\n Potencia: %i",(*Enlaces)[i].nomEnlace,(*Enlaces)[i].frecuencia,(*Enlaces)[i].potencia);
				
			}
			}
		}
	


	
	///////////////////////////////////////
	
	int main(int argc, char *argv[]) {
		
		int i,P,opcion;
		
		int cantidad;
		enlace* Enlaces;
		
		
		printf("Ingrese cantidad de enlaces: \n ");
		scanf("%d", &cantidad);
		
		Enlaces=(enlace*)malloc(cantidad * sizeof(enlace));
		
		
		/*llenar enlaces */
		for(i=0;i<cantidad;i++){
			
			printf("Ingrese el nombre del enlace:\n");
			scanf("%s",&Enlaces[i].nomEnlace);
			printf("\nIngrese la frecuencia\n");
			scanf("%i",&Enlaces[i].frecuencia);
			printf("Ingrese la potencia:\n ");
			scanf("%i",&Enlaces[i].potencia);
		}
		
		
		do{
			printf("\n 1:buscar enlace por su nombre \n 2:agregar un nuevo Enlace\n 3:Mostrar Enlaces\n 4: mostrar enlaces a potencia cercana\n 6:Salir\n");
			scanf("%i",&opcion);
			
			switch(opcion)
			{
			case 1:Buscar_E(&Enlaces,&cantidad);
			break;
			case 2:Agregar_E(&Enlaces,&cantidad);
			break;
			case 3:Mostrar_E(&Enlaces,&cantidad);
			break;
			case 4:Mostrar_P(&Enlaces,&cantidad);
			break;
			case 6:	printf("ingreso una opcion Salir\n");
			break;	
			}
			
		
		}while(opcion!=6);
		
		
		
		return 0;
	}
