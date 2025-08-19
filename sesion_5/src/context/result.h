#ifndef RESULT_H
#define RESULT_H

typedef struct {
    void* valor;
    char tipo;
    int lengthValor;
} Result;

Result nuevoValorResultado(void* valor, char tipo);//, int lengthValor);
Result nuevoValorResultadoVacio(void);

#endif