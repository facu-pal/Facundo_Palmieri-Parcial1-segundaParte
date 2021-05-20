/*
 * recaudacion.h
 *
 *  Created on: 20 may. 2021
 *      Author: facun
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_
#include "Contribuyente.h"

#define FINACIADO 0
#define REFINANCIAR 1
#define SALDADO 2

typedef struct {
	int idRecaudacion;
	int idContribuyente;
	int mes;
	int tipo;
	float importe;
	int estado;
	int isEmpty;
} Recaudacion;


#define TAME_STRUC_RECAUDACION 50

/*brief Para indicar que todas las posiciones en la matriz están vacías, esta función coloca la bandera (isEmpty) en VERDADERO en todas las posiciones de la matriz
 *\param list Recaudacion* Puntero a la variedad de empleados
 *\param len int Longitud de la matriz
 *\return int Return (-1) si Error [Longitud no válida o puntero NULO] - (0) si está bien*/
int initRecaudacion(Recaudacion *array, int len);

/** \brief  busca en el campo isEmpty del array, con 0 para saber que esta libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibre(Recaudacion array[], int cantidadDeArray);

/*briefagregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
 *\param array Recaudacion* es el punto de mi array del main
* \param len int es la tamaño de array
* \return int Return (-1) si Error [Longitud no válida o puntero NULL o sin espacio libre] - (0) si está bien*/
int addRecaudacion(Recaudacion array[], int len, int *contadorId,  Contribuyente Contribuyente[], int cantidadContribuyente);

/*\Imprime solo un empleado del array.
* \param Empleado Recaudacion*/
void printRecaudacion(Recaudacion array);

/*\Imprime todos los empleados de la array.
* \param list Recaudacion* para toda la array
* \param len int le pasa el tamaño de la array
* \return int*/
int printsRecaudaciones(Recaudacion array[], int len);

/*\brief Busca un empleado en el arrat.
* \param list Recaudacion* pasa la array
* \param len int pasa el tamaño de la array
* \return Return devuelve la ID*/
int  findRecaudacionById(Recaudacion array[], int len);

/** \brief Elimina de manera lógica (isEmpty Flag en 0) un empleado recibiendo como parámetro su Id.
* \param list Recaudacion* pasa la array
* \param posicion int pasa la posicion que se quiere dar de baja
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Recaudacion] - (0) if Ok*/
int removeRecaudacion(Recaudacion* list,int posicion);


int removeRecaudacio_Contribuyente(Recaudacion array[], int len,int ID);


int buscaIDRecaudacion(Recaudacion array[], int len, int contadorRecauda, int* posicion);

int refinanciarRecaudacion(Recaudacion array[], int pos);

int estadoRecSaldar(Recaudacion array[], int posicion);



#endif /* RECAUDACION_H_ */
