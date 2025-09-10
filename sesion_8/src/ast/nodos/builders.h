#ifndef BUILDERS_H
#define BUILDERS_H

#include "ast/AbstractExpresion.h"

/*
    Estructura de un builder:
    AbstractExpresion* nombreExpresionNodo a construir (datos iniciales)
*/

AbstractExpresion* nuevoInstruccionesExpresion(void);
AbstractExpresion* nuevoPrintExpresion(AbstractExpresion* listaExpresiones);
AbstractExpresion* nuevoPrimitivoExpresion(char* valor, char tipo);
AbstractExpresion* nuevoListaExpresiones(void);
AbstractExpresion* nuevoDeclaracionVariables(TipoDato, char* nombre, AbstractExpresion* expresion);
AbstractExpresion* nuevoIdentificadorExpresion(char* nombre);
//AbstractExpresion* nuevoExpresionLenguaje(char op, AbstractExpresion* izquierda, AbstractExpresion* derecha);

/*
    Builds expresiones
*/
AbstractExpresion* nuevoSumaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha);
AbstractExpresion* nuevoRestaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha);
AbstractExpresion* nuevoUnarioExpresion(AbstractExpresion* expresion);

AbstractExpresion* nuevoComparacionExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha);

/*
    Builds if
*/
AbstractExpresion* nuevoIfExpresion(AbstractExpresion* expresion, AbstractExpresion* bloqueTrue);
AbstractExpresion* nuevoIfElseExpresion(AbstractExpresion* expresion, AbstractExpresion* bloqueTrue, AbstractExpresion* bloqueFalse);
AbstractExpresion* nuevoElseIfExpresion(AbstractExpresion* expresion, AbstractExpresion* bloqueTrue, AbstractExpresion* IfExpresionSiguiente);

AbstractExpresion* nuevoFuncionExpresion(TipoDato tipoDato, char* nombre, AbstractExpresion* listaExpr, AbstractExpresion* bloque);
AbstractExpresion* nuevoLlamadaExpresion(char* id, AbstractExpresion* listaExpresiones);
AbstractExpresion* nuevoListaParametros();
AbstractExpresion* nuevoReturnExpresion(AbstractExpresion* expresion);

#endif