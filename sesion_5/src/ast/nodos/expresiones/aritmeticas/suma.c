#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

Result sumarIntInt(ExpresionLenguaje* self) {
    int* res = malloc(sizeof(int));
    *res =  *((int*)self->izquierda.valor) + *((int*)self->derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result sumarFloatFloat(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = *((float*)self->izquierda.valor) + *((float*)self->derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarIntFloat(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = *((int*)self->izquierda.valor) + *((float*)self->derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarFloatInt(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = *((float*)self->izquierda.valor) + *((int*)self->derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = sumarIntInt,
    [FLOAT][FLOAT] = sumarFloatFloat,
    [INT][FLOAT] = sumarIntFloat,
    [FLOAT][INT] = sumarFloatInt,
};

//builders.h
AbstractExpresion* nuevoSumaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* sumaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    sumaExpresion->tablaOperaciones = &tablaOperacionesSuma;
    return (AbstractExpresion*) sumaExpresion;
}
