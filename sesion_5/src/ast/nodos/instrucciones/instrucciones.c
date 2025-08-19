#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"

#include <stdlib.h>
#include <stdio.h>

/* bloque (lista de instrucciones) */
typedef struct {
    AbstractExpresion base;
} InstruccionesExpresion;

Result interpretInstrucciones(AbstractExpresion* self, Context* context) {
    printf("Instrucciones");
    
    for (size_t i = 0; i < self->numHijos; ++i) {
        self->hijos[i]->interpret(self->hijos[i], context);
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion* nuevoInstruccionesExpresion() {
    // asignar memoria
    InstruccionesExpresion* nodo = malloc(sizeof(InstruccionesExpresion));
    if (!nodo) return NULL;
    buildAbstractExpresion(&nodo->base, interpretInstrucciones);
    printf("creando nodo %ld \n", nodo->base.numHijos);
    return (AbstractExpresion*) nodo;
}
