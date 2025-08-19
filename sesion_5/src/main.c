#include <stdio.h>
#include "ast/AbstractExpresion.h"
#include "context/context.h"
#include "ast/nodos/instrucciones/instrucciones.h"

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
            InstruccionesExpresion* bloque = (InstruccionesExpresion*) ast_root;
            printf("Validado %ld", bloque->base.numHijos);
            Context contextPadre = {};
            ast_root->interpret(ast_root, &contextPadre);
            printf("Validado.\n");
            //printf("Program result (last statement): %f\n", result);
            //liberarAST(ast_root);
            //ast_root = NULL;
        } else {
            printf("No input parsed.\n");
        }
    } else {
        fprintf(stderr, "Parsing failed.\n");
    }

    if (yyin && yyin != stdin) fclose(yyin);

    return 0;
}

/* void startRecorrido(AbstractExpresion* nodo) {
    Context contextPadre = {};
    nodo->interpret(nodo, &contextPadre);
    for (int i = 0; i < nodo->numHijos; i++) {
        AbstractExpresion_recorrer(nodo->hijos[i]);
    }
} */