#include "enemigos.h"
#include "inventario.h"
#include "personaje.h"
#include "game_menu.h"
#include <stdio.h>
#include <unistd.h>



void enemigos_x_zona(personaje_ *p, int elegir_ruta, inventario i)
{
    cola_enemigos Q = crear_cola(3);
    switch (elegir_ruta)
    {
    case 1:
        enemigos_bosque(Q);
        imprimir_enemigos(Q);
        imprimir_combate(p,Q,i);
        break;
    
    case 2:
        enemigos_cuevas(Q);
        imprimir_enemigos(Q);
        imprimir_combate(p,Q,i);
        break;  
    case 3:
        enemigos_castillo(Q);
        imprimir_enemigos(Q);
        imprimir_combate(p,Q,i);
        break;
    default:
        break;
    }
}

void vaciar_cola(cola_enemigos Q)
{
    Q->tamanho = 0;
    Q->front = 1;
    Q->rear = 0;
}

int cola_vacia(cola_enemigos Q)
{
    return Q->tamanho == 0;
}

int cola_llena(cola_enemigos Q)
{
    return Q->tamanho == Q->capacidad;
}

cola_enemigos crear_cola(int max_elementos)
{
    cola_enemigos Q;
    if(max_elementos < MIN_TAMANHO_COLA)
    {
        printf("Error. El tamanho de la cola es muy pequenho\n");
        return NULL;
    }

    Q = malloc(sizeof(struct registro_cola));
    if(Q == NULL)
    {
        printf("Error. Sin espacio en la memoria \n");
        return NULL;
    }

    Q->arreglo = malloc(sizeof(enemigo_) * max_elementos);
    if(Q->arreglo == NULL)
    {
        printf("Error. Sin espacio en la memoria\n");
        free(Q);
        return NULL;
    }

    Q->capacidad = max_elementos;
    vaciar_cola(Q);
    return Q;
}

int sucesor(int valor, cola_enemigos Q)
{
    if(++valor == Q->capacidad)
    {
        valor = 0;
    }
    return valor;
}

cola_enemigos enqueue(enemigo_ X, cola_enemigos Q)
{
    if(cola_llena(Q))
    {
        printf("Error. Cola llena\n");
    }
    else
    {
        Q->tamanho++;
        Q->rear = sucesor(Q->rear, Q);
        Q->arreglo[Q->rear] = X;
    }
    return Q;
}

cola_enemigos dequeue(cola_enemigos Q)
{
    if(cola_vacia(Q))
    {
        printf("Error. Cola vacia\n");
    }
    else
    {
        Q->tamanho--;
        Q->front = sucesor(Q->front, Q);
    }
    return Q;
}

void imprimir_enemigos(cola_enemigos Q)
{
    int indice = Q->front;
    for (int i = 0; i < Q->tamanho; i++)
    {
        printf("  %d. %s (%d PV)\n",
               Q->arreglo[indice].id,
               Q->arreglo[indice].nombre,
               Q->arreglo[indice].puntos_de_vida);
        indice = sucesor(indice, Q);
    }
    sleep(1);
}


void enemigos_bosque(cola_enemigos Q)
{
    int cantidad = rand () % 3 + 1;
    for(int i = 1; i <= cantidad; i++)
    {
        enemigo_ nuevo;
        nuevo.id = i;

        int tipo_enemigo = rand() % 3;
        if(tipo_enemigo == 0)
        {
            strcpy(nuevo.nombre, "Duende");
            nuevo.puntos_de_vida = 10;
            nuevo.ataque = 2;
        }
        if(tipo_enemigo == 1)
        {
            strcpy(nuevo.nombre, "Lobo");
            nuevo.puntos_de_vida = 15;
            nuevo.ataque = 5;
        }
        if(tipo_enemigo == 2)
        {
            strcpy(nuevo.nombre, "Ogro");
            nuevo.puntos_de_vida = 20;
            nuevo.ataque = 7;
        }

        enqueue(nuevo, Q);
    }
}

void enemigos_cuevas(cola_enemigos Q)
{
    int cantidad = rand () % 3 + 1;
    for(int i = 1; i <= cantidad; i++)
    {
        enemigo_ nuevo;
        nuevo.id = i;

        int tipo_enemigo = rand() % 3;
        if(tipo_enemigo == 0)
        {
            strcpy(nuevo.nombre, "Rata Fea");
            nuevo.puntos_de_vida = 20;
            nuevo.ataque = 7;
        }
        if(tipo_enemigo == 1)
        {
            strcpy(nuevo.nombre, "Esqueleto");
            nuevo.puntos_de_vida = 15;
            nuevo.ataque = 5;
        }
        if(tipo_enemigo == 2)
        {
            strcpy(nuevo.nombre, "Aranha Gigante");
            nuevo.puntos_de_vida = 30;
            nuevo.ataque = 9;
        }

        enqueue(nuevo, Q);
    }
}

void enemigos_castillo(cola_enemigos Q)
{
    int cantidad = rand () % 3 + 1;
    for(int i = 1; i <= cantidad; i++)
    {
        enemigo_ nuevo;
        nuevo.id = i;

        int tipo_enemigo = rand() % 3;
        if(tipo_enemigo == 0)
        {
            strcpy(nuevo.nombre, "Caballero Oscuro");
            nuevo.puntos_de_vida = 35;
            nuevo.ataque = 10;
        }
        if(tipo_enemigo == 1)
        {
            strcpy(nuevo.nombre, "Fantasma del Esclavo");
            nuevo.puntos_de_vida = 40;
            nuevo.ataque = 12;
        }
        if(tipo_enemigo == 2)
        {
            strcpy(nuevo.nombre, "Mago Malo");
            nuevo.puntos_de_vida = 45;
            nuevo.ataque = 15;
        }

        enqueue(nuevo, Q);
    }
}

void imprimir_combate(personaje_ *p, cola_enemigos Q, inventario i)
{
    sleep(2);
    printf("\t==== COMBATE ====\n");
    
    while(!cola_vacia(Q) && p->puntos_de_vida > 0)
    {
        enemigo_ *enemigo_actual = &Q->arreglo[Q->front];
        printf("\n%s: %d PV | Ataque %d | Defensa %d\n", p->nombre, p->puntos_de_vida, p->ataque, p->defensa);
        printf("Enemigo actual: %s (%d PV)\n", enemigo_actual->nombre, enemigo_actual->puntos_de_vida);
        printf("Enemigos en espera: %d\n\n", Q->tamanho - 1);
        printf("1. Atacar\n");
        printf("2. Ver inventario\n");
        printf("3. Usar objeto\n");
        sleep(1);

        int opcion = elegir_opcion();
        if(opcion == 1)
        {
            ataque(p,Q);
        }
        else if(opcion == 2)
        {
            imprimir_objetos(i);
        }
        else if(opcion == 3)
        {
            i = usar_objeto_por_id(i, *p, *enemigo_actual);
        }
        else
        {
            printf("Elige una opcion valida!\n");
        }        
    }

    if(p->puntos_de_vida <= 0)
    {
        printf("\nHas sido derrotado...");
        p->historial = push(p->historial, "Has sido derrotado en combate\n");
    }
    else
    {
        printf("Has ganado el combate!");
        p->historial = push(p->historial, "Has ganado un combate!\n");
    }
}

void ataque(personaje_ *p, cola_enemigos Q)
{
    enemigo_ *enemigo_actual = &Q->arreglo[Q->front];
    enemigo_actual->puntos_de_vida -= p->ataque;
    if(enemigo_actual->puntos_de_vida < 0)
    {
        //para que no quede vida negativa
        enemigo_actual->puntos_de_vida = 0;
    }
    printf("Atacas a %s, le haces %d de Danho.\n", enemigo_actual->nombre, p->ataque);
    printf("%s: %d PV\n", enemigo_actual->nombre, enemigo_actual->puntos_de_vida);
    sleep(2);

    if(enemigo_actual->puntos_de_vida == 0)
    {
        printf("Mataste a %s.  EPICO\n", enemigo_actual->nombre);

        char accion[64]; //variable accion para guardar la frase y poder mostrarla en historial
        snprintf(accion, sizeof(accion), "Mataste al enemigo %s\n", enemigo_actual->nombre);
        p->historial = push(p->historial, accion);

        dequeue(Q);
        return;
    }

    int danho_enemigo = enemigo_actual->ataque - p->defensa;
    
    if(danho_enemigo < 0)
    {
        danho_enemigo = 0;
    }

    p->puntos_de_vida -= danho_enemigo;
    if(p->puntos_de_vida < 0)
    {
        p->puntos_de_vida = 0; //para no tener vida negativa
    }

    printf("%s te ataca, recibes %d de danho\n", enemigo_actual->nombre, danho_enemigo);
    printf("Tienes %d PV", p->puntos_de_vida);
    sleep(2);
    system("clear");
}

inventario usar_objeto_por_id(inventario i, personaje_ personaje, enemigo_ enemigo)
{
	if(inventario_vacio(i) == true)
	{
		return i;
	}

	int id;
	int escanear = 0;

	imprimir_objetos(i);

	printf("Ingrese la id del objeto a utilizar: ");
	escanear = scanf("%d", &id);
	while(escanear != 1)
	{
		printf("Seleccion invalida, intente de nuevo: ");
	}

	posicion p;
	p = encontrar_objeto_por_id(i, id);

	// Accionar el objeto
	switch(p->objeto.clase)
	{
		case EQUIPABLE:
		{
			switch(id) 
			{
				case 1:
				{
					personaje.ataque = 8;
					break;
				}
				case 2:
				{
					personaje.ataque = 12;
					break;
				}
				case 3:
				{
					personaje.ataque = 16;
					break;
				}
				default:
				{
					printf("Error de usar_objeto_por_id: Equipable ausente\n");
					break;
				}
			}
			break;
		}
		case CONSUMIBLE:
		{
			switch(id) 
			{
				case 4:
				{
					personaje.puntos_de_vida += 15;
					break;
				}
				case 5:
				{
					personaje.regeneracion = 4; 
					break;
				}
				case 6:
				{
					personaje.puntos_de_vida += 30;
					break;
				}
				case 7:
				{
					enemigo.puntos_de_vida -= 30;
					break;
				}
				case 8:
				{
					enemigo.envenenado = true;
					break;
				}
				case 9:
				{
					personaje.espejo_activo = true;
					break;
				}
				default:
				{
					printf("Error de usar_objeto_por_id: Consumible ausente\n");
					break;
				}
			}
			eliminar_objeto_por_id(i, id);
			break;
		}
		case ACCESORIO:
		{
			switch(id)
			{
				case 10:
				{
					personaje.accesorio = BANDANA_NINJA;
					break;
				}
				case 11:
				{
					personaje.accesorio = ARO_CARMESI;
					break;
				}
				case 12:
				{
					personaje.accesorio = CORONA_REY;
					break;
				}
				default:
				{
					printf("Error de usar_objeto_por_id: Accesorio ausente\n");
					break;
				}
			}
			eliminar_objeto_por_id(i, id);
			break;
		}
		default:
		{
			printf("Error de usar_objeto_por_id: Clase invalida\n");
			break;
		}
	}

	return i;
}
