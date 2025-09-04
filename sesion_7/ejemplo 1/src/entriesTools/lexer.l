%{
#include "parser.tab.h"

#include <stdio.h>
#include <string.h>

extern void yyerror(const char *s);

/* Contador de columna */
int yycolumn = 1;

/* Se ejecuta antes de cada accion, actualiza yylloc y columna */
#define YY_USER_ACTION                                   \
    yylloc.first_line   = yylineno;                      \
    yylloc.first_column = yycolumn;                      \
    yylloc.last_line    = yylineno;                      \
    yylloc.last_column  = yycolumn + yyleng - 1;         \
    yycolumn += yyleng;
%}

/* Opciones de Flex 
 * yylineno:  mantenga el numero de la linea actual
 leida desde su entrada en la variable global yylineno.
 * noyywrap:  hace que el analizador no llame a yywrap() hasta el fin-de-fichero, 
 pero simplemente asume que no hay mas ficheros que analizar.
*/
%option noyywrap yylineno nounput noinput

/* Condiciones de arranque */
%x COMMENT2 COMMENTLINEA

/* definiciones */
white_space       [ \t]*
digit             [0-9]
alpha             [A-Za-z_]
alpha_num         ({alpha}|{digit})
/* hex_digit         [0-9A-F] */
identifier        {alpha}{alpha_num}*
unsigned_integer  {digit}+
/* hex_integer       ${hex_digit}{hex_digit}* */
exponent          e[+-]?{digit}+
i                 {unsigned_integer}
real              ({i}\.{i}?|{i}?\.{i}){exponent}?
string            \"([^"\n]|\"\")+\"
bad_string        \"([^"\n]|\"\")+

%%
"//"                     BEGIN(COMMENTLINEA);
<COMMENTLINEA>[^\n\r]+ 
<COMMENTLINEA><<EOF>>    yyerror("EOF in comment");
<COMMENTLINEA>[\n\r]     {yycolumn=1; BEGIN(INITIAL);}

"(*"                 BEGIN(COMMENT2);
<COMMENT2>[^)*\n\r]+
<COMMENT2>[\n\r]     {yycolumn=1;}
<COMMENT2><<EOF>>    yyerror("EOF in comment");
<COMMENT2>"*)"       BEGIN(INITIAL);
<COMMENT2>[*)]

if                  return(TOKEN_IF);
else                return(TOKEN_ELSE);
print               return(TOKEN_PRINT);
func               return(TOKEN_FUNC);
int                 return(TOKEN_DINT);
float               return(TOKEN_DFLOAT);
String              return(TOKEN_DSTRING);
true                return(TOKEN_TRUE);
false               return(TOKEN_FALSE);
return              return(TOKEN_RETURN);

{unsigned_integer}   {yylval.string = strdup(yytext); return(TOKEN_UNSIGNED_INTEGER);}
{real}               {yylval.string = strdup(yytext); return(TOKEN_REAL);}
{string}             {yylval.string = malloc(yyleng); strncpy(yylval.string, &yytext[1], yyleng - 2); return(TOKEN_STRING);}
{bad_string}         yyerror("Unterminated string");

{identifier}         {yylval.string = strdup(yytext); return(TOKEN_IDENTIFIER);}

[*/+\-,^()\[\]{}\;=\>\<!]      return(yytext[0]);

{white_space}        /* do nothing */
[\n\r]               {yycolumn=1;}
.                    yyerror("Illegal input");

%%