#include "AbstractTerminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* liberación */
void liberarAST(NodoBase* raiz) {
    if (!raiz) return;
    for (size_t i = 0; i < raiz->numHijos; ++i) {
        liberarAST(raiz->hijos[i]);
    }
    free(raiz->hijos);
    free(raiz);
}

// Añadir hijo al Nodo
void agregarHijo(NodoBase* padre, NodoBase* hijo) {
    if (!padre || !hijo) return;
    // reasignar el tamaño del bloque de almacenamiento
    // si tenia 4 espacios de tipo puntero le sumamos 1 espacio más
    // realloc(puntero al principio del bloque, tamaño )
    //TODO: mejorar
    NodoBase** newarr = realloc(padre->hijos, sizeof(NodoBase*) * (padre->numHijos + 1));
    if (!newarr) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    padre->hijos = newarr;
    padre->hijos[padre->numHijos] = hijo;
    padre->numHijos++;
}

