#include "game_menu.h"
#include "personaje.h"
#include "enemigos.h"
#include "exploracion.h"
#include <unistd.h>

void inicializacion_rpg(int *indice_archivo_guardado)
{
    printf("Binevenido a juego epico\n");
    printf("Que archivo de guardado desea abrir\n");
    printf("[1] Guardado 1\n");
    printf("[2] Guardado 2\n");
    printf("[3] Guardado 3\n");

    while (scanf("%d", indice_archivo_guardado) != 1)
    {
        printf("Error de entrada de archivo de guardado");
        return;
    }

}

void imprimir_guardados(void)
{
    printf("Bienvenido :D\n");
    printf("Elija que archivo de guardado desea abrir:\n");
    printf("Save 1\n");
    printf("Save 2\n");
    printf("Save 3\n");
}

void imprimir_menu(void)
{
    printf("\n====(Fanfared Misadventures)====\n");
    printf("\t==== Menu ====\n");
    printf("\t1. Explorar zona\n");
    printf("\t2. Ver personaje\n");
    printf("\t3. Inventario\n");
    printf("\t4. Historial\n");
    printf("\t5. Salir :(\n");
}

void selector_menu(personaje_ *p, int *loop_juego, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo)
{
    int opcion = elegir_opcion();
    system("clear");
    switch (opcion)
    {
    case 1:
        camino(p, i, botin_bosque, botin_cuevas, botin_castillo);
        break;
    case 2:
        estado_personaje(p);
        volver_menu();
        break;
    case 3:
        imprimir_objetos(i);
        volver_menu();
        break;
    case 4:
        imprimir_historial(p->historial);
        volver_menu();
        break;
    case 5:
        printf("Cerrando el juego");
        *loop_juego = 0;
        break;
    default:
        printf("Eliga una opcion valida!\n");
        sleep(1);
        selector_menu(p, loop_juego, i, botin_bosque, botin_cuevas, botin_castillo);
    }
}

void volver_menu(void)
{
    int opcion = 1;
    while (opcion != 0)
    {
        printf("\nIngresa 0 para volver al menu: ");
        while (scanf("%d", &opcion) != 1);
    }
}

int elegir_opcion(void)
{
    int opcion;
    printf("\nElige una opcion: ");
    while (scanf("%d", &opcion) != 1);
    return opcion;
}
