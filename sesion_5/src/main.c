#include <stdio.h>
#include "ast/AbstractExpresion.h"

/* Declaraciones generadas por Bison/Flex */
int yyparse(void);
extern FILE* yyin;

AbstractExpresion* ast_root = NULL;

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) { perror("fopen"); return 1; }
    }

    if (yyparse() == 0) {
        if (ast_root) {
            printf("Validado.\n");
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

/* void AbstractExpresion_recorrer(AbstractExpresion* nodo) {
    nodo->ejecutar(nodo);
    for (int i = 0; i < nodo->numHijos; i++) {
        AbstractExpresion_recorrer(nodo->hijos[i]);
    }
} */