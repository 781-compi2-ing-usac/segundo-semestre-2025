#ifndef EXPRESIONES_H
#define EXPRESIONES_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
    char* nombre;
} IdentificadorExpresion;

Result interpretIdentificadorExpresion(AbstractExpresion*, Context*);
#endif