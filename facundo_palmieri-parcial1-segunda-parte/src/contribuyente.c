#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyente.h"
#include "utn.h"

int initContribuyentes(Contribuyente *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 0;
			retorno = 0;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int buscaLibreContCont(Contribuyente pArray[], int len) {
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (pArray[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

int addContribuyente(Contribuyente aContribuyente[], int len, int *contadorId) {
	int retorno = -1;
	Contribuyente Contribuyente;
	int posicion;

	if (aContribuyente != NULL && len > 0 && contadorId != NULL) {
		posicion = buscaLibreContCont(aContribuyente, len);
		if (posicion == -1) {
			printf("\nNo hay lugares libres");
		} else {
			if ((utn_getString(Contribuyente.nombre, "Ingrese Apellido:","Error.Ingrese Apellido:", 2) == 0)
					&& (utn_getString(Contribuyente.apellido, "Ingrese Nombre:","Error.Ingrese Nombre:", 2) == 0)
					&& (utn_getCuit(Contribuyente.cuit, "Ingrese cuit de la forma XX-XXXXXXXX-X", "Error, reingrese", 2)==0)) {
				Contribuyente.idContribuyente = *contadorId + 1;
				printf("Estos son los datos, desea continuar:");
				printContribuyente(Contribuyente);
				if (utn_getConfirm() == 0) {
					(*contadorId)++;
					printf("s");
					Contribuyente.idContribuyente = *contadorId;
					Contribuyente.isEmpty = 1;
					aContribuyente[posicion] = Contribuyente;
					retorno = 0;
					printContribuyente(aContribuyente[posicion]);

				}
			}
		}
	}
	return retorno;
}
void printContribuyente(Contribuyente Contribuyente) {
	printf("\n %-5d %-10s %-15s %-15s ", Contribuyente.idContribuyente,Contribuyente.nombre, Contribuyente.apellido, Contribuyente.cuit);

}
int imprimirContribuyentes(Contribuyente Contribuyente[], int len) {
	int i;
	int retorno = -1;

		printf("\n\t> Listado Contribuyentes ");
		printf("\n %5s %10s %15s %15s\n", "ID","APELLIDO","NOMBRE","CUIT");
	if (Contribuyente != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (Contribuyente[i].isEmpty == 0) {

				continue;
			} else {

				printContribuyente(Contribuyente[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int findContribuyenteById(Contribuyente Contribuyente[], int len, int *buscarID) {
	int retorno = -1;
	int i;
	int auxID;
	if (Contribuyente != NULL && len > 0) {
		printf("Ingrese ID del Contribuyente:");
		scanf("%d", &auxID);
		for (i = 0; i < len; i++) {
			if (Contribuyente[i].idContribuyente == auxID && Contribuyente[i].isEmpty == 1) {
				retorno = i;
				*buscarID = auxID;
				break;
			}
		}
		if (retorno == -1) {
			printf("El numero de ID %d no existe", auxID);
		}
	}
	return retorno;
}

int modificaContribuyente(Contribuyente Contribuyente[], int posicion) {
	int retorno = -1;
	int respuesta;

	if (Contribuyente != NULL && posicion != -1) {

		printContribuyente(Contribuyente[posicion]);
		printf(	"\n  Ingreso una opcion  (opciones del 1 al 3)");
					printf("¿Que desea modificar?\n");
					printf("1_Apellido \n");
					printf("2_Nombre\n");
					printf("3_cuit\n");
					scanf("%d", &respuesta);
		while (respuesta > 3 || respuesta < 1) {
			printf(
					"\nError. no ingreso una opcion correcta (opciones del 1 al 4)");
			printf("¿Que desea modificar?\n");
			printf("1_Nombre \n");
			printf("2_Apellido\n");
			printf("3_cuit\n");
			scanf("%d", &respuesta);
		}
		switch (respuesta) {
		case 1:
			utn_getString(Contribuyente[posicion].nombre, "Ingrese el nuevo nombre:","Error.Ingrese el nuevo nombre:", 2);
			printf("Cambias realisados correctamente: ");
			printf("%5s %15s %15s %15s\n", "ID","APELLIDO","NOMBRE","CUIT");
			printContribuyente(Contribuyente[posicion]);

			break;
		case 2:
			utn_getString(Contribuyente[posicion].apellido, "Ingrese el nuevo apellido:","Error.Ingrese el nuevo apellido:", 2);
			printf("Cambias realisados correctamente: ");
			printf("%5s %15s %15s %15s\n", "ID","APELLIDO","NOMBRE","CUIT");
			printContribuyente(Contribuyente[posicion]);

			break;
		case 3:
			utn_getCuit(Contribuyente[posicion].cuit, "Ingrese el nuevo cuit de la forma XX-XXXXXXXX-X:", "Error,Ingrese el nuevo cuit de la forma XX-XXXXXXXX-X:", 2);
			printf("\nCambias realisados correctamente: ");
			printf("%5s %15s %15s %15s\n", "ID","APELLIDO","NOMBRE","CUIT");
			printContribuyente(Contribuyente[posicion]);
			break;
		}

		retorno = 0;

	}
	return retorno;
}

int removeContribuyente(Contribuyente *list, int posicion) {
	int retorno = -1;
	if (list != NULL && posicion != -1) {

		printContribuyente(list[posicion]);
		printf("\n¿Desea borrar el Contribuyente?\n");
		if (utn_getConfirm() == 0) {
			list[posicion].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}


int findContribuyenteByIdParametro(Contribuyente Contribuyente[], int len, int *buscarID) {
		int retorno = -1;
		int i;
		if(Contribuyente!=NULL && len>0)
		{
			for(i=0; i<len; i++)
			{
				if(Contribuyente[i].idContribuyente == *buscarID && Contribuyente[i].isEmpty == 1 )
				{
					retorno = i;
					break;
				}
				else
				{
					printf("El numero de id %d no existe", *buscarID);
					break;
				}
			}
		}
		return retorno;
	}
