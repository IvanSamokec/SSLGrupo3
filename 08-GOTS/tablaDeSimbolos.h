#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

// Tipos de símbolos
typedef enum {
    SYM_VARIABLE,
    SYM_CONSTANT,
    SYM_FUNCTION,
    SYM_TYPE,
    SYM_PARAMETER
} SymbolKind;

// Tipos de datos
typedef enum {
    TYPE_INT,
    TYPE_FLOAT32,
    TYPE_FLOAT64,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_RUNE,
    TYPE_BYTE,
    TYPE_VOID,
    TYPE_CUSTOM,
    TYPE_UNKNOWN
} DataType;

// Estructura para parámetros de función
typedef struct Parameter {
    char *name;
    DataType type;
    struct Parameter *next;
} Parameter;

// Información del símbolo
typedef struct Symbol {
    char *name;
    SymbolKind kind;
    DataType type;
    char *customType;  // Para tipos personalizados
    int line;
    int column;
    bool initialized;
    bool isGlobal;
    
    // Para funciones
    Parameter *parameters;
    DataType returnType;
    char *customReturnType;
    int paramCount;
    
    // Para arreglos
    bool isArray;
    int arraySize;
    
    struct Symbol *next;
} Symbol;

// Estructura de alcance (scope)
typedef struct Scope {
    Symbol *symbols;
    struct Scope *parent;
    int level;
} Scope;

// Variables globales
extern Scope *currentScope;
extern Scope *globalScope;
extern int semanticErrors;

// Funciones de manejo de alcance
void initSymbolTable();
void enterScope();
void exitScope();

// Funciones de tabla de símbolos
Symbol* insertSymbol(const char *name, SymbolKind kind, DataType type, 
                     int line, int column);
Symbol* lookupSymbol(const char *name);
Symbol* lookupSymbolInCurrentScope(const char *name);
bool isDeclared(const char *name);
bool isDeclaredInCurrentScope(const char *name);

// Funciones auxiliares para símbolos
void setSymbolInitialized(Symbol *sym);
void setSymbolAsArray(Symbol *sym, int size);
void addParameter(Symbol *funcSym, const char *paramName, DataType paramType);
void setReturnType(Symbol *funcSym, DataType returnType);

// Funciones de conversión de tipos
DataType stringToDataType(const char *typeStr);
const char* dataTypeToString(DataType type);
bool areTypesCompatible(DataType type1, DataType type2);
DataType getResultType(DataType type1, DataType type2, const char *op);

// Funciones de reporte de errores semánticos
void semanticError(int line, int column, const char *format, ...);
void semanticWarning(int line, int column, const char *format, ...);

// Funciones de impresión
void printSymbolTable();
void printScope(Scope *scope);

// Liberación de memoria
void freeSymbolTable();
void freeScope(Scope *scope);

#endif // SYMBOL_TABLE_H