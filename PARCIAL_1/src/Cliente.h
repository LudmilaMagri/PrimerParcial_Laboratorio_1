/*
 * Pantalla.h
 *
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 99
#define APELLIDO_LEN 99
#define CUIT_LEN 14

#define TIPO_LCD 0
#define TIPO_LED 1

typedef struct
{
	char nombre [NOMBRE_LEN];
	char apellido [APELLIDO_LEN];
	char cuit [CUIT_LEN];
	int isEmpty;
	int idCli;
}Cliente;

int cli_imprimir (Cliente* pElemento);
int cli_inicializarArray (Cliente* array, int limite);
int cli_altaArray(Cliente* array, int limite, int indice, int* id);
int cli_getEmptyIndex (Cliente* array, int limite);
int cli_imprimirArray (Cliente* array, int limite);
int cli_buscarId (Cliente* array, int limite, int valorBuscado);
int cli_modificarArray (Cliente* array, int limite, int indice);
int cli_cargarModificarArray (Cliente* array, int limite, int indice);
int cli_bajarArray (Cliente* array, int limite, int indice);
int cli_darDeBajaArray (Cliente* array, int limite, int indice);

int cli_ordenarPorNombre (Cliente* array, int limite);

int cli_buscarIdIngresado (Cliente* array, int limite, int indice);


int cli_altaArrayForzada (Cliente* array, int limite, int indice, int* id, char* nombre, char* apellido, char* cuit);

void cli_cargarCliente (Cliente* array, int limite, int indice, int* id);
int cli_cargarAuxIndice (Cliente* array, int limite, int indice, int* id);

#endif /* CLIENTE_H_ */
