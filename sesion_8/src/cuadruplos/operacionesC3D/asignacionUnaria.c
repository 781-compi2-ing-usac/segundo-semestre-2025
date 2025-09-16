#include "cuadruplos/cuadruplos.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void generarEnsambladorUnaria() {
    printf("Sin implementar\n");
}

void agregarAsignacionUnaria(GeneradorC3D* generador, Cuadruplo* dato) {
    dato->generar = generarEnsambladorUnaria;
    
    CuadruploItem* item = malloc(sizeof(CuadruploItem));
    item->dato = *dato;
    item->siguiente = NULL;
    item->anterior = generador->ultimo;
    if (generador->ultimo) {
        generador->ultimo->siguiente = item;
    }  else {
        generador->primero = item;
    }
    generador->ultimo = item;
}
