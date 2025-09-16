#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "ast/nodos/expresiones/expresiones.h"
#include "logicas.h"

#include <stdlib.h>
#include <stdbool.h>

TipoDato tablaOperacionesComparacion[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = BOOLEAN,
};

//builders.h
AbstractExpresion* nuevoComparacionExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* restaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    restaExpresion->tablaOperaciones = &tablaOperacionesComparacion;
    return (AbstractExpresion*) restaExpresion;
}
