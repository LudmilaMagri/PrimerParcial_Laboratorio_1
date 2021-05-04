/*
 * Contratacion.c
 */

#include "Compras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static const char ESTADO [2][10] ={"PENDIENTE","COBRADA"};

/*
 * \brief Imprime los datos de..
 * \param pElemento Puntero al elemento que se busca imprimir
 * \param limite Limite del array de ..
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int com_imprimir (Compras* pElemento)
{
	int retorno = -1;
	if (pElemento != NULL && pElemento->isEmpty == 0){
		retorno = 0;
		printf ("\n ID COMPRA: %-10d - CANTIDAD BARBIJOS %-15d -  DIRECCION %-15s - COLOR %-10s - ESTADO %-10s - ID CLIENTE: %-10d",
				pElemento->idCompra, pElemento->cantBarbijos, pElemento->direccion, pElemento->colorBarbijos, ESTADO[pElemento->estadoDeCompra], pElemento ->idCliente);
	}
	return retorno;
}

/*
 * \brief Imprime el array de...
 * \param array Array de ... a ser actualizado
 * \param limite Limite del array de ..
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int com_imprimirArray (Compras* array, int limite)
{
	int retorno = -1;
	int i;
	if (array != NULL && limite > 0){
		retorno = 0;
		for (i=0; i<limite; i++){
			if(array[i].isEmpty == 0)
			{
			com_imprimir(&array [i]);
			}
		}
	}
	return retorno;
}

/*
 * \brief Inicializa el array
 * \param array Array de... a ser actualizados
 * \param limite Limite del array de ..
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int com_inicializarArray (Compras* array, int limite)
{
	int retorno = -1;
	int i;
	if(array != NULL && limite>0){
		retorno = 0;
		for (i=0; i<limite; i++){
			array [i].isEmpty = 1;
		}
	}
	return retorno;
}

/*
 * \brief Da de alta un ... en una posicion del array
 * \param array Array de... a ser actualizados
 * \param limite Limite del array de ..
 * \param indice Posicion a ser actualizado
 * \param id Identificador a ser asignado al ...
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */


int com_altaArray(Compras* array, int limite, int indice, int idCompras, int idCliente)
{
	int retorno = -1;
	Compras bufferCompras;
	if (array != NULL && limite>0 && indice<limite && indice >= 0){
		if (utn_getNumeroInt(&bufferCompras.cantBarbijos, "\nIngrese cantidad de barbijos\n", "\nError\n", 0, 10000, 3)==0 &&
				utn_getDireccion(bufferCompras.direccion, DIRECCION_LEN, "\nIngrese la direccion\n", "\nError\n", 3) == 0 &&
				utn_getTexto(bufferCompras.colorBarbijos, COLOR_BARBIJO, "\nIngrese el color del barbijo\n", "\nError\n", 3)==0)
		{
			printf ("\n ID CLIENTE: %d", idCliente);
			printf ("\n ID COMPRA: %d", idCompras);
			bufferCompras.idCompra = idCompras;
			bufferCompras.idCliente = idCliente;
			bufferCompras.isEmpty = 0;
			bufferCompras.estadoDeCompra = 0;
			array[indice] = bufferCompras;
			retorno = 0;
		}
	}
	return retorno;
}


/*
 * \brief Actualiza los datos de ... en una posicion del array
 * \param array Array de... a ser actualizados
 * \param limite Limite del array de ..
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
/*
int com_modificarArray (Compras* array, int limite, int indice)
{
	int retorno = -1;
	int dias;
	if (array!=NULL && limite>0 && indice<limite && indice>=0 && array[indice].isEmpty ==0){
		if (utn_getNumeroInt(&dias, "Dias?", "Error", 1, 365, 3)==0){
				retorno=0;
				array[indice].dias = dias;
			}
	}
	return retorno;
}
*/
/*
 * \brief Actualiza una posicion del array
 * \param array Array de... a ser actualizados
 * \param limite Limite del array de ..
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int com_bajarArray (Compras* array, int limite, int idCliente)
{
	int retorno = -1;
	if (array != NULL && limite >0 && idCliente <limite && idCliente >= 0 && array[idCliente].isEmpty == 0){
		array[idCliente].isEmpty = 1;
		retorno = 0;
	}

	return retorno;
}

/*
 * \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array Array de...
 * \param limite Limite del array de ..
 * \param valorBuscado Valor que ingreso el usuario a ser buscado
 * \return Retorna -1 (ERROR) o la posicion del indice en la que se encuentre el id (EXITO)
 */

