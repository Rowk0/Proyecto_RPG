#include "personaje.h"

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

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d/save.txt", *indice_archivo_guardado);

    FILE *archivo = fopen(ruta_archivo, "r"); //Por ahora está en save_1 más adelante lo hago dinamico

    if (archivo == NULL)
    {
        printf("Error al abrir el cargar el personaje");
        return;
    }

    if (fgets(lineas, sizeof(lineas), archivo) != NULL)
    {
        lineas[strcspn(lineas, "\n")] = '\0';

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

void estado_personaje(personaje_ *p)
{
    printf("====== %s ======\n", p->nombre);
    printf("[%-7s]: %d\n", "Ataque", p->ataque);
    printf("[%-7s]: %d\n", "Vida", p->puntos_de_vida);
    printf("[%-7s]: %d\n", "Defensa", p->defensa);
    printf("[%-7s]: %d\n", "Accesorio", p->accesorio);
    printf("[%-7s]: %d\n", "Regeneracion", p->regeneracion);
    printf("[%-7s]: %d\n", "Espejo activo", p->espejo_activo);
    printf("[%-7s]: %d\n", "Ataque total", p->ataque_total);
}

void guardar_personaje(personaje_ *p, int *indice_archivo_guardado)
{
    char ruta_archivo[30];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d/save.txt", *indice_archivo_guardado);

    FILE *archivo = fopen(ruta_archivo, "w"); 

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }
    
    fprintf(archivo, "%s\n%d\n%d\n%d\n", p->nombre, p->puntos_de_vida, p->ataque, p->defensa);

    fclose(archivo);
}

int archivo_guardado_vacio(int *indice_archivo_guardado)
{
    char ruta_archivo[30];
    char lineas[100];

    snprintf(ruta_archivo, sizeof(ruta_archivo), "save/save_%d/save.txt", *indice_archivo_guardado);
    FILE *archivo = fopen(ruta_archivo, "r"); 

    if (archivo == NULL)
    {
        printf("Error al verificar si el arhcivo de guardado esta vacio");
        return -1;
    }

    if (fgets(lineas, sizeof(lineas), archivo) == NULL)
    {
        printf("El archivo se encuentra vacio\n");
        return 1;
    }

    return 0;
}
