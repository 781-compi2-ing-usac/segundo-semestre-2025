#ifndef CUADRUPLOS_H
#define CUADRUPLOS_H

#include "context/definiciones.h"
#include "context/result.h"

//lista de cuadruplos, cada nodo tendra una funcion que traduce a ensamblador con la información que hay en ella
typedef enum {
    SUMA,
    RESTA,
    MENOS_ARITMETICA,
    MULTIPLICACION,
} OperacionC3D;
// para imprimir el resultado

extern char* labelOperacionC3D[];
typedef void (*GeneradorEnsamblador) ();

typedef struct {
    OperacionC3D operacion;
    Direccion* argumento1;
    Direccion* argumento2;
    Direccion* resultado;
    GeneradorEnsamblador generar;
} Cuadruplo;

typedef struct CuadruploItem CuadruploItem;

struct CuadruploItem {
    Cuadruplo dato;
    CuadruploItem* siguiente;
    CuadruploItem* anterior;
};

typedef struct  {
    int temporal;
    int label;
    CuadruploItem* ultimo; //listCuadruplos
    CuadruploItem* primero; //listCuadruplos
} GeneradorC3D;

extern GeneradorC3D* generadorC3D;


GeneradorC3D* buildGeneradorC3D();

Cuadruplo* buildCuadruplo(OperacionC3D, Direccion*, Direccion*, Direccion*);
void mostrarC3d(GeneradorC3D*);

//instrucciones
void agregarAsignacion(GeneradorC3D*, Cuadruplo*);
void agregarAsignacionUnaria(GeneradorC3D*, Cuadruplo*);

#endif
