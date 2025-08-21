#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "primitivos.h"

#include <stdlib.h>
#include <stdio.h>


Result interpretPrimitivoExpresion(AbstractExpresion* self, Context* context) {
    PrimitivoExpresion* nodo = (PrimitivoExpresion*) self;
    switch (nodo->tipo) {
        case 'I':
            int valor = atoi(nodo->valor);
            return nuevoValorResultado((void*) &valor, nodo->tipo);
    }
    return nuevoValorResultadoVacio();
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