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
	printf("  - id (BORRAR ESTO AL TERMINAR!!): %d\n", o.id);
	printf("  - Nombre: %s\n", o.nombre);
	printf("  - Descripcion: %s\n", o.descripcion);
}

void liberar_objeto(objeto_ o)
{
	free(o.nombre);
	free(o.descripcion);
}
