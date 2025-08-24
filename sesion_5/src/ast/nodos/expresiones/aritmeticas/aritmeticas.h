#ifndef ARITMETICAS_H
#define ARITMETICAS_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"
#include "ast/nodos/expresiones/expresiones.h"

/* SUMA */
Result sumarIntInt(ExpresionLenguaje* self);
Result sumarFloatFloat(ExpresionLenguaje* self);
Result sumarIntFloat(ExpresionLenguaje* self);
Result sumarFloatInt(ExpresionLenguaje* self);

extern Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT];

/* RESTA */
Result restaIntInt(ExpresionLenguaje* self);
Result restaFloatFloat(ExpresionLenguaje* self);
Result restaIntFloat(ExpresionLenguaje* self);
Result restaFloatInt(ExpresionLenguaje* self);

extern Operacion tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT];

/* UNARIO */
Result negarAritmeticoInt(ExpresionLenguaje* self);
Result negarAritmeticoFloat(ExpresionLenguaje* self);

extern Operacion tablaOperacionesUnario[TIPO_COUNT][TIPO_COUNT];

#endif