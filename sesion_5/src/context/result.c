#include "result.h"

Result nuevoValorResultado(void* valor, char tipo){ //, int lengthValor) {
    // ... dentro de la función, por ejemplo:
    Result resultado;

    // Inicializamos la variable temporal
    resultado.tipo = tipo;
    resultado.valor = valor;

    // Retornamos la variable
    return resultado;
}

Result nuevoValorResultadoVacio() {
    // ... dentro de la función, por ejemplo:
    Result resultado;
    // Retornamos la variable
    return resultado;
}