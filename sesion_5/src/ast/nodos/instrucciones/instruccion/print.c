#include "../../expresiones/listaExpresiones.h"
#include "./../../AbstractTerminal.h"
#include "print.h"
#include <stdlib.h>

NodoImprimir* nuevoNodoImprimir(AbstractExpresion* listaExpresiones) {
    //reservar el espacio en memoria y obtener el puntero a este
    NodoImprimir* n = malloc(sizeof(NodoImprimir));
    if (!n) return NULL;
    //asignar valores
    n->base.ejecutar = ejecutarImprimir;
    n->base.hijos = NULL;
    n->base.numHijos = 0;

    if (listaExpresiones) agregarHijo((AbstractExpresion*)n, listaExpresiones);

    return n;
}

void ejecutarImprimir(AbstractExpresion* self) {
    // interpretar la lista de expresiones
    // recorremos  cada expresion y lo que nos devuelva imprimimos el valor
    print("imprimiendo")
}