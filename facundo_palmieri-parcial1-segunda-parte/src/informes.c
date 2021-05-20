/*
 * informes.c
 *
 *  Created on: 20 may. 2021
 *      Author: facun
 */
#include "informes.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void informeC (Recaudacion arrayRecaudacion[], int lenRecaudaciones, Contribuyente ArrayContribuyente[], int lenContribuyente){
	int tipo;
	int auxId;
	int idEmpleadoBuscar;


	utn_getInt(&tipo, "Ingrese el tipo  1.ARBA, 2.IIBB, 3.GANANCIAS", "Error,ingrese el tipo 1.ARBA, 2.IIBB, 3.GANANCIAS",1,3,2);
	printf("\n\t> Listado Contribuyentes del tipo %d ",tipo);
	printf("\n %5s %10s %15s %15s\n", "ID","APELLIDO","NOMBRE","CUIT");
	for(int i = 0; i < lenRecaudaciones; i++){
		if(arrayRecaudacion[i].tipo == tipo){
			auxId = arrayRecaudacion[i].idContribuyente;
			idEmpleadoBuscar = findContribuyenteByIdParametro(ArrayContribuyente, lenContribuyente,&auxId);
			printContribuyente(ArrayContribuyente[idEmpleadoBuscar]);
		}
	}

}
void informeD (Recaudacion arrayRecaudacion[], int lenRecaudaciones, Contribuyente ArrayContribuyente[], int lenContribuyente){
	int auxId;
	int idEmpleadoBuscar;

	printf("\n\t> Listado Contribuyentes que pagaron en el mes de febrero ");
	printf("\n %15s %15s\n", "NOMBRE","CUIT");

	for(int i = 0; i < lenRecaudaciones; i++){
		if(arrayRecaudacion[i].mes == 2){
			auxId = arrayRecaudacion[i].idContribuyente;
			idEmpleadoBuscar = findContribuyenteByIdParametro(ArrayContribuyente, lenContribuyente,&auxId);
			printInformeD(ArrayContribuyente[idEmpleadoBuscar]);
		}
	}

}























































