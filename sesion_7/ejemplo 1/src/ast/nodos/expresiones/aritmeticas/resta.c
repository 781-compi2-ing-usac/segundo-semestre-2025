#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

Result restaIntInt(Result izquierda, Result derecha) {
    int* res = malloc(sizeof(int));
    *res = *((int*)izquierda.valor) - *((int*)derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result restaFloatFloat(Result izquierda, Result derecha) {
    float* res = malloc(sizeof(float));
    *res = *((float*)izquierda.valor) - *((float*)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaIntFloat(Result izquierda, Result derecha) {
    float* res = malloc(sizeof(float));
    *res = *((int*)izquierda.valor) - *((float*)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaFloatInt(Result izquierda, Result derecha) {
    float* res = malloc(sizeof(float));
    *res = *((float*)izquierda.valor) - *((int*)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Operacion tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = restaIntInt,
    [FLOAT][FLOAT] = restaFloatFloat,
    [INT][FLOAT] = restaIntFloat,
    [FLOAT][INT] = restaFloatInt,
};

//builders.h
AbstractExpresion* nuevoRestaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* restaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    restaExpresion->tablaOperaciones = &tablaOperacionesResta;
    return (AbstractExpresion*) restaExpresion;
}
