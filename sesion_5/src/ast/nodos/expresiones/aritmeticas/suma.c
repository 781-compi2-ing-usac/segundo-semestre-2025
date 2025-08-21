#include "ast/AbstractExpresion.h"
#include "ast/nodos/builders.h"
#include "context/context.h"
#include "context/result.h"
#include "aritmeticas.h"
#include "ast/nodos/expresiones/expresiones.h"

Result interpretSumaLenguaje(AbstractExpresion* self, Context* context) {
    ExpresionLenguaje* nodo = (ExpresionLenguaje*) self;
    calcularResultados(nodo);

    


    int valorFinal = *((int*) resultado1->valor) + *((int*) resultado2.valor);
    Result resultadoFinal = nuevoValorResultado((void* ) &valorFinal, 'I');
    return resultadoFinal;
}

AbstractExpresion* nuevoSumaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha) {
    return nuevoExpresionLenguaje(interpretSumaLenguaje, izquierda, derecha);
}
