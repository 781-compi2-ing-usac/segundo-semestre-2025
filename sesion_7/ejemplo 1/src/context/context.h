#ifndef CONTEXT_H
#define CONTEXT_H

#include "result.h"

typedef enum {
    VARIABLE,
    FUNCION,
    STRUCT,
} Clase;

typedef struct Symbol Symbol;
typedef struct Context Context;

struct Symbol{
    char* nombre;
    void* valor;
    TipoDato tipo;
    Clase clase;

    Symbol* anterior;
};

struct Context {
    int nombre;
    Context* anterior;
    Symbol* ultimoSymbol; //tabla de simbolos
};

Context* nuevoContext(Context* anterior);
Symbol* nuevoVariable(char* nombre, void* valor, TipoDato tipo);
void agregarSymbol(Context* actual, Symbol*);
Symbol* buscarSymbol(Symbol* actual, char* nombre);
Symbol* buscarTablaSimbolos(Context* actual, char* nombre);

//cambiar la lista de symbol con una tabla hash donde la funcion hash esta dada por el nombre del symbol + la linea + columna inicio + columna final + tipo + clase

#endif