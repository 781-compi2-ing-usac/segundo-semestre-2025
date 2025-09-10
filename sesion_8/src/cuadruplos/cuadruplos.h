#ifndef CUADRUPLOS_H
#define CUADRUPLOS_H

#include "context/definiciones.h"

//lista de cuadruplos, cada nodo tendra una funcion que traduce a ensamblador con la información que hay en ella

/*
    la idea es no usar un switch case cuando se recorra esta lista para generar el codigo ensamblador
*/

typedef enum {
    SUMA,
    MULTIPLICACION,
} OperacionC3D;
// para imprimir el resultado

typedef void (*GeneradorEnsamblador) ();

struct Cuadruplo {
    OperacionC3D operacion;
    Symbol* argumento1;
    Symbol* argumento2;
    Symbol* resultado;
    GeneradorEnsamblador generar;
}

typedef struct CuadruplosList CuadruplosList;

struct CuadruplosList {
    Cuadruplo dato;
    CuadruplosList* siguiente;
    CuadruplosList* anterior;
}

struct GeneradorC3D {
    int temporal;
    int label;
    CuadruplosList* ultimo;
}


Cuadruplo buildCuadruplo(OperacionC3D, Symbol*, Symbol*, Symbol*);
void mostrarC3d(Cuadruplo);


//instrucciones
void agregarAsignacion(GeneradorC3D*);

#endif
