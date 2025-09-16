#include "cuadruplos/cuadruplos.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void generarEnsamblador() {
    printf("Sin implementar\n");
}

void agregarAsignacion(GeneradorC3D* generador, Cuadruplo* dato) {
    dato->generar = generarEnsamblador;
    
    CuadruploItem* item = malloc(sizeof(CuadruploItem));
    item->dato = *dato;
    item->siguiente = NULL;
    item->anterior = generador->ultimo;
    if (generador->ultimo) {
        generador->ultimo->siguiente = item;
    } else {
        generador->primero = item;
    }
    generador->ultimo = item;
}