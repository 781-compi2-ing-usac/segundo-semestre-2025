#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "primitivos.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Result interpretPrimitivoExpresion(AbstractExpresion* self, Context* context) {
    PrimitivoExpresion* nodo = (PrimitivoExpresion*) self;
    Result resultado = nuevoValorResultado(nodo->valor, nodo->tipo);
    resultado.isConstante = true;
}

AbstractExpresion* nuevoPrimitivoExpresion(char* v, char tipo) { //, int lengthValor) {
    //reservar el espacio en memoria y obtener el puntero a este
    PrimitivoExpresion* nodo = malloc(sizeof(PrimitivoExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretPrimitivoExpresion);

    nodo->valor = v;
    nodo->tipo = tipo;
    return (AbstractExpresion*) nodo;
}