#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    AbstractExpresion base;
} PrintExpresion;

Result interpretPrintExpresion(AbstractExpresion* self, Context* context) {
    // interpretar la lista de expresiones
    // recorremos  cada expresion y lo que nos devuelva imprimimos el valor
    AbstractExpresion* listaExpresiones = self->hijos[0];
    for (size_t i = 0; i < listaExpresiones->numHijos; ++i) {
        Result result = listaExpresiones->hijos[i]->interpret(listaExpresiones->hijos[i], context);
        switch (result.tipo) {
            case 'S'://string
                //result.valor[result.lengthValor] = "\0"
                printf("%s", (char*) result.valor);
                break;
            case 'I': //int
                printf("%d", *(int*)result.valor);
                break;
            default:
                printf("Codigo incorrecto\n");
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
    printf("creando nodo 2 %ld \n", nodo->base.numHijos);
    return (AbstractExpresion*) nodo;
}