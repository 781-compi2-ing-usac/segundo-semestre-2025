#ifndef ABSTRACT_EXPRESION_H
#define ABSTRACT_EXPRESION_H

#include "context/result.h"
#include "context/context.h"

#include <stddef.h>

/*
 * se usa para no tener que escribir struct AbstractExpresion* nodo; 
 * se define antes porque se accede a este tipo en el mismo struct
*/
typedef struct AbstractExpresion AbstractExpresion;
/*
 * Link: https://www.geeksforgeeks.org/c/how-to-create-typedef-for-function-pointer-in-c/
 * typedef return_type (*alias_name)(parameter_types and numbers....);
*/
typedef Result (*Interpret)(AbstractExpresion*, Context*);
typedef void (*Graficar)(AbstractExpresion*);

struct AbstractExpresion {
    Interpret interpret; // Método interpretar puntero
    //Graficar graficar; //Método graficar puntero
    AbstractExpresion** hijos; // Array dinámico de hijos
    size_t numHijos;
};

void agregarHijo(AbstractExpresion* padre, AbstractExpresion* hijo);
void liberarAST(AbstractExpresion* raiz);
void buildAbstractExpresion(AbstractExpresion* base, Interpret interpretPuntero);

#endif