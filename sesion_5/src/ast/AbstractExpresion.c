#include "AbstractExpresion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Añadir hijo al Nodo
void agregarHijo(AbstractExpresion* padre, AbstractExpresion* hijo) {
    if (!padre || !hijo) return;
    // reasignar el tamaño del bloque de almacenamiento
    // si tenia 4 espacios de tipo puntero le sumamos 1 espacio más
    // realloc(puntero al principio del bloque, tamaño )
    //TODO: mejorar
    AbstractExpresion** newarr = realloc(padre->hijos, sizeof(AbstractExpresion*) * (padre->numHijos + 1));
    if (!newarr) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    padre->hijos = newarr;
    padre->hijos[padre->numHijos] = hijo;
    padre->numHijos++;
}

/* liberación */
void liberarAST(AbstractExpresion* raiz) {
    if (!raiz) return;
    for (size_t i = 0; i < raiz->numHijos; ++i) {
        liberarAST(raiz->hijos[i]);
    }
    free(raiz->hijos);
    free(raiz);
}

void buildAbstractExpresion(AbstractExpresion* base, Interpret interpretPuntero) {
    //asignar valores
    base->interpret = interpretPuntero;
    base->hijos = NULL;
    base->numHijos = 0;
}
