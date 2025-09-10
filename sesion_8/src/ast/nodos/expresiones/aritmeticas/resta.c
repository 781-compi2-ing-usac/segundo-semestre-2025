#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

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
