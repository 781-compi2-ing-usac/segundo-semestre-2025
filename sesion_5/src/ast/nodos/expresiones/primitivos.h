#ifndef PRIMITIVOS_H
#define PRIMITIVOS_H

#include "./../AbstractTerminal.h"

typedef struct {
    AbstractExpresion base;
    char* valor;
    char tipo;
} NodoPrimitivo;

void ejecutarPrimitivo(AbstractExpresion* self);

#endif