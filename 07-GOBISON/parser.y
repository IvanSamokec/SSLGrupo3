%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s);

int errorCount = 0;
%}

%locations

%union {
    int ival;
    double dval;
    char cval;
    char *cadena;
}

/* Tokens con tipo */
%token <cadena> IDENTIFICADOR TIPO_DATO CADENA
%token <ival> ENTERO TRUE FALSE
%token <dval> REAL
%token <cval> CARACTER

/* Palabras reservadas */
%token PACKAGE IMPORT FUNC VAR CONST TYPE STRUCT
%token IF ELSE FOR SWITCH CASE DEFAULT
%token RETURN BREAK CONTINUE

/* Operadores */
%token DECLARACION_CORTA
%token INCREMENTO DECREMENTO
%token MAS_IGUAL MENOS_IGUAL POR_IGUAL DIV_IGUAL MOD_IGUAL
%token IGUALDAD DIFERENTE MENOR_IGUAL MAYOR_IGUAL
%token AND OR

/* Precedencia y asociatividad */
%left OR
%left AND
%left IGUALDAD DIFERENTE
%left '<' '>' MENOR_IGUAL MAYOR_IGUAL
%left '+' '-'
%left '*' '/' '%'
%right '!' UNARIO
%left INCREMENTO DECREMENTO
%left '.' '(' '['

%%

programa:
    PACKAGE IDENTIFICADOR imports declaraciones_top
    {
        if (errorCount == 0) {
            printf("\nAnálisis completado exitosamente.\n");
        } else {
            printf("\nSe encontraron %d errores.\n", errorCount);
        }
    }
    | PACKAGE IDENTIFICADOR declaraciones_top
    {
        if (errorCount == 0) {
            printf("\nAnálisis completado exitosamente.\n");
        } else {
            printf("\nSe encontraron %d errores.\n", errorCount);
        }
    }
    ;

imports:
    imports import_stmt
    | import_stmt
    ;

import_stmt:
    IMPORT CADENA
    | IMPORT '(' import_list ')'
    ;

import_list:
    import_list CADENA
    | CADENA
    ;

declaraciones_top:
    declaraciones_top declaracion_top
    | /* vacío */
    ;

declaracion_top:
    funcion
    | variable_top
    | constante_top
    | type_decl
    ;

type_decl:
    TYPE IDENTIFICADOR tipo
    ;

variable_top:
    VAR IDENTIFICADOR tipo '=' expresion
    | VAR IDENTIFICADOR '=' expresion
    | VAR IDENTIFICADOR tipo
    | VAR '(' var_block ')'
    ;

var_block:
    var_block var_spec
    | var_spec
    | /* vacío */
    ;

var_spec:
    IDENTIFICADOR tipo '=' expresion
    | IDENTIFICADOR '=' expresion
    | IDENTIFICADOR tipo
    ;

constante_top:
    CONST IDENTIFICADOR tipo '=' expresion
    | CONST IDENTIFICADOR '=' expresion
    | CONST '(' const_block ')'
    ;

const_block:
    const_block const_spec
    | const_spec
    | /* vacío */
    ;

const_spec:
    IDENTIFICADOR tipo '=' expresion
    | IDENTIFICADOR '=' expresion
    | IDENTIFICADOR tipo
    | IDENTIFICADOR
    ;

funcion:
    FUNC IDENTIFICADOR '(' parametros ')' tipo_retorno bloque
    | FUNC IDENTIFICADOR '(' parametros ')' bloque
    ;

parametros:
    lista_parametros
    | /* vacío */
    ;

lista_parametros:
    lista_parametros ',' parametro
    | parametro
    ;

parametro:
    IDENTIFICADOR tipo
    | IDENTIFICADOR ',' IDENTIFICADOR tipo
    ;

tipo_retorno:
    tipo
    | '(' lista_tipos ')'
    ;

lista_tipos:
    lista_tipos ',' tipo
    | tipo
    ;

variable:
    VAR IDENTIFICADOR tipo '=' expresion
    | VAR IDENTIFICADOR '=' expresion
    | VAR IDENTIFICADOR tipo
    | VAR lista_ids tipo
    | VAR lista_ids '=' lista_expresiones
    ;

lista_ids:
    lista_ids ',' IDENTIFICADOR
    | IDENTIFICADOR ',' IDENTIFICADOR
    ;

lista_expresiones:
    lista_expresiones ',' expresion
    | expresion ',' expresion
    ;

constante:
    CONST IDENTIFICADOR tipo '=' expresion
    | CONST IDENTIFICADOR '=' expresion
    ;

tipo:
    TIPO_DATO
    | IDENTIFICADOR
    | '[' ENTERO ']' tipo
    | '[' ']' tipo
    ;

bloque:
    '{' sentencias '}'
    ;

sentencias:
    sentencias sentencia
    | /* vacío */
    ;

sentencia:
    RETURN expresion
    | RETURN
    | IF expresion bloque
    | IF expresion bloque ELSE bloque
    | IF expresion bloque ELSE sentencia
    | FOR expresion bloque
    | FOR bloque
    | FOR inicializacion ';' condicion ';' post_iteracion bloque
    | SWITCH expresion '{' casos '}'
    | expresion
    | declaracion_corta
    | declaracion_corta_multiple
    | asignacion
    | asignacion_multiple
    | variable
    | constante
    | BREAK
    | CONTINUE
    | bloque
    ;

declaracion_corta:
    IDENTIFICADOR DECLARACION_CORTA expresion
    ;

declaracion_corta_multiple:
    lista_ids DECLARACION_CORTA lista_expresiones
    ;

asignacion:
    expresion '=' expresion
    | expresion MAS_IGUAL expresion
    | expresion MENOS_IGUAL expresion
    | expresion POR_IGUAL expresion
    | expresion DIV_IGUAL expresion
    | expresion MOD_IGUAL expresion
    ;

asignacion_multiple:
    lista_ids '=' lista_expresiones
    ;

inicializacion:
    declaracion_corta
    | declaracion_corta_multiple
    | asignacion
    | asignacion_multiple
    | /* vacío */
    ;

condicion:
    expresion
    | /* vacío */
    ;

post_iteracion:
    expresion
    | asignacion
    | /* vacío */
    ;

casos:
    casos caso
    | caso
    ;

caso:
    CASE expresion ':' sentencias
    | DEFAULT ':' sentencias
    ;

expresion:
    IDENTIFICADOR
    | ENTERO
    | REAL
    | CARACTER
    | CADENA
    | TRUE
    | FALSE
    | '(' expresion ')'
    | expresion '+' expresion
    | expresion '-' expresion
    | expresion '*' expresion
    | expresion '/' expresion
    | expresion '%' expresion
    | expresion IGUALDAD expresion
    | expresion DIFERENTE expresion
    | expresion '<' expresion
    | expresion '>' expresion
    | expresion MENOR_IGUAL expresion
    | expresion MAYOR_IGUAL expresion
    | expresion AND expresion
    | expresion OR expresion
    | '!' expresion %prec UNARIO
    | '-' expresion %prec UNARIO
    | '+' expresion %prec UNARIO
    | expresion INCREMENTO
    | expresion DECREMENTO
    | INCREMENTO expresion
    | DECREMENTO expresion
    | expresion '(' argumentos ')'
    | expresion '[' expresion ']'
    | expresion '.' IDENTIFICADOR
    | TIPO_DATO '(' expresion ')'
    | IDENTIFICADOR '(' expresion ')'
    ;

argumentos:
    lista_argumentos
    | /* vacío */
    ;

lista_argumentos:
    lista_argumentos ',' expresion
    | expresion
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico en línea %d, columna %d: %s\n", 
            yylloc.first_line, yylloc.first_column, s);
    errorCount++;
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

    extern void iniciarUbicaciones();
    iniciarUbicaciones();

    printf("Iniciando análisis de %s...\n\n", argv[1]);
    yyparse();
    
    fclose(yyin);
    return errorCount > 0 ? 1 : 0;
}