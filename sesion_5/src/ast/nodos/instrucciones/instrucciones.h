#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"


/* bloque (lista de instrucciones) */
typedef struct {
    AbstractExpresion base;
} InstruccionesExpresion;

AbstractExpresion* nuevoInstruccionesExpresion(void);
Result interpretInstrucciones(AbstractExpresion* self, Context* context);

#endif