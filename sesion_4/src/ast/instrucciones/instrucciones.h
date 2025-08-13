#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "./../AbstractTerminal.h"

/* bloque (lista de instrucciones) */
typedef struct {
    NodoBase base;
} NodoBloque;

NodoBloque* nuevoNodoBloque(void);
void ejecutarBloque(NodoBase* self);

#endif