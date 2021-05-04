/*
 * Pantalla.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "utn.h"
#include "Compras.h"
#define CLI_LEN 100



/*
 * \brief Imprime los datos de..
 * \param pElemento Puntero al elemento que se busca imprimir
 * \param limite Limite del array de ..
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_imprimir (Cliente* pElemento)
{
	int retorno = -1;
	if (pElemento != NULL && pElemento->isEmpty == 0){
		retorno = 0;
		printf ("\n ID CLIENTE: %-15d NOMBRE: %-15s APELLIDO: %-15s CUIT: %-15s",pElemento->idCli, pElemento->nombre, pElemento->apellido, pElemento->cuit);
	}
	return retorno;
}
/*
 * \brief Imprime el array de...
 * \param array Array de ... a ser actualizado
 * \param limite Limite del array de ..
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_imprimirArray (Cliente* array, int limite)
{
	int retorno = -1;
	int i;
	if (array != NULL && limite >0){
		retorno = 0;
		for (i=0; i<limite; i++)
		{
			cli_imprimir(&array [i]);
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
int cli_inicializarArray (Cliente* array, int limite)
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
int cli_altaArray(Cliente* array, int limite, int indice, int* id)
{
	int retorno = -1;
	Cliente bufferPant;
	if (array != NULL && limite>0 && indice<limite && indice >= 0 && id != NULL){
		if (utn_getNombre(bufferPant.nombre,NOMBRE_LEN, "\nIngrese nombre", "\nError", 3)==0 &&
			utn_getNombre(bufferPant.apellido, APELLIDO_LEN, "\nIngrese apellido?:", "\nError", 3) ==0 &&
			utn_getCuit(bufferPant.cuit, CUIT_LEN, "\nIngrese cuit [xx-xxxxxxxx-x]", "\nError", 3)==0)
		{
			bufferPant.idCli =*id;
			bufferPant.isEmpty = 0;
			array[indice] = bufferPant;
			(*id)++;
			retorno = 0;
		}
	}
	return retorno;
}
/*
 * \brief Actualiza los datos del cliente en una posicion del array
 * \param array Array de clientes a ser actualizados
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int cli_modificarArray (Cliente* array, int limite, int indice)
{
	int retorno = -1;
	Cliente bufferPant;
	if (array!=NULL && limite>0 && indice<limite && indice>=0 && array[indice].isEmpty ==0){
		if (utn_getNombre(bufferPant.nombre,NOMBRE_LEN, "\nIngrese nombre", "\nError", 3)==0 &&
			utn_getNombre(bufferPant.apellido, APELLIDO_LEN, "\nIngrese apellido?:", "\nError", 3) ==0 &&
			utn_getCuit(bufferPant.cuit, CUIT_LEN, "\nIngrese cuit [xx-xxxxxxxx-x]", "\nError", 3)==0)
		{
			bufferPant.idCli = array[indice].idCli;
			bufferPant.isEmpty = 0;
			array[indice] = bufferPant;
			retorno = 0;
		}
	}
	return retorno;
}
/*
 * \brief Actualiza los datos del cliente en una posicion del array
 * \param array Array de clientes a ser actualizados
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_cargarModificarArray (Cliente* array, int limite, int indice)
{
	int retorno = 0;
	int posicion;
	int modificoArray;
	int valorBuscado;

	if (array != NULL && limite >0 && indice < limite && indice >= 0)
	{
		cli_imprimirArray(array, CLI_LEN);
		if (utn_getNumeroInt(&valorBuscado,"\n Indique el ID del cliente a modificar", "\n Id invalido", 0, CLI_LEN, 2)==0)
		{
			posicion = cli_buscarId(array, CLI_LEN, valorBuscado);
		}
			modificoArray = cli_modificarArray(array, CLI_LEN, posicion);
			if (modificoArray == 0)
			{
				printf ("\n Modificacion realizada con exito \n");
				retorno = 1;
			}
	}
		return retorno;
}

/*
 * \brief Actualiza una posicion del array
 * \param array Array de... a ser actualizados
 * \param limite Limite del array de ..
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_bajarArray (Cliente* array, int limite, int indice)
{
	int retorno = -1;

	if (array != NULL && limite >0 && indice <limite && indice >= 0 && array[indice].isEmpty ==0){
		array[indice].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}
/*
 * Baja de cliente: Se ingresa el ID del cliente y
 * se listarán todas las compras de dicho cliente.
 *  Luego se preguntará si se quiere confirmar la eliminación,
 *  la cual implicará la eliminación de todas las compras y del cliente*/
