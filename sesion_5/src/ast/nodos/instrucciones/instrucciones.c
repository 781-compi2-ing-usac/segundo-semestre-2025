#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include <stdlib.h>

/* bloque (lista de instrucciones) */
typedef struct {
    AbstractExpresion base;
} InstruccionesExpresion;

AbstractExpresion* nuevoInstruccionesExpresion() {
    buildAbstractExpresion(ejecutarBloque);
    // asignar memoria
    InstruccionesExpresion* n = malloc(sizeof(InstruccionesExpresion));
    if (!n) return NULL;

    //asignar valores
    n->base.ejecutar = ejecutarBloque;
    n->base.hijos = NULL;
    n->base.numHijos = 0;
    return n;
}

void ejecutarBloque(AbstractExpresion* self) {
    /* float last = 0.0f;
    for (size_t i = 0; i < self->numHijos; ++i) {
        last = self->hijos[i]->ejecutar(self->hijos[i]);
    }
    return last; */
}
