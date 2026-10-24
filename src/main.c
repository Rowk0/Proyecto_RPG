#include "commons.h"

int main()
{

    /*El personaje se vuelve a cargar por un archivo .txt*/
    personaje_ personaje = {"\0", 20, 2, 1};
    int loop_juego = 1;

    /*Si existe un archivo de guardado saltar esta parte*/
    creacion_personaje(&personaje);

    while(loop_juego)
    {
        imprimir_menu();
        selector_menu(&personaje, &loop_juego);
    }

    guardar_personaje(&personaje);
    return 0;

}