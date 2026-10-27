#ifndef OBJETOS
#define OBJETOS

#include <stdbool.h>

#define EQUIPABLE 1
#define CONSUMIBLE 2
#define ACCESORIO 3

#define BANDANA_NINJA 1
#define ARO_CARMESI 2
#define CORONA 3

/**
 * @brief Estructura de objetos
 * 
 * Cada campo indica las caracteristicas del objeto
 * 
 * id: Identificador del objeto. Utilizado para usar un objeto dado.
 * nombre: Nombre del objeto.
 * descripcion: Describe la funcionalidad del objeto en cuestion.
 */
typedef struct 
{
    int id;
	int clase;
	char* nombre;
	char* descripcion;
} objeto_;

/**
 * @brief Crea un objeto.
 * 
 * Se crearan los objetos antes de comenzar el juego.
 */
objeto_ crear_objeto(int id, int clase, char* nombre, char* descripcion);

/**
 * @brief Imprime los atributos del objeto en pantalla.
 *
 * @param o Objeto a analizar.
 */
void analizar_objeto(objeto_ o);

/**
 * @brief Elimina un objeto.
 *
 * @param o Instancia de objeto.
*/
void liberar_objeto(objeto_ o);

#endif
