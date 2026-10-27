#ifndef ENEMIGOS
#define ENEMIGOS
#define MIN_TAMANHO_COLA 3

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

struct registro_cola
{
    int capacidad;
    int front;
    int rear;
    int tamanho;
    enemigo_ *arreglo;
};

typedef struct registro_cola* cola_enemigos;

cola_enemigos crear_cola(int max_elementos);
void vaciar_cola(cola_enemigos Q);
int cola_vacia(cola_enemigos Q);
int cola_llena(cola_enemigos Q);
int sucesor(int valor, cola_enemigos Q);
cola_enemigos enqueue(enemigo_ X, cola_enemigos Q);
cola_enemigos dequeue(cola_enemigos Q);
void imprimir_enemigos(cola_enemigos Q);



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