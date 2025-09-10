%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast/AbstractExpresion.h"

    /* Prototipo del scanner */
    extern int yylex(void);
    extern AbstractExpresion* ast_root;
    /* yyerror con firma estándar */
    void yyerror(const char *s);
%}

/* Esto va al parser.tab.h */
%code requires {
    #include "ast/nodos/builders.h"
    #include "context/result.h"
}

/* Seguimiento de ubicaciones */
%locations
/* Mensajes de error más detallados */
//%define parse.error verbose

/* Unión de tipos semánticos */
%union {
  char* string;
  AbstractExpresion* nodo;
  TipoDato tipoDato;
}

/* Tokens tipados */
%token <string> TOKEN_PRINT TOKEN_TRUE TOKEN_FALSE TOKEN_UNSIGNED_INTEGER TOKEN_REAL

// TOKEN_DINT TOKEN_DFLOAT TOKEN_IF TOKEN_ELSE TOKEN_FUNC TOKEN_DSTRING  TOKEN_STRING  TOKEN_RETURN TOKEN_IDENTIFIER

/* Tipo de los no-terminales que llevan valor */
%type <nodo> s lSentencia sentencia expr imprimir lista_Expr bloque primitivo

//declaracion_var sentencia_if sentencia_funcion lista_parametros

//%type <tipoDato> tipoPrimitivo

// precedencia menor a mayor
//%left NUMERO
%left '+' '-' //menos -
%left '*' '/' //más
%left NEG

%%

%start s;

s: lSentencia  { ast_root = $1; $$ = $1; }
    ;

lSentencia: lSentencia sentencia ';' { agregarHijo($1, $2); $$ = $1;}
    | sentencia ';' {
                        AbstractExpresion* b = nuevoInstruccionesExpresion();
                        agregarHijo(b, $1);
                        $$ =  b;
                    }
    ;

sentencia: imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    ;

bloque: '{' lSentencia '}' { $$ =  $2; }
    ;

lista_Expr: lista_Expr ','  expr { agregarHijo($1, $3); $$ = $1; }
    | expr { 
                AbstractExpresion* b = nuevoListaExpresiones();
                agregarHijo(b, $1);
                $$ =  b;
            }
    ;

imprimir: TOKEN_PRINT '(' lista_Expr ')' { $$ =  nuevoPrintExpresion($3); }
    ;

expr: expr '+' expr   { $$ =  nuevoSumaExpresion($1, $3);  }
    | expr '-' expr { $$ =  nuevoRestaExpresion($1, $3); }
    | '-' expr %prec NEG  { $$ =  nuevoUnarioExpresion($2);  }
    | expr '=' '=' expr { $$ = nuevoComparacionExpresion($1, $4); }
    | primitivo { $$ = $1; }
    ;

primitivo: TOKEN_UNSIGNED_INTEGER { $$ =  nuevoPrimitivoExpresion($1, INT); }
    | TOKEN_REAL { $$ =  nuevoPrimitivoExpresion($1, FLOAT); }
    | TOKEN_TRUE { $$ =  nuevoPrimitivoExpresion($1, BOOLEAN); }
    | TOKEN_FALSE { $$ =  nuevoPrimitivoExpresion($1, BOOLEAN); }
    ;
%%

/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    fprintf(stderr,
            "Illegal input %s en %d:%d\n",
            s,
            yylloc.first_line,
            yylloc.first_column);
}
