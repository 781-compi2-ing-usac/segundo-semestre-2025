#ifndef LISTA_ARGUMENTOS_H
#define LISTA_ARGUMENTOS_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
} ListaParametros;

//Result interpretListaExpresiones(AbstractExpresion*, Context*);

#endif