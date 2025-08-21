#ifndef EXPRESIONES_H
#define EXPRESIONES_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

typedef struct {
    AbstractExpresion base;
    Result izquierda;
    Result derecha;
} ExpresionLenguaje;

AbstractExpresion* nuevoExpresionLenguaje(Interpret funcionEspecifica, AbstractExpresion* izquierda, AbstractExpresion* derecha);
bool validarTipos(Result resultado1, Result resultado2);
void calcularResultadoIzquierdo(AbstractExpresion* self);
void calcularResultadoDerecho(AbstractExpresion* self);
void calcularResultados(AbstractExpresion* self);
#endif