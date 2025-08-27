#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "listaExpresiones.h"

#include <stdlib.h>

/* Result interpretListaExpresiones(AbstractExpresion* self, Context* context) {
    return nuevoValorResultadoVacio();
} */

AbstractExpresion* nuevoListaExpresiones() {
    //reservar el espacio en memoria y obtener el puntero a este
    ListaExpresiones* nodo = malloc(sizeof(ListaExpresiones));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, NULL);

    return (AbstractExpresion*) nodo;
}