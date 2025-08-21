#ifndef EXPRESIONES_H
#define EXPRESIONES_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
    char* valor;
    char tipo;
    int lengthValor;
} PrimitivoExpresion;

Result interpretPrimitivoExpresion(AbstractExpresion*, Context*);
#endif