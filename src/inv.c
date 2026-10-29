/**
 * @file product.c
 * @brief Funciones relacionadas con inventarios de objetos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "inventario.h"
#include "objetos.h"

inventario crear_inventario_vacio(inventario i)
{
	if(inventario_vacio(i) == false)
	{
		eliminar_inventario(i);
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

inventario cargar_inventario(inventario i, int numero_de_guardado)
{
	// Crear un inventario vacio.
	i = crear_inventario_vacio(i);

	if(numero_de_guardado < 1 || numero_de_guardado > 3)	
	{
		printf("Error de cargar_inventario: Numero de guardado invalido\n");
		return i;
	}

	FILE* archivo_inventario;
	FILE* archivo_lootpool;
	int id; // Id a leer de inventario.txt.
	int numero_lineas; // Variable utilizada para posicionar el cursor detras del objeto a insertar en el inventario del personaje.
	char caracter = '\0';

	// Revisa si se leyeron correctamente 4 parametros.
	int leer;

	// Variables para grabar los valores leidos de lootpool.csv, y luego copiar en un objeto individual.
	int id_objeto, clase_objeto;
	char* nombre_objeto = NULL;
	char* descripcion_objeto = NULL;

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
			printf("Error de cargar_inventario: No se pudo abrir el archivo inventario.txt\n");
			return i;
		}
		break;

		case 2:
		archivo_inventario = fopen("save/save_2/inventario.txt", "r");
		if(archivo_inventario == NULL)
		{
			printf("Error de cargar_inventario: No se pudo abrir el archivo inventario.txt\n");
			return i;
		}
		break;

		case 3:
		archivo_inventario = fopen("save/save_3/inventario.txt", "r");
		if(archivo_inventario == NULL)
		{
			printf("Error de cargar_inventario: No se pudo abrir el archivo inventario.txt\n");
			return i;
		}
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

static inventario inicializar_botin(inventario botin, int numero_de_zona)
{
	// Crear un inventario vacio.
	botin = crear_inventario_vacio(botin);

	FILE* archivo_lootpool;

	// Revisa si se leyeron correctamente 4 parametros.
	int leer;

	// Contador de botines ingresados. Controla que se ingresen exactamente 4 objetos.
	int cont_botines;

	// Variables para grabar los valores leidos de lootpool.csv, y luego copiar en un objeto individual.
	int id_objeto, clase_objeto;
	char nombre_objeto[50];
	char descripcion_objeto[128];

	if(numero_de_zona < 1 || numero_de_zona > 3)
	{
		printf("Error de inicializar_botin: Numero de zona invalida\n");
		return botin;
	}

	// Abrir archivo de todos los objetos.
	archivo_lootpool = fopen("lootpool.csv", "r");
	if(archivo_lootpool == NULL)
	{
		printf("Error de inicializar_botin: No se pudo abrir el archivo\n");
		return botin;
	}

	// Colocar cursor en la posicion correcta dependiendo de la zona.
	if(numero_de_zona == 2)
	{
		fseek(archivo_lootpool, 262, SEEK_SET);
	}
	else if(numero_de_zona == 3)
	{
		fseek(archivo_lootpool, -314, SEEK_END);
	}

	for(cont_botines = 0; cont_botines < 4 && !feof(archivo_lootpool); cont_botines++)
	{
		leer = fscanf(archivo_lootpool, "%d, %d, %49[^,], %127[^\n]", &id_objeto, &clase_objeto, nombre_objeto, descripcion_objeto);
		if(leer != 4 && !feof(archivo_lootpool))
		{
			printf("Error de inicializar_botin en zona %d: Formato de archivo incorrecto\n", numero_de_zona);
			return botin;
		}
		if(ferror(archivo_lootpool))
		{
			printf("Error de inicializar_botin: Error al leer el archivo\n");
			return botin;
		}
		// Crear el objeto en base a los parametros leidos.
		botin = insertar_objeto(botin, crear_objeto(id_objeto, clase_objeto, nombre_objeto, descripcion_objeto));
	}

	fclose(archivo_lootpool);

	return botin;
}

static inventario corregir_inicializacion_botin(inventario botin, int numero_de_guardado)
{
	// Idea: Crear funcion cargar_botin que corra inicializar_botin y luego corregir_inicializacion_botin
	// Inicializar botin antes de correr esto!!!
	FILE* archivo_objetos_tomados;
	FILE* archivo_lootpool;
	int id; // Id a leer de inventario.txt.

	if(numero_de_guardado < 1 || numero_de_guardado > 3)
	{
		printf("Error de corregir_inicializacion_botin: Numero de guardado invalido\n");
		return botin;
	}

	// Abrir archivo de todos los objetos
	archivo_lootpool = fopen("lootpool.csv", "r");
	if(archivo_lootpool == NULL)
	{
		printf("Error de corregir_inicializacion_botin: No se pudo abrir el archivo\n");
		return botin;
	}

	// Abrir archivo de inventario del personaje (sostiene las ids de los objetos en el inventario)
	switch(numero_de_guardado)
	{
		case 1:
		archivo_objetos_tomados = fopen("save/save_1/objetos_tomados.txt", "r");
		if(archivo_objetos_tomados == NULL)
		{
			printf("Error de corregir_inicializacion_botin: No se pudo abrir el archivo objetos_tomados.txt\n");
			return botin;
		}
		break;

		case 2:
		archivo_objetos_tomados = fopen("save/save_2/objetos_tomados.txt", "r");
		if(archivo_objetos_tomados == NULL)
		{
			printf("Error de corregir_inicializacion_botin: No se pudo abrir el archivo objetos_tomados.txt\n");
			return botin;
		}
		break;

		case 3:
		archivo_objetos_tomados = fopen("save/save_3/objetos_tomados.txt", "r");
		if(archivo_objetos_tomados == NULL)
		{
			printf("Error de corregir_inicializacion_botin: No se pudo abrir el archivo objetos_tomados.txt\n");
			return botin;
		}
		break;
	}

	while(fscanf(archivo_objetos_tomados, "%d", &id) == 1)
	{
		printf("id de objeto a eliminar: %d\n", id);
		eliminar_objeto_por_id(botin, id);
	}

	fclose(archivo_objetos_tomados);
	fclose(archivo_lootpool);

	return botin;
}

inventario cargar_botin(inventario botin, int numero_de_zona, int numero_de_guardado)
{
	// En main, correr esta funcion en cada lista de botines.
	if(inventario_vacio(botin) == false)
	{
		botin = inicializar_botin(botin, numero_de_zona);
		botin = corregir_inicializacion_botin(botin, numero_de_guardado);
	}


	return botin;
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

	while(p == NULL || p == botin)
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

void tomar_objeto_de_botin(inventario i, inventario botin, objeto_ o)
{
	char eleccion;
	int leer;

	o = extraer_objeto_al_azar(botin);
	printf("Encontraste un objeto!\n");
	analizar_objeto(o);
	printf("Tomar %s? (S/n)\n", o.nombre);
	printf("-> ");
	leer = scanf("%c", &eleccion);
	while(leer != 1 || (eleccion != 'S' && eleccion != 'n'))
	{
		printf("Caracter invalido, intente de nuevo\n-> ");
		leer = scanf(" %c", &eleccion);
	}
	switch(eleccion)
	{
		case 'S':
		i = insertar_objeto(i, o);
		break;

		case 'n':
		printf("Ignoras %s y sigues con tu camino...\n", o.nombre);
		break;
	}
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
			//printf("Objeto encontrado!\n");
			//analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	//printf("Objeto no encontrado! :<\n");
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
			//printf("encontrar_objeto_anterior_por_id: Objeto anterior encontrado!\n");
			//analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	//printf("encontrar_objeto_anterior_por_id: Objeto no encontrado! :<\n");
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
			//printf("encontrar_objeto_por_nombre: Objeto encontrado!\n");
			//analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	//printf("encontrar_objeto_por_nombre: Objeto no encontrado! :<\n");
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
			//printf("encontrar_objeto_por_anterior_nombre: Objeto encontrado!\n");
			//analizar_objeto(p->objeto);
			return p;
		}
		p = p->siguiente;
	}
	//printf("encontrar_objeto_anterior_por_nombre: Objeto no encontrado! :<\n");
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
	
	printf("  ===========\n");
	printf("  Inventario:\n");
	printf("  ===========\n\n");
	if(i->siguiente == NULL)
	{
		printf("Vacio!\n\n");
		return;
	}
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
	if(inventario_vacio(i) == true)
	{
		printf("Error de eliminar_objeto: Inventario vacio o nulo\n");
		return;
	}
	
	posicion p, aux;
	p = encontrar_objeto_anterior_por_id(i, id); // (habia dado error la funcion de encontrar objeto anterior)
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

void eliminar_inventario(inventario i)
{
	posicion aux = i;

	while(aux != NULL)
	{
		aux = aux->siguiente;
		free(i);
		i = aux;
	}
}
