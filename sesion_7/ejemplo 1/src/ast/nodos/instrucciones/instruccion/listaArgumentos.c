#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "listaArgumentos.h"

#include <stdlib.h>

/* Result interpretListaParametros(AbstractExpresion* self, Context* context) {
    return nuevoValorResultadoVacio();
} */

AbstractExpresion* nuevoListaParametros() {
    //reservar el espacio en memoria y obtener el puntero a este
    ListaParametros* nodo = malloc(sizeof(ListaParametros));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, NULL);

    return (AbstractExpresion*) nodo;
}