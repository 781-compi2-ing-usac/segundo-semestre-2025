#ifndef EXPRESIONES_H
#define EXPRESIONES_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"
#include "cuadruplos/cuadruplos.h"

typedef struct ExpresionLenguaje ExpresionLenguaje;

struct ExpresionLenguaje{
    AbstractExpresion base;
    TipoDato (*tablaOperaciones)[TIPO_COUNT][TIPO_COUNT];
    OperacionC3D operacion;
};


//interpret basico de expresiones
Direccion* interpretExpresionLenguaje(AbstractExpresion* self, Context* context);
Direccion* interpretUnarioLenguaje(AbstractExpresion* self, Context* context);
//constructor
ExpresionLenguaje* nuevoExpresionLenguaje(Interpret funcionEspecifica, AbstractExpresion* izquierda, AbstractExpresion* derecha);

Direccion* calcularResultadoIzquierdo(ExpresionLenguaje* self, Context* context);
Direccion* calcularResultadoDerecho(ExpresionLenguaje* self, Context* context);
#endif