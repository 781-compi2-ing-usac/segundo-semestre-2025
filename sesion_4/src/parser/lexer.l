/*{NUMBER} {
    yylval.num = atoi(yytext);
    return NUMBER;
}*/

%{
#include <stdio.h>
#include "parser.tab.h"

//void yyerror(char *message);

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
%x COMMENT1 COMMENT2

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

"/*"                  BEGIN(COMMENT1);
<COMMENT1>[^}\n]+
<COMMENT1>\n            ++yylineno;
<COMMENT1><<EOF>>    yyerror("EOF in comment");
<COMMENT1>"*/"        BEGIN(INITIAL);

"(*"                 BEGIN(COMMENT2);
<COMMENT2>[^)*\n]+
<COMMENT2>\n            ++yylineno;
<COMMENT2><<EOF>>    yyerror("EOF in comment");
<COMMENT2>"*)"       BEGIN(INITIAL);
<COMMENT2>[*)]

if                  return(TOKEN_IF);
else                return(TOKEN_ELSE);
print               return(TOKEN_PRINT);
int                 return(TOKEN_DINT);
float               return(TOKEN_DFLOAT);
String              return(TOKEN_DSTRING);

">"                  return(TOKEN_MAYOR);
"<"                  return(TOKEN_MENOR);
"!"                  return(TOKEN_NEGACION);
"="                  return(TOKEN_IGUAL);

{unsigned_integer}   return(TOKEN_UNSIGNED_INTEGER);
{real}               return(TOKEN_REAL);
{string}             return(TOKEN_STRING);
{bad_string}         yyerror("Unterminated string");

{identifier}         return(TOKEN_IDENTIFIER);

[*/+\-,^()\[\]\{\}\;]      return(yytext[0]);

{white_space}        /* do nothing */
\n                   yylineno += 1;
.                    yyerror("Illegal input");

%%

/* void yyerror(char *message)
{
   fprintf(stderr,"Error: \"%s\" in line %d. Token = %s\n",
           message,yylineno,yytext);
   exit(1);
} */