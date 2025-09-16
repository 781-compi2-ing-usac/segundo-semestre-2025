#ifndef ARITMETICAS_H
#define ARITMETICAS_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"
#include "ast/nodos/expresiones/expresiones.h"

extern TipoDato tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT];
extern TipoDato tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT];
extern TipoDato tablaOperacionesUnario[TIPO_COUNT][TIPO_COUNT];

#endif