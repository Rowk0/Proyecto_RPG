#include "commons.h"
#include <unistd.h>

void creacion_personaje(personaje_ *p)
{
    printf("Introduzca el nombre de su personaje:");

    //Posible caso limite
    if (fgets(p->nombre, sizeof(p->nombre), stdin) == NULL)
    {
        printf("Error al leer la entrada");
        return;
    }

    // Elimina el salto de línea sobrante
    p->nombre[strcspn(p->nombre, "\n")] = '\0';
}

void estado_personaje(personaje_ *p)
{
    printf("====== %s ======\n", p->nombre);
    printf("[%-7s]: %d\n", "Ataque", p->ataque);
    printf("[%-7s]: %d\n", "Vida", p->puntos_de_vida);
    printf("[%-7s]: %d\n", "Defensa", p->defensa);
}

void guardar_personaje(personaje_ *p)
{
    FILE *archivo = fopen("save/save_1.txt", "w"); //Por ahora está en save_1 más adelante lo hago dinamico

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
    printf("\t1. Elegir camino\n");
    printf("\t2. Ver personaje\n");
    printf("\t3. Inventario\n");
    printf("\t4. Historial\n");
    printf("\t5. Salir :(\n");
}

void selector_menu(personaje_ *p)
{
    imprimir_menu();
    int opcion = elegir_opcion();
    switch (opcion)
    {
    case 1:
        camino();
        break;
    case 2:
        estado_personaje(p);
        elegir_opcion();
        break;
    case 3:
        printf("opcion ver inventariooo");
        elegir_opcion();
        break;
    case 4:
        printf("historial de acciones");
        elegir_opcion();
        break;
    case 5:
        printf("Cerrando el juego");
        exit(0);
    default:
        printf("Eliga una opcion valida!\n");
        sleep(1);
        selector_menu(p);
    }
}


int elegir_opcion(void)
{
    int opcion;
    printf("\nElige una opcion: ");
    scanf("%d", &opcion);
    //opcion predeterminada 0 para abrir el menu
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
        camino_1();
        break;
    
    default:
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

void camino_1(void)
{
    printf("PRUEBA");
}