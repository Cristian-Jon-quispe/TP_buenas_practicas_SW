
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
	/* modificacion de la lectura de texto*/
	scanf("%39s", nenlace);

	
	for(i=0;i<(*cantidad);i++)
	{
		if ( strcmp((*Enlaces)[i].nomEnlace,nenlace) == 0 )
		{                                              // en el siguiente print vamos mostrando las coincidencias
			printf("\n nombre del enlace: %s\n frecuencia: %i\n Potencia: %i",(*Enlaces)[i].nomEnlace,(*Enlaces)[i].frecuencia,(*Enlaces)[i].potencia);
		}
	}
}



/*
modificacion de funcion Agregar_E.
Parametros: recibe el arreglo de enlaces y la cantidad de elementos.
Entrada: nombre, frecuencia y potencia del nuevo enlace.
Salida: incorpora un nuevo enlace al arreglo.
Comportamiento: reserva memoria adicional y carga los datos del nuevo enlace y Comprobamos si la reserva de memoria falló.
*/

void Agregar_E(enlace** Enlaces, int * cantidad){

    enlace *auxiliar;

    auxiliar = (enlace*)realloc(*Enlaces, (*cantidad + 1) * sizeof(enlace));

    if(auxiliar == NULL){

        printf("\nError al reservar memoria\n");

        return;
    }

    *Enlaces = auxiliar;

    (*cantidad)++;

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
		
	/*  aca tambien se modifica para Comprobamos que el usuario haya ingresado un número entero.Evitamos aceptar cantidades iguales o menores a cero.Evitamos continuar con datos inválidos.*/	
	printf("Ingrese cantidad de enlaces: \n ");

if(scanf("%d", &cantidad) != 1 || cantidad <= 0){

    printf("\nCantidad de enlaces invalida\n");

    return 1;
}
		/*  aca tambien se modifica para Comprobar si la reserva de memoria fue exitosa.*/
		Enlaces = (enlace*)malloc(cantidad * sizeof(enlace));

if(Enlaces == NULL){

    printf("\nError al reservar memoria\n");

    return 1;
}
		
		
		/*llenar enlaces */
		for(i=0;i<cantidad;i++){
			
			printf("Ingrese el nombre del enlace:\n");

			/* modificacion de la lectura de texto*/
			scanf("%39s", Enlaces[i].nomEnlace);

			
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



