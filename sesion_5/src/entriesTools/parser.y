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
}

/* Tokens tipados */
%token <string> TOKEN_IF TOKEN_ELSE TOKEN_PRINT TOKEN_DINT TOKEN_DFLOAT 
TOKEN_DSTRING TOKEN_MAYOR TOKEN_MENOR TOKEN_NEGACION TOKEN_IGUAL TOKEN_UNSIGNED_INTEGER TOKEN_REAL TOKEN_STRING TOKEN_IDENTIFIER

/* Tipo de los no-terminales que llevan valor */
%type <nodo> s lSentencia sentencia expr imprimir lista_Expr bloque declaracion_var asignacion_var primitivo

// precedencia menor a mayor
//%left NUMERO
%left '+' '-' //menos -
%left '*' '/' //más
%left NEG

%%

%start s;

s: lSentencia  { ast_root = $1; $$ = $1; }
    //| error '\n'  { yyerrok; }
    ;
//                                               Padre, hijo;
lSentencia: lSentencia sentencia ';' { agregarHijo($1, $2); $$ = $1;}
    | sentencia ';' {
                        AbstractExpresion* b = nuevoInstruccionesExpresion();
                        agregarHijo(b, $1);
                        $$ =  b;
                    }
    ;

sentencia: imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    //| asignacion_var {$$ = $1; }
    //| declaracion_var {$$ = $1;}
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

bloque: '{' lSentencia '}' { AbstractExpresion* b = nuevoInstruccionesExpresion();
                        agregarHijo(b, $2);
                        $$ =  b; }


/* declaracion_var: primitivo {   T_ID* id = new T_ID(QString::fromStdString($2));
                                    $$ = new NT_DeclVar($4, id); }
    | primitivo '=' expr { T_ID* id = new T_ID(QString::fromStdString($2));
                                $$ = new NT_DeclVar($4, id,$6 );  }
    ;

asignacion_var: TOKEN_IDENTIFIER '=' expr   {   
                                                T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                                $$ = new NT_AsigVar(id_avar, $3);
                                            }
    ; */


//TODO: para mejorar la legibilidad en lugar de guardar la operacion por incumplir el principio de responsabilidad única y también el Principio de abierto/cerrado (SOLID)
// la accion semantica fungirá como factoría abstracta y cada expresión tendra su método interpret para hacer la operación además de utilizar otros métodos "heredados".
/* expr: expr '+' expr   { $$ =  nuevoExpresionLenguaje('+', $1, $3);  }
    | expr '-' expr { $$ =  nuevoExpresionLenguaje('-', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | '-' expr %prec NEG  { $$ =  nuevoExpresionLenguaje('U', $2, NULL);  }
    | primitivo { $$ = $1; }
    //| TOKEN_IDENTIFIER { $$ =  nuevoExpresionLenguaje('I', $1, $3); }
    ; */

expr: expr '+' expr   { $$ =  nuevoSumaExpresion($1, $3);  }
    | expr '-' expr { $$ =  nuevoRestaExpresion($1, $3); }
    | '(' expr ')' { $$ = $2; }
    | '-' expr %prec NEG  { $$ =  nuevoUnarioExpresion($2);  }
    | primitivo { $$ = $1; }
    ;

primitivo: TOKEN_UNSIGNED_INTEGER { $$ =  nuevoPrimitivoExpresion($1, INT); }
    | TOKEN_STRING { $$ =  nuevoPrimitivoExpresion($1, STRING); }
    | TOKEN_REAL { $$ =  nuevoPrimitivoExpresion($1, FLOAT); }
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
