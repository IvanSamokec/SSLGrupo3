%option noinput nounput noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

void iniciarUbicaciones() {
    yylloc.first_line = yylloc.last_line = 1;
    yylloc.first_column = yylloc.last_column = 0;
}

void actualizarLocationsNuevaFila() {
    yylloc.first_column = yylloc.last_column = 0;
    yylloc.first_line += 1;
    yylloc.last_line += 1;
}

void actualizarLocationsColumnas() {
    yylloc.first_column = yylloc.last_column;
    yylloc.last_column += yyleng;
}

extern int errorCount;
%}

DECIMAL         0|[1-9][0-9]*
OCTAL           0[0-7]+
HEXADECIMAL     0[xX][0-9a-fA-F]+
REAL            [0-9]+\.[0-9]+([Ee][+-]?[0-9]+)?|[0-9]+[Ee][+-]?[0-9]+
CARACTER        \'(\\.|[^'\\])\'
LITERAL_CADENA  \"(\\.|[^"\\])*\"
RAW_STRING      `[^`]*`
TIPO_DATO       int|float32|float64|string|bool|rune|byte
IDENTIFICADOR   [a-zA-Z_][a-zA-Z0-9_]*

%%

[ \t\r] { 
    actualizarLocationsColumnas();
}

"\n" {
    actualizarLocationsNuevaFila();
}

"//"[^\n]* {
    actualizarLocationsColumnas();
}

"/*"([^*]|\*+[^*/])*\*+"/" {
    actualizarLocationsColumnas();
}

package { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return PACKAGE;
}

import { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return IMPORT;
}

func { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return FUNC;
}

var { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return VAR;
}

const { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return CONST;
}

type { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return TYPE;
}

struct { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return STRUCT;
}

if { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return IF;
}

else { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return ELSE;
}

for { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return FOR;
}

switch { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return SWITCH;
}

case { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return CASE;
}

default { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return DEFAULT;
}

return { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return RETURN;
}

break { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return BREAK;
}

continue { 
    printf("Palabra reservada: %s\n", yytext); 
    actualizarLocationsColumnas();
    return CONTINUE;
}

{TIPO_DATO} { 
    printf("Tipo de dato: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.cadena = strdup(yytext); 
    return TIPO_DATO;
}

true { 
    printf("Literal booleano: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.ival = 1;
    return TRUE;
}

false { 
    printf("Literal booleano: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.ival = 0;
    return FALSE;
}

{DECIMAL} { 
    printf("Constante entera decimal: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.ival = strtol(yytext, NULL, 10); 
    return ENTERO;
}

{OCTAL} { 
    printf("Constante entera octal: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.ival = strtol(yytext, NULL, 8); 
    return ENTERO;
}

{HEXADECIMAL} { 
    printf("Constante entera hexadecimal: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.ival = strtol(yytext, NULL, 16); 
    return ENTERO;
}

{REAL} { 
    printf("Constante real: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.dval = atof(yytext); 
    return REAL;
}

{CARACTER} { 
    printf("Constante caracter: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.cval = yytext[1]; 
    return CARACTER;
}

{LITERAL_CADENA} { 
    printf("Literal cadena: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.cadena = strdup(yytext); 
    return CADENA;
}

{RAW_STRING} { 
    printf("Raw string: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.cadena = strdup(yytext); 
    return CADENA;
}

{IDENTIFICADOR} { 
    printf("Identificador: %s\n", yytext); 
    actualizarLocationsColumnas();
    yylval.cadena = strdup(yytext); 
    return IDENTIFICADOR;
}

":=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return DECLARACION_CORTA;
}

"+=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return MAS_IGUAL;
}

"-=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return MENOS_IGUAL;
}

"*=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return POR_IGUAL;
}

"/=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return DIV_IGUAL;
}

"%=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return MOD_IGUAL;
}

"++" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return INCREMENTO;
}

"--" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return DECREMENTO;
}

"+" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '+';
}

"-" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '-';
}

"*" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '*';
}

"/" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '/';
}

"%" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '%';
}

"==" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return IGUALDAD;
}

"!=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return DIFERENTE;
}

"<=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return MENOR_IGUAL;
}

">=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return MAYOR_IGUAL;
}

"<" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '<';
}

">" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '>';
}

"&&" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return AND;
}

"||" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return OR;
}

"!" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '!';
}

"=" { 
    printf("Operador: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '=';
}

";" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return ';';
}

"," { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return ',';
}

"." { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '.';
}

":" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return ':';
}

"{" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '{';
}

"}" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '}';
}

"(" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '(';
}

")" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return ')';
}

"[" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return '[';
}

"]" { 
    printf("Caracter de puntuacion: %s\n", yytext); 
    actualizarLocationsColumnas();
    return ']';
}

. {
    actualizarLocationsColumnas();
    fprintf(stderr, "Error lexico <linea:%d columna:%d> Caracter no valido: '%s'\n", 
            yylloc.first_line, yylloc.first_column, yytext);
    errorCount++;
}

%%