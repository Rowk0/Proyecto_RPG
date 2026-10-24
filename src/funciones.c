#include "commons.h"
#include <unistd.h>

void creacion_personaje(personaje_ *p)
{
    printf("Introduzca el nombre de su personaje:");

    while (getchar() != '\n');

    //Posible caso limite
    if (fgets(p->nombre, sizeof(p->nombre), stdin) == NULL)
    {
        printf("Error al leer la entrada");
        return;
    }

    // Elimina el salto de línea sobrante
    p->nombre[strcspn(p->nombre, "\n")] = '\0';
}

void cargar_personaje(personaje_ *p, int *indice_archivo_guardado)
{
    char ruta_archivo[30];
    char lineas[100];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d.txt", *indice_archivo_guardado);

    FILE *archivo = fopen(ruta_archivo, "r"); //Por ahora está en save_1 más adelante lo hago dinamico

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }

    if (fgets(lineas, sizeof(lineas), archivo) != NULL)
    {
        strcpy(p->nombre, lineas);
    }

    if (fgets(lineas, sizeof(lineas), archivo) != NULL)
    {
        p->puntos_de_vida = atoi(lineas);
    }

    if (fgets(lineas, sizeof(lineas), archivo) != NULL)
    {
        p->ataque = atoi(lineas);
    }

    if (fgets(lineas, sizeof(lineas), archivo) != NULL)
    {
        p->defensa = atoi(lineas);
    }

    fclose(archivo);
}

int archivo_guardado_vacio(int *indice_archivo_guardado)
{
    char ruta_archivo[30];
    char lineas[100];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d.txt", *indice_archivo_guardado);

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

void estado_personaje(personaje_ *p)
{
    printf("====== %s ======\n", p->nombre);
    printf("[%-7s]: %d\n", "Ataque", p->ataque);
    printf("[%-7s]: %d\n", "Vida", p->puntos_de_vida);
    printf("[%-7s]: %d\n", "Defensa", p->defensa);
}

void guardar_personaje(personaje_ *p, int *indice_archivo_guardado)
{
    char ruta_archivo[30];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d.txt", *indice_archivo_guardado);

    FILE *archivo = fopen(ruta_archivo, "w"); //Por ahora está en save_1 más adelante lo hago dinamico

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }
    
    fprintf(archivo, "%s\n%d\n%d\n%d\n", p->nombre, p->puntos_de_vida, p->ataque, p->defensa);

    fclose(archivo);
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
    printf("\n====(NOMBRE DEL JUEGO EPICO)====\n");
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
    switch (opcion)
    {
    case 1:
        camino();
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
        printf("historial de acciones");
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

void camino(void)
{
    int elegir_ruta;
    printf("0. Para abrir el menu\n");
    printf("1. Para ir a Bosque de Almas\n");
    printf("2. Para ir a Sistema de Cuevas\n");
    printf("3. Para ir a Castillo en Ruinas\n");
    elegir_ruta = elegir_opcion();
    switch (elegir_ruta)
    {
    case 1:
        caminando();
        zona_bosque();
        break;
    case 2:
        caminando();
        //camino_2();
        exit(0);
    case 3:
        caminando();
        //camino_3();
        exit(0);
    default:
        printf("Elige una zona valida!\n");
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

void zona_bosque(void)
{
    int explorando = 1;

    printf("Entrando al Bosque de Almas\n");
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
            }

            else if(evento == 1)
            {
                printf("encontraste un objeto!\n");
            }
            
            else if(evento == 2)
            {
                printf("encontraste a unos enemigos!\n");
            }
        }
        printf("Quieres seguir explorando el Bosque de Almas?\n");

        printf("0. Volver al menu\n");
        printf("1. Seguir explorando\n");
        if (elegir_opcion() == 0)
        {
            explorando = 0;
        }
    }
    
}