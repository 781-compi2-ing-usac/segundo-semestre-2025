#ifndef ARITMETICAS_H
#define ARITMETICAS_H

#include "ast/AbstractExpresion.h"
#include "context/result.h"
#include "context/context.h"
#include "ast/nodos/expresiones/expresiones.h"

/* SUMA */
Result sumarIntInt(Result, Result);
Result sumarFloatFloat(Result, Result);
Result sumarIntFloat(Result, Result);
Result sumarFloatInt(Result, Result);

extern Operacion tablaOperacionesSuma[TIPO_COUNT][TIPO_COUNT];

/* RESTA */
Result restaIntInt(Result, Result);
Result restaFloatFloat(Result, Result);
Result restaIntFloat(Result, Result);
Result restaFloatInt(Result, Result);

extern Operacion tablaOperacionesResta[TIPO_COUNT][TIPO_COUNT];

/* UNARIO */
Result negarAritmeticoInt(Result, Result);
Result negarAritmeticoFloat(Result, Result);

extern Operacion tablaOperacionesUnario[TIPO_COUNT][TIPO_COUNT];

#endif