#include "exploracion.h"
#include "enemigos.h"
#include "game_menu.h"
#include <unistd.h>

void camino(personaje_ *p, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo)
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
        explorar_zona(p, elegir_ruta, i, botin_bosque, botin_cuevas, botin_castillo);
        break;
    case 2:
        printf("Entrando al Sistema de Cuevas\n");
        explorar_zona(p, elegir_ruta, i, botin_bosque, botin_cuevas, botin_castillo);
        break;
    case 3:
        printf("Entrando al Castillo en Ruinas\n");
        explorar_zona(p, elegir_ruta, i, botin_bosque, botin_cuevas, botin_castillo);
        break;
    default:
        printf("Elige una zona valida!\n");
        sleep(1);
        system("clear");
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

void explorar_zona(personaje_ *p, int elegir_ruta, inventario i, inventario botin_bosque, inventario botin_cuevas, inventario botin_castillo)
{
	objeto_ o = {0, 0, NULL, NULL};
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
                switch(elegir_ruta)
				{
					case 1:
					tomar_objeto_de_botin(i, botin_bosque, o);
					break;
					case 2:
					tomar_objeto_de_botin(i, botin_cuevas, o);
					break;
					case 3:
					tomar_objeto_de_botin(i, botin_castillo, o);
					break;
					default:
					printf("Error de explorar_zona: Ruta para extraer botin invalida\n");
					break;
				}
                explorando = 0;
            }
            
            else if(evento == 2)
            {
                printf("Encontraste a unos enemigos!\n");
                enemigos_x_zona(p, elegir_ruta, i);
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
