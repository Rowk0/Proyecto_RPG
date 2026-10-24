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
 * @brief Comprueba si el archivo de guardado está vacio 
 * 
 * @param indice_archivo_guardado Indice del archivo a guardar
 * @return int Devuele 1 si está vacio o 0 en el caso contrario
 */
int archivo_guardado_vacio(int *indice_archivo_guardado);

/**
 * @brief Funcion donde introduce los parametros de un archivo .txt al personaje
 * 
 * @param p Personaje al que atribuirle los parametros
 */
void cargar_personaje(personaje_ *p, int *indice_archivo_guardado);

/**
 * @brief Imprime una bienvenida al jugador y se le pide que archivo de guardado desea abrir
 * 
 * @param indice_archivo_guardado Indice del archivo de guardado a abrir
 */
void inicializacion_rpg(int *indice_archivo_guardado);

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