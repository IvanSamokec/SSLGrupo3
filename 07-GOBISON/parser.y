%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

/* Tokens */
%token PACKAGE IMPORT FUNC VAR CONST RETURN IF ELSE FOR SWITCH CASE DEFAULT
%token INT FLOAT32 FLOAT64 STRING_TYPE BOOL RUNE
%token IDENTIFICADOR
%token DECIMAL REAL CARACTER LITERAL_CADENA
%token OPERADOR

/* Precedencia y asociatividad */
%left OPERADOR
%nonassoc IF ELSE

%%

programa:
    PACKAGE IDENTIFICADOR declaraciones
    ;

declaraciones:
    declaraciones declaracion
    | /* vacío */
    ;

declaracion:
    funcion
    | variable
    | constante
    ;

funcion:
    FUNC IDENTIFICADOR '(' ')' bloque
    ;

variable:
    VAR IDENTIFICADOR tipo '=' expresion ';'
    ;

constante:
    CONST IDENTIFICADOR tipo '=' expresion ';'
    ;

tipo:
    INT
    | FLOAT32
    | FLOAT64
    | STRING_TYPE
    | BOOL
    | RUNE
    ;

bloque:
    '{' sentencias '}'
    ;

sentencias:
    sentencias sentencia
    | /* vacío */
    ;

sentencia:
    RETURN expresion ';'
    | IF expresion bloque
    | FOR expresion bloque
    | expresion ';'
    ;

expresion:
    IDENTIFICADOR
    | DECIMAL
    | REAL
    | CARACTER
    | LITERAL_CADENA
    | '(' expresion ')'
    | expresion OPERADOR expresion %prec OPERADOR
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico: %s\n", s);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo.go>\n", argv[0]);
        return 1;
    }

    extern FILE *yyin;
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    yyparse();
    fclose(yyin);
    return 0;
}
