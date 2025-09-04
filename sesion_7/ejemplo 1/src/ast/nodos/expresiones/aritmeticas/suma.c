#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

Result sumarIntInt(Result izquierda, Result derecha) {
    int* res = malloc(sizeof(int));
    *res =  *((int*) izquierda.valor) + *((int*) derecha.valor);
    return nuevoValorResultado(res, INT);
}

Result sumarFloatFloat(Result izquierda, Result derecha) {
    float* res = malloc(sizeof(float));
    *res = *((float*)izquierda.valor) + *((float*)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarIntFloat(Result izquierda, Result derecha) {
    float* res = malloc(sizeof(float));
    *res = *((int*)izquierda.valor) + *((float*)derecha.valor);
    return nuevoValorResultado(res, FLOAT);
}

Result sumarFloatInt(Result izquierda, Result derecha) {
    float* res = malloc(sizeof(float));
    *res = *((float*)izquierda.valor) + *((int*)derecha.valor);
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
