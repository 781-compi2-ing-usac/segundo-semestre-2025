#include "primitivos.h"
#include <stdlib.h>

NodoPrimitivo* nuevoNodoPrimitivo(char* v, char tipo) {
    //reservar el espacio en memoria y obtener el puntero a este
    NodoPrimitivo* n = malloc(sizeof(NodoPrimitivo));
    if (!n) return NULL;
    //asignar valores
    n->base.ejecutar = ejecutarPrimitivo;
    n->base.hijos = NULL;
    n->base.numHijos = 0;
    n->valor = v;
    n->tipo = tipo;
    return n;
}

Resultado* ejecutarPrimitivo(NodoBase* self) {
    NodoPrimitivo* n = (NodoPrimitivo*)self;
    //return n->valor;
}


typedef struct {
    TipoDevuelto char,
    ....
} Resultado