#ifndef INVENTARIO
#define INVENTARIO

#include "objetos.h"

typedef struct nodo_objeto* puntero_a_nodo_objeto;
typedef puntero_a_nodo_objeto inventario;
typedef puntero_a_nodo_objeto posicion;

/**
 * @brief Estructura del inventario
 * 
 * Cada campo indica las caracteristicas de un nodo del inventario.
 */
struct nodo_objeto
{
    objeto_ objeto;
    puntero_a_nodo_objeto siguiente;
};

/**
 * @brief Crea un inventario a una variable de tipo inventario.
 * 
 * @return El inventario si se creo correctamente, NULL en caso contrario.
 */
inventario crear_inventario_vacio(inventario i);

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
inventario usar_objeto(inventario i, int id);

/**
 * @brief Busca un objeto por id en el inventario dado.
 * 
 * @param i Inventario a buscar el objeto.
 * @param id id para buscar el objeto.
 *
 * @return La variable posicion del objeto si es encontrado, NULL en caso contrario.
 */
posicion encontrar_objeto_por_id(inventario i, int id);

/**
 * @brief Busca el objeto anterior al objeto indicado por id en el inventario dado.
 * 
 * @param i Inventario a buscar el objeto.
 * @param id id para buscar el objeto anterior.
 *
 * @return La variable posicion del objeto anterior si es encontrado, NULL en caso contrario.
 */
posicion encontrar_objeto_anterior_por_id(inventario i, int id);

/**
 * @brief Busca un objeto por nombre en el inventario dado.
 * 
 * @param i Inventario a buscar el objeto.
 * @param nombre Nombre para buscar un objeto.
 *
 * @return La variable posicion del objeto si es encontrado, NULL en caso contrario.
 */
posicion encontrar_objeto_por_nombre(inventario i, char* nombre);

/**
 * @brief Busca el objeto anterior al objeto indicado por nombre en el inventario dado.
 * 
 * @param i Inventario a buscar el objeto.
 * @param nombre Nombre para buscar el objeto anterior.
 *
 * @return La variable posicion del objeto si es encontrado, NULL en caso contrario.
 */
posicion encontrar_objeto_anterior_por_nombre(inventario i, char* nombre);

/**
 * @brief Comprueba si el inventario está vacio 
 * 
 * @param inventario Indice del archivo a guardar
 * @return 1 si esta vacio, 0 si no esta vacio o si es nulo.
 */
bool inventario_vacio(inventario i);

/**
 * @brief Imprime todos los objetos del inventario en orden de primer.
 */
void imprimir_objetos(inventario i);

/**
 * @brief Elimina el objeto indicado del inventario.
 *
 * @param i Inventario en donde se elimina un objeto.
 * @param o Objeto a eliminar.
 */
void eliminar_objeto_por_id(inventario i, int id);
/**
 * @brief Elimina el inventario dado.
 *
 * Corre un bucle que libera la memoria asignada del ultimo nodo hasta alcanzar la cabecera,
 * acto seguido, libera su memoria.
 *
 * @param i Inventario a eliminar.
 */
inventario eliminar_inventario(inventario i);

#endif
