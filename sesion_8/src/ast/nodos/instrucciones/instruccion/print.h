#ifndef PRINT_H
#define PRINT_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
} PrintExpresion;

Direccion* interpretPrintExpresion(AbstractExpresion*, Context*);

#endif
