#ifndef AbstractTerminal
#define AbstractTerminal

#include <stddef.h>

/*
 * se usa para no tener que escribir struct NodoBase* nodo; 
 * se define antes porque se accede a este tipo en el mismo struct
*/
typedef struct NodoBase NodoBase;
/*
 * Link: https://www.geeksforgeeks.org/c/how-to-create-typedef-for-function-pointer-in-c/
 * typedef return_type (*alias_name)(parameter_types and numbers....);
*/
typedef void (*MetodoEjecutar)(NodoBase* self);
typedef void (*Graficar)(NodoBase* self);

struct NodoBase {
    MetodoEjecutar ejecutar; // Método ejecutar puntero
    //Graficar graficar;
    NodoBase** hijos; // Array dinámico de hijos
    size_t numHijos;
};

void agregarHijo(NodoBase* padre, NodoBase* hijo);
void liberarAST(NodoBase* raiz);

#endif