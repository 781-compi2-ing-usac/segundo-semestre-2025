#include <stdio.h>
#include "ast/AbstractTerminal.h"

/* Declaraciones generadas por Bison/Flex */
int yyparse(void);
extern FILE* yyin;

NodoBase* ast_root = NULL;

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) { perror("fopen"); return 1; }
    }

    if (yyparse() == 0) {
        if (ast_root) {
            //ast_root->ejecutar(ast_root);
            //printf("Program result (last statement): %f\n", result);
            liberarAST(ast_root);
            ast_root = NULL;
        } else {
            printf("No input parsed.\n");
        }
    } else {
        fprintf(stderr, "Parsing failed.\n");
    }

    if (yyin && yyin != stdin) fclose(yyin);

    return 0;
}

/* void NodoBase_recorrer(NodoBase* nodo) {
    nodo->ejecutar(nodo);
    for (int i = 0; i < nodo->numHijos; i++) {
        NodoBase_recorrer(nodo->hijos[i]);
    }
} */