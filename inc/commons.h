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

/**
 * @brief Funcion crear personaje.
 * 
 * Se le permite al usuario crear el nombre de su personaje.
 * 
 * @param p personaje a crear.
 */
void creacion_personaje(personaje_ *p);

/**
 * @brief Imprime los campos del personaje.
 * 
 * @param p Personaje en juego
 */
void estado_personaje(personaje_ *p);

/**
 * @brief Estoy loco
 * 
 * @param p 
 */
void guardar_personaje(personaje_ *p);

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


//void camino(void);
#endif