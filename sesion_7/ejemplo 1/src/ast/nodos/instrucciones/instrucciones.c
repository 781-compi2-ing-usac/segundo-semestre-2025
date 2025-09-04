#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "instrucciones.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretInstrucciones(AbstractExpresion* self, Context* context) {
    for (size_t i = 0; i < self->numHijos; ++i) {
        Result resultadoSentencia = self->hijos[i]->interpret(self->hijos[i], context);
        if (resultadoSentencia.isReturn) {
            return resultadoSentencia;
        }
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
