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
							 int idCliente, int estadoDeCompra /*int importePorUnidad*/);
int com_altaImporte (Compras* array, int limite, int indice);


/*
//PANTALLA LCD - PEPITO - ID 1
// contratacion ID 1 CUIT 1234 PANTALLA 1 CANT 4
//contratacion ID 2 CUIT 4545 PANTALLA 2 CANT 5
//contratacion ID 3 CUIT 343  PANTALLA 1
//contratacion ID 2 CUIT 4545 PANTALLA 1 CANT 3

//PANTALLA 1 VER PRECIO 20
//CUIT 4545 1 CONTRATACION 20*5
//CUIT 1234 1 CONTRATACION 20*4
//CUIT 4545 1 CONTRATACION 20*3

//te muestro los datos de la contratacion PANTALLA 1y los imprime

//PANTALLA 1
//CONTRATACION ID 1
//CONTRATACION ID 3

char arrayCuitsUnicos [10][]

typedef struct{
	char cuit [];
	int facturado;

}CuitsFacturados;

 *
 * CONTRATACION ID 2 IDPANTALLA 2 ---> PRECIO
 *
 * buscar indiceIdPantalla
 * set (arrayPantalla, indice, precioNuevo) (set de modificar el precio)
 *
 *
 * CONTRATACION ID 2 IDPANTALLA 2 ---> CONSULTAR NOMBRE
 *
 * buscar indiceIdPantalla
 * getNombre (ArrayPantallas, indice, variable) (ver el nombre)
 *
 *
 *
 *
int con_mostrarPorIdPantalla();

int con_mostrarUnasolaContratacion();

//SET: PARA ESCRIBIR -> dar alta, modificar
//GET: PARA OBTENER

int con_getCantDias (Contratacion* array, int indice, int* pCantDias){
	int retorno = -1;
	if (array != NULL && indice>=0 && pCantDias != NULL){
		*pCantDias=array[i].dias;
		retorno = 0;
	}
	return retorno;
}

int contratacion_cantDiasMayorA20 (Contratacion* pContrataciones, int indice){
	int retorno =-1;
	if (pContrataciones!= NULL )
}


int contratacion_setCantDias (Contratacion* array, int indice, int* pCantDiasAGuardar){
	int retorno =-1;
	if (array != NULL && indice>=0 && validarDias (pCantDiasAGuardar)==0){
		array[indice].dias = *pCantDiasAGuardar;
		retorno = 0;
	}
}


int con_getCuit (Contratacion* array, int indice, int* pCuit){
	int retorno = -1;
	if (array != NULL && indice>=0 && pCuit != NULL){
		strncpy(pCuit, array[indice].cuit, CUIT_LEN);
		retorno = 0;
	}
	return retorno;
}

int contratacion_setCuit (Contratacion* array, int indice, int* pCuit){
	int retorno =-1;
	if (array != NULL && indice>=0 && validarCuit (pCuit)==0){
		strncpy(pCuit, array[indice].cuit, CUIT_LEN);
		retorno = 0;
	}
}

int contratacion_alta (){

}
*/

#endif /* COMPRAS_H_ */
