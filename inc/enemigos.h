#ifndef ENEMIGOS
#define ENEMIGOS

#include "personaje.h"

/**
 * @brief Estructura del enemigo
 * 
 * Cada campo indica las caracteristicas del enemigo
 * 
 */
typedef struct 
{
    int id; //num de aparicion
    char nombre[20];
    int puntos_de_vida;
    int ataque;
} enemigo_;

typedef struct nodo_enemigo* puntero_enemigo;
typedef puntero_enemigo cola_enemigos;

struct nodo_enemigo
{
    enemigo_ enemigo;
    puntero_enemigo siguiente;
};

cola_enemigos crear_cola(void);

cola_enemigos enqueue(cola_enemigos C, enemigo_ e);

cola_enemigos dequeue(cola_enemigos C);

void imprimir_enemigos(cola_enemigos C);



/**
 * @brief Funcion que separa los enemigos dependiendo de la zona en que 
 * se encuentre el jugador
 * 
 */
void enemigos_x_zona(personaje_ *p, int elegir_ruta);


/**
 * @brief aparicion de enemigos exclusivos del bosque
 * 
 */
void enemigos_bosque();


void enemigos_cuevas();

void enemigos_castillo();
#endif