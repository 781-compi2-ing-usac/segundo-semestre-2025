#include "result.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char* labelTipoDato[TIPO_COUNT] = {
    [BOOLEAN] = "boolean",
    [CHAR] = "char",
    [INT] = "int",
    [FLOAT] = "float",
    [STRING] = "string",
    [NULO] = "null",
    [NO_EXISTE] = "no existe"
};

Direccion* nuevoConstanteDireccion(char* valor, TipoDato tipo) {
    ConstanteDireccion* resultado = malloc(sizeof(ConstanteDireccion));
    resultado->base.tipo = tipo;
    resultado->base.valor = valor;
    resultado->base.usar = NULL;
    return (Direccion*) resultado;
}

Direccion* nuevoNombreDireccion(char* valor, TipoDato tipo, Symbol* entrada) {
    NombreDireccion* resultado = malloc(sizeof(NombreDireccion));
    resultado->base.tipo = tipo;
    resultado->base.valor = valor;
    resultado->base.usar = NULL;
    resultado->symbol = entrada;
    return (Direccion*) resultado;
}

Direccion* nuevoTemporalDireccion(int numeroTemporal, TipoDato tipo) {
    TemporalDireccion* resultado = malloc(sizeof(TemporalDireccion));
    int longitud_necesaria = snprintf(NULL, 0, "%c%d", 'T', numeroTemporal);
    char* nombreTemporal = malloc(longitud_necesaria);
    snprintf(nombreTemporal, longitud_necesaria + 1, "%c%d", 'T', numeroTemporal);
    resultado->base.tipo = tipo;
    resultado->base.valor = nombreTemporal;
    resultado->base.usar = NULL;
    resultado->numeroTemporal = numeroTemporal;
    return (Direccion*) resultado;
}

Direccion* nuevoValorResultadoVacio() {
    TemporalDireccion* resultado = malloc(sizeof(TemporalDireccion));
    int longitud_necesaria = snprintf(NULL, 0, "%c%d", 'T', -1);
    char* nombreTemporal = malloc(longitud_necesaria);
    snprintf(nombreTemporal, longitud_necesaria + 1, "%c%d", 'T', -1);
    resultado->base.tipo = NULO;
    resultado->base.valor = nombreTemporal;
    resultado->base.usar = NULL;
    resultado->numeroTemporal = -1;
    return (Direccion*) resultado;
}

//Sin usar
TipoDato tipoResultante(Direccion valor1, Direccion valor2) {
    if (valor1.tipo >= valor2.tipo) {
        return valor1.tipo;
    } else {
        return valor2.tipo;
    }
}