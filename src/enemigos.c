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


cola_enemigos crear_cola(void)
{
    cola_enemigos C;
    C = malloc(sizeof(struct nodo_enemigo));
    if(C == NULL)
    {
        printf("Error, sin espacio");
        return C;
    }

    C->siguiente = NULL;
    return C;
}

cola_enemigos enqueue(cola_enemigos C, enemigo_ e)
{
    cola_enemigos aux;
    aux = malloc(sizeof(struct nodo_enemigo));
    if(aux == NULL)
    {
        printf("Error, sin espacio");
        return C;
    }
    aux->enemigo = e;
    aux->siguiente = NULL;
    puntero_enemigo p = C;
    while(p->siguiente != NULL)
    {
        p = p->siguiente;
    }
    p->siguiente = aux;
    return C;
}

cola_enemigos dequeue(cola_enemigos C)
{
    if(C == NULL || C->siguiente == NULL)
    {
        printf("La cola de enemigos ya esta vacia\n");
        return C;
    }
    puntero_enemigo primero = C->siguiente;
    C->siguiente = C->siguiente->siguiente;

    free(primero);
    return C;
    
}

void imprimir_enemigos(cola_enemigos C)
{
    puntero_enemigo actual = C->siguiente;
    while(actual != NULL)
    {
    printf("  %d. %s (%d PV)\n", actual->enemigo.id, actual->enemigo.nombre, actual->enemigo.puntos_de_vida);
    actual = actual->siguiente;
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