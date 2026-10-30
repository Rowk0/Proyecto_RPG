/**
 * @file objeto.c
 * @brief Funciones relacionadas con objetos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "objetos.h"

objeto_ crear_objeto(int id, int clase, char* nombre, char* descripcion)
{
	objeto_ o = {id, clase, NULL, NULL};
	
	o.nombre = malloc(strlen(nombre) + 1);
	if(o.nombre == NULL)
	{
		printf("Out of memory!\n");
		return o;
	}
	strcpy(o.nombre, nombre);

	o.descripcion = malloc(strlen(descripcion) + 1);
	if(o.descripcion == NULL)
	{
		printf("Out of memory!\n");
		free(o.nombre);
		o.nombre = NULL;
		return o;
	}
	strcpy(o.descripcion, descripcion);

	return o;
}

void analizar_objeto(objeto_ o)
{
	printf("  - id: %d\n", o.id);
	printf("  - Nombre: %s\n", o.nombre);
	printf("  - Descripcion: %s\n", o.descripcion);
}

void liberar_objeto(objeto_ o)
{
	free(o.nombre);
	free(o.descripcion);
}

/* Recalcula bonos a partir del inventario. Llamar tras insertar/eliminar objetos. */
void actualizar_equipo(personaje_ *p, inventario inv)
{
    int mejor_arma = 0;
    int accesorio = 0;

    for (posicion pos = inv->siguiente; pos != NULL; pos = pos->siguiente)
    {
        switch (pos->objeto.clase)
        {
        case 1:
        {
            int bono = 0;
            switch (pos->objeto.id)
            {
            case 1: bono = 8;  break;
            case 5: bono = 12; break;
            case 9: bono = 16; break;
            }
            if (bono > mejor_arma) mejor_arma = bono;
            break;
        }
        case 3:
            /* prioridad simple: se queda con el de mayor id */
            if (pos->objeto.id > accesorio) accesorio = pos->objeto.id;
            break;
        }
    }

    p->ataque = p->ataque_base + mejor_arma;
    p->accesorio = accesorio;
}