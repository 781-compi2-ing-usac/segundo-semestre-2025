#ifndef LLAMADA_FUNCION_H
#define LLAMADA_FUNCION_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
    char* id;
} LlamadaFuncionExpresion;

Result interpretLlamadaFuncionExpresion(AbstractExpresion*, Context*);

#endif