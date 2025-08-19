#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "./../../AbstractTerminal.h"

/* bloque (lista de instrucciones) */
typedef struct {
    AbstractExpresion base;
} NodoImprimir;

void ejecutarImprimir(AbstractExpresion* self);

#endif