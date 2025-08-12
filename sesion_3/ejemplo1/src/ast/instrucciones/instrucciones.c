#include "instrucciones.h"
#include <stdlib.h>

NodoBloque* nuevoNodoBloque() {
    // asignar memoria
    NodoBloque* n = malloc(sizeof(NodoBloque));
    if (!n) return NULL;

    //asignar valores
    n->base.ejecutar = ejecutarBloque;
    n->base.hijos = NULL;
    n->base.numHijos = 0;
    return n;
}

void ejecutarBloque(NodoBase* self) {
    /* float last = 0.0f;
    for (size_t i = 0; i < self->numHijos; ++i) {
        last = self->hijos[i]->ejecutar(self->hijos[i]);
    }
    return last; */
}
