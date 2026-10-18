#include "commons.h"

int main()
{
    /*El personaje se vuelve a cargar por un archivo .txt*/
    personaje_ personaje = {"\0", 20, 2, 1};

    /*Si existe un archivo de guardado saltar esta parte*/
    creacion_personaje(&personaje);
    estado_personaje(&personaje);
    guardar_personaje(&personaje);

    return 0;
}