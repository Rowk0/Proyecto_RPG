#ifndef EXPLORACION
#define EXPLORACION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "personaje.h"

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
void camino(personaje_ *p);

/**
 * @brief funcion que sirve para cualquier zona que el jugador explore
 * dependiendo de que zona eligio, los objetos y enemigos se restrigen exclusivamente
 * a sus respectivas zonas
 * 
 */
void explorar_zona(personaje_ *p, int elegir_ruta);

#endif