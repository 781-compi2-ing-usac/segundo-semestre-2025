#ifndef RETURN_H
#define RETURN_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
} ReturnExpresion;

Result interpretReturnExpresion(AbstractExpresion*, Context*);

#endif