/*int cli_darDeBajaArray (Cliente* array, int limite, int indice)
{
	int retorno = 0;
	int posicion;
	int bajarArrayCli;
	int bajarArrayCom;
	int valorBuscado;

	if (array != NULL && limite >0 && indice < limite && indice >= 0)
	{
		cli_imprimirArray(array, CLI_LEN);
		if (utn_getNumeroInt(&valorBuscado,"\n Indique el ID del cliente que desea eliminar", "\n Id invalido", 0, CLI_LEN, 2)==0)
		{
			posicion = cli_buscarId(array, CLI_LEN, valorBuscado);
		}
			com_imprimirArray(array, limite, posicion);

			bajarArrayCli = cli_bajarArray(array, CLI_LEN, posicion);
			bajarArrayCom = com_bajarArray(array, COM_LEN, posicion);
			if (bajarArrayCli == 0 && bajarArrayCom ==0)
			{
				printf ("\n Eliminacion de cliente exitosa \n");
				retorno = 1;
			}
	}
		return retorno;

}
*/

/*
 * \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array Array de...
 * \param limite Limite del array de ..
 * \param valorBuscado Valor que ingreso el usuario a ser buscado
 * \return Retorna -1 (ERROR) o la posicion del indice en la que se encuentre el id (EXITO)
 */

int cli_buscarId (Cliente* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite>0 && valorBuscado>=0){
		for (i=0; i<limite; i++){
			if (array[i].idCli == valorBuscado){
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

int cli_getEmptyIndex (Cliente* array, int limite)
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
 * \return Retorna
 */
/*
int cli_ordenarPorNombre (Cliente* array, int limite)
{
	int respuesta = -1;
	int i;
	Cliente buffer;
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
				if (strncmp(array[i].nombre, array[i+1].nombre, NOMBRE_LEN) >0)
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
int cli_ordenarPorNombreAltura (Cliente* array, int limite)
{
	int respuesta = -1;
		int i;
		Cliente buffer;
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
					if (strncmp(array[i].nombre, array[i+1].nombre, NOMBRE_LEN) >0 ||
						(strncmp(array[i].nombre, array[i+1].nombre, NOMBRE_LEN) ==0 &&
						array[i].precio > array [i+1].precio))
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
int cli_altaArrayForzada (Cliente* array, int limite, int indice, int* id, char* nombre, char* apellido, char* cuit)
{
	int respuesta = -1;
	Cliente bufferPantalla;

	if (array != NULL && limite >0 && indice <limite && indice >= 0 && id != NULL)
	{
		strncpy(bufferPantalla.apellido, apellido, APELLIDO_LEN);
		strncpy(bufferPantalla.nombre, nombre, BARBIJOS_LEN);
		strncpy(bufferPantalla.cuit, cuit, CUIT_LEN);
		respuesta = 0;
		bufferPantalla.idCli = *id;
		bufferPantalla.isEmpty=0;
		array[indice] = bufferPantalla;
		(*id)++;
	}
	return respuesta;
}


int cli_cargarAuxIndice (Cliente* array, int limite, int indice, int* id)
{
   int auxiliarIndice;
   auxiliarIndice= cli_getEmptyIndex(array, limite);
    return auxiliarIndice;
}

/* Valido si existe lugar en pantalla */
void cli_cargarCliente(Cliente* array, int limite, int indice, int* id)
 {
	indice = cli_cargarAuxIndice(array, limite, indice, id);
    if (indice >= 0 )
     {
    	cli_altaArray(array, limite, indice, id);
    	cli_imprimirArray(array, limite);
     }
}

