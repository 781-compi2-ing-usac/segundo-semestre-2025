#include "cuadruplos/cuadruplos.h"

#include <stdlib.h>
#include <stdio.h>

char* labelOperacionC3D[TIPO_COUNT] = {
    [SUMA] = "+",
    [RESTA] = "-",
    [MENOS_ARITMETICA] = "-",
};

GeneradorC3D* buildGeneradorC3D() {
    GeneradorC3D* generadorC3D = malloc(sizeof(GeneradorC3D));
    generadorC3D->temporal = 0;
    generadorC3D->label = 0;
    generadorC3D->label = 0;
    generadorC3D->ultimo = NULL;
    generadorC3D->primero = NULL;
    return generadorC3D;
}

Cuadruplo* buildCuadruplo(OperacionC3D op, Direccion* arg1, Direccion* arg2, Direccion* resultado) {
    Cuadruplo* nuevoCuadruplo = malloc(sizeof(Cuadruplo));
    nuevoCuadruplo->operacion = op;
    nuevoCuadruplo->argumento1 = arg1;
    nuevoCuadruplo->argumento2 = arg2;
    nuevoCuadruplo->resultado = resultado;
    nuevoCuadruplo->generar = NULL;
    return nuevoCuadruplo;
}

void mostrarC3d(GeneradorC3D* generador) {
    CuadruploItem* actual = generador->primero;
    int numeroFila = 0;
    printf("No.|op|arg1|arg2|resultado|\n");
    while (actual) {
        printf("%d|%s|%s|%s|%s|\n", numeroFila, labelOperacionC3D[actual->dato.operacion], actual->dato.argumento1->valor, 
            actual->dato.argumento2->valor, actual->dato.resultado->valor);
        actual = actual->siguiente;
        numeroFila += 1;
    }
}
