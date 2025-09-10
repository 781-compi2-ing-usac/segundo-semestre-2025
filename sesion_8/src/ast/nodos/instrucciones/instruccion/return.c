#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "return.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretReturnExpresion(AbstractExpresion* self, Context* context) {
    if (self->numHijos == 1) {
        Result resultadoReturn = self->hijos[0]->interpret(self->hijos[0], context);
        resultadoReturn.isReturn = true;
        return resultadoReturn;
    } else {
        Result resultadoVacio = nuevoValorResultadoVacio();
        resultadoVacio.isReturn = true;
        return resultadoVacio;
    }
}

AbstractExpresion* nuevoReturnExpresion(AbstractExpresion* expresion) {
    //reservar el espacio en memoria y obtener el puntero a este
    ReturnExpresion* nodo = malloc(sizeof(ReturnExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretReturnExpresion);

    if (expresion) agregarHijo((AbstractExpresion*) nodo, expresion);
    
    return (AbstractExpresion*) nodo;
}