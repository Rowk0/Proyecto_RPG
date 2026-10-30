#ifndef GAME_MENU
#define GAME_MENU

#include "personaje.h"
#include "inventario.h"
#include "historial.h"

/**
 * @brief Imprime una bienvenida al jugador y se le pide que archivo de guardado desea abrir
 * 
 * @param indice_archivo_guardado Indice del archivo de guardado a abrir
 */
void inicializacion_rpg(int *indice_archivo_guardado);

/**
 * @brief imprime el menu de inicio
 */
void imprimir_menu(void);

/**
 * @brief Verifica la seleccion
 */
void selector_menu(personaje_ *p, int *loop_juego, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo, historial historial, int indice_archivo_guardado);

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
 * @brief Pregunta al usuario si desea descartar algun objeto de su inventario
 * 
 * @param I Inventario de objetos
 */
void eliminar_objeto_print(inventario i, historial historial);
#endif
