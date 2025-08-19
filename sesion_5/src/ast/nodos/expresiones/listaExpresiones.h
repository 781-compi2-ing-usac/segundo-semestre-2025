#ifndef LISTA_EXPRESIONS_H
#define LISTA_EXPRESIONS_H

#include "./../AbstractTerminal.h"

typedef struct {
    AbstractExpresion base;
} NodoListaExpresiones;

void ejecutarListaExpresiones(AbstractExpresion* self);

#endif