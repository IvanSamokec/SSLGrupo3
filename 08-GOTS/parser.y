%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

int yylex(void);
void yyerror(const char *s);

int errorCount = 0;
Symbol *currentFunction = NULL;
bool hasReturnStatement = false;
%}

%code requires {
    #include "tabla_simbolos.h"
}

%locations

%union {
    int ival;
    double dval;
    char cval;
    char *cadena;
    DataType tipo;
    Symbol *simbolo;
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

/* Tipos para no terminales */
%type <tipo> tipo expresion
%type <cadena> tipo_retorno opt_tipo_retorno
%type <simbolo> funcion

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
    PACKAGE IDENTIFICADOR 
    {
        initSymbolTable();
    }
    imports declaraciones_top
    {
        if (errorCount == 0 && semanticErrors == 0) {
            printf("\n  Analisis completado exitosamente.\n");
        } else {
            printf("\n  Se encontraron %d errores sintacticos y %d errores semanticos.\n", 
                   errorCount, semanticErrors);
        }
    }
    | PACKAGE IDENTIFICADOR 
    {
        initSymbolTable();
    }
    declaraciones_top
    {
        if (errorCount == 0 && semanticErrors == 0) {
            printf("\n  Analisis completado exitosamente.\n");
        } else {
            printf("\n  Se encontraron %d errores sintacticos y %d errores semanticos.\n", 
                   errorCount, semanticErrors);
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
    | /* vacio */
    ;

declaracion_top:
    funcion
    | variable_top
    | constante_top
    | type_decl
    ;

type_decl:
    TYPE IDENTIFICADOR tipo
    {
        insertSymbol($2, SYM_TYPE, $3, 
            @1.first_line, @1.first_column);
        free($2);
    }
    ;

variable_top:
    VAR IDENTIFICADOR tipo '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_VARIABLE, $3, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible($3, $5)) {
                semanticError(@5.first_line, @5.first_column,
                    "Tipo incompatible en inicializacion de '%s': esperado %s, obtenido %s",
                    $2, dataTypeToString($3), dataTypeToString($5));
            }
        }
        free($2);
    }
    | VAR IDENTIFICADOR '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_VARIABLE, $4, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free($2);
    }
    | VAR IDENTIFICADOR tipo
    {
        insertSymbol($2, SYM_VARIABLE, $3, 
                                   @2.first_line, @2.first_column);
        free($2);
    }
    | VAR '(' var_block ')'
    ;

var_block:
    var_block var_spec
    | var_spec
    | /* vacio */
    ;

var_spec:
    IDENTIFICADOR tipo '=' expresion
    {
        Symbol *sym = insertSymbol($1, SYM_VARIABLE, $2, 
                                   @1.first_line, @1.first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible($2, $4)) {
                semanticError(@4.first_line, @4.first_column,
                    "Tipo incompatible en inicializacion de '%s'", $1);
            }
        }
        free($1);
    }
    | IDENTIFICADOR '=' expresion
    {
        Symbol *sym = insertSymbol($1, SYM_VARIABLE, $3, 
                                   @1.first_line, @1.first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free($1);
    }
    | IDENTIFICADOR tipo
    {
        insertSymbol($1, SYM_VARIABLE, $2, 
                                   @1.first_line, @1.first_column);
        free($1);
    }
    ;

constante_top:
    CONST IDENTIFICADOR tipo '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_CONSTANT, $3, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible($3, $5)) {
                semanticError(@5.first_line, @5.first_column,
                    "Tipo incompatible en constante '%s'", $2);
            }
        }
        free($2);
    }
    | CONST IDENTIFICADOR '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_CONSTANT, $4, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free($2);
    }
    | CONST '(' const_block ')'
    ;

const_block:
    const_block const_spec
    | const_spec
    | /* vacio */
    ;

const_spec:
    IDENTIFICADOR tipo '=' expresion
    {
        Symbol *sym = insertSymbol($1, SYM_CONSTANT, $2, 
                                   @1.first_line, @1.first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible($2, $4)) {
                semanticError(@4.first_line, @4.first_column,
                    "Tipo incompatible en constante '%s'", $1);
            }
        }
        free($1);
    }
    | IDENTIFICADOR '=' expresion
    {
        Symbol *sym = insertSymbol($1, SYM_CONSTANT, $3, 
                                   @1.first_line, @1.first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free($1);
    }
    | IDENTIFICADOR tipo
    {
        semanticError(@1.first_line, @1.first_column,
            "Las constantes deben ser inicializadas: '%s'", $1);
        free($1);
    }
    | IDENTIFICADOR
    {
        semanticError(@1.first_line, @1.first_column,
            "Las constantes deben tener tipo e inicializacion: '%s'", $1);
        free($1);
    }
    ;

funcion:
    FUNC IDENTIFICADOR 
    {
        currentFunction = insertSymbol($2, SYM_FUNCTION, TYPE_VOID, 
                                       @2.first_line, @2.first_column);
        hasReturnStatement = false;
    }
    '(' parametros ')' opt_tipo_retorno bloque
    {
        if (currentFunction && $7) {
            DataType retType = stringToDataType($7);
            setReturnType(currentFunction, retType);
           
        }
        currentFunction = NULL;
        free($2);
        if ($7) free($7);
        $$ = currentFunction;
    }
    ;

opt_tipo_retorno:
    tipo_retorno
    { $$ = $1; }
    | /* vacio */
    { $$ = NULL; }
    ;

parametros:
    lista_parametros
    | /* vacio */
    ;

lista_parametros:
    lista_parametros ',' parametro
    | parametro
    ;

parametro:
    IDENTIFICADOR tipo
    {
        Symbol *param = insertSymbol($1, SYM_PARAMETER, $2, 
                                     @1.first_line, @1.first_column);
        if (param && currentFunction) {
            addParameter(currentFunction, $1, $2);
        }
        free($1);
    }
    | IDENTIFICADOR ',' IDENTIFICADOR tipo
    {
        Symbol *param1 = insertSymbol($1, SYM_PARAMETER, $4, 
                                      @1.first_line, @1.first_column);
        Symbol *param2 = insertSymbol($3, SYM_PARAMETER, $4, 
                                      @3.first_line, @3.first_column);
        if (currentFunction) {
            if (param1) addParameter(currentFunction, $1, $4);
            if (param2) addParameter(currentFunction, $3, $4);
        }
        free($1);
        free($3);
    }
    ;

tipo_retorno:
    tipo
    {
        $$ = strdup(dataTypeToString($1));
    }
    | '(' lista_tipos ')'
    {
        $$ = strdup("multiple");
    }
    ;

lista_tipos:
    lista_tipos ',' tipo
    | tipo
    ;

variable:
    VAR IDENTIFICADOR tipo '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_VARIABLE, $3, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible($3, $5)) {
                semanticError(@5.first_line, @5.first_column,
                    "Tipo incompatible en inicializacion de '%s'", $2);
            }
        }
        free($2);
    }
    | VAR IDENTIFICADOR '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_VARIABLE, $4, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free($2);
    }
    | VAR IDENTIFICADOR tipo
    {
        insertSymbol($2, SYM_VARIABLE, $3, 
                                   @2.first_line, @2.first_column);
        free($2);
    }
    | VAR lista_ids tipo
    | VAR lista_ids '=' lista_expresiones
    ;

lista_ids:
    lista_ids ',' IDENTIFICADOR
    {
        free($3);
    }
    | IDENTIFICADOR ',' IDENTIFICADOR
    {
        free($1);
        free($3);
    }
    ;

lista_expresiones:
    lista_expresiones ',' expresion
    | expresion ',' expresion
    ;

constante:
    CONST IDENTIFICADOR tipo '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_CONSTANT, $3, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible($3, $5)) {
                semanticError(@5.first_line, @5.first_column,
                    "Tipo incompatible en constante '%s'", $2);
            }
        }
        free($2);
    }
    | CONST IDENTIFICADOR '=' expresion
    {
        Symbol *sym = insertSymbol($2, SYM_CONSTANT, $4, 
                                   @2.first_line, @2.first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free($2);
    }
    ;

tipo:
    TIPO_DATO
    {
        $$ = stringToDataType($1);
        free($1);
    }
    | IDENTIFICADOR
    {
        Symbol *typeSym = lookupSymbol($1);
        if (typeSym && typeSym->kind == SYM_TYPE) {
            $$ = typeSym->type;
        } else {
            semanticError(@1.first_line, @1.first_column,
                "Tipo no definido: '%s'", $1);
            $$ = TYPE_UNKNOWN;
        }
        free($1);
    }
    | '[' ENTERO ']' tipo
    {
        $$ = $4;
    }
    | '[' ']' tipo
    {
        $$ = $3;
    }
    ;

bloque:
    '{' 
    {
        enterScope();
    }
    sentencias '}'
    {
        exitScope();
    }
    ;

sentencias:
    sentencias sentencia
    | /* vacio */
    ;

sentencia:
    RETURN expresion
    {
        hasReturnStatement = true;
        if (currentFunction) {
            if (!areTypesCompatible(currentFunction->returnType, $2)) {
                semanticError(@2.first_line, @2.first_column,
                    "Tipo de retorno incompatible: esperado %s, obtenido %s",
                    dataTypeToString(currentFunction->returnType),
                    dataTypeToString($2));
            }
        }
    }
    | RETURN
    {
        hasReturnStatement = true;
        if (currentFunction && currentFunction->returnType != TYPE_VOID) {
            semanticError(@1.first_line, @1.first_column,
                "La funcion debe retornar un valor de tipo %s",
                dataTypeToString(currentFunction->returnType));
        }
    }
    | IF expresion 
    {
        if ($2 != TYPE_BOOL && $2 != TYPE_UNKNOWN) {
            semanticError(@2.first_line, @2.first_column,
                "La condicion del if debe ser de tipo bool");
        }
    }
    bloque
    | IF expresion 
    {
        if ($2 != TYPE_BOOL && $2 != TYPE_UNKNOWN) {
            semanticError(@2.first_line, @2.first_column,
                "La condicion del if debe ser de tipo bool");
        }
    }
    bloque ELSE bloque
    | IF expresion 
    {
        if ($2 != TYPE_BOOL && $2 != TYPE_UNKNOWN) {
            semanticError(@2.first_line, @2.first_column,
                "La condicion del if debe ser de tipo bool");
        }
    }
    bloque ELSE sentencia
    | FOR expresion 
    {
        if ($2 != TYPE_BOOL && $2 != TYPE_UNKNOWN) {
            semanticError(@2.first_line, @2.first_column,
                "La condicion del for debe ser de tipo bool");
        }
    }
    bloque
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
    {
        if (isDeclaredInCurrentScope($1)) {
            semanticError(@1.first_line, @1.first_column,
                "Redeclaracion de '%s' con :=", $1);
        } else {
            Symbol *sym = insertSymbol($1, SYM_VARIABLE, $3, 
                                       @1.first_line, @1.first_column);
            if (sym) {
                setSymbolInitialized(sym);
            }
        }
        free($1);
    }
    ;

declaracion_corta_multiple:
    lista_ids DECLARACION_CORTA lista_expresiones
    ;

asignacion:
    expresion '=' expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@3.first_line, @3.first_column,
                "Tipos incompatibles en asignacion");
        }
    }
    | expresion MAS_IGUAL expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@3.first_line, @3.first_column,
                "Tipos incompatibles en operacion +=");
        }
    }
    | expresion MENOS_IGUAL expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@3.first_line, @3.first_column,
                "Tipos incompatibles en operacion -=");
        }
    }
    | expresion POR_IGUAL expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@3.first_line, @3.first_column,
                "Tipos incompatibles en operacion *=");
        }
    }
    | expresion DIV_IGUAL expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@3.first_line, @3.first_column,
                "Tipos incompatibles en operacion /=");
        }
    }
    | expresion MOD_IGUAL expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@3.first_line, @3.first_column,
                "Tipos incompatibles en operacion %=");
        }
    }
    ;

asignacion_multiple:
    lista_ids '=' lista_expresiones
    ;

inicializacion:
    declaracion_corta
    | declaracion_corta_multiple
    | asignacion
    | asignacion_multiple
    | /* vacio */
    ;

condicion:
    expresion
    | /* vacio */
    ;

post_iteracion:
    expresion
    | asignacion
    | /* vacio */
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
    {
        Symbol *sym = lookupSymbol($1);
        if (!sym) {
          
            $$ = TYPE_UNKNOWN;
        } else {
           
            $$ = sym->type;
        }
        free($1);
    }
    | ENTERO
    {
        $$ = TYPE_INT;
    }
    | REAL
    {
        $$ = TYPE_FLOAT64;
    }
    | CARACTER
    {
        $$ = TYPE_RUNE;
    }
    | CADENA
    {
        $$ = TYPE_STRING;
        free($1);
    }
    | TRUE
    {
        $$ = TYPE_BOOL;
    }
    | FALSE
    {
        $$ = TYPE_BOOL;
    }
    | '(' expresion ')'
    {
        $$ = $2;
    }
    | expresion '+' expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@2.first_line, @2.first_column,
                "Tipos incompatibles en operacion +");
        }
        $$ = getResultType($1, $3, "+");
    }
    | expresion '-' expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@2.first_line, @2.first_column,
                "Tipos incompatibles en operacion -");
        }
        $$ = getResultType($1, $3, "-");
    }
    | expresion '*' expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@2.first_line, @2.first_column,
                "Tipos incompatibles en operacion *");
        }
        $$ = getResultType($1, $3, "*");
    }
    | expresion '/' expresion
    {
        if (!areTypesCompatible($1, $3)) {
            semanticError(@2.first_line, @2.first_column,
                "Tipos incompatibles en operacion /");
        }
        $$ = getResultType($1, $3, "/");
    }
    | expresion '%' expresion
    {
        if ($1 != TYPE_INT || $3 != TYPE_INT) {
            semanticError(@2.first_line, @2.first_column,
                "El operador %% requiere operandos enteros");
        }
        $$ = TYPE_INT;
    }
    | expresion IGUALDAD expresion
    {
        $$ = TYPE_BOOL;
    }
    | expresion DIFERENTE expresion
    {
        $$ = TYPE_BOOL;
    }
    | expresion '<' expresion
    {
        $$ = TYPE_BOOL;
    }
    | expresion '>' expresion
    {
        $$ = TYPE_BOOL;
    }
    | expresion MENOR_IGUAL expresion
    {
        $$ = TYPE_BOOL;
    }
    | expresion MAYOR_IGUAL expresion
    {
        $$ = TYPE_BOOL;
    }
    | expresion AND expresion
    {
        if ($1 != TYPE_BOOL || $3 != TYPE_BOOL) {
            semanticError(@2.first_line, @2.first_column,
                "El operador && requiere operandos booleanos");
        }
        $$ = TYPE_BOOL;
    }
    | expresion OR expresion
    {
        if ($1 != TYPE_BOOL || $3 != TYPE_BOOL) {
            semanticError(@2.first_line, @2.first_column,
                "El operador || requiere operandos booleanos");
        }
        $$ = TYPE_BOOL;
    }
    | '!' expresion %prec UNARIO
    {
        if ($2 != TYPE_BOOL) {
            semanticError(@1.first_line, @1.first_column,
                "El operador ! requiere un operando booleano");
        }
        $$ = TYPE_BOOL;
    }
    | '-' expresion %prec UNARIO
    {
        if ($2 != TYPE_INT && $2 != TYPE_FLOAT32 && $2 != TYPE_FLOAT64) {
            semanticError(@1.first_line, @1.first_column,
                "El operador unario - requiere un operando numerico");
        }
        $$ = $2;
    }
    | '+' expresion %prec UNARIO
    {
        if ($2 != TYPE_INT && $2 != TYPE_FLOAT32 && $2 != TYPE_FLOAT64) {
            semanticError(@1.first_line, @1.first_column,
                "El operador unario + requiere un operando numerico");
        }
        $$ = $2;
    }
    | expresion INCREMENTO
    {
        if ($1 != TYPE_INT && $1 != TYPE_FLOAT32 && $1 != TYPE_FLOAT64) {
            semanticError(@2.first_line, @2.first_column,
                "El operador ++ requiere un operando numerico");
        }
        $$ = $1;
    }
    | expresion DECREMENTO
    {
        if ($1 != TYPE_INT && $1 != TYPE_FLOAT32 && $1 != TYPE_FLOAT64) {
            semanticError(@2.first_line, @2.first_column,
                "El operador -- requiere un operando numerico");
        }
        $$ = $1;
    }
    | INCREMENTO expresion
    {
        if ($2 != TYPE_INT && $2 != TYPE_FLOAT32 && $2 != TYPE_FLOAT64) {
            semanticError(@1.first_line, @1.first_column,
                "El operador ++ requiere un operando numerico");
        }
        $$ = $2;
    }
    | DECREMENTO expresion
    {
        if ($2 != TYPE_INT && $2 != TYPE_FLOAT32 && $2 != TYPE_FLOAT64) {
            semanticError(@1.first_line, @1.first_column,
                "El operador -- requiere un operando numerico");
        }
        $$ = $2;
    }
    | expresion '(' argumentos ')'
    {
        $$ = TYPE_UNKNOWN;
    }
    | expresion '[' expresion ']'
    {
        if ($3 != TYPE_INT) {
            semanticError(@3.first_line, @3.first_column,
                "El indice del arreglo debe ser de tipo int");
        }
        $$ = $1;
    }
    | expresion '.' IDENTIFICADOR
    {
        $$ = TYPE_UNKNOWN;
        free($3);
    }
    | TIPO_DATO '(' expresion ')'
    {
        $$ = stringToDataType($1);
        free($1);
    }
    | IDENTIFICADOR '(' argumentos ')'
    {
        /* Accept zero or more arguments for function calls
           and treat result as unknown for now (could be refined
           using symbol table / signature checking). */
        Symbol *funcSym = lookupSymbol($1);
        if (funcSym && funcSym->kind == SYM_FUNCTION) {
            $$ = funcSym->returnType;
        } else {
            $$ = TYPE_UNKNOWN;
        }
        free($1);
    }
    ;

argumentos:
    lista_argumentos
    | /* vacio */
    ;

lista_argumentos:
    lista_argumentos ',' expresion
    | expresion
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico en linea %d, columna %d: %s\n", 
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

    yyparse();
    
    fclose(yyin);
    return (errorCount > 0 || semanticErrors > 0) ? 1 : 0;
}