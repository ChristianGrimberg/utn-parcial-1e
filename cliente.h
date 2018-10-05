#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "utn.h"
#define CLIENT_NAME_MAX 32
#define CUIT_MAX 32
#define CLIENT_INIT 1
#define CLIENT_MAX 100
#define ERROR_MESSAGE "Valor incorrecto. " /**< Mensaje de falla de reintento. */
#define ERROR_EMPTY_LIST "No hay Cliente/as en el listado.\n" /**< Mensaje lista vacia. */
#define HEADER 1 /**< Encabezado de tabla de una lista de Clientes. */
#define BODY 2 /**< Cuerpo de tabla de una lista de Clientes. */
#define FOOTER 3 /**< Pie de tabla de una lista de Clientes. */
#define FIELD_NAME 1 /**< Campo Nombre del Cliente. */
#define FIELD_LASTNAME 2 /**< Campo Apellido del Cliente. */
#define FIELD_CUIT 3 /**< Campo CUIT del Cliente. */
#define FORMAT_ID_LEN 5


/*! \struct Client
    \brief
    Tipo de dato de Cliente.
    Cliente que adquiere afiches.
*/
typedef struct
{
    int clientId;
    char name[NAME_MAX];
    char lastName[NAME_MAX];
    char cuit[CUIT_MAX];
    int isEmpty;
}Client;

/** \brief
 *  Funcion que inicializa un array de Clientes con estado vacio FALSE.
 *  \param list Client* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \return 0 si se inicializo correctamente, -1 si hubo un error.
 *
 */
int cliente_init(Client* list, int len);

/** \brief
 *  Funcion que busca el primer Cliente libre a cargar en el array.
 *  \param list Client* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \return El indice del elemento libre, -1 si no encontro elemento libre.
 *
 */
int cliente_getFirstEmptyClient(Client* clientes, int len);

/** \brief
 *  La funcion busca un Cliente en un array por el campo Id.
 *  \param list Client* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \param id int Campo Id del Cliente.
 *  \return El indice del elemento en el array, de lo contrario devuelve -1.
 *
 */
int cliente_findClientById(Client* list, int len, int id);

/** \brief
 *  La funcion agrega un nuevo Cliente de acuerdo a los parametros ingresados
 *      en un array existente.
 *  \param list Client* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \param name char* Campo Nombre del Cliente.
 *  \param lastName char* Campo Apellido del Cliente.
 *  \param cuit char* Campo CUIT del Cliente.
 *  \return 0 si se pudo agregar el Cliente, -1 si hubo un error.
 *
 */
int cliente_addClient(Client* list, int len, char* name, char* lastName,
    char* cuit);

/** \brief
 *  La funcion obtiene la cantidad de Cliente Activos de la nomina.
 *  \param list Client* Direccion de memoria del array de Cliente.
 *  \param len int Longitud del array de Cliente.
 *  \return La cantidad de Cliente Activos, si no hay ninguno devuelve -1.
 *
 */
int cliente_getNumberOfClients(Client* list, int len);

/** \brief
 *  La funcion edita un Cliente del array mediante el ingreso del indice del Array.
 *  \param list Client* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \param index int Direccion de memoria del Indice del Array del Cliente.
 *  \param field int Campo del Cliente a modificar.
 *  \return 0 si la edicion fue correcta, -1 si hubo un error.
 *
 */
int cliente_editClientByIndex(Client* list, int len, int index, int field);

/** \brief
 *  La funcion da de baja un Cliente del array indicando si estado en FALSE
 *      como vacio.
 *  \param list Client* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \param index int Indice del Array del Cliente.
 *  \return 0 si la baja fue correcta, -1 si hubo un error.
 *
 */
int cliente_removeClientByIndex(Client* list, int len, int index);

/** \brief
 *  Imprime un elemento de un array de Clientes.
 *  \param list Employee* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \param index int Indice del Array del Cliente.
 *  \return La funcion no retorna valores.
 *
 */
void cliente_printClientByIndex(Client* list, int len, int index);

/** \brief
 *  Imprime la lista ingresada de Clientes en una tabla.
 *  \param list Employee* Direccion de memoria del array de Clientes.
 *  \param len int Longitud del array de Clientes.
 *  \return La funcion no retorna valores.
 *
 */
void cliente_printClientList(Client* list, int len);

#endif // CLIENTE_H_INCLUDED
