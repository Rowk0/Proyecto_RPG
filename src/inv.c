
/**
 * @file product.c
 * @brief Funciones relacionadas con inventarios de objetos
*/


#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

inventario tomar_objeto(inventario i, objeto_ o)
{
	// Revisar si el inventario existe.
	if(i == NULL)
	{
		printf("Error: Inventario nulo\n");
		return i;
	}

	// Posicionar un puntero posicion al ultimo elemento del inventario.
	posicion p = i;
	while(p->siguiente != NULL)
	{
		p = p->siguiente;
	}

	// Crea el nodo auxilar a sostener el objeto a insertar.
	inventario aux = malloc(sizeof(struct nodo));
    if(aux == NULL)
    {
        printf("Sin memoria!\n");
        return aux;
    }

	// Inserta el nodo auxiliar al final de la lista.
    aux->objeto = o;
    aux->siguiente = NULL;
    p->siguiente = aux;

    return i;
}


