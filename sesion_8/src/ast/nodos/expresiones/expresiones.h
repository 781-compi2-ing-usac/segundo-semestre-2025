#ifndef EXPRESIONES_H
#define EXPRESIONES_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct ExpresionLenguaje ExpresionLenguaje;

struct ExpresionLenguaje{
    AbstractExpresion base;
    TipoDato (*tablaOperaciones)[TIPO_COUNT][TIPO_COUNT];
};


//interpret basico de expresiones
Result interpretExpresionLenguaje(AbstractExpresion* self, Context* context);
Result interpretUnarioLenguaje(AbstractExpresion* self, Context* context);
//constructor
ExpresionLenguaje* nuevoExpresionLenguaje(Interpret funcionEspecifica, AbstractExpresion* izquierda, AbstractExpresion* derecha);

Result calcularResultadoIzquierdo(ExpresionLenguaje* self, Context* context);
Result calcularResultadoDerecho(ExpresionLenguaje* self, Context* context);
#endif