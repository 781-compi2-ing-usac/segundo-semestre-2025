#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>

Result negarAritmeticoInt(ExpresionLenguaje* self) {
    int* res = malloc(sizeof(int));
    *res = - *((int*)self->izquierda.valor);
    return nuevoValorResultado(res, INT);
}

Result negarAritmeticoFloat(ExpresionLenguaje* self) {
    float* res = malloc(sizeof(float));
    *res = - *((float*)self->izquierda.valor);
    return nuevoValorResultado(res, FLOAT);
}

Operacion tablaOperacionesUnario[TIPO_COUNT][TIPO_COUNT] = {
    [INT][NULO] = negarAritmeticoInt,
    [FLOAT][NULO] = negarAritmeticoFloat,
};

//builders.h
AbstractExpresion* nuevoUnarioExpresion(AbstractExpresion* expresion) {
    ExpresionLenguaje* unarioExpresion = nuevoExpresionLenguaje(interpretUnarioLenguaje, expresion, NULL);
    unarioExpresion->tablaOperaciones = &tablaOperacionesUnario;
    return (AbstractExpresion*) unarioExpresion;
}