int com_buscarId (Compras* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite>0 && valorBuscado>=0){
		for (i=0; i<limite; i++){
			if (array[i].idCompra == valorBuscado){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/*
 * \brief Buscar la primera posicion que este vacia
 * \param array Array de...
 * \param limite Limite del array de ..
 * \return Retorna -1 (ERROR) o el indice de la posicion vacia
 */

int com_getEmptyIndex (Compras* array, int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite>0){
		respuesta = 0;
		for (i=0; i<limite; i++){
			if (array[i].isEmpty == 1){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}




/*
 * \brief Ordenar el array de ... por ...
 * \param array Array de ..
 * \param limite Limite del array de ..
 * \return Retorna el
 */
/*
int com_ordenarPorNombre (Compras* array, int limite)
{
	int respuesta = -1;
	int i;
	Compras buffer;
	int flagSwap;
	if(array != NULL && limite>0)
	{
		do
		{
			flagSwap = 0;
			for (i=0; i<limite-1; i++)
			{
				if(array [i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if (strncmp(array[i].nombreArchivo, array[i+1].nombreArchivo, BARBIJOS_LEN) >0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
			}
			limite--;
		}while (flagSwap);
	}
	return respuesta;
}
*/
/*
 * \brief Ordenar el array de ... por ... y por ..
 * \param array Array de ..
 * \param limite Limite del array de ..
 * \return Retorna el
 */
/*
int com_ordenarPorNombreAltura (Compras* array, int limite)
{
	int respuesta = -1;
		int i;
		Compras buffer;
		int flagSwap;
		if(array != NULL && limite>0)
		{
			do
			{
				flagSwap = 0;
				for (i=0; i<limite-1; i++)
				{
					if(array [i].isEmpty || array[i+1].isEmpty)
					{
						continue;
					}
					if (strncmp(array[i].nombreArchivo, array[i+1].nombreArchivo, BARBIJOS_LEN) >0 ||
						(strncmp(array[i].nombreArchivo, array[i+1].nombreArchivo, BARBIJOS_LEN) ==0 &&
						array[i].dias > array [i+1].dias))
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1] = buffer;
					}
				}
				limite--;
			}while (flagSwap);
		}
		return respuesta;
}
*/
int com_altaArrayForzada (Compras* array, int limite, int indice, int cantBarbijos,
							char* colorBarbijos, char* direccion,int* idCompra,
							 int idCliente, int estadoDeCompra/*, int importePorUnidad*/)
{
	int respuesta = -1;
	Compras bufferCompra;

	if (array != NULL && limite >0 && indice <limite && indice >= 0 && idCompra!= NULL)
	{
		strncpy(bufferCompra.colorBarbijos, colorBarbijos, COLOR_BARBIJO);
		strncpy(bufferCompra.direccion, direccion, DIRECCION_LEN);
		bufferCompra.cantBarbijos = cantBarbijos;
		bufferCompra.idCompra = *idCompra;
		bufferCompra.idCliente =idCliente;
		bufferCompra.estadoDeCompra = estadoDeCompra;
		//bufferCompra.importePorUnidad = importePorUnidad;
		bufferCompra.isEmpty=0;
		array[indice] = bufferCompra;
		(*idCompra)++;
		respuesta = 0;
	}
	return respuesta;
}


