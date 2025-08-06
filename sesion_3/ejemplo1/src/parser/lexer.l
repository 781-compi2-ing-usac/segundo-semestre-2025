/*
 * pascal.lex: An example PASCAL scanner
 *
 */

/*{NUMBER} {
    yylval.num = atoi(yytext);
    return NUMBER;
}*/

%{
#include <stdio.h>
#include "parser.tab.h"

void yyerror(char *message);

/* Contador de columna */
int yycolumn = 1;

/* Se ejecuta antes de cada accion, actualiza yylloc y columna */
#define YY_USER_ACTION                                   \
    yylloc.first_line   = yylineno;                      \
    yylloc.first_column = yycolumn;                      \
    yylloc.last_line    = yylineno;                      \
    yylloc.last_column  = yycolumn + yyleng - 1;         \
    yycolumn           += yyleng;
%}

/* Opciones de Flex 
 * yylineno:  mantenga el numero de la linea actual
 leida desde su entrada en la variable global yylineno.
 * noyywrap:  hace que el analizador no llame a yywrap() hasta el fin-de-fichero, 
 pero simplemente asume que no hay mas ficheros que analizar.
*/
%option noyywrap yylineno

/* Condiciones de arranque */
% COMMENT1 COMMENT2

/* definiciones */
white_space       [ \t]*
digit             [0-9]
alpha             [A-Za-z_]
alpha_num         ({alpha}|{digit})
hex_digit         [0-9A-F]
identifier        {alpha}{alpha_num}*
unsigned_integer  {digit}+
hex_integer       ${hex_digit}{hex_digit}*
exponent          e[+-]?{digit}+
i                 {unsigned_integer}
real              ({i}\.{i}?|{i}?\.{i}){exponent}?
string            \"([^"\n]|\"\")+\"
bad_string        \"([^"\n]|\"\")+

%%

"/*"                  yybegin(COMMENT1);
<COMMENT1>[^}\n]+
<COMMENT1>\n            ++yylineno;
<COMMENT1><<EOF>>    yyerror("EOF in comment");
<COMMENT1>"*/"        yybegin(INITIAL);

"(*"                 yybegin(COMMENT2);
<COMMENT2>[^)*\n]+
<COMMENT2>\n            ++yylineno;
<COMMENT2><<EOF>>    yyerror("EOF in comment");
<COMMENT2>"*)"       yybegin(INITIAL);
<COMMENT2>[*)]

 /* note that FILE and BEGIN are already 
  * defined in FLEX or C so they can't  
  * be used. This can be overcome in                               
  * a cleaner way by defining all the
  * tokens to start with TOK_ or some
  * other prefix.
  */

and                  return(AND);
array                return(ARRAY);

">"                  return(MAYOR);
"<"                  return(MENOR);
"!"                  return(NEGACION);
"="                  return(IGUAL);

{unsigned_integer}   return(UNSIGNED_INTEGER);
{real}               return(REAL);
{string}             return{STRING};
{bad_string}         yyerror("Unterminated string");

{identifier}         return(IDENTIFIER);

[*/+\-,^()\[\]]      return(yytext[0]);

{white_space}        /* do nothing */
\n                   yylineno += 1;
.                    yyerror("Illegal input");

%%

void yyerror(char *message)
{
   fprintf(stderr,"Error: \"%s\" in line %d. Token = %s\n",
           message,yylineno,yytext);
   exit(1);
}