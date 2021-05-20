/*
 ============================================================================
 Name        : facundo_palmieri-parcial1-segunda-parte.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contribuyente.h"
#include "recaudacion.h"
#include "informes.h"


int main(void) {
	setbuf(stdout, NULL);
		int menu;
		int contContribuyente = 0;
		int contRecaudaciones = 0;
		int idContribuyente = 999;
		int idRecaudacion = 99;
		int idEmpleadoBuscar =-1;
		int auxID;
		int auxInt;
		int posicion = -1;
		int subMenuInforme;

		Contribuyente contribuyente[TAME_STRUC_CONTRIBUYENTE];
		Recaudacion recaudacion[TAME_STRUC_RECAUDACION];

		initContribuyentes(contribuyente, TAME_STRUC_CONTRIBUYENTE);
		initRecaudacion(recaudacion, TAME_STRUC_RECAUDACION);

		do {
			printf("\n Menu\n");
			printf(" 1. Alta de contribuyente\n");
			printf(" 2. Modificar contribuyente\n");
			printf(" 3. Baja de contribuyente\n");
			printf(" 4. Recaudacion\n");
			printf(" 5. Refinanciar recaudacion \n");
			printf(" 6. Saldar recaudacion\n");
			printf(" 7. Imprimir contribuyente\n");
			printf(" 8. Imprimir recaudacion\n");
			printf(" 9. Informes\n");
			printf(" 10. Salir\n");

			scanf("%d", &menu);
			switch (menu) {
			case 1://alta contribuyente
				if (addContribuyente(contribuyente, TAME_STRUC_CONTRIBUYENTE, &idContribuyente) == 0) {
					printf("\n El contribuyente se a dado de alta correctamente");
					contContribuyente++;
				} else {
					printf("\nERROR. El contribuyente no se a dado de alta correctamente");
				}
				break;
			case 2://modificar contribuyente
				if (contContribuyente > 0) {
					imprimirContribuyentes(contribuyente, TAME_STRUC_CONTRIBUYENTE);
					printf("\n");
					idEmpleadoBuscar = findContribuyenteById(contribuyente, TAME_STRUC_CONTRIBUYENTE,&auxID);
					modificaContribuyente(contribuyente, idEmpleadoBuscar);
					idEmpleadoBuscar = -1;
					printf("\nSe modifico correctamente contribuyente\n");
					} else {
					printf("\nNo se modifico el contribuyente\n");
				}

				break;
			case 3://baja contribuyente y recaudacion
				if (contContribuyente != 0) {
					imprimirContribuyentes(contribuyente, TAME_STRUC_CONTRIBUYENTE);
					printf("\n");
					idEmpleadoBuscar = findContribuyenteById(contribuyente, TAME_STRUC_CONTRIBUYENTE,&auxID);
					removeContribuyente(contribuyente, idEmpleadoBuscar);
					removeRecaudacio_Contribuyente(recaudacion, TAME_STRUC_RECAUDACION,auxID);
					idEmpleadoBuscar = -1;
					printf("\nSe elimino correctamente contribuyente\n");}
				else {
					printf("\nNo se modifico el contribuyente\n");
					}
				break;
			case 4://alta recaudacion
				if (contContribuyente != 0) {
					imprimirContribuyentes(contribuyente, TAME_STRUC_CONTRIBUYENTE);
					printf("\n");
					addRecaudacion(recaudacion, TAME_STRUC_RECAUDACION, &idRecaudacion,contribuyente, TAME_STRUC_CONTRIBUYENTE);
					contRecaudaciones++;
				}
				break;
			case 5:// Refinanciar recaudacion
				if (contContribuyente != 0 && contRecaudaciones != 0) {
					printsRecaudaciones(recaudacion, TAME_STRUC_RECAUDACION);
					printf("\n");
					auxInt=buscaIDRecaudacion(recaudacion, TAME_STRUC_RECAUDACION, idRecaudacion, &posicion);
					idEmpleadoBuscar = findContribuyenteByIdParametro(contribuyente, TAME_STRUC_CONTRIBUYENTE,&auxInt);
					printContribuyente(contribuyente[idEmpleadoBuscar]);
					if(posicion != 1){
					refinanciarRecaudacion(recaudacion, posicion);
					}
					posicion = -1;

				}
				break;
			case 6://Saldar recaudacion
				if (contContribuyente != 0 && contRecaudaciones != 0) {
					printsRecaudaciones(recaudacion, TAME_STRUC_RECAUDACION);
					printf("\n");
					auxInt=buscaIDRecaudacion(recaudacion, TAME_STRUC_RECAUDACION, idRecaudacion, &posicion);
					idEmpleadoBuscar = findContribuyenteByIdParametro(contribuyente, TAME_STRUC_CONTRIBUYENTE,&auxInt);
					printContribuyente(contribuyente[idEmpleadoBuscar]);
					if(posicion != 1){
					estadoRecSaldar(recaudacion, posicion);

					}
					posicion = -1;
				}
				break;
			case 7://Imprimir contribuyente

				break;
			case 8://Imprimir recaudacion

				break;
			case 9://Informe
			if (contContribuyente != 0 && contRecaudaciones != 0) {
				do {
					printf("\n Menu\n");
					printf(" 1. Informe A\n");
					printf(" 2. Informe B\n");
					printf(" 3. Informe C\n");
					printf(" 4. Informe D\n");
					scanf("%d", &subMenuInforme);

					switch (subMenuInforme) {
					case 1:
						printf("No lo hice informe A");
						break;
					case 2:
						printf("No lo hice informe B");

						break;
					case 3:
						informeC(recaudacion, TAME_STRUC_RECAUDACION,contribuyente, TAME_STRUC_CONTRIBUYENTE);
						break;
					case 4:
						printf("No lo hice informe c");

						break;
					case 5: //salir
						break;
					default:
						printf("No elegiste ninguna opcion \n");
						break;
					}
				} while (subMenuInforme != 5);
			}
				break;
			case 10://salir
				break;
			default:
				printf("No elegiste ninguna opcion \n");
			}

		} while (menu != 10);

		return EXIT_SUCCESS;
	}
