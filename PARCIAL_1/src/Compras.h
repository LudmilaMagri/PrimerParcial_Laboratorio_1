/*
 * Contratacion.h
 */

#ifndef COMPRAS_H_
#define COMPRAS_H_

#define COLOR_BARBIJO 32
#define DIRECCION_LEN 64

#include "utn.h"

typedef struct
{
	int cantBarbijos;
	char colorBarbijos [COLOR_BARBIJO];
	char direccion [DIRECCION_LEN];
	int isEmpty;
	int idCompra;
	int idCliente;
	int estadoDeCompra;
	float importePorUnidad;
}Compras;

int com_imprimir (Compras* pElemento);
int com_inicializarArray (Compras* array, int limite);
int com_altaArray(Compras* array, int limite, int indice, int idContratacion, int idPantalla);
int com_getEmptyIndex (Compras* array, int limite);
int com_imprimirArray (Compras* array, int limite);
int com_buscarId (Compras* array, int limite, int valorBuscado);
int com_modificarArray (Compras* array, int limite, int indice);
int com_bajarArray (Compras* array, int limite, int idCliente);
int com_ordenarPorNombre (Compras* array, int limite);

int com_altaArrayForzada (Compras* array, int limite, int indice, int cantBarbijos,
							char* colorBarbijos, char* direccion,int* idCompra,
							 int idCliente, int estadoDeCompra, int importePorUnidad);
int com_altaImporte (Compras* array, int limite, int indice);



#endif /* COMPRAS_H_ */
