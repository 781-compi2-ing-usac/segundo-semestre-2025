%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast/AbstractTerminal.h"

    /* Prototipo del scanner */
    extern int yylex(void);
    extern NodoBase* ast_root;
    /* yyerror con firma estándar */
    void yyerror(const char *s);
%}

/* Esto va al parser.tab.h */
%code requires {
    #include "ast/instrucciones/instrucciones.h"
    #include "ast/expresiones/expresiones.h"
    #include "ast/expresiones/primitivos.h"
    #include "ast/expresiones/listaExpresiones.h"
    #include "ast/instrucciones/instruccion/print.h"
}

/* Seguimiento de ubicaciones */
%locations
/* Mensajes de error más detallados */
//%define parse.error verbose

/* Unión de tipos semánticos */
%union {
  char* string;
  NodoBase* nodo;
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

s: lSentencia  { ast_root = $1; }
    //| error '\n'  { yyerrok; }
    ;
//                                               Padre, hijo;
lSentencia: lSentencia sentencia ';' { agregarHijo($1, $2); $$ = $1; }
    | sentencia ';' {
                        NodoBloque* b = nuevoNodoBloque();
                        agregarHijo((NodoBase*)b, $1);
                        $$ = (NodoBase*) b;
                    }
    ;

sentencia: imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    //| asignacion_var {$$ = $1; }
    //| declaracion_var {$$ = $1;}
    ;

lista_Expr: lista_Expr ','  expr { agregarHijo($1, $3); $$ = $1; }
    | expr { 
                NodoListaExpresiones* b = nuevoNodoListaExpresiones();
                agregarHijo((NodoBase*)b, $1);
                $$ = (NodoBase*) b;
            }
    ;

imprimir: TOKEN_PRINT '(' lista_Expr ')' { $$ = (NodoBase*) nuevoNodoImprimir($3); }
    ;

bloque: '{' lSentencia '}' { NodoBloque* b = nuevoNodoBloque();
                        agregarHijo((NodoBase*)b, $2);
                        $$ = (NodoBase*) b; }


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


    
expr: expr '+' expr   { $$ = (NodoBase*) nuevoNodoExpresion('+', $1, $3);  }
    | expr '-' expr { $$ = (NodoBase*) nuevoNodoExpresion('-', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | '-' expr %prec NEG  { $$ = (NodoBase*) nuevoNodoExpresion('U', $2, NULL);  }
    | primitivo { $$ = $1; } 
    //| TOKEN_IDENTIFIER { $$ = (NodoBase*) nuevoNodoExpresion('I', $1, $3); }
    //| TOKEN_STRING { $$ = NodoTipoA_init($1);  }
    ;

primitivo: TOKEN_UNSIGNED_INTEGER { $$ = (NodoBase*) nuevoNodoPrimitivo($1, 'I'); }
    | TOKEN_STRING { $$ = (NodoBase*) nuevoNodoPrimitivo($1, 'S'); }
    | TOKEN_REAL { $$ = (NodoBase*) nuevoNodoPrimitivo($1, 'F'); }
    ;
%%

/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    fprintf(stderr,
            "%s en %d:%d\n",
            s,
            yylloc.first_line,
            yylloc.first_column);
}
