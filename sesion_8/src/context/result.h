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

/* struct Symbol{
    TipoDato tipo;
    char* nombre;
    Clase clase;
    Symbol* anterior;
}; 

struct Constante {
    TipoDato tipo;
    char* nombre;
    TipoDireccion tipoDireccion;
}

struct Temporal {
    TipoDato tipo;
    char* nombre;
    TipoDireccion tipoDireccion;
}

struct Direccion {
    
}
*/

typedef struct {
    TipoDato tipo;
    //simular los 3 tipos de memoria
    //en el resultado
    Symbol* resultado;
} Result;

TipoDato tipoResultante(Result, Result);
Result nuevoValorResultado(void* valor, TipoDato tipo);
Result nuevoValorResultadoVacio(void);

#endif