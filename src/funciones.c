#include "commons.h"
#include "personaje.h"
#include "enemigos.h"
#include <unistd.h>

int archivo_guardado_vacio(int *indice_archivo_guardado)
{
    char ruta_archivo[30];
    char lineas[100];

snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d/save.txt", *indice_archivo_guardado);
    FILE *archivo = fopen(ruta_archivo, "r"); //Por ahora está en save_1 más adelante lo hago dinamico

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return -1;
    }

    if (fgets(lineas, sizeof(lineas), archivo) == NULL)
    {
        printf("El archivo se encuentra vacio\n");
        return 1;
    }

    return 0;
}

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

void imprimir_guardados(void)/*personaje_ *p*/
{
    printf("Bienvenido :D\n");
    printf("Elija que archivo de guardado desea abrir:\n");
    printf("Save 1\n");
    printf("Save 2\n");
    printf("Save 3\n");
}

void imprimir_menu()
{
    printf("\n====(Fanfared Misadventures)====\n");
    printf("\t==== Menu ====\n");
    printf("\t1. Explorar zona\n");
    printf("\t2. Ver personaje\n");
    printf("\t3. Inventario\n");
    printf("\t4. Historial\n");
    printf("\t5. Salir :(\n");
}

void selector_menu(personaje_ *p, int *loop_juego)
{
    int opcion = elegir_opcion();
    system("clear");
    switch (opcion)
    {
    case 1:
        camino(p);
        break;
    case 2:
        estado_personaje(p);
        volver_menu();
        break;
    case 3:
        printf("opcion ver inventariooo");
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
        selector_menu(p, loop_juego);
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

void camino(personaje_ *p)
{
    int elegir_ruta;
    printf("0. Para volver el menu\n");
    printf("1. Para ir a Bosque de Almas\n");
    printf("2. Para ir a Sistema de Cuevas\n");
    printf("3. Para ir a Castillo en Ruinas\n");
    elegir_ruta = elegir_opcion();

    switch (elegir_ruta)
    {
    case 0:
        printf("Volviendo al menu..");
        sleep(1);
        system("clear");
        break;
    case 1:
        printf("Entrando al Bosque de Almas\n");
        explorar_zona(p, elegir_ruta);
        break;
    case 2:
        printf("Entrando al Sistema de Cuevas\n");
        explorar_zona(p, elegir_ruta);
        exit(0);
    case 3:
        printf("Entrando al Castillo en Ruinas\n");
        explorar_zona(p, elegir_ruta);
        exit(0);
    default:
        printf("Elige una zona valida!\n");
        sleep(1);
        /*system("clear");
        camino(p);*/
        break;
    }
    
}

void caminando(void)
{
    printf("caminando");
    fflush(stdout);

    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
}

void cargando(void)
{
    printf("cargando");
    fflush(stdout);

    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    printf("\n");
}

void explorar_zona(personaje_ *p, int elegir_ruta)
{
    int explorando = 1;

    while (explorando == 1)
    {

        int evento = 0;
        while (evento == 0) // 1: objeto ; 2:enemigos
        {
            caminando();
            evento = rand() % 3;

            if(evento == 0)
            {
                printf("Sigues caminando. No encuentras nada\n");
                p->historial = push(p->historial, "Sigues caminando. No encuentras nada\n");
            }

            else if(evento == 1)
            {
                printf("Encontraste un objeto!\n");
            }
            
            else if(evento == 2)
            {
                printf("Encontraste a unos enemigos!\n");
                enemigos_x_zona(p,  elegir_ruta);
            }
        }

        if(p->puntos_de_vida <= 0)
        {
            printf("Volviendo al menu\n");
            sleep(2);
            p->puntos_de_vida = 20;
            explorando = 0;
        }
        else
        {
            printf("\n Deseas seguir explorando?\n");
            printf("1: Seguir explorando\n");
            printf("2: Volver al menu\n");
            explorando = elegir_opcion();
            while(explorando != 1 && explorando != 2)
            {
                printf("Ingrese una opcion valida!\n");
                sleep(2);
                system("clear");
                printf("\n Deseas seguir explorando?\n");
                printf("1: Seguir explorando\n");
                printf("2: Volver al menu\n");
                explorando = elegir_opcion();
            }
        }

    }
    
}