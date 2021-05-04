/*
 * Informes.h
 *
 *  Created on: 27 abr. 2021
 *      Author: ludmi
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_realizarComprasArray(Compras* arrayCompra, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int indice, int* idCompras, int idCliente);
int info_pagarCompra(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCliente);
int info_cancelarCompra(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCompra);
int info_imprimirComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCliente);
void info_bajaDeCliente(Cliente* arrayCliente,int limiteCliente,Compras* arrayCompras,int auxiliarId,int limiteCompras);
int cli_clienteConCompras (Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCompra);
int info_imprimirClientes(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCliente);

int info3_imprimirSoloComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente,  int idCliente);
int info_borrarComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente,  int idCliente);
int info_colorBarbijoMasComprado(Compras* arrayCompras, int limiteCompras);

int info_cantComprasPendientes(Compras* arrayCompras, int limiteCompras);
int info_compraPrecioPorUnidadMin(Compras* arrayCompras, int limiteCompras);

#endif /* INFORMES_H_ */
