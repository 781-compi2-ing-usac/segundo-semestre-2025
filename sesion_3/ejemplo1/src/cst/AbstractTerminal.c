#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct NodoBase {
    char nombre[50];
    MetodoEjecutar ejecutar; // Método virtual
    NodoBase** hijos; // Array dinámico de hijos
    int numHijos;
};

// Constructor Base
void NodoBase_init(NodoBase* nodo, const char* nombre, MetodoEjecutar metodo) {
    snprintf(nodo->nombre, sizeof(nodo->nombre), "%s", nombre);
    nodo->ejecutar = metodo;
    nodo->hijos = NULL;
    nodo->numHijos = 0;
}

// Añadir hijo al Nodo
void NodoBase_addHijo(NodoBase* padre, NodoBase* hijo) {
    padre->hijos = realloc(padre->hijos, (padre->numHijos + 1) * sizeof(NodoBase*));
    padre->hijos[padre->numHijos] = hijo;
    padre->numHijos++;
}

// Recorrer árbol y ejecutar el método polimórfico
void NodoBase_recorrer(NodoBase* nodo) {
    nodo->ejecutar(nodo);
    for (int i = 0; i < nodo->numHijos; i++) {
        NodoBase_recorrer(nodo->hijos[i]);
    }
}
