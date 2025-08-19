#ifndef BUILDERS_H
#define BUILDERS_H

#include "ast/AbstractExpresion.h"

/*
    Estructura de un builder:
    AbstractExpresion* nombreExpresionNodo a construir (datos iniciales)
*/

AbstractExpresion* nuevoNodoBloque(void);
AbstractExpresion* nuevoNodoExpresion(char op, AbstractExpresion* izquierda, AbstractExpresion* derecha);
AbstractExpresion* nuevoNodoImprimir(AbstractExpresion* listaExpresiones);
AbstractExpresion* nuevoNodoListaExpresiones();
AbstractExpresion* nuevoNodoPrimitivo(char* valor, char tipo);
AbstractExpresion* nuevoNodoBloque(void);


#endif