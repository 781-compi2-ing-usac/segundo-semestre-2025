#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "expresiones.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretExpresionLenguaje(AbstractExpresion* self, Context* context) {
    ExpresionLenguaje* nodo = (ExpresionLenguaje*) self;

    Result izquierda = calcularResultadoIzquierdo(nodo, context);
    Result derecha = calcularResultadoDerecho(nodo, context);
    
    Operacion op = (*nodo->tablaOperaciones)[izquierda.tipo][derecha.tipo];
    if (op == NULL) {
        printf("Operación no soportada para los tipos %s, %s\n", 
            labelTipoDato[izquierda.tipo], labelTipoDato[derecha.tipo]);
            return nuevoValorResultadoVacio();
    }
    return op(izquierda, derecha);
}

Result interpretUnarioLenguaje(AbstractExpresion* self, Context* context) {
    ExpresionLenguaje* nodo = (ExpresionLenguaje*) self;
    Result izquierda = calcularResultadoIzquierdo(nodo, context);

    Operacion op = (*nodo->tablaOperaciones)[izquierda.tipo][NULO];
    if (op == NULL) {
        printf("Operación no soportada para el tipo %s\n", 
            labelTipoDato[izquierda.tipo]);
        return nuevoValorResultadoVacio();
    }
    return op(izquierda, nuevoValorResultadoVacio());
}

ExpresionLenguaje* nuevoExpresionLenguaje(Interpret funcionEspecifica, AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    // reservar el espacio en memoria y obtener el puntero a este
    ExpresionLenguaje* nodo = malloc(sizeof(ExpresionLenguaje));
    if (!nodo) return NULL;

    //asignar valores
    buildAbstractExpresion(&nodo->base, funcionEspecifica);

    //guardar los punteros en lo hijos de este arbol a los lados de la expresion
    if (izquierda) agregarHijo((AbstractExpresion*) nodo, izquierda);
    if (derecha) agregarHijo((AbstractExpresion*) nodo, derecha);
    
    return nodo;
}

Result calcularResultadoIzquierdo(ExpresionLenguaje* self, Context* context) {
    return self->base.hijos[0]->interpret(self->base.hijos[0], context);
}

Result calcularResultadoDerecho(ExpresionLenguaje* self, Context* context) {
    return self->base.hijos[1]->interpret(self->base.hijos[1], context);
}
