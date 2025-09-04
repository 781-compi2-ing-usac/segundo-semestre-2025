#include "context.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Context* nuevoContext(Context* anterior) {
    Context* nuevo = malloc(sizeof(Context));
    nuevo->anterior = anterior;
    if (anterior) {
        nuevo->nombre = anterior->nombre + 1;
        nuevo->global = anterior->global;
    } else {
        nuevo->global = nuevo;
    }
    nuevo->ultimoSymbol = NULL;

    return nuevo;
}

Symbol* nuevoVariable(char* nombre, void* valor, TipoDato tipo) {
    Symbol* nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->valor = valor;
    nuevo->tipo = tipo;
    nuevo->clase = VARIABLE;
    return nuevo;
}

Symbol* nuevaFuncion(char* nombre, TipoDato tipo, AbstractExpresion* nodo) {
    Symbol* nuevo = malloc(sizeof(Symbol));
    nuevo->nombre = nombre;
    nuevo->tipo = tipo;
    nuevo->clase = FUNCION;
    nuevo->nodo = nodo;
    return nuevo;
}

void agregarSymbol(Context* actual, Symbol* symbol) {
    if (buscarSymbol(actual->ultimoSymbol, symbol->nombre)) {
        printf("La variable de nombre '%s' ya existe.\n", symbol->nombre);
        return;
    }
    symbol->anterior = actual->ultimoSymbol;
    actual->ultimoSymbol = symbol;
}

Symbol* buscarSymbol(Symbol* actual, char* nombre) {
    while (actual) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return actual;
        }
        actual = actual->anterior;
    }
    return NULL;
}

Symbol* buscarTablaSimbolos(Context* actual, char* nombre) {
    while (actual) {
        Symbol* symbolEncontrado = buscarSymbol(actual->ultimoSymbol, nombre);
        if (symbolEncontrado) {
            return symbolEncontrado;
        }
        actual = actual->anterior;
    }
    return NULL;
}