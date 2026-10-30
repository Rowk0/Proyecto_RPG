#ifndef ACCIONES
#define ACCIONES

#include "personaje.h"
#include "inventario.h"

/**
 * @brief Funcion que calcula el mejor arma del inventario del pesonaje y pone el accesorio de mayor id en su campo
 * 
 * @param p Personaje al que equipar
 * @param inv Inventario a explorar objetos
 */
void actualizar_equipo(personaje_ *p, inventario inv);

#endif
