#ifndef DEF_H
#define DEF_H

/*
 * se usa para no tener que escribir struct AbstractExpresion* nodo; 
 * se define antes porque se accede a este tipo en el mismo struct
*/
typedef struct AbstractExpresion AbstractExpresion;

typedef struct Symbol Symbol;

typedef struct Context Context;

#endif