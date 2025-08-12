#include "listaExpresiones.h"
#include <stdlib.h>

NodoListaExpresiones* nuevoNodoListaExpresiones() {
    //reservar el espacio en memoria y obtener el puntero a este
    NodoListaExpresiones* n = malloc(sizeof(NodoListaExpresiones));
    if (!n) return NULL;
    //asignar valores
    n->base.ejecutar = ejecutarListaExpresiones;
    n->base.hijos = NULL;
    n->base.numHijos = 0;

    return n;
}

void ejecutarListaExpresiones(NodoBase* self) {
}