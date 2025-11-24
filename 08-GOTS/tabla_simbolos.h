#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

typedef enum {
    SYM_VARIABLE,
    SYM_CONSTANT,
    SYM_FUNCTION,
    SYM_TYPE,
    SYM_PARAMETER
} SymbolKind;

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

typedef struct Parameter {
    char *name;
    DataType type;
    struct Parameter *next;
} Parameter;

typedef struct Symbol {
    char *name;
    SymbolKind kind;
    DataType type;
    char *customType;
    int line;
    int column;
    bool initialized;
    bool isGlobal;
    Parameter *parameters;
    DataType returnType;
    char *customReturnType;
    int paramCount;
    bool isArray;
    int arraySize;
    struct Symbol *next;
} Symbol;

typedef struct Scope {
    Symbol *symbols;
    struct Scope *parent;
    int level;
} Scope;

extern Scope *currentScope;
extern Scope *globalScope;
extern int semanticErrors;

void initSymbolTable();
void enterScope();
void exitScope();

Symbol* insertSymbol(const char *name, SymbolKind kind, DataType type,
                     int line, int column);
Symbol* lookupSymbol(const char *name);
Symbol* lookupSymbolInCurrentScope(const char *name);
bool isDeclared(const char *name);
bool isDeclaredInCurrentScope(const char *name);

void setSymbolInitialized(Symbol *sym);
void setSymbolAsArray(Symbol *sym, int size);
void addParameter(Symbol *funcSym, const char *paramName, DataType paramType);
void setReturnType(Symbol *funcSym, DataType returnType);

DataType stringToDataType(const char *typeStr);
const char* dataTypeToString(DataType type);
bool areTypesCompatible(DataType type1, DataType type2);
DataType getResultType(DataType type1, DataType type2, const char *op);

void semanticError(int line, int column, const char *format, ...);
void semanticWarning(int line, int column, const char *format, ...);

void printSymbolTable();
void printScope(Scope *scope);

void freeSymbolTable();
void freeScope(Scope *scope);

#endif