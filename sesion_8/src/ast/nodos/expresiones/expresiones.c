#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "expresiones.h"
#include "cuadruplos/cuadruplos.h"

#include <stdlib.h>
#include <stdio.h>

Direccion* interpretExpresionLenguaje(AbstractExpresion* self, Context* context) {
    ExpresionLenguaje* nodo = (ExpresionLenguaje*) self;

    Direccion* izquierda = calcularResultadoIzquierdo(nodo, context);
    Direccion* derecha = calcularResultadoDerecho(nodo, context);
    
    TipoDato tipoResultante = (*nodo->tablaOperaciones)[izquierda->tipo][derecha->tipo];
    printf("resultado %s\n", labelTipoDato[tipoResultante]);
    if (tipoResultante == NO_EXISTE) {
        printf("Operación no soportada para los tipos %s, %s\n",
            labelTipoDato[izquierda->tipo], labelTipoDato[derecha->tipo]);
            return nuevoValorResultadoVacio();
    }
    Direccion* resultado = nuevoTemporalDireccion(generadorC3D->temporal, tipoResultante);
    generadorC3D->temporal += 1;
    Cuadruplo* cuadruplo = buildCuadruplo(nodo->operacion, izquierda, derecha, resultado);
    
    agregarAsignacion(generadorC3D, cuadruplo);
    return resultado;
}

Direccion* interpretUnarioLenguaje(AbstractExpresion* self, Context* context) {
    ExpresionLenguaje* nodo = (ExpresionLenguaje*) self;
    Direccion* izquierda = calcularResultadoIzquierdo(nodo, context);

    TipoDato tipoResultante = (*nodo->tablaOperaciones)[izquierda->tipo][NULO];
    if (tipoResultante == NO_EXISTE) {
        printf("Operación no soportada para el tipo %s\n", 
            labelTipoDato[izquierda->tipo]);
        return nuevoValorResultadoVacio();
    }

    Direccion* resultado = nuevoTemporalDireccion(generadorC3D->temporal, tipoResultante);
    generadorC3D->temporal += 1;

    Cuadruplo* cuadruplo = buildCuadruplo(nodo->operacion, izquierda, NULL, resultado);
    agregarAsignacionUnaria(generadorC3D, cuadruplo);
    return resultado;
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

Direccion* calcularResultadoIzquierdo(ExpresionLenguaje* self, Context* context) {
    return self->base.hijos[0]->interpret(self->base.hijos[0], context);
}

Direccion* calcularResultadoDerecho(ExpresionLenguaje* self, Context* context) {
    return self->base.hijos[1]->interpret(self->base.hijos[1], context);
}
