#include <stdio.h>

/* Declaraciones generadas por Bison/Flex */
int yyparse(void);

int main(void) {
    printf("Calculadora simple (Ctrl+D para salir)\n> ");
    if (yyparse() != 0) {
        fprintf(stderr, "Fallo en el parseo\n");
        return 1;
    }

    // Recorrer árbol y ejecutar el método polimórfico
    void NodoBase_recorrer(NodoBase* nodo) {
        nodo->ejecutar(nodo);
        for (int i = 0; i < nodo->numHijos; i++) {
            NodoBase_recorrer(nodo->hijos[i]);
        }
    }

    return 0;
}

/*
int main() {
    NodoTipoA raiz;
    NodoTipoA_init(&raiz, "RaizA", 100);

    NodoTipoB hijo1;
    NodoTipoB_init(&hijo1, "HijoB1", "Hola mundo");

    NodoTipoA hijo2;
    NodoTipoA_init(&hijo2, "HijoA2", 200);

    NodoTipoB nieto1;
    NodoTipoB_init(&nieto1, "NietoB1", "Soy nieto");

    // Construir el árbol
    NodoBase_addHijo((NodoBase*)&raiz, (NodoBase*)&hijo1);
    NodoBase_addHijo((NodoBase*)&raiz, (NodoBase*)&hijo2);
    NodoBase_addHijo((NodoBase*)&hijo2, (NodoBase*)&nieto1);

    // Recorrer y ejecutar polimórficamente
    NodoBase_recorrer((NodoBase*)&raiz);

    // Liberar memoria de hijos (simplificado)
    free(raiz.base.hijos);
    free(hijo2.base.hijos);

    return 0;
}*/