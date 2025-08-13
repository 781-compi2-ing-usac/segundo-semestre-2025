#include "../../expresiones/listaExpresiones.h"
#include "./../../AbstractTerminal.h"
#include "print.h"
#include <stdlib.h>

NodoImprimir* nuevoNodoImprimir(NodoBase* listaExpresiones) {
    //reservar el espacio en memoria y obtener el puntero a este
    NodoImprimir* n = malloc(sizeof(NodoImprimir));
    if (!n) return NULL;
    //asignar valores
    n->base.ejecutar = ejecutarImprimir;
    n->base.hijos = NULL;
    n->base.numHijos = 0;

    if (listaExpresiones) agregarHijo((NodoBase*)n, listaExpresiones);

    return n;
}

void ejecutarImprimir(NodoBase* self) {
    // interpretar la lista de expresiones
    // recorremos  cada expresion y lo que nos devuelva imprimimos el valor
    print("imprimiendo")
}