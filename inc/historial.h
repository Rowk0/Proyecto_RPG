#ifndef HISTORIAL
#define HISTORIAL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief El historial tomara la estructura de una pila
 * 
 */
typedef struct 
{
    char *accion; //Acciones
    int k; // Tamaño
    int p; // Cantidad
} pila_;

/**
 * @brief Crea la pila vacia, de caso contrario vacia totalmente al pila de historial
 * 
 * @param k Tamaño de la pila
 * @return pila_ Devuelve la pila creada
 */
pila_ crear_vacio(int k);

/**
 * @brief Pone un elemento en la pila
 * 
 * @param H Pila al que insertar el elemento
 * @param accion Cadena de caracteres a poner en el historial
 * @return pila_ Devuelve la pila actualizada
 */
pila_ push(pila_ H, char *accion);

/**
 * @brief Elimina el ultimo elemento puesto en la pila
 * 
 * @param H Pila al que eliminar el elemento
 */
void pop(pila_ H);

/**
 * @brief Imprime el contenido de la pila
 * 
 * @param H Pila al que imprimir
 */
void imprimir_pila(pila_ H);

#endif