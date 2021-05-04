/*
 * Informes.h
 *
 *  Created on: 27 abr. 2021
 *      Author: ludmi
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/*
int info_imprimirPantallasContratadasByCuit(Contratacion* arrayContrataciones, int limiteContrataciones, Pantalla* arrayPantallas, int limitePantalla, char* auxCuit);

int info_imprimirContratacionesConImporte(Contratacion* arrayContrataciones, int limiteContrataciones, Pantalla* arrayPantallas, int limitePantalla, char* auxCuit);

int info_imprimirContratacionesPorCliente(Contratacion* arrayContrataciones, int limiteContrataciones, Pantalla* arrayPantallas, int limitePantalla, char* auxCuit);

int info_calcularDeudaCliente (Contratacion* arrayContrataciones, int limiteContrataciones, Pantalla* arrayPantallas, int limitePantalla, char* auxCuit, float* deuda);
*/
int info_darDeBajaArray (Cliente* arrayCliente, int limiteCliente, int indice, Compras* arrayCompra, int limiteCompra);
int info_bajar (Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int* id);
int info_cargarComprasArray(Compras* arrayCompra, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int indice, int* idCompras, int idCliente);
//int info_imprimirComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCompra);
#endif /* INFORMES_H_ */

int info_funcionMain (Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int id);
int info_pagarCompra(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCliente);
int info_cancelarCompra(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteClientes, int idCompra);
int info_imprimirComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCliente);

int cli_clienteConCompras (Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCompra);
int info_imprimirClientes(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, int idCliente);

int info3_imprimirComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente,  int idCliente);
int delete_borrarComprasPorCliente(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente,  int idCliente);
void case3(Cliente* arrayCliente,int limiteCliente,Compras* arrayCompras,int auxiliarId,int limiteCompras);
int info_colorBarbijoMasComprado(Compras* arrayCompras, int limiteCompras, Cliente* arrayCliente, int limiteCliente, char* color);

int info_cantComprasPendientes(Compras* arrayCompras, int limiteCompras);
int info_compraPrecioPorUnidadMin(Compras* arrayCompras, int limiteCompras);

