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
historial crear_pila();

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

#endif