#ifndef LISTA_EXPRESIONS_H
#define LISTA_EXPRESIONS_H

#include "./../AbstractTerminal.h"

typedef struct {
    NodoBase base;
} NodoListaExpresiones;

NodoListaExpresiones* nuevoNodoListaExpresiones();
void ejecutarListaExpresiones(NodoBase* self);

#endif