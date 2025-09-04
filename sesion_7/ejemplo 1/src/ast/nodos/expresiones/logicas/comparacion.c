#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "logicas.h"

#include <stdlib.h>
#include <stdbool.h>

Result compararIntInt(Result izquierda, Result derecha) {
    bool* res = malloc(sizeof(bool));
    *res = *((int*) izquierda.valor) == *((int*) derecha.valor);
    return nuevoValorResultado(res, BOOLEAN);
}

Operacion tablaOperacionesComparacion[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = compararIntInt,
};

//builders.h
AbstractExpresion* nuevoComparacionExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* restaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    restaExpresion->tablaOperaciones = &tablaOperacionesComparacion;
    return (AbstractExpresion*) restaExpresion;
}
