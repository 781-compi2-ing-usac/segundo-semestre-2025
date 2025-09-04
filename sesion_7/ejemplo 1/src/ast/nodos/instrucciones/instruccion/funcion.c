#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "funcion.h"

#include <stdlib.h>
#include <stdio.h>

//solo se declara y guarda la referencia del subarbol de la funcion para ejectuar en la llamada
Result interpretFuncionExpresion(AbstractExpresion* nodo, Context* context) {
    FuncionExpresion* self = (FuncionExpresion*) nodo;

    agregarSymbol(context, nuevaFuncion(self->nombre, self->tipo, &self->base));
    return nuevoValorResultadoVacio();
}

AbstractExpresion* nuevoFuncionExpresion(TipoDato tipoDato, char* nombre, AbstractExpresion* ListaParametros, AbstractExpresion* bloque) {
    //reservar el espacio en memoria y obtener el puntero a este
    FuncionExpresion* nodo = malloc(sizeof(FuncionExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretFuncionExpresion);
    nodo->nombre = nombre;
    nodo->tipo = tipoDato;

    if (ListaParametros) agregarHijo((AbstractExpresion*) nodo, ListaParametros);
    agregarHijo((AbstractExpresion*) nodo, bloque);
    
    return (AbstractExpresion*) nodo;
}