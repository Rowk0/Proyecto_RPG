#include "commons.h"
#include "personaje.h"
#include "historial.h"
#include <time.h>
int main()
{
    srand(time(NULL));
   
    personaje_ personaje = {"\0", 20, 2, 1, crear_pila()};
    int loop_juego = 1;
    int indice_archivo_guardado = -1;

    inicializacion_rpg(&indice_archivo_guardado);
    cargar_personaje(&personaje, &indice_archivo_guardado);
    cargar_historial(personaje.historial, &indice_archivo_guardado);

    if (archivo_guardado_vacio(&indice_archivo_guardado) == 1)
    {
        creacion_personaje(&personaje);
    }

    while(loop_juego)
    {
        imprimir_menu();
        selector_menu(&personaje, &loop_juego);
    }

    guardar_personaje(&personaje, &indice_archivo_guardado);
    guardar_historial(personaje.historial, &indice_archivo_guardado);
    return 0;

}