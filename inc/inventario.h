#ifndef INVENTARIO
#define INVENTARIO

#include "objetos.h"

typedef struct nodo* punt_a_nodo;
typedef punt_a_nodo inventario;
typedef punt_a_nodo posicion;

/**
 * @brief Estructura del inventario
 * 
 * Cada campo indica las caracteristicas de un nodo del inventario.
 */
struct nodo
{
    objeto_ objeto;
    punt_a_nodo sig;
};

/**
 * @brief Crea un inventario a una variable de tipo inventario.
 * 
 * @return El inventario si se creo correctamente, NULL en caso contrario.
 */
inventario crear_inventario();

/**
 * @brief Inserta el objeto al inventario dado al final de la lista.
 * 
 * @param i Inventario a insertar el objeto.
 * @param o Objeto a insertar.
 *
 * @return El inventario en todos los casos.
 */
inventario tomar_objeto(inventario i, objeto_ o);

/**
 * @brief Usa un objeto y lo elimina en caso de ser un consumible.
 * 
 * Al usar un objeto consumible, se ejecuta su efecto en el personaje o los enemigos
 * y es eliminado del inventario.
 *
 * Un objeto equipable ejecuta su efecto al ser utilizado, y no puede usarse hasta que
 * se use otro objeto equipable.
 *
 * Un objeto tipo arma ejecuta su efecto y entra en un periodo de enfriamiento (cd),
 * en el cual no puede volver a ser utilizado hasta que se termine este periodo.
 *
 * @param i Inventario a usar un objeto.
 * @param o Objeto a usar.
 *
 * @return El inventario en todos los casos.
 */
void usar_objeto(inventario i, objeto_ o);

/**
 * @brief Comprueba si el inventario está vacio 
 * 
 * @param inventario Indice del archivo a guardar
 * @return 1 si esta vacio, 0 si no esta vacio, -1 si no existe el inventario dado.
 */
bool inventario_vacio(inventario i);

/**
 * @brief Imprime todos los objetos del inventario en orden de primer.
 */
void imprimir_objetos(inventario i);

/**
 * @brief Elimina el inventario dado.
 */
void eliminar_inventario(inventario i);

#endif
