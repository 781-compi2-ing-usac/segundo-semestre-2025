#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

#include <stdlib.h>
#include <stdio.h>

TipoDato tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = INT,
    [FLOAT][FLOAT] = FLOAT,
    [INT][FLOAT] = FLOAT,
    [FLOAT][INT] = FLOAT,
};

//builders.h
AbstractExpresion* nuevoSumaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* sumaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    sumaExpresion->tablaOperaciones = &tablaOperacionesSuma;
    return (AbstractExpresion*) sumaExpresion;
}
