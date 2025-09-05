#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "primitivos.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
    CREAR SIEMPRE NUEVO ESPACIO DE MEMORIA PARA ESTE ESCENARIO CON malloc
    porque si usamos la direccion de memoria de esa variable, es posible que el garbage
    collector la elimine por ser variable local
*/
Result interpretPrimitivoExpresion(AbstractExpresion* self, Context* context) {
    PrimitivoExpresion* nodo = (PrimitivoExpresion*) self;
    switch (nodo->tipo) {
        case INT:
            int* valorint = malloc(sizeof(int));
            *valorint = atoi(nodo->valor);
            return nuevoValorResultado((void*) valorint, nodo->tipo);
        case BOOLEAN:
            bool* valorbool = malloc(sizeof(bool));
            if (*nodo->valor == 'T') {
                *valorbool = true;
            } else if (*nodo->valor == 'F') {
                *valorbool = false;
            } else {
                printf("Error desconocido al convertir el boolean\n");
            }
            return nuevoValorResultado((void*) valorbool, nodo->tipo);
        case FLOAT:
            float* valorfloat = malloc(sizeof(float));
            *valorfloat = atof(nodo->valor);
            return nuevoValorResultado((void*) valorfloat, nodo->tipo);
        case STRING:
            return nuevoValorResultado((void*) nodo->valor, nodo->tipo);
        default:
            printf("Tipo de dato primitivo no implementado\n");
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