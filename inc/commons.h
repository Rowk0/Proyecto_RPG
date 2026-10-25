#ifndef COMMONS
#define COMMONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "personaje.h"

/**
 * @brief Comprueba si el archivo de guardado está vacio 
 * 
 * @param indice_archivo_guardado Indice del archivo a guardar
 * @return int Devuele 1 si está vacio o 0 en el caso contrario
 */
int archivo_guardado_vacio(int *indice_archivo_guardado);

/**
 * @brief Imprime una bienvenida al jugador y se le pide que archivo de guardado desea abrir
 * 
 * @param indice_archivo_guardado Indice del archivo de guardado a abrir
 */
void inicializacion_rpg(int *indice_archivo_guardado);

/**
 * @brief imprime el menu de inicio
 */
void imprimir_menu();

/**
 * @brief Verifica la seleccion
 */
void selector_menu(personaje_ *p, int *loop_juego);

/**
 * @brief Imprime archivos de guardado
 * 
 * El usuario elige que archivo abrir y seguir jugando
 * 
 */
void imprimir_guardados(void)/*personaje_ *p*/;


/**
 * @brief funcion ingresar 0 para salir
 * 
 * El usuario ingresa 0 para volver al menu
 * 
 */
void volver_menu(void);

/**
 * @brief funcion para elegir 
 * 
 * Esta funcion se utiliza para no tener que repetir el mismo codigo para elegir una opcion
 * 
 */
int elegir_opcion(void);

/**
 * @brief funcion de animacion para caminar
 * 
 * funcion hecha con ayuda de IA
 */
void caminando (void);

/**
 * @brief elegir que camino tomar
 * 
 */
void camino(personaje_ *p);

/**
 * @brief jugador elige camino bosque
 * 
 */
void zona_bosque(personaje_ *p);
#endif