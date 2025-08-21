#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "instrucciones.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretInstrucciones(AbstractExpresion* self, Context* context) {
    printf("instrucci\n");
    //InstruccionesExpresion* bloque = (InstruccionesExpresion*) self;
    printf("1\n");
    printf("2\n");
    printf("%ld\n", self->numHijos);
    printf("2\n");

    for (size_t i = 0; i < self->numHijos; ++i) {
        printf("ff %ld\n", i);
        self->hijos[i]->interpret(self->hijos[i], context);
    }
    return nuevoValorResultadoVacio(); 
}

AbstractExpresion* nuevoInstruccionesExpresion() {
    // asignar memoria
    InstruccionesExpresion* nodo = malloc(sizeof(InstruccionesExpresion));
    if (!nodo) return NULL;
    buildAbstractExpresion(&nodo->base, interpretInstrucciones);
    
    return (AbstractExpresion*) nodo;
}
