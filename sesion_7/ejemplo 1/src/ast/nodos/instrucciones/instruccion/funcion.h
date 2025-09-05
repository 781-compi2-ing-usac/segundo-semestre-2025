#ifndef FUNCION_H
#define FUNCION_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
    char* nombre;
    TipoDato tipo;
} FuncionExpresion;

Result interpretFuncionExpresion(AbstractExpresion*, Context*);

#endif
