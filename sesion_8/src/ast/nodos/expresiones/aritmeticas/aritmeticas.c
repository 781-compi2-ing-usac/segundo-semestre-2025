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

TipoDato tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT] = {
    [INT][INT] = INT,
    [FLOAT][FLOAT] = FLOAT,
    [INT][FLOAT] = FLOAT,
    [FLOAT][INT] = FLOAT,
};

TipoDato tablaOperacionesUnario[TIPO_COUNT][TIPO_COUNT] = {
    [INT][NULO] = INT,
    [FLOAT][NULO] = FLOAT,
};

//builders.h
AbstractExpresion* nuevoSumaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* sumaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    sumaExpresion->operacion = SUMA;
    sumaExpresion->tablaOperaciones = &tablaOperacionesSuma;
    return (AbstractExpresion*) sumaExpresion;
}

//builders.h
AbstractExpresion* nuevoRestaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    ExpresionLenguaje* restaExpresion = nuevoExpresionLenguaje(interpretExpresionLenguaje, izquierda, derecha);
    restaExpresion->operacion = RESTA;
    restaExpresion->tablaOperaciones = &tablaOperacionesResta;
    return (AbstractExpresion*) restaExpresion;
}

//builders.h
AbstractExpresion* nuevoUnarioExpresion(AbstractExpresion* expresion) {
    ExpresionLenguaje* unarioExpresion = nuevoExpresionLenguaje(interpretUnarioLenguaje, expresion, NULL);
    unarioExpresion->operacion = MENOS_ARITMETICA;
    unarioExpresion->tablaOperaciones = &tablaOperacionesUnario;
    return (AbstractExpresion*) unarioExpresion;
}
