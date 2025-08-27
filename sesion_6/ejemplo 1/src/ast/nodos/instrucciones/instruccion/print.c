#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "print.h"

#include <stdlib.h>
#include <stdio.h>


Result interpretPrintExpresion(AbstractExpresion* self, Context* context) {
    // interpretar la lista de expresiones
    // recorremos  cada expresion y lo que nos devuelva imprimimos el valor
    AbstractExpresion* listaExpresiones = self->hijos[0];
    for (size_t i = 0; i < listaExpresiones->numHijos; ++i) {
        Result result = listaExpresiones->hijos[i]->interpret(listaExpresiones->hijos[i], context);
        switch (result.tipo) {
            case STRING:
                printf("%s\n", (char*) result.valor);
                break;
            case INT:
                printf("%d\n", *(int*)result.valor);
                break;
            case FLOAT:
                printf("%f\n", *(float*)result.valor);
                break;
            case NULO:
                printf("NULL\n");
                break;
            default:
                printf("Tipo no implementado\n");
        }
    }
    return nuevoValorResultadoVacio();
}

AbstractExpresion* nuevoPrintExpresion(AbstractExpresion* listaExpresiones) {
    //reservar el espacio en memoria y obtener el puntero a este
    PrintExpresion* nodo = malloc(sizeof(PrintExpresion));
    if (!nodo) return NULL;
    //asignar valores
    buildAbstractExpresion(&nodo->base, interpretPrintExpresion);

    if (listaExpresiones) agregarHijo((AbstractExpresion*) nodo, listaExpresiones);
    return (AbstractExpresion*) nodo;
}