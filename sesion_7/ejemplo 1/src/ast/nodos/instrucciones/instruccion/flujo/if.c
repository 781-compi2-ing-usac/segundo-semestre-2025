#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "if.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


Result interpretIfExpresion(AbstractExpresion* self, Context* context) {
    //nuevo env
    Context* nuevoContexto = nuevoContext(context);
    IfExpresion* nodo = (IfExpresion*) self;
    //todavia contexto anterior
    Result result = self->hijos[0]->interpret(self->hijos[0], context);
    
    if (result.tipo == BOOLEAN) {
        if (*((bool*) result.valor)) {
            //bloque de instrucciones verdadero
            return self->hijos[1]->interpret(self->hijos[1], nuevoContexto);
        } else if (nodo->isElseif) {
            //le pasa el contexto padre
            return self->hijos[2]->interpret(self->hijos[2], context);
        } else if (nodo->isElse) {
            //nuevo contexto
            return self->hijos[2]->interpret(self->hijos[2], nuevoContexto);
        }
    } else {
        printf("Error se esperaba True o false\n no: %s", labelTipoDato[result.tipo]);
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion* nuevoIfExpresion(AbstractExpresion* expresion, AbstractExpresion* bloqueTrue) {
    //reservar el espacio en memoria y obtener el puntero a este
    IfExpresion* nodo = malloc(sizeof(IfExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretIfExpresion);
    nodo->isElse = false;
    nodo->isElseif = false;

    agregarHijo((AbstractExpresion*) nodo, expresion);
    agregarHijo((AbstractExpresion*) nodo, bloqueTrue);

    return (AbstractExpresion*) nodo;
}

AbstractExpresion* nuevoIfElseExpresion(AbstractExpresion* expresion, AbstractExpresion* bloqueTrue, AbstractExpresion* bloqueFalse) {
    //reservar el espacio en memoria y obtener el puntero a este
    IfExpresion* nodo = malloc(sizeof(IfExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretIfExpresion);
    nodo->isElse = true;
    nodo->isElseif = false;

    agregarHijo((AbstractExpresion*) nodo, expresion);
    agregarHijo((AbstractExpresion*) nodo, bloqueTrue);
    agregarHijo((AbstractExpresion*) nodo, bloqueFalse);
    return (AbstractExpresion*) nodo;
}

AbstractExpresion* nuevoElseIfExpresion(AbstractExpresion* expresion, AbstractExpresion* bloqueTrue, AbstractExpresion* IfExpresionSiguiente) {
    //reservar el espacio en memoria y obtener el puntero a este
    IfExpresion* nodo = malloc(sizeof(IfExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretIfExpresion);
    nodo->isElse = false;
    nodo->isElseif = true;

    agregarHijo((AbstractExpresion*) nodo, expresion);
    agregarHijo((AbstractExpresion*) nodo, bloqueTrue);
    agregarHijo((AbstractExpresion*) nodo, IfExpresionSiguiente);
    return (AbstractExpresion*) nodo;
}