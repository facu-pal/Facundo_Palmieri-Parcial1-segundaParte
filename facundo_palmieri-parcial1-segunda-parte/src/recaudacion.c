#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recaudacion.h"
#include "utn.h"

int initRecaudacion(Recaudacion *array, int len) {
	int i;
	int retorno = -1;
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			array[i].isEmpty = 0;
			retorno = 0;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int buscaLibre(Recaudacion array[], int len) {
	int retorno = -1;
	int i;

	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

int addRecaudacion(Recaudacion array[], int len, int *contadorId,  Contribuyente Contribuyente[], int cantidadContribuyente) {
	int retorno = -1;
	Recaudacion recaudaciones;
	int posicion;
	int auxId;

	if (array != NULL && len > 0 && contadorId != NULL) {
		posicion = buscaLibre(array, len);
		if (posicion == -1) {
			printf("\nNo hay lugares libres");
		} else {
			if ((findContribuyenteById(Contribuyente, cantidadContribuyente, &auxId)!=-1)
					&&(utn_getInt(&recaudaciones.tipo, "Ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS", "Error,ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS",1,3,2)==0)
					&& (utn_getInt(&recaudaciones.mes, "Ingrese MES", "Error,ingrese MES del 1 al 12",1,12,2)==0)
					&& (utn_getFlotante(&recaudaciones.importe, "Ingrese importe de 300 a 30000 ","Error, ingrese de 100 a 1000", 300, 30000, 2)==0)) {

				recaudaciones.estado = FINACIADO;
				recaudaciones.idContribuyente = auxId;

				recaudaciones.idRecaudacion = *contadorId + 1;
				printf("Estos son los datos, desea continuar:");
				printRecaudacion(recaudaciones);
				if (utn_getConfirm() == 0) {
					(*contadorId)++;
					recaudaciones.idRecaudacion = *contadorId;
					recaudaciones.isEmpty = 1;
					array[posicion] = recaudaciones;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
void printRecaudacion(Recaudacion array) {

	switch(array.tipo){
	case 1:
		printf("\n %-5d %-5d %-10s %-5d %-5.2f %-5d ", array.idRecaudacion, array.tipo, "ARBA" ,array.mes, array.importe, array.idContribuyente);
		break;
	case 2:
			printf("\n %-5d %-5d %-10s %-5d %-5.2f %-5d ", array.idRecaudacion, array.tipo,"IIBB",array.mes, array.importe, array.idContribuyente);
			break;
	case 3:
			printf("\n %-5d %-5d %-10s %-5d %-5.2f %-5d ", array.idRecaudacion, array.tipo,"GANANCIAS",array.mes, array.importe, array.idContribuyente);
			break;
	}


}
int printsRecaudaciones(Recaudacion array[], int len) {
	int i;
	int retorno = -1;

	printf("\n\t> LISTADO Recaudacion\n");
	printf("%5s %10s %10s %8s %12s %5s\n", "ID","TIPO","DESCRIPCION","MES","IMPORTE","ID Contribuyente");
	if (array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 0) {
				continue;
			} else {
				printRecaudacion(array[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int findRecaudacionById(Recaudacion array[], int len) {
	int retorno = -1;
	int i;
	int auxID;
	if (array != NULL && len > 0) {
		printf("Ingrese ID del Recaudacion:");
		scanf("%d", &auxID);
		for (i = 0; i < len; i++) {
			if (array[i].idRecaudacion == auxID && array[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
		if (retorno == -1) {
			printf("El numero de ID %d no existe", auxID);
		}
	}
	return retorno;
}


int removeRecaudacion(Recaudacion *array, int posicion) {
	int retorno = -1;
	if (array != NULL && posicion != -1) {

		printRecaudacion(array[posicion]);
		printf("\n¿Desea borrar el Recaudacion?\n");
		if (utn_getConfirm() == 0) {
			array[posicion].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

int removeRecaudacio_Contribuyente(Recaudacion array[], int len,int ID){
	int retorno = -1;
		int i;
		if(array!=NULL && len>0)
			{
				for(i=0; i<len; i++)
				{
					if(array[i].idContribuyente==ID)
					{
						array[i].isEmpty=1;
					}
				}
			}
		return retorno;
}

int buscaIDRecaudacion(Recaudacion array[], int len, int contadorRecauda, int* posicion){
	int retorno = -1;
	int auxI;

	if(array!=NULL && len>0)
	{
		printf("Ingrese ID Recaudacion");
		scanf("%d", &auxI);
			for(int i=0; i<len; i++)
			{
				if(array[i].idRecaudacion==auxI && array[i].isEmpty==1)
				{
					*posicion=i;
					retorno=array[i].idContribuyente;
					break;
				}
			}

	}
	return retorno;
}


int estadoRecSaldar(Recaudacion array[], int posicion){
	int retorno = -1;

	if(array!=NULL && posicion!=-1 )
	{
		printRecaudacion(array[posicion]);
		printf("\n¿Desea saldar esta Recaudacion?");
		if(utn_getConfirm()==0)
		{
			array[posicion].estado= REFINANCIAR;
			retorno = 0;
		}
	}
	return retorno;
}

int refinanciarRecaudacion(Recaudacion array[], int pos){
	int retorno = -1;

	if(array!=NULL && pos!=-1 )
	{
		printRecaudacion(array[pos]);
		printf("\n¿Desea refinanciar esta Recaudacion?");
		if(utn_getConfirm()==0)
		{
			array[pos].estado= REFINANCIAR;
			retorno = 0;
		}
	}
	return retorno;
}
