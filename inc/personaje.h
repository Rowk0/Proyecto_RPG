#ifndef PERSONAJE
#define PERSONAJE

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

/**
 * @brief Funcion crear personaje.
 * 
 * Se le permite al usuario crear el nombre de su personaje.
 * 
 * @param p personaje a crear.
 */
void creacion_personaje(personaje_ *p);

/**
 * @brief Funcion donde introduce los parametros de un archivo .txt al personaje
 * 
 * @param p Personaje al que atribuirle los parametros
 */
void cargar_personaje(personaje_ *p, int *indice_archivo_guardado);

/**
 * @brief Imprime los campos del personaje.
 * 
 * @param p Personaje en juego
 */
void estado_personaje(personaje_ *p);

/**
 * @brief Guarda los parametros del personaje en el archivo de guardado elejido previamente
 * 
 * @param p Personaje a guardar los parametros
 */
void guardar_personaje(personaje_ *p, int *indice_archivo_guardado);

#endif