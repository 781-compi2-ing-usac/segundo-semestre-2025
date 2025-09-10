#ifndef RESULT_H
#define RESULT_H

#include <stdbool.h>

typedef enum {
    BOOLEAN,
    CHAR,
    INT,
    FLOAT,
    STRING,
    NULO,
    TIPO_COUNT
} TipoDato;

extern char* labelTipoDato[];

typedef struct {
    TipoDato tipo;
    char* valor;
    bool isReturn;
    bool isConstante;
    Symbol* resultado;
} Result;

TipoDato tipoResultante(Result, Result);
Result nuevoValorResultado(void* valor, TipoDato tipo);
Result nuevoValorResultadoVacio(void);

#endif