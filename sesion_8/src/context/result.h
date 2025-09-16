#ifndef RESULT_H
#define RESULT_H

#include "context/definiciones.h"
#include <stdbool.h>

typedef enum {
    NO_EXISTE,
    
    BOOLEAN, CHAR, INT, FLOAT, STRING, NULO,
    
    TIPO_COUNT
} TipoDato;

extern char* labelTipoDato[];
typedef struct Direccion Direccion;
typedef void (*Implementacion) (Direccion* self);

struct Direccion{
    TipoDato tipo;
    char* valor;
    Implementacion usar;
};

typedef struct{
    Direccion base;
    Symbol* symbol;
} NombreDireccion;

typedef struct {
    Direccion base;
} ConstanteDireccion;

typedef struct {
    Direccion base;
    int numeroTemporal;
} TemporalDireccion;

TipoDato tipoResultante(Direccion, Direccion);
Direccion* nuevoNombreDireccion(char* valor, TipoDato tipo, Symbol* entrada);
Direccion* nuevoConstanteDireccion(char* valor, TipoDato tipo);
Direccion* nuevoTemporalDireccion(int numeroTemporal, TipoDato tipo);

Direccion* nuevoValorResultadoVacio(void);

#endif