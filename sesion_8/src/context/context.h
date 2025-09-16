#ifndef CONTEXT_H
#define CONTEXT_H

#include "context/definiciones.h"
#include "result.h"

#include <stdio.h>

typedef enum {
    VARIABLE,
    FUNCION,
    STRUCT,
} Clase;

struct Symbol{
    char* nombre;
    TipoDato tipo;
    Clase clase;
    Symbol* anterior;
};

struct Context {
    int nombre;
    Context* global; //referencia al contexto global
    Context* anterior;
    Symbol* ultimoSymbol; //tabla de simbolos
    FILE* archivo;
};

Context* nuevoContext(Context* anterior);
Symbol* nuevoVariable(char* nombre, TipoDato tipo);
Symbol* nuevaFuncion(char* nombre, TipoDato tipo);

void agregarSymbol(Context* actual, Symbol*);
Symbol* buscarSymbol(Symbol* actual, char* nombre);
Symbol* buscarTablaSimbolos(Context* actual, char* nombre);

//cambiar la lista de symbol con una tabla hash donde la funcion hash esta dada por el nombre del symbol + la linea + columna inicio + columna final + tipo + clase

#endif