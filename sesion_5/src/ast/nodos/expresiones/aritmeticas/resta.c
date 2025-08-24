#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

Result restaIntInt(ExpresionLenguaje* self) {
    int* res = malloc(sizeof(int));
    *res = *((int*)self->izquierda.valor) - *((int*)self->derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result restaFloatFloat(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = *((float*)self->izquierda.valor) - *((float*)self->derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaIntFloat(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = *((int*)self->izquierda.valor) - *((float*)self->derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result restaFloatInt(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = *((float*)self->izquierda.valor) - *((int*)self->derecha.valor);
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
