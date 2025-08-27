#include "ast/AbstractExpresion.h"
#include "ast/nodos/instrucciones/instrucciones.h"
#include "context/context.h"

#include <stdlib.h>
#include <stdio.h>

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
            printf("Inicio, cantidad de instrucciones: %ld \n", ast_root->numHijos);
            Context* contextPadre = nuevoContext(NULL);
            ast_root->interpret(ast_root, contextPadre);
            printf("Fin, arhivo validado.\n");
        } else {
            printf("No input parsed.\n");
        }
    } else {
        fprintf(stderr, "Parsing failed.\n");
    }

    if (yyin && yyin != stdin) fclose(yyin);

    return 0;
}