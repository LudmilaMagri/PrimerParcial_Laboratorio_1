/*
 * Informes.c
 *
 *  Created on: 27 abr. 2021
 *      Author: ludmi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compras.h"
#include "utn.h"
#include "Cliente.h"
#include "Informes.h"
#define COM_LEN 1000
#define CLI_LEN 100
static const char ESTADO [2][10] ={"PENDIENTE","COBRADA"};

/*
 * \brief Imprime las compras realizadas por un cliente con los datos del cliente
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param idCliente Id del cliente a comparar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int info_imprimirComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCliente)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int auxIdCompra;
	int contadorCompras =0;
	if (arrayCompras!= NULL && limiteCompras>=0 &&arrayCliente != NULL && limiteClientes>=0)
	{
		for (i=0; i<limiteCompras; i++)
		{
			if (arrayCompras[i].isEmpty==0)
			{
				if (arrayCompras[i].idCliente == idCliente)//comparo a ver si son iguales el id que ingreso el usuario
				{
					auxIdCompra = arrayCompras[i].idCliente;  //del array de compras obtengo el id de ese cliente
					indiceArrayCliente= cli_buscarId(arrayCliente, limiteCompras, auxIdCompra);
					printf ("\nID COMPRA: %-5d - CANT DE BARBIJOS: %-5d- DIRECCION: %-15s - COLOR: %-5s - ID CLI: %-5d - ESTADO: %-10s - IMPORTE POR UNIDAD: %-5.2f", arrayCompras[i].idCompra, arrayCompras[i].cantBarbijos , arrayCompras[i].direccion,arrayCompras[i].colorBarbijos, arrayCompras[i].idCliente, ESTADO[arrayCompras[i].estadoDeCompra], arrayCompras[i].importePorUnidad);
					contadorCompras++;
				}
			}
		}
	}
	printf ("\nID CLI: %-5d	- NOMBRE: %-10s	- APELLIDO: %-10s - CUIT: %-10s\n", arrayCliente[indiceArrayCliente].idCli, arrayCliente[indiceArrayCliente].nombre, arrayCliente[indiceArrayCliente].apellido, arrayCliente[indiceArrayCliente].cuit);
	printf ("Cantidad de Compras: %d\n", contadorCompras);
	return retorno;
}
/*
 * \brief Imprime solo las compras realizadas por un cliente
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param idCliente Id del cliente a comparar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int info3_imprimirSoloComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente,  int idCliente)
{
	int retorno = -1;
	int i;

	if (arrayCompras!= NULL && limiteCompras>=0 &&arrayCliente != NULL && arrayCompras[idCliente].isEmpty == 0)
	{
		for (i=0; i<limiteCompras; i++)
		{
			if (arrayCompras[i].isEmpty==0)
			{
				if (arrayCompras[i].idCliente == idCliente)//comparo a ver si son iguales el id que ingreso el usuario
				{
					printf ("\nID COMPRA: %-10d - DIRECCION: %-15s - COLOR: %-10s  - ID CLI: %-10d - ESTADO: %-10s \n", arrayCompras[i].idCompra, arrayCompras[i].direccion,arrayCompras[i].colorBarbijos, arrayCompras[i].idCliente, ESTADO[arrayCompras[i].estadoDeCompra]);

				}
			}
		}
	}
	return retorno;
}
/*
 * \brief Da de alta una compra
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param indice Indice del array
 * \param idCompras Puntero al id de Compras
 * \param idCliente Id del cliente
 * \return Retorna 1 (EXITO) y -1 (ERROR)
 */
int info_realizarComprasArray(Compras* arrayCompra, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int indice, int* idCompras, int idCliente)
{
	int retorno = 0;
	if (indice>= 0 )
	{
		if (utn_getNumeroInt(&idCliente, "\nIngrese el ID de cliente\n", "\nID inválido\n", 0, idCliente, 2)== 0 &&
					cli_buscarId(arrayCliente, limiteCliente, idCliente)!= -1)
		{
			com_altaArray(arrayCompra, limiteCompras, indice, *idCompras, idCliente);
		(*idCompras)++;
			retorno = 1;
		}
	}
	else{
		printf ("\nId inválido\n");
	}
	return retorno;
}
/*
 * \brief Compara el id de compra ingresado con el array de compras,
 * 			imprime las compras y los datos del cliente asociado
 * 			calcula el importe por unidad y cambia el estado de la
 * 			compra a "COBRADO"
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param idCompra Id de la compra a comparar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int info_pagarCompra(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCompra)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int auxIdCliente;
	float importe;
	int respuesta;
	if (arrayCompras!= NULL && limiteCompras>=0 &&arrayCliente != NULL && limiteClientes>=0)
	{
		for (i=0; i<limiteCompras; i++)
		{
			if (arrayCompras[i].isEmpty==0  && arrayCompras[i].estadoDeCompra == 0)
			{
				if (arrayCompras[i].idCompra == idCompra)//comparo a ver si son iguales el id que ingreso el usuario
				{
					auxIdCliente = arrayCompras[i].idCliente;  //del array de compras obtengo el id de ese cliente
					indiceArrayCliente= cli_buscarId(arrayCliente, limiteCompras, auxIdCliente); //busco en el array de clientes el indice donde estan los datos de esos clie
					printf ("\nID COMPRA: %-10d - CANT DE BARBIJOS: %-10d - DIRECCION: %-10s - COLOR: %-10s - ID CLI: %-10d - ESTADO: %-10s \n", arrayCompras[i].idCompra, arrayCompras[i].cantBarbijos,arrayCompras[i].direccion,arrayCompras[i].colorBarbijos, arrayCompras[i].idCliente, ESTADO[arrayCompras[i].estadoDeCompra]);
					printf ("\nID CLI: %-10d - NOMBRE: %-10s - APELLIDO: %-10s - CUIT: %-10s\n", arrayCliente[indiceArrayCliente].idCli, arrayCliente[indiceArrayCliente].nombre, arrayCliente[indiceArrayCliente].apellido, arrayCliente[indiceArrayCliente].cuit);
					if (utn_getNumeroFlotante(&importe, "\nIngrese importe a pagar\n", "Error", 0, 300000, 3)==0)
					{
						if (importe >0 &&utn_getNumeroInt(&respuesta, "\nDesea cambiar el estado de la compra a 'COBRADO' [1: SI / 2: NO]\n?", "\nError\n", 0, 2, 3)== 0)
						{
							if (respuesta == 1)
							{
								arrayCompras[i].importePorUnidad = importe/ arrayCompras[i].cantBarbijos;
								arrayCompras [i].estadoDeCompra = 1;
								retorno = 1;
								printf ("\nID COMPRA: %-10d - CANT DE BARBIJOS: %-10d - DIRECCION: %-10s - COLOR: %-10s - ID CLI: %-10d - ESTADO: %-10s- IMPORTE POR BARBIJO: $%-10.2f\n", arrayCompras[i].idCompra, arrayCompras[i].cantBarbijos, arrayCompras[i].direccion,arrayCompras[i].colorBarbijos, arrayCompras[i].idCliente, ESTADO[arrayCompras[i].estadoDeCompra], arrayCompras[i].importePorUnidad);
								printf ("\nCompra realizada exitosamente");
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
/*
 * \brief Compara el id de compra ingresado con el array de compras,
 * 			imprime las compras y los datos del cliente asociado
 * 			da de baja esa compra solo si esta en estado "PENDIENTE".
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param idCompra Id de la compra a comparar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int info_cancelarCompra(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCompra)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int auxIdCliente;
	int respuesta;
	if (arrayCompras!= NULL && limiteCompras>=0 &&arrayCliente != NULL && limiteClientes>=0)
	{
		for (i=0; i<limiteCompras; i++)
		{
			if (arrayCompras[i].isEmpty==0)
			{
				if (arrayCompras[i].idCompra == idCompra)//comparo a ver si son iguales el id que ingreso el usuario
				{
					auxIdCliente = arrayCompras[i].idCliente;  //del array de compras obtengo el id de ese cliente
					indiceArrayCliente= cli_buscarId(arrayCliente, limiteCompras, auxIdCliente); //busco en el array de clientes el indice donde estan los datos de esos clie
					printf ("\nID COMPRA: %-10d- CANT DE BARBIJOS: %-10d - DIRECCION: %-10s - COLOR: %-10s - ID CLI: %-10d - ESTADO: %-10s \n", arrayCompras[i].idCompra, arrayCompras[i].cantBarbijos,arrayCompras[i].direccion,arrayCompras[i].colorBarbijos, arrayCompras[i].idCliente, ESTADO[arrayCompras[i].estadoDeCompra]);
					printf ("\nID CLI: %-10d - NOMBRE: %-10s - APELLIDO: %-10s - CUIT: %-10s\n", arrayCliente[indiceArrayCliente].idCli, arrayCliente[indiceArrayCliente].nombre, arrayCliente[indiceArrayCliente].apellido, arrayCliente[indiceArrayCliente].cuit);

					if (utn_getNumeroInt(&respuesta, "\nDesea cancelar la compra [1: SI / 2: NO]?\n", "\nError\n", 0, 2, 3)== 0)
					{
						if (respuesta == 1 && arrayCompras[i].estadoDeCompra == 0)
						{
							com_bajarArray(arrayCompras, limiteCompras, i);
							retorno = 1;
							printf ("\nEliminacion exitosa\n");
						}
						else
						{
							printf ("\nError, la compra ya esta cobrada\n");
						}
					}
				}
			}
		}
	}
	return retorno;
}
/*
 * \brief Compara el id de cliente ingresado con el array de clientes,
 * 			pone un vacio a la posicion del array de Clientes que coincide con
 * 			lo ingresado.
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param idCompra Id de la compra a comparar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int info_borrarComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente,  int idCliente)
{
	int retorno = -1;
	int i;
	if (arrayCompras!= NULL && limiteCompras>=0 &&arrayCliente != NULL && arrayCompras[idCliente].isEmpty == 0)
	{
		for (i=0; i<limiteCompras; i++)
		{
			if (arrayCompras[i].isEmpty==0)
			{
				if (arrayCompras[i].idCliente == idCliente)//comparo a ver si son iguales el id que ingreso el usuario
				{
					arrayCompras[i].isEmpty = 1;
				}
			}
		}
	}
	return retorno;
}
/*
 * \brief Imprime el array de Clientes y las compras de ese cliente.
 * 		 Da de baja a un cliente
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \param arrayCliente Array de la estructura Cliente
 * \param limiteCliente Limite del array de clientes
 * \param auxiliarId Id a comparar
 */
void info_bajaDeCliente(Cliente* arrayCliente,int limiteCliente,Compras* arrayCompras,int auxiliarId,int limiteCompras)
{
	int respuesta;
	cli_imprimirArray(arrayCliente, limiteCliente);

	if(utn_getNumeroInt(&auxiliarId, "\nIngrese id de cliente\n", "\nError\n",0,10000, 3)==0)
	{
		info3_imprimirSoloComprasPorCliente(arrayCompras, limiteCliente, arrayCliente, auxiliarId);
	}
	printf ("\nEsta seguro que desea eliminar al usuario: %s %s ?",arrayCliente[auxiliarId].nombre, arrayCliente[auxiliarId].apellido);
	if (utn_getNumeroInt(&respuesta, "\n[SI: 1 / NO: 0)\n", "Error", 0, 2, 3)==0)
	{
		if (respuesta == 1)
		{
			cli_bajarArray(arrayCliente, limiteCliente, auxiliarId);
			info_borrarComprasPorCliente(arrayCompras, limiteCliente, arrayCliente, auxiliarId);
			printf ("Se eliminó exitosamente al usuario %s %s", arrayCliente[auxiliarId].nombre, arrayCliente[auxiliarId].apellido);
		}
	}
}
/*
 * \brief Cuenta e imprime el barbijo mas comprado.
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int info_colorBarbijoMasComprado(Compras* arrayCompras, int limiteCompras)
{
	int retorno = -1;
	//char listaBarbijos [4][COLOR_BARBIJO];
	int i;
	int contadorAzul= 0;
	int contadorBlanco = 0;
	int flag;
	int j;
	int indiceColorLibre = 0;
	char listaColor [COM_LEN][COLOR_BARBIJO];
	int contador= 0;
	for (i=0; i<limiteCompras;i++)
	{
		flag= 0;
		if (arrayCompras[i].isEmpty == 0)
		{	for (j=0; j<indiceColorLibre; j++)
			{
				if (strncmp(arrayCompras[i].colorBarbijos, listaColor[j], COLOR_BARBIJO) == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				strncpy(listaColor[indiceColorLibre], arrayCompras[i].colorBarbijos, COLOR_BARBIJO);
				indiceColorLibre++;
				contador++;
			}
			if (strncmp(arrayCompras[i].colorBarbijos, "azul" , COLOR_BARBIJO)==0)
			{
				contadorAzul++;
			}
			else if (strncmp(arrayCompras[i].colorBarbijos, "blanco", COLOR_BARBIJO)==0)
			{
				contadorBlanco++;
			}
		}
	}
	if (contadorAzul> contadorBlanco)
	{
		printf ("\nEl color de barbijo que tuvo mas compras fue el color azul.\n"
				"Total de compras con barbijos azules: %d\n ", contadorAzul);
	}
	else if(contadorAzul< contadorBlanco)
	{
		printf ("\nEl color de barbijo que tuvo mas compras fue el color blanco.\n"
				"Total de compras con barbijos blancos: %d\n ", contadorBlanco);
	}
	else
	{
		printf ("\nSe compro la misma cantidad de colores\n");
	}
	return retorno;
}
/*
 * \brief Cuenta e imprime la cantidad de compras en estado "PENDIENTE"
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \return Retorna 1 (EXITO) y -1 (ERROR)
 */

int info_cantComprasPendientes(Compras* arrayCompras, int limiteCompras)
{
	int retorno = -1;
	int i;
	int contadorCompras =0;
	if (arrayCompras!= NULL && limiteCompras>=0)
	{
		for (i=0; i<limiteCompras; i++)
		{
			if (arrayCompras[i].isEmpty==0)
			{
				if (arrayCompras[i].estadoDeCompra == 0)
				{
					contadorCompras++;
					retorno= 1;
				}
			}
		}
		printf ("\nCantidad de Compras pendientes: %d\n", contadorCompras);
	}
	return retorno;
}
/*
 * \brief Imprime el precio por unidad mas bajo
 * \param arrayCompras Array de la estructura Compras
 * \param limiteCompras Limite del array de Compras
 * \return Retorna 1 (EXITO) y -1 (ERROR)
 */

int info_compraPrecioPorUnidadMin(Compras* arrayCompras, int limiteCompras)
{
	Compras buffer;
	int retorno = -1;
	int i;
	int flag = 0;

	if (arrayCompras!= NULL && limiteCompras>=0)
	{
		do
		{
			flag = 0;
			for (i= 0 ; i < limiteCompras-1; i++)
			{
				if(arrayCompras [i].isEmpty == 0 && arrayCompras[i+1].isEmpty == 0 &&
						arrayCompras[i].estadoDeCompra == 1)
				{
					if (arrayCompras[i].importePorUnidad > arrayCompras[i+1].importePorUnidad)
					{
						flag = 1;
						buffer = arrayCompras[i];
						arrayCompras[i] = arrayCompras[i+1];
						arrayCompras[i+1] = buffer;
						retorno = 1;
					}
				}
			}
			limiteCompras--;
		}while(flag);
		printf ("\nCompra con el precio por unidad mas bajo: %.2f\n", arrayCompras[0].importePorUnidad);
	}
	return retorno;
}
int info_imprimirClientes(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCliente)
{
	int retorno = -1;
	char listaCliente[CLI_LEN];
	int i;
	int j;
	int flagCliente;
	int indiceClienteLibre =0;
	for (i=0; i<limiteCompras;i++)
	{
		flagCliente = 0;
		if (arrayCompras[i].isEmpty==0)
		{
			for (j=0; j<indiceClienteLibre;j++)
			{
				if (arrayCompras[i].idCliente == listaCliente[j])
				{
					flagCliente = 1;
					break;
				}
			}
			if (flagCliente ==0)
			{
				listaCliente[indiceClienteLibre] = arrayCompras[i].idCliente;
				indiceClienteLibre++;
			}
		}
	}
	for(j=0; j<indiceClienteLibre;j++)
	{
		printf ("\n\n******EL CLIENTE CON ID:  %d ******\n", listaCliente[j]);
		info_imprimirComprasPorCliente(arrayCompras, limiteCompras, arrayCliente, limiteCliente, listaCliente[j]);
	}
return retorno;
}



int cli_clienteConCompras (Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCompra)
{
	int retorno = -1;
	int i;
	if (arrayCliente != NULL && limiteCliente >0){
		retorno = 0;
		for (i=0; i<limiteCliente; i++)
		{
			cli_imprimir(&arrayCliente [i]);
		}
	}
	return retorno;
}

