#include "acciones.h"

/* Recalcula bonos a partir del inventario. Llamar tras insertar/eliminar objetos. */
void actualizar_equipo(personaje_ *p, inventario inv)
{
    int mejor_arma = 0;
    int accesorio = 0;

    for (posicion pos = inv->siguiente; pos != NULL; pos = pos->siguiente)
    {
        switch (pos->objeto.clase)
        {
        case 1:
        {
            int bono = 0;
            switch (pos->objeto.id)
            {
            case 1: bono = 8;  break;
            case 5: bono = 12; break;
            case 9: bono = 16; break;
            }
            if (bono > mejor_arma) mejor_arma = bono;
            break;
        }
        case 3:
            /* prioridad simple: se queda con el de mayor id */
            if (pos->objeto.id > accesorio) accesorio = pos->objeto.id;
            break;
        }
    }

    //p->ataque = p->ataque_base + mejor_arma;
    p->accesorio = accesorio;
}