#include "game_menu.h"
#include "personaje.h"
#include "enemigos.h"
#include "exploracion.h"
#include "inventario.h"
#include "historial.h"
#include "acciones.h"
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

void selector_menu(personaje_ *p, int *loop_juego, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo, historial historial, int indice_archivo_guardado)
{
    int opcion = elegir_opcion();

    if (system("clear") != 0) 
    {
        printf("Error selector_menu: No se pudo limpiar pantalla");
        return;
    }

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
        menu_inventario(p, i, historial);
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
        selector_menu(p, loop_juego, i, botin_bosque, botin_cuevas, botin_castillo, historial, indice_archivo_guardado);
    }
}

void eliminar_objeto_print(inventario i, historial historial)
{
    int opcion = -1, id = -1;
    char accion[50];

    printf("¿Desea descartar algun objeto?\n");
    printf("(1) Si\n");
    printf("(2) No\n");
    printf("(3) Deseo recuperar mi objeto descartado\n");
    printf("Warning: Recuperar el objeto descartado solo si no haz hechos mas acciones\n");
    printf("Por ejemplo: Explorar la zona luego de descartar no seras capaz de recuperar tu objeto");
    opcion = elegir_opcion();

    if (opcion == 1)
    {
        printf("Introduzca el id del objeto a eliminar:\n");
        id = elegir_opcion();
        eliminar_objeto_por_id(i, id);
        snprintf(accion, sizeof(accion), "Eliminaste el objeto de id: %d\n", id);
        historial = push(historial, accion); 
    }
    else if (opcion == 2)
    {
        return;
    }
    else if (opcion == 3)
    {
        i = deshacer_descarte_objeto(historial, i);
    }
    
    return;
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

void menu_inventario(personaje_ *p, inventario i, historial H)
{
    int opcion;

    printf("=====MENU INVENTARIO=====\n");
    printf("(1) Actualizar equipamiento\n");
    printf("(2) Descartar objeto del inventario\n");
    opcion = elegir_opcion();

    if (opcion == 1)
    {
        actualizar_equipo(p, i);
    }
    else if (opcion == 2)
    {
        eliminar_objeto_print(i, H);
    }
    
    return;
}