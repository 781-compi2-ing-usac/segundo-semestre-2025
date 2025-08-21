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
            InstruccionesExpresion* bloque = (InstruccionesExpresion*) ast_root;
            printf("sentencia final %ld \n", bloque->base.numHijos);
            Context contextPadre = {};
            bloque->base.interpret(bloque, &contextPadre);
            printf("Validado.\n");
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