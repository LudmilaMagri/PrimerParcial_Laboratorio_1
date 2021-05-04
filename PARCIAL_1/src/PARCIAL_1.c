/*
 ============================================================================
 Name        : PARCIAL_1.c
 Author      : LUDMILA MAGRI
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Compras.h"
#include "Informes.h"
#include "utn.h"

#define CLI_LEN 100
#define COM_LEN 1000

int main(void) {

	setbuf(stdout, NULL);

	Cliente arrayCliente[CLI_LEN];
	Compras arrayCompra [COM_LEN];
	int idCliente = 0;
	int idCompra = 0;
	int opcionMenu;
	int auxiliarIndice = 0;
	int auxiliarIndiceCompra;
	int auxiliarId;
	int opcionSubMenu;

	if (cli_inicializarArray(arrayCliente, CLI_LEN) == 0)
	{
		printf ("Array inicializado correctamente.");
	}
	if (com_inicializarArray(arrayCompra, COM_LEN)== 0)
	{
		printf ("\nArray inicializado correctamente.");
	}
	cli_altaArrayForzada(arrayCliente, CLI_LEN, 0, &idCliente, "Ludmila", "Magri", "11-11111111-2");
	cli_altaArrayForzada(arrayCliente, CLI_LEN, 1, &idCliente, "Harry", "Potter", "22-33232323-2");
	cli_altaArrayForzada(arrayCliente, CLI_LEN, 2, &idCliente, "Robert", "Pattinson", "54-44444444-4");
	cli_altaArrayForzada(arrayCliente, CLI_LEN, 3, &idCliente, "Tom", "Riddle", "56-55555555-5");
	cli_altaArrayForzada(arrayCliente, CLI_LEN, 4, &idCliente, "Ricardo", "Fort", "23-33333333-3");

	com_altaArrayForzada(arrayCompra, COM_LEN, 0, 10, "azul", "Defensa 123", &idCompra, 1, 1, 100);
	com_altaArrayForzada(arrayCompra, COM_LEN, 1, 35, "blanco", "Tacuari 555" , &idCompra, 2, 0, 60);
	com_altaArrayForzada(arrayCompra, COM_LEN, 2, 20, "blanco", "Piedras 100", &idCompra, 3, 0, 10);
	com_altaArrayForzada(arrayCompra, COM_LEN, 3, 80, "azul" , "Pilcomayo 700",&idCompra, 4, 0, 700);
	com_altaArrayForzada(arrayCompra, COM_LEN, 4, 50, "azul", "Peru 234", &idCompra, 0, 1, 232);


	do
	{
		if (!utn_getNumeroInt(&opcionMenu,
							"\n\n"
							"\n--------------------------------------------------"
							"\n		***** MENU *****							\n"
							"\n*	1.  Alta de cliente"
							"\n*	2.  Modificar datos de cliente"
							"\n*	3.  Baja de cliente"
							"\n*	4.  Realizar compra"
							"\n*	5.  Pagar compra"
							"\n*	6.  Cancelar compra"
							"\n*	7.  Imprimir Clientes"
							"\n*	8.  Listar compras"
							"\n*	0. Salir"
							"\n------------------------------------------------\n",
							"\nError opcion invalida", 0, 11, 2))
		{
			switch (opcionMenu)
			{
			case 1:
					cli_cargarCliente(arrayCliente, CLI_LEN, auxiliarIndice, &idCliente);
					break;
			case 2:
					cli_cargarModificarArray(arrayCliente, CLI_LEN, auxiliarIndice);
					break;
			case 3:
					info_bajaDeCliente(arrayCliente, CLI_LEN, arrayCompra, auxiliarId, COM_LEN);
					break;
			case 4:
					auxiliarIndiceCompra = com_getEmptyIndex(arrayCompra, COM_LEN);
					if (auxiliarIndiceCompra>= 0)
					{
						info_realizarComprasArray(arrayCompra, COM_LEN, arrayCliente, CLI_LEN, auxiliarIndiceCompra, &idCompra, idCliente);
					}
					break;
			case 5:
					if (utn_getNumeroInt(&auxiliarId, "\nIngrese un ID de compra\n", "\nError\n", 0, 1000, 3)== 0)
					{
						info_pagarCompra(arrayCompra, COM_LEN, arrayCliente, CLI_LEN, auxiliarId);
					}
					break;
			case 6:
					if (utn_getNumeroInt(&auxiliarId, "\nIngrese un ID de compra\n", "\nError\n", 0, 1000, 3)== 0)
					{
						info_cancelarCompra(arrayCompra, COM_LEN, arrayCliente, CLI_LEN, auxiliarId);
					}
					break;
			case 7:
					info_imprimirClientes(arrayCompra, COM_LEN, arrayCliente, CLI_LEN, idCliente);
					break;
			case 8:
					do
					{
						if(!utn_getNumeroInt(&opcionSubMenu,
											"\n\n"
											"\n**************************************************"
											"\n|		***** SUB-MENU *****					\n"
											"\n|	1.  Color de barbijo mas comprado"
											"\n|	2.  Cantidad de compras pendientes"
											"\n|	3.  Compra con “precio por unidad” mas bajo"
											"\n|	4. 	Volver al menu principal"
											"\n*************************************************\n",
											"\nError opcion invalida", 0, 5, 2))
						{
					switch (opcionSubMenu)
					{
						case 1:
							info_colorBarbijoMasComprado(arrayCompra, COM_LEN);
							break;
						case 2:
							info_cantComprasPendientes(arrayCompra, COM_LEN);
							break;
						case 3:
							 info_compraPrecioPorUnidadMin(arrayCompra, COM_LEN);
							break;
					}
						}

					}
					while(opcionSubMenu!=4);

					break;
			}
		}
	}while (opcionMenu !=0);

	if (opcionMenu == 0)
		printf ("\n*****¡¡¡HASTA LUEGO!!!*****");

	return EXIT_SUCCESS;
}
