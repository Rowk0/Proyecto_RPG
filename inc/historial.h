#ifndef HISTORIAL
#define HISTORIAL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct nodo* puntero_a_nodo;
typedef puntero_a_nodo historial;

/**
 * @brief El historial tomara la estructura de una pila
 * 
 */
struct nodo
{
    char *accion;
    historial siguiente;
};

/**
 * @brief Crea el centinela de la pila del historial
 * 
 * @param H Historial a crear
 * @return historial Devuelve la pila actualizada
 */
historial crear_pila(void);

/**
 * @brief Pone un elemento en la pila
 * 
 * @param H Pila al que insertar el elemento
 * @param accion Cadena de caracteres a poner en el historial
 * @return pila_ Devuelve la pila actualizada
 */
historial push(historial H, char *accion_texto);

/**
 * @brief Elimina el ultimo elemento puesto en la pila
 * 
 * @param H Pila al que eliminar el elemento
 */
historial pop(historial H);

/**
 * @brief Imprime el historial
 * 
 * @param H Historial a imprimir
 */
void imprimir_historial(historial H);

/**
 * @brief Verifica si la pila dada está vacia
 * 
 * @param H Historial a verificar
 * @return int Devuelve 1 si esta vacia o 0 en el caso contrario
 */
int pila_esta_vacia(historial H);

/**
 * @brief Guarda el historial de acciones de un personaje en un archivo .txt
 * 
 * @param H Historial a guardar
 * @param indice_archivo_guardado Indice de archivo de guardado cargado
 */
void guardar_historial(historial H, int *indice_archivo_guardado);

/**
 * @brief Carga el historial del archivo de guardado elegido por el usario
 * 
 * @param H Historial donde cargar los datos
 * @param indice_archivo_guardado Indice de archivo de guardado elegido
 */
void cargar_historial(historial H, int *indice_archivo_guardado);

/**
 * @brief Funcion recursiva que imprime de manera estetica una pila al revez (tope abajo, la base arriba)
 * 
 * @param H Historial a imprimir
 */
void imprimir_desde_el_fondo(historial H);

/**
 * @brief Funcion recursiva que explora la pila del historial hasta el ultimo elemento y empezar
 * a escribir cuando llege al caso limite
 * 
 * @param archivo Archivo donde guardar el historial
 * @param H Historial a guardar
 */
void escribir_desde_el_fondo(FILE *archivo, historial H);

#endif
