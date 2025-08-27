#ifndef LISTA_EXPRESIONS_H
#define LISTA_EXPRESIONS_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
} ListaExpresiones;

//Result interpretListaExpresiones(AbstractExpresion*, Context*);

#endif