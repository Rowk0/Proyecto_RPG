#include "enemigos.h"
#include "personaje.h"

void enemigos_x_zona(personaje_ *p, int elegir_ruta)
{
    switch (elegir_ruta)
    {
    case 1:
        enemigos_bosque();
        break;
    
    case 2:
        enemigos_cuevas();
        break;  
    case 3:
        enemigos_castillo();
        break;
    default:
        break;
    }
}

void vaciar_cola(cola_enemigos Q)
{
    Q->tamanho = 0;
    Q->front = 1;
    Q->rear = 0;
}

int cola_vacia(cola_enemigos Q)
{
    return Q->tamanho == 0;
}

int cola_llena(cola_enemigos Q)
{
    return Q->tamanho == Q->capacidad;
}

cola_enemigos crear_cola(int max_elementos)
{
    cola_enemigos Q;
    if(max_elementos < MIN_TAMANHO_COLA)
    {
        printf("Error. El tamanho de la cola es muy pequenho\n");
        return NULL;
    }

    Q = malloc(sizeof(struct registro_cola));
    if(Q == NULL)
    {
        printf("Error. Sin espacio en la memoria \n");
        return NULL;
    }

    Q->arreglo = malloc(sizeof(enemigo_) * max_elementos);
    if(Q->arreglo == NULL)
    {
        printf("Error. Sin espacio en la memoria\n");
        free(Q);
        return NULL;
    }

    Q->capacidad = max_elementos;
    vaciar_cola(Q);
    return Q;
}

int sucesor(int valor, cola_enemigos Q)
{
    if(++valor == Q->capacidad)
    {
        valor = 0;
    }
    return valor;
}

cola_enemigos enqueue(enemigo_ X, cola_enemigos Q)
{
    if(cola_llena(Q))
    {
        printf("Error. Cola llena\n");
    }
    else
    {
        Q->tamanho++;
        Q->rear = sucesor(Q->rear, Q);
        Q->arreglo[Q->rear] = X;
    }
    return Q;
}

cola_enemigos dequeue(cola_enemigos Q)
{
    if(cola_vacia(Q))
    {
        printf("Error. Cola vacia\n");
    }
    else
    {
        Q->tamanho--;
        Q->front = sucesor(Q->front, Q);
    }
    return Q;
}

void imprimir_enemigos(cola_enemigos Q)
{
    int indice = Q->front;
    for (int i = 0; i < Q->tamanho; i++)
    {
        printf("  %d. %s (%d PV)\n",
               Q->arreglo[indice].id,
               Q->arreglo[indice].nombre,
               Q->arreglo[indice].puntos_de_vida);
        indice = sucesor(indice, Q);
    }
}


void enemigos_bosque()
{
    
}

void enemigos_cuevas()
{

}

void enemigos_castillo()
{

}