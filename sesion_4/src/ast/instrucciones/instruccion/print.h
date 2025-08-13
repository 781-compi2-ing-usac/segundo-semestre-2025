#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "./../../AbstractTerminal.h"

/* bloque (lista de instrucciones) */
typedef struct {
    NodoBase base;
} NodoImprimir;

NodoImprimir* nuevoNodoImprimir(NodoBase* listaExpresiones);
void ejecutarImprimir(NodoBase* self);

#endif