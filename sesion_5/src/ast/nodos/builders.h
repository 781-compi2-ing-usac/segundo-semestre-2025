#ifndef BUILDERS_H
#define BUILDERS_H

#include "ast/AbstractExpresion.h"

/*
    Estructura de un builder:
    AbstractExpresion* nombreExpresionNodo a construir (datos iniciales)
*/

AbstractExpresion* nuevoInstruccionesExpresion(void);
AbstractExpresion* nuevoPrintExpresion(AbstractExpresion* listaExpresiones);
AbstractExpresion* nuevoPrimitivoExpresion(char* valor, char tipo);//, int lengthValor);
AbstractExpresion* nuevoListaExpresiones(void);
//AbstractExpresion* nuevoExpresionLenguaje(char op, AbstractExpresion* izquierda, AbstractExpresion* derecha);

/*
    Builds expresiones
*/
AbstractExpresion* nuevoSumaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha);
AbstractExpresion* nuevoRestaExpresion(AbstractExpresion* izquierda, AbstractExpresion* derecha);


#endif