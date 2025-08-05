%{
#include <stdio.h>
#include <stdlib.h>
#include ""

/* Prototipo del scanner */
extern int yylex(void);
/* yyerror con firma estándar */
void yyerror(const char *s);
%}

/* Seguimiento de ubicaciones */
%locations
/* Mensajes de error más detallados */
//%define parse.error verbose

/* Unión de tipos semánticos */
%union {
  int num;
}

/* Tokens tipados */
%token <num> NUMBER
/* Tipo de los no-terminales que llevan valor */
%type  <num> expr

/* Precedencias */
%left '+' '-'
%left '*' '/'

%%

%start s;

s: lSentencia  { 
    intr.raiz = new NT_S($1);
    $$ = intr.raiz; 
    }
;
    

lSentencia: lSentencia sentencia z {
                                    $$ = $1; 
                                    $$->AddSentencia($2);
                                    }
    | sentencia z { 
        $$ = new NT_LSentencias();
        $$->AddSentencia($1);
    }
    ;
    /*sentencias*/
sentencia: declaracion_var {$$ = $1;}
    | asignacion_var {$$ = $1; }
    | imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    ;


lista_Expr: lista_Expr ','  expr {   $1->AddNodo($3); 
                                    $$ = $1;
                                }
    | expr { $$ = new NT_ListaExpr($1);}
    ;

imprimir: IMPR '(' lista_Expr ')' { $$ = new NT_Imprimir($3); }
    ;

bloque: '{' lSentencia '}' { $$ = new NT_Bloque($2); }

z: ';' {  }
    | %empty { }
    ;


declaracion_var: DIM ID AS tipo {   T_ID* id = new T_ID(QString::fromStdString($2));
                                    $$ = new NT_DeclVar($4, id); }
    | DIM ID AS tipo '=' expr { T_ID* id = new T_ID(QString::fromStdString($2));
                                $$ = new NT_DeclVar($4, id,$6 );  }
    ;

asignacion_var: ID '=' expr {   T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar, $3);
                                }
    ;


    
expr: expr SUMA expr   { $$ = new NT_Suma($1, $3);  }
    | expr MENOS expr { $$ = $1;  
                        /*pendiente de implementar*/}
    | '(' expr ')' { $$ = $2; }
    | MENOS expr %prec NEG  { $$ = new NT_Negacion($2);  }
    | NUMERO { $$ = new T_Numero( QString::fromStdString($1)); } 
    | ID { $$ = new NT_ID( QString::fromStdString($1)); }
    | STRING { $$ = new T_String( QString::fromStdString($1));  }
    ;

tipo:  INT { $$ = new NT_Tipo( QString::fromStdString($1)); }
    | STR { $$ = new NT_Tipo( QString::fromStdString($1)); }
    | FLO { $$ = new NT_Tipo( QString::fromStdString($1)); }
    ;
    
/* input:
  | input line
  ;

line:
    '\n'
  | expr '\n'   { printf("= %d\n", $1); }
  | error '\n'  { yyerrok; }
  ;

expr:
    expr '+' expr   { $$ = $1 + $3; }
  | expr '*' expr   { $$ = $1 * $3; }
  | '(' expr ')'    { $$ = $2; }
  | NUMBER          { $$ = $1; }
  ; */
%%

/* definición de yyerror, usa el yylloc global para ubicación */
void yyerror(const char *s) {
    fprintf(stderr,
            "%s en %d:%d\n",
            s,
            yylloc.first_line,
            yylloc.first_column);
}
