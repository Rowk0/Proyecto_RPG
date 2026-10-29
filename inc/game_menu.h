#ifndef GAME_MENU
#define GAME_MENU

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "personaje.h"

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
#endif