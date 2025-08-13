#ifndef PRIMITIVOS_H
#define PRIMITIVOS_H

#include "./../AbstractTerminal.h"

typedef struct {
    NodoBase base;
    char* valor;
    char tipo;
} NodoPrimitivo;

NodoPrimitivo* nuevoNodoPrimitivo(char* valor, char tipo);
void ejecutarPrimitivo(NodoBase* self);

#endif