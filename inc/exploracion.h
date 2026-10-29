#ifndef EXPLORACION
#define EXPLORACION

#include "personaje.h"
#include "inventario.h"

/**
 * @brief funcion de animacion para caminar
 * 
 * funcion hecha con ayuda de IA
 */
void caminando (void);

/**
 * @brief funcion de animacion para caminar
 * 
 * funcion hecha con ayuda de IA
 */
void cargando (void);

/**
 * @brief elegir que camino tomar
 * 
 */
void camino(personaje_ *p, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo);

/**
 * @brief funcion que sirve para cualquier zona que el jugador explore
 * dependiendo de que zona eligio, los objetos y enemigos se restrigen exclusivamente
 * a sus respectivas zonas
 * 
 */
void explorar_zona(personaje_ *p, int elegir_ruta, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo);

#endif
