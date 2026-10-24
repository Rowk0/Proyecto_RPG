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
    printf("\t1. Caminar\n");
    printf("\t2. Ver personaje\n");
    printf("\t3. Inventario\n");
    printf("\t4. Historial\n");
    printf("\t5. Salir :(\n");
}

void selector_menu(personaje_ *p, int *loop_juego)
{
    int opcion;
    printf("Elige una opcion:");
    if (scanf("%d", &opcion) != 1)
    {
        printf("Entrada invalida\n");
        return;
    }

    switch (opcion)
    {
    case 1:
        printf("opcion caminando..");
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
        printf("\nIngresa 0 para abrir el menu: ");
        while (scanf("%d",&opcion) != 1);
    }
}
