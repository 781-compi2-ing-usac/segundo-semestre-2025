#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "identificadores.h"

#include <stdlib.h>
#include <stdio.h>

Result interpretIdentificadorExpresion(AbstractExpresion* self, Context* context) {
    IdentificadorExpresion* nodo = (IdentificadorExpresion*) self;
    Symbol* valorEncontrado = buscarTablaSimbolos(context, nodo->nombre);
    if (valorEncontrado) {
        return nuevoValorResultado(valorEncontrado->valor, valorEncontrado->tipo);
    }
    printf("El identificador no existe %s\n", nodo->nombre);
    return nuevoValorResultadoVacio();
}

AbstractExpresion* nuevoIdentificadorExpresion(char* nombre) {
    //reservar el espacio en memoria y obtener el puntero a este
    IdentificadorExpresion* nodo = malloc(sizeof(IdentificadorExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretIdentificadorExpresion);

    nodo->nombre = nombre;
    return (AbstractExpresion*) nodo;
}