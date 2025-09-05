#ifndef IF_H
#define IF_H

#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "context/result.h"

#include <stdbool.h>

//misma informarcion del struct padre pero diferente implementacion
/*
    equivalente a esto:
    class IfExpresion extends AbstractExpresion {
    
        IfExpresion() {
            super()
            ....
        }

        //sobrecarga
        IfExpresion(...) {
            super()
            ....
        }

        interpret(..) {
            ....
        }
    }
*/
typedef struct {
    AbstractExpresion base;
    bool isElse;
    bool isElseif;
    //expresion
    //siguiente else if
    //sentencias
    //sentencias else
} IfExpresion;

Result interpretIfExpresion(AbstractExpresion*, Context*);
Result interpretIfElseExpresion(AbstractExpresion*, Context*);
Result interpretElseIfExpresion(AbstractExpresion*, Context*);

#endif
