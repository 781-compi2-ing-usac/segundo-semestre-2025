#include "../AbstractTerminal.h"
#include "expresiones.h"
#include <stdlib.h>

NodoExpresion* nuevoNodoExpresion(char op, NodoBase* izquierda, NodoBase* derecha) {
    // reservar el espacio en memoria y obtener el puntero a este
    NodoExpresion* n = malloc(sizeof(NodoExpresion));
    if (!n) return NULL;

    //asignar valores
    n->base.ejecutar = ejecutarExpresiones;
    n->base.hijos = NULL;
    n->base.numHijos = 0;
    n->op = op;

    //guardar los punteros en lo hijos de este arbol a los lados de la expresion
    if (izquierda) agregarHijo((NodoBase*)n, izquierda);
    if (derecha) agregarHijo((NodoBase*)n, derecha);
    return n;
}

void ejecutarExpresiones(NodoBase* self) {
    self->hijos[0]->ejecutar(self->hijos[0]);
    self->hijos[1]->ejecutar(self->hijos[1]);
    /* 
    if (self->numHijos < 2) {
        fprintf(stderr, "Binop requires 2 children\n");
        return 0.0f;
    }
    float a = self->hijos[0]->ejecutar(self->hijos[0]);
    float b = self->hijos[1]->ejecutar(self->hijos[1]);
    NodoExpresion* nb = (NodoExpresion*)self;
    switch (nb->op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0.0f ? a / b : (fprintf(stderr, "Division by zero\n"), 0.0f);
        default:
            fprintf(stderr, "Unknown operator %c\n", nb->op);
            return 0.0f;
    } */
}