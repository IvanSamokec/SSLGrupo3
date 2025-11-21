%option noyywrap
%option yylineno
%option noinput
%option nounput

%{
   #include <stdio.h>
%}

DECIMAL         [0-9]+
OCTAL           0[0-7]+
HEXADECIMAL     0[xX][0-9a-fA-F]+
BINARIO         0[bB][01]+
REAL            [0-9]+\.[0-9]+([eE][+-]?[0-9]+)?
CARACTER        \'(\\.|[^\\'])\'
LITERAL_CADENA  \"([^\"\\]|\\.)*\"|`([^`]*)`
TIPO_DATO       int|int64|int32|float64|float32|string|bool|byte|rune
IF              if
ELSE            else
FOR             for
SWITCH          switch
CASE            case
DEFAULT         default
RETURN          return
FUNC            func
PACKAGE         package
IMPORT          import
VAR             var
CONST           const
TYPE            type
STRUCT          struct
INTERFACE       interface
GO              go
DEFER           defer
SELECT          select
BREAK           break
CONTINUE        continue
IDENTIFICADOR   [a-zA-Z_][a-zA-Z0-9_]*
OPERADOR        "++"|"--"|"+="|"-="|"*="|"/="|"%="|"+"|"-"|"*"|"/"|"%"|"=="|"="|"!="|"<"|"<="|">"|">="|"&&"|"||"|"!"|":="|"..."
PUNTUACION      ";"|","|"{"|"}"|"("|")"|"["|"]"|"."


%%

[ \t\n]+             { /* Ignorar espacios en blanco */ }

{DECIMAL}              { printf("Constante entera decimal: %s\n", yytext); }
{OCTAL}                { printf("Constante entera octal: %s\n", yytext); }
{HEXADECIMAL}          { printf("Constante entera hexadecimal: %s\n", yytext); }
{BINARIO}              { printf("Constante entera binaria: %s\n", yytext); }
{REAL}                 { printf("Constante real: %s\n", yytext); }
{CARACTER}             { printf("Constante caracter: %s\n", yytext); }
{LITERAL_CADENA}       { printf("Literal cadena: %s\n", yytext); }
{TIPO_DATO}            { printf("Palabra reservada (tipo de dato): %s\n", yytext); }
{IF}                   { printf("Palabra reservada (control): %s\n", yytext); }
{ELSE}                 { printf("Palabra reservada (control): %s\n", yytext); }
{FOR}                  { printf("Palabra reservada (control): %s\n", yytext); }
{SWITCH}               { printf("Palabra reservada (control): %s\n", yytext); }
{CASE}                 { printf("Palabra reservada (control): %s\n", yytext); }
{DEFAULT}              { printf("Palabra reservada (control): %s\n", yytext); }
{RETURN}               { printf("Palabra reservada (control): %s\n", yytext); }
{FUNC}                 { printf("Palabra reservada (definicion): %s\n", yytext); }
{PACKAGE}              { printf("Palabra reservada (definicion): %s\n", yytext); }
{IMPORT}               { printf("Palabra reservada (definicion): %s\n", yytext); }
{VAR}                  { printf("Palabra reservada (definicion): %s\n", yytext); }
{CONST}                { printf("Palabra reservada (definicion): %s\n", yytext); }
{TYPE}                 { printf("Palabra reservada (definicion): %s\n", yytext); }
{STRUCT}               { printf("Palabra reservada (definicion): %s\n", yytext); }
{INTERFACE}            { printf("Palabra reservada (definicion): %s\n", yytext); }
{GO}                   { printf("Palabra reservada (concurrencia): %s\n", yytext); }
{DEFER}                { printf("Palabra reservada (concurrencia): %s\n", yytext); }
{SELECT}               { printf("Palabra reservada (concurrencia): %s\n", yytext); }
{BREAK}                { printf("Palabra reservada (control): %s\n", yytext); }
{CONTINUE}             { printf("Palabra reservada (control): %s\n", yytext); }
{IDENTIFICADOR}        { printf("Identificador: %s\n", yytext); }
{OPERADOR}             { printf("Operador: %s\n", yytext); }
{PUNTUACION}           { printf("Caracter de puntuacion: %s\n", yytext); }

.                      { printf("Error lexico: %s\n", yytext); }

%%

int main(int argc, char *argv[]) {
   if (argc < 2) {
      fprintf(stderr, "Uso: %s <archivo.go>\n", argv[0]);
      return 1;
   }

   yyin = fopen(argv[1], "r");
   yylex();
   fclose(yyin);
   return 0;
}
