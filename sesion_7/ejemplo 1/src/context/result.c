#include "result.h"

#include <stddef.h>
#include <stdio.h>

char* labelTipoDato[TIPO_COUNT] = {
    [BOOLEAN] = "boolean",
    [CHAR] = "char",
    [INT] = "int",
    [FLOAT] = "float",
    [STRING] = "string",
    [NULO] = "null"
};

Result nuevoValorResultado(void* valor, TipoDato tipo) {
    Result resultado;
    resultado.tipo = tipo;
    resultado.valor = valor;
    resultado.isReturn = false;
    return resultado;
}

Result nuevoValorResultadoVacio() {
    Result resultado;
    resultado.tipo = NULO;
    resultado.valor = NULL;
    resultado.isReturn = false;
    return resultado;
}

//Sin usar
TipoDato tipoResultante(Result valor1, Result valor2) {
    if (valor1.tipo >= valor2.tipo) {
        return valor1.tipo;
    } else {
        return valor2.tipo;
    }
}