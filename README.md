# Fanfared Misadventures

RPG de texto en C para el Proyecto 2 de Estructura de Datos. El jugador explora zonas, recoge objetos, administra su inventario y enfrenta grupos de enemigos por terminal. Las listas enlazadas, pilas y colas están implementadas por el grupo, sin bibliotecas externas.

## Estructuras de datos
| Funcionalidad | Estructura | Archivos |
|---|---|---|
| Inventario y botín por zona | Lista simplemente enlazada con nodo centinela | `inv.c` |
| Combate (orden de aparición) | Cola circular (FIFO) sobre arreglo dinámico | `enemigos.c` |
| Historial y deshacer descarte | Pila (LIFO) con nodos enlazados y centinela | `historial.c` |

## Estructura del repositorio
- `src/`: código fuente (`.c`)
- `inc/`: encabezados (`.h`)
- `save/`: partidas (3 ranuras: `save_1`, `save_2`, `save_3`)
- `obj/`: archivos objeto generados al compilar
- `lootpool.csv`: catálogo de objetos del juego
- `Makefile`: compilación (`-Wall -Wextra -Wpedantic`)

## Funcionalidades
- **Personaje:** crear, cargar y ver estado.
- **Exploración:** tres zonas (Bosque de Almas, Sistema de Cuevas, Castillo en Ruinas) con eventos aleatorios: seguir caminando, encontrar un objeto o enfrentar enemigos.
- **Inventario:** listar, buscar, usar, descartar por ID y recuperar el último objeto descartado.
- **Combate:** por turnos contra 1 a 3 enemigos, en orden de aparición.
- **Historial:** acciones de la más reciente a la más antigua.
- **Guardar/Cargar:** se guarda al salir y se carga al elegir ranura.

## Modo de uso
```
make        # compila el proyecto
make run    # ejecuta el juego
make clean  # elimina archivos generados
```

## Autores
- Franco Rodriguez
- Tomás Minte
- Felipe Desmaras

Profesora: Jacqueline Aldridge | Ayudante: Milton Hernandez