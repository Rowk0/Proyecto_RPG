#ifndef COMMONS
#define COMMONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief Estructura del personaje
 * 
 * Cada campo indica las caracteristicas del personaje
 * 
 * Se usa arreglo en el nombre pues queremos de manera estetica mantener bajo el numero de
 * caracteres a la hora de imprimir al jugador.
 */
typedef struct 
{
    char nombre[20];
    int puntos_de_vida;
    int ataque;
    int defensa;
} personaje_;

#endif