#include "cuadruplos/cuadruplos.h"

// va agregar a los cuadruplos la operacion de asignacion

void agregarAsignacion(GeneradorC3D generador, Cuadruplo dato) {
    struct CuadruplosList item = {dato, NULL, generador->ultimo};
    if (generador->ultimo) {
        generador->ultimo->siguiente = item;
    }
    generador->ultimo = item;
}