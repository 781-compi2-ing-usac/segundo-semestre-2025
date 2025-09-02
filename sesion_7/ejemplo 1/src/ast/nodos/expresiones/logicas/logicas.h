#ifndef ARITMETICAS_H
#define ARITMETICAS_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"
#include "ast/nodos/expresiones/expresiones.h"

/* SUMA */
Result compararIntInt(ExpresionLenguaje* self);

extern Operacion tablaOperacionesComparacion[TIPO_COUNT][TIPO_COUNT];

#endif