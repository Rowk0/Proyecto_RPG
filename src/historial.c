#include "historial.h"

historial crear_pila()
{
    historial H;

    H = malloc(sizeof(struct nodo));

    H->siguiente = NULL;

    return H;
}

historial push(historial H, char *accion_texto)
{
    historial celda_temporal;

    celda_temporal = malloc(sizeof(struct nodo));

    if (celda_temporal == NULL)
    {
        printf("Error: la celda auxiliar no se pudo crear\n");
        return H;
    }

    celda_temporal->accion = malloc(strlen(accion_texto) + 1);
    
    strcpy(celda_temporal->accion, accion_texto);

    celda_temporal->siguiente = H->siguiente;

    H->siguiente = celda_temporal;

    return H;
}

historial pop(historial H)
{
    if (H->siguiente == NULL)
    {
        printf("Error: El siguiente nodo del centinela esta vacio\n");
        return H;
    }

    historial primera_celda;

    primera_celda = H->siguiente;

    H->siguiente = H->siguiente->siguiente;

    free(primera_celda->accion);
    free(primera_celda);

    return H;
}

void imprimir_historial(historial H)
{
    historial actual = H->siguiente;

    printf("=====HISTORIAL DE ACCIONES=====\n");

    while (actual != NULL)
    {
        printf("%s", actual->accion);
        actual = actual->siguiente;
    }
}