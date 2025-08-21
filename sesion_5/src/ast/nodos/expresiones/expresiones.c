#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "expresiones.h"

#include <stdlib.h>
#include <stdio.h>


Result interpretExpresionLenguaje(AbstractExpresion* self, Context* context) {
    printf("en expresion\n");
    ExpresionLenguaje* nodo = (ExpresionLenguaje*) self;
    Result resultado1;
    Result resultado2;

    if (nodo->base.numHijos > 0) {
        resultado1 = nodo->base.hijos[0]->interpret(nodo->base.hijos[0], context);
    }

    if (nodo->base.numHijos > 1) {
        resultado2 = nodo->base.hijos[1]->interpret(nodo->base.hijos[1], context);
    }
    switch (nodo->op) {
        case '+':
            if (resultado1.tipo == resultado2.tipo && resultado1.tipo == 'I') {
                int valorFinal = *((int*) resultado1->valor) + *((int*) resultado2.valor);
                Result resultadoFinal = nuevoValorResultado((void* ) &valorFinal, 'I');
                return resultadoFinal;
            }
        case '-':
            if (resultado1.tipo == resultado2.tipo && resultado1.tipo == 'I') {
                int valorFinal = *((int*) resultado1->valor) + *((int*) resultado2.valor);
                Result resultadoFinal = nuevoValorResultado((void* ) &valorFinal, 'I');
                return resultadoFinal;
            }
        default:
            fprintf(stderr, "Unknown operator %c\n", nodo->op);
            return nuevoValorResultadoVacio();
    }
}

AbstractExpresion* nuevoExpresionLenguaje(Interpret funcionEspecifica, AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    // reservar el espacio en memoria y obtener el puntero a este
    ExpresionLenguaje* nodo = malloc(sizeof(ExpresionLenguaje));
    if (!nodo) return NULL;

    //asignar valores
    buildAbstractExpresion(&nodo->base, funcionEspecifica);

    //guardar los punteros en lo hijos de este arbol a los lados de la expresion
    if (izquierda) agregarHijo((AbstractExpresion*) nodo, izquierda);
    if (derecha) agregarHijo((AbstractExpresion*) nodo, derecha);
    
    return (AbstractExpresion*) nodo;
}

bool validarTipos(Result resultado1, Result resultado2) {
    return true;
}

void calcularResultadoIzquierdo(ExpresionLenguaje* self) {
    self->izquierda = self->hijos[0]->interpret(self->hijos[0], context);
}

void calcularResultadoDerecho(ExpresionLenguaje* self) {
    self->derecha = self->hijos[1]->interpret(self->hijos[1], context);
}

void calcularResultados(ExpresionLenguaje* self) {
    calcularResultadoIzquierdo(self);
    calcularResultadoDerecho(self);
}