#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "declaracion.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretDeclaracionVariable(AbstractExpresion* nodo, Context* context) {
    DeclaracionVariable* self = (DeclaracionVariable*) nodo;
    
    //se esta definiendo
    if (nodo->numHijos > 0) {
        Result resultado = nodo->hijos[0]->interpret(nodo->hijos[0], context);
        if (resultado.tipo == self->tipo) {
            agregarSymbol(context, nuevoVariable(self->nombre, resultado.valor, self->tipo));
            return nuevoValorResultadoVacio();
        }
        printf("Error tipos incorrectos \n");
    }
    agregarSymbol(context, nuevoVariable(self->nombre, NULL,self->tipo));
    return nuevoValorResultadoVacio();
}

AbstractExpresion* nuevoDeclaracionVariables(TipoDato tipo, char* nombre, AbstractExpresion* expresion) {
    //reservar el espacio en memoria y obtener el puntero a este
    DeclaracionVariable* nodo = malloc(sizeof(DeclaracionVariable));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretDeclaracionVariable);
    nodo->tipo = tipo;
    nodo->nombre = nombre;

    if (expresion) agregarHijo((AbstractExpresion*) nodo, expresion);
    return (AbstractExpresion*) nodo;
}
