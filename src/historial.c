#include "historial.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

historial crear_pila(void)
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
    printf("=====HISTORIAL DE ACCIONES=====\n");
    imprimir_desde_el_fondo(H->siguiente);
}

int pila_esta_vacia(historial H)
{
    if (H->siguiente == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void guardar_historial(historial H, int *indice_archivo_guardado)
{
    if (H == NULL)
    {
        printf("Error: El historial es nulo");
        return;
    }
    
    char ruta_archivo[30];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d/historial.txt", *indice_archivo_guardado);

    FILE *archivo = fopen(ruta_archivo, "w"); 

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }

    escribir_desde_el_fondo(archivo, H->siguiente);
    
    fclose(archivo);
}

void cargar_historial(historial H, int *indice_archivo_guardado)
{
    char ruta_archivo[30];
    char lineas[100];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d/historial.txt", *indice_archivo_guardado);

    FILE *archivo = fopen(ruta_archivo, "r"); //Por ahora está en save_1 más adelante lo hago dinamico

    if (archivo == NULL)
    {
        printf("Error al abrir el cargar el historial");
        return;
    }

    while (fgets(lineas, sizeof(lineas), archivo) != NULL)
    {
        lineas[strcspn(lineas, "\n")] = '\0';

        push(H, lineas);
    }

    fclose(archivo);
}

void imprimir_desde_el_fondo(historial H)
{
    if (H == NULL)
    {
        return;
    }
    
    imprimir_desde_el_fondo(H->siguiente);
    printf("%s\n", H->accion);
}

void escribir_desde_el_fondo(FILE *archivo, historial H)
{
    if (H == NULL)
    {
        return;
    }

    escribir_desde_el_fondo(archivo, H->siguiente);
    fprintf(archivo, "%s\n", H->accion);
}
