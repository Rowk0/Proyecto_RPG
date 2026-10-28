/**
 * @file product.c
 * @brief Funciones relacionadas con inventarios de objetos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "inventario.h"
#include "objetos.h"
#include "personaje.h"

inventario crear_inventario_vacio(inventario i)
{
	if(inventario_vacio(i) == false)
	{
		i = eliminar_inventario(i);
	}

	i = malloc(sizeof(struct nodo_objeto));
	if(i == NULL)
	{
		printf("Out of memory!\n");
		return i;
	}
	i->siguiente = NULL;

	return i;
}

inventario cargar_inventario(inventario i, int numero_de_guardado)
{
	FILE* archivo_inventario;
	FILE* archivo_lootpool;
	i = NULL; // Inventario a cargar.
	int id; // Id a leer de inventario.txt.
	int numero_lineas; // Variable utilizada para posicionar el cursor detras del objeto a insertar en el inventario del personaje.
	char caracter = '\0';

	// Revisa si se leyeron correctamente 4 parametros.
	int leer;

	// Variables para grabar los valores leidos de lootpool.csv, y luego copiar en un objeto individual.
	int id_objeto, clase_objeto;
	char* nombre_objeto = NULL;
	char* descripcion_objeto = NULL;

	// Crear un inventario vacio.

	i = crear_inventario_vacio(i);

	// Abrir archivo de todos los objetos
	archivo_lootpool = fopen("lootpool.csv", "r");
	if(archivo_lootpool == NULL)
	{
		printf("Error de cargar_inventario: No se pudo abrir el archivo\n");
		return i;
	}

	// Abrir archivo de inventario del personaje (sostiene las ids de los objetos en el inventario)
	switch(numero_de_guardado)
	{
		case 1:
		archivo_inventario = fopen("save/save_1/inventario.txt", "r");
		if(archivo_inventario == NULL)
		{
			printf("Error de cargar_inventario: No se pudo abrir el archivo inventario\n");
			return i;
		}
		break;

		case 2:
		archivo_inventario = fopen("save/save_2/inventario.txt", "r");
		if(archivo_inventario == NULL)
		{
			printf("Error de cargar_inventario: No se pudo abrir el archivo inventario\n");
			return i;
		}
		break;

		case 3:
		archivo_inventario = fopen("save/save_3/inventario.txt", "r");
		if(archivo_inventario == NULL)
		{
			printf("Error de cargar_inventario: No se pudo abrir el archivo inventario\n");
			return i;
		}
		break;

		default:
		printf("Error de cargar_inventario: Numero de guardado invalido\n");
		return i;
		break;
	}

	while(fscanf(archivo_inventario, "%d", &id) == 1)
	{
		printf("id: %d\n", id);
		// Coloca el cursor detras del id del objeto a cargar
		for(numero_lineas = 1; numero_lineas < id; caracter = fgetc(archivo_lootpool))
		{
			if(caracter == '\n')
			{
				numero_lineas++;
			}
		}
		// Parsing
		leer = fscanf(archivo_lootpool, "%d, %d, %49c[^,], %128c[^,]", &id_objeto, &clase_objeto, nombre_objeto, descripcion_objeto);
		if(leer != 4 && !feof(archivo_lootpool))
		{
			printf("Error de cargar_inventario: Formato de archivo incorrecto\n");
			return i;
		}
		if(ferror(archivo_lootpool))
		{
			printf("Error de cargar_inventario: Error al leer el archivo\n");
			return i;
		}
		// Crear el objeto en base a los parametros leidos.
		i = insertar_objeto(i, crear_objeto(id_objeto, clase_objeto, nombre_objeto, descripcion_objeto));
	}
	printf("Debug: Inventario impreso:\n");
	imprimir_objetos(i);

	fclose(archivo_inventario);
	fclose(archivo_lootpool);

	return i;
}

inventario insertar_objeto(inventario i, objeto_ o)
{
	// Restricciones: El inventario debe existir y el inventario no puede estar lleno.
	// Revisa si el inventario existe.
	if(i == NULL)
	{
		printf("Error de tomar_objeto: Inventario nulo\n");
		return i;
	}

	// Posiciona un puntero posicion al ultimo elemento del inventario.
	posicion p = i;
	while(p->siguiente != NULL)
	{
		p = p->siguiente;
	}

	// Crea el nodo auxilar a sostener el objeto a insertar.
	inventario aux = malloc(sizeof(struct nodo_objeto));
    if(aux == NULL)
    {
        printf("Out of memory!\n");
        return aux;
    }

	// Inserta el nodo auxiliar al final de la lista.
    aux->objeto = o;
    aux->siguiente = NULL;
    p->siguiente = aux;

    return i;
}

static objeto_ extraer_objeto_al_azar(inventario botin)
{
	objeto_ o = {0, 0, NULL, NULL};

	if(inventario_vacio(botin) == true)
	{
		printf("Error de extraer_objeto_al_azar: Inventario vacio o nulo\n");
		return o;
	}

	int random;
	posicion p = botin;

	while(p != NULL && p != botin)
	{
		random = rand() % 3 + 1;
		for(int i = 0; i < random; i++)
		{
			p = p->siguiente;
		}
	}

	o = p->objeto;
	eliminar_objeto_por_id(botin, p->objeto.id);
	return o;
}

inventario tomar_objeto_de_botin(inventario i, inventario botin)
{
	objeto_ o;

	o = extraer_objeto_al_azar(botin);
	i = insertar_objeto(i, o);

	return i;
}

inventario usar_objeto_por_id(inventario i, int id, personaje_ personaje) // (anhadir parametro de enemigo)
{
	if(inventario_vacio(i) == true)
	{
		printf("Error de usar_objeto_por_id: Inventario vacio o nulo\n");
	}

	posicion p;
	p = encontrar_objeto_por_id(i, id);

	// Accionar el objeto
	switch(p->objeto.clase)
	{
		case EQUIPABLE:
		{
			switch(id) 
			{
				case 1:
				{
					personaje.ataque = 8;
					break;
				}
				case 2:
				{
					personaje.ataque = 12;
					break;
				}
				case 3:
				{
					personaje.ataque = 16;
					break;
				}
				default:
				{
					printf("Error de usar_objeto_por_id: Equipable ausente\n");
					break;
				}
			}
			break;
		}
		case CONSUMIBLE:
		{
			switch(id) 
			{
				case 4:
				{
					personaje.puntos_de_vida += 15;
					break;
				}
				case 5:
				{
					// (quitar slashes de comentario al implementar)
					//personaje.regeneracion = 4; 
					break;
				}
				case 6:
				{
					personaje.puntos_de_vida += 30;
					break;
				}
				case 7:
				{
					// (quitar slashes de comentario al implementar)
					//enemigo.puntos_de_vida -= 30;
					break;
				}
				case 8:
				{
					// (quitar slashes de comentario al implementar)
					//enemigo.envenenado = true;
					break;
				}
				case 9:
				{
					// (quitar slashes de comentario al implementar)
					//personaje.espejo_activo = true,
					break;
				}
				default:
				{
					printf("Error de usar_objeto_por_id: Consumible ausente\n");
					break;
				}
			}
			eliminar_objeto_por_id(i, id);
			break;
		}
		case ACCESORIO:
		{
			switch(id)
			{
				case 10:
				{
					// (quitar slashes de comentario al implementar)
					//personaje.accesorio = BANDANA_NINJA;
					break;
				}
				case 11:
				{
					// (quitar slashes de comentario al implementar)
					//personaje.accesorio = ARO_CARMESI;
					break;
				}
				case 12:
				{
					// (quitar slashes de comentario al implementar)
					//personaje.accesorio = CORONA_REY;
					break;
				}
				default:
				{
					printf("Error de usar_objeto_por_id: Accesorio ausente\n");
					break;
				}
			}
			eliminar_objeto_por_id(i, id);
			break;
		}
		default:
		{
			printf("Error de usar_objeto_por_id: Clase invalida\n");
			break;
		}
	}

	return i;
}

posicion encontrar_objeto_por_id(inventario i, int id)
{
	if(inventario_vacio(i) == true)
	{
		printf("Error de encontrar_objeto_por_id: Inventario vacio o nulo\n");
		return i;
	}

	posicion p = i->siguiente;
	while(p != NULL)
	{
		if(p->objeto.id == id)
		{
			printf("Objeto encontrado!\n");
			analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	printf("Objeto no encontrado! :<\n");
	return NULL;
}

posicion encontrar_objeto_anterior_por_id(inventario i, int id)
{
	if(inventario_vacio(i) == true)
	{
		printf("Error de encontrar_objeto_anterior_por_id: Inventario vacio o nulo\n");
		return i;
	}

	posicion p = i;
	while(p->siguiente != NULL) // Gracias a la inicializacion de p, deberia ser imposible tratar de eliminar la cabecera.
	{
		if(p->siguiente->objeto.id == id)
		{
			// Quitar funciones de mensaje despues de arreglar bugs.
			printf("encontrar_objeto_anterior_por_id: Objeto anterior encontrado!\n");
			analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	printf("encontrar_objeto_anterior_por_id: Objeto no encontrado! :<\n");
	return NULL;
}

posicion encontrar_objeto_por_nombre(inventario i, char* nombre)
{
	if(inventario_vacio(i) == true)
	{
		printf("Error de encontrar_objeto_por_nombre: Inventario vacio o nulo\n");
		return i;
	}

	posicion p = i->siguiente;
	while(p != NULL)
	{
		if(strcmp(p->objeto.nombre, nombre) == 0)
		{
			printf("encontrar_objeto_por_nombre: Objeto encontrado!\n");
			analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	printf("encontrar_objeto_por_nombre: Objeto no encontrado! :<\n");
	return NULL;
}

posicion encontrar_objeto_anterior_por_nombre(inventario i, char* nombre)
{
	if(inventario_vacio(i) == true)
	{
		printf("Error de encontrar_objeto_anterior_por_nombre: Inventario vacio o nulo\n");
		return i;
	}

	posicion p = i;
	while(p->siguiente != NULL)
	{
		if(strcmp(p->siguiente->objeto.nombre, nombre) == 0)
		{
			printf("encontrar_objeto_por_anterior_nombre: Objeto encontrado!\n");
			analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	printf("encontrar_objeto_anterior_por_nombre: Objeto no encontrado! :<\n");
	return NULL;
}

bool inventario_vacio(inventario i)
{
	if(i == NULL || i->siguiente == NULL)
	{
		return true;
	}
	return false;
}

void imprimir_objetos(inventario i)
{
	if(i == NULL)
	{
		printf("Error de imprimir_objetos: Inventario nulo\n");
		return;
	}
	else if(i->siguiente == NULL)
	{
		printf("imprimir_objetos: Inventario vacio!\n\n");
		return;
	}
	
	printf("  ===========\n");
	printf("  Inventario:\n");
	printf("  ===========\n\n");
	posicion p = i->siguiente;
	while(p != NULL)
	{
		analizar_objeto(p->objeto);
		printf("\n");
		p = p->siguiente;
	}
}

void eliminar_objeto_por_id(inventario i, int id)
{
	if(i == NULL)
	{
		printf("Error de eliminar_objeto: Inventario nulo\n");
		return;
	}
	else if(inventario_vacio(i) == true)
	{
		printf("Error de eliminar_objeto: Inventario vacio\n");
		return;
	}
	
	posicion p, aux;
	p = encontrar_objeto_anterior_por_id(i, id); // (habia dado error la funcion de encontrar objeto anterior)
	printf("oliwi\n");
	if(p == NULL)
	{
		printf("Error de eliminar_objeto: No se encontro el objeto a eliminar\n");
		return;
	}

	aux = p->siguiente;
	printf("Eliminando [%s]...\n", aux->objeto.nombre);
	p->siguiente = aux->siguiente;
	free(aux);
}

inventario eliminar_inventario(inventario i)
{
	posicion aux = i;

	while(aux != NULL)
	{
		aux = aux->siguiente;
		free(i);
		i = aux;
	}
	return i;
}
