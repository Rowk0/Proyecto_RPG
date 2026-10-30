#include "game_menu.h"
#include "personaje.h"
#include "historial.h"
#include <time.h>

int main(void)
{
    srand(time(NULL));
   
    personaje_ personaje = {"\0", 20, 2, 1, 0, 0, 0, crear_pila()};
	inventario i = NULL;
	inventario botin_bosque = NULL;
	inventario botin_cuevas = NULL;
	inventario botin_castillo = NULL;
    int loop_juego = 1;
    int indice_archivo_guardado = -1;

    inicializacion_rpg(&indice_archivo_guardado);
    cargar_personaje(&personaje, &indice_archivo_guardado);
	i = cargar_inventario(i, indice_archivo_guardado);
	botin_bosque = cargar_botin(botin_bosque, 1, indice_archivo_guardado);
	botin_cuevas = cargar_botin(botin_cuevas, 2, indice_archivo_guardado);
	botin_castillo = cargar_botin(botin_castillo, 3, indice_archivo_guardado);
    cargar_historial(personaje.historial, &indice_archivo_guardado);

    if (archivo_guardado_vacio(&indice_archivo_guardado) == 1)
    {
        creacion_personaje(&personaje);
    }

    while(loop_juego)
    {
        imprimir_menu();
        selector_menu(&personaje, &loop_juego, i, botin_bosque, botin_cuevas, botin_castillo, personaje.historial, indice_archivo_guardado);
    }

    guardar_personaje(&personaje, &indice_archivo_guardado);
    guardar_inventario(i, indice_archivo_guardado);
    guardar_historial(personaje.historial, &indice_archivo_guardado);
	eliminar_inventario(i);
    return 0;

}
