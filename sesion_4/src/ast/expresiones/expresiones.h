#ifndef EXPRESIONS_H
#define EXPRESIONS_H

#include "./../AbstractTerminal.h"

typedef struct {
    NodoBase base;
    char op; /* '+', '-', '*', '/' */
} NodoExpresion;

NodoExpresion* nuevoNodoExpresion(char op, NodoBase* izquierda, NodoBase* derecha);
void ejecutarExpresiones(NodoBase* self);

#endif