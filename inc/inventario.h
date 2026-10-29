#ifndef INVENTARIO
#define INVENTARIO

#include "objetos.h"
#include "historial.h"

#define inventarios , inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo

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
 * @param i Variable de tipo inventario en donde crearlo.
 *
 * @return El inventario si se creo correctamente, NULL en caso contrario.
 */
inventario crear_inventario_vacio(inventario i);

/**
 * @brief Carga un inventario de un archivo texto de un guardado a una variable de tipo inventario.
 * 
 * @param i Variable de tipo inventario en donde cargarlo.
 *
 * @return El inventario si se creo correctamente, NULL en caso contrario.
 */
inventario cargar_inventario(inventario i, int numero_de_guardado);

/**
 * @brief Guarda el inventario de objetos en un archivo .txt tras cerrar sesion
 * 
 * @param i Inventario el cual guardar en el archivo .txt
 * @param numero_de_guardado  Indice de archivo de la carpeta de save en el que guardar
 */
void guardar_inventario(inventario i, int numero_de_guardado);

/**
 * @brief Inserta el objeto al inventario dado al final de la lista.
 * 
 * @param i Inventario a insertar el objeto.
 * @param o Objeto a insertar.
 *
 * @return El inventario en todos los casos.
 */
inventario insertar_objeto(inventario i, objeto_ o);

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

inventario cargar_botin(inventario botin, int numero_de_zona, int numero_de_guardado);

void tomar_objeto_de_botin(inventario i, inventario botin, objeto_ o);

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
void eliminar_inventario(inventario i);

#endif
