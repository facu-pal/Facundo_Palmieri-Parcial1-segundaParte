/*
 * contribuyente.h
 *
 *  Created on: 20 may. 2021
 *      Author: facun
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

typedef struct {
	int idContribuyente;
	char nombre[25];
	char apellido[25];
	char cuit[14];
	int isEmpty;
} Contribuyente;




#define TAME_STRUC_CONTRIBUYENTE 50

/*brief Para indicar que todas las posiciones en la matriz están vacías, esta función coloca la bandera (isEmpty) en VERDADERO en todas las posiciones de la matriz
 *\param list Contribuyente* Puntero a la variedad de empleados
 *\param len int Longitud de la matriz
 *\return int Return (-1) si Error [Longitud no válida o puntero NULO] - (0) si está bien*/
int initContribuyentes(Contribuyente *list, int len);

/** \brief  busca en el campo isEmpty del array, con 0 para saber que esta libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibreCont(Contribuyente pArray[], int cantidadDeArray);

/*briefagregar en una lista existente de empleados los valores recibidos como parámetros en la primera posición vacía
 *\param array Contribuyente* es el punto de mi array del main
* \param len int es la tamaño de array
* \return int Return (-1) si Error [Longitud no válida o puntero NULL o sin espacio libre] - (0) si está bien*/
int addContribuyente(Contribuyente* array,int len, int* contadorId);

/*\Imprime solo un empleado del array.
* \param Empleado Contribuyente*/
void printContribuyente(Contribuyente Contribuyente);

/*\Imprime todos los empleados de la array.
* \param list Contribuyente* para toda la array
* \param len int le pasa el tamaño de la array
* \return int*/
int imprimirContribuyentes(Contribuyente Contribuyente[], int len);

/*brief modifica a un empleado
 * param1 empleado[] employe pasa la array
 * param2 posicion int pasa solo la posicion de la array que se quiere modificar*/
int modificaContribuyente(Contribuyente Contribuyente[], int posicion);

/*\brief Busca un empleado en el arrat.
* \param list Contribuyente* pasa la array
* \param len int pasa el tamaño de la array
* \return Return devuelve la ID*/
int  findContribuyenteById(Contribuyente Contribuyente[], int len,int *buscarID);

/** \brief Elimina de manera lógica (isEmpty Flag en 0) un empleado recibiendo como parámetro su Id.
* \param list Contribuyente* pasa la array
* \param posicion int pasa la posicion que se quiere dar de baja
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a Contribuyente] - (0) if Ok*/
int removeContribuyente(Contribuyente* list,int posicion);

int findContribuyenteByIdParametro(Contribuyente Contribuyente[], int len, int *buscarID);

void printInformeD(Contribuyente array);

#endif /* CONTRIBUYENTE_H_ */
