#ifndef EXPRESIONS_H
#define EXPRESIONS_H

#include "./../AbstractTerminal.h"

typedef struct {
    AbstractExpresion base;
    char op; /* '+', '-', '*', '/' */
} NodoExpresion;

void ejecutarExpresiones(AbstractExpresion* self);

#endif