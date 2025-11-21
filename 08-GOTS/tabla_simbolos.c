#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Variables globales
Scope *currentScope = NULL;
Scope *globalScope = NULL;
int semanticErrors = 0;

// ========== INICIALIZACIÓN ==========

void initSymbolTable() {
    globalScope = malloc(sizeof(Scope));
    globalScope->symbols = NULL;
    globalScope->parent = NULL;
    globalScope->level = 0;
    currentScope = globalScope;
    semanticErrors = 0;
}

void enterScope() {
    Scope *newScope = malloc(sizeof(Scope));
    newScope->symbols = NULL;
    newScope->parent = currentScope;
    newScope->level = currentScope->level + 1;
    currentScope = newScope;
}

void exitScope() {
    if (currentScope == globalScope) {
        return; // No salir del scope global
    }
    currentScope = currentScope->parent;
    // No liberamos el scope porque puede necesitarse para debugging
    // En producción podrías llamar freeScope(oldScope)
}

// ========== BÚSQUEDA DE SÍMBOLOS ==========

Symbol* lookupSymbolInCurrentScope(const char *name) {
    Symbol *current = currentScope->symbols;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Symbol* lookupSymbol(const char *name) {
    Scope *scope = currentScope;
    while (scope != NULL) {
        Symbol *current = scope->symbols;
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                return current;
            }
            current = current->next;
        }
        scope = scope->parent;
    }
    return NULL;
}

bool isDeclared(const char *name) {
    return lookupSymbol(name) != NULL;
}

bool isDeclaredInCurrentScope(const char *name) {
    return lookupSymbolInCurrentScope(name) != NULL;
}

// ========== INSERCIÓN DE SÍMBOLOS ==========

Symbol* insertSymbol(const char *name, SymbolKind kind, DataType type, 
                     int line, int column) {
    // Verificar si ya existe en el scope actual
    if (lookupSymbolInCurrentScope(name)) {
        semanticError(line, column, 
            "Redeclaración de '%s'", name);
        return NULL;
    }
    
    // Crear nuevo símbolo
    Symbol *newSym = malloc(sizeof(Symbol));
    newSym->name = strdup(name);
    newSym->kind = kind;
    newSym->type = type;
    newSym->customType = NULL;
    newSym->line = line;
    newSym->column = column;
    newSym->initialized = false;
    newSym->isGlobal = (currentScope == globalScope);
    newSym->parameters = NULL;
    newSym->returnType = TYPE_VOID;
    newSym->customReturnType = NULL;
    newSym->paramCount = 0;
    newSym->isArray = false;
    newSym->arraySize = 0;
    newSym->next = NULL;
    
    // Insertar al inicio de la lista del scope actual
    newSym->next = currentScope->symbols;
    currentScope->symbols = newSym;
    
    return newSym;
}

// ========== FUNCIONES AUXILIARES PARA SÍMBOLOS ==========

void setSymbolInitialized(Symbol *sym) {
    if (sym) {
        sym->initialized = true;
    }
}

void setSymbolAsArray(Symbol *sym, int size) {
    if (sym) {
        sym->isArray = true;
        sym->arraySize = size;
    }
}

void addParameter(Symbol *funcSym, const char *paramName, DataType paramType) {
    if (!funcSym || funcSym->kind != SYM_FUNCTION) {
        return;
    }
    
    Parameter *newParam = malloc(sizeof(Parameter));
    newParam->name = strdup(paramName);
    newParam->type = paramType;
    newParam->next = NULL;
    
    // Agregar al final de la lista
    if (funcSym->parameters == NULL) {
        funcSym->parameters = newParam;
    } else {
        Parameter *current = funcSym->parameters;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newParam;
    }
    
    funcSym->paramCount++;
}

void setReturnType(Symbol *funcSym, DataType returnType) {
    if (funcSym && funcSym->kind == SYM_FUNCTION) {
        funcSym->returnType = returnType;
    }
}

// ========== CONVERSIÓN DE TIPOS ==========

DataType stringToDataType(const char *typeStr) {
    if (!typeStr) return TYPE_UNKNOWN;
    
    if (strcmp(typeStr, "int") == 0) return TYPE_INT;
    if (strcmp(typeStr, "float32") == 0) return TYPE_FLOAT32;
    if (strcmp(typeStr, "float64") == 0) return TYPE_FLOAT64;
    if (strcmp(typeStr, "string") == 0) return TYPE_STRING;
    if (strcmp(typeStr, "bool") == 0) return TYPE_BOOL;
    if (strcmp(typeStr, "rune") == 0) return TYPE_RUNE;
    if (strcmp(typeStr, "byte") == 0) return TYPE_BYTE;
    if (strcmp(typeStr, "void") == 0) return TYPE_VOID;
    
    return TYPE_UNKNOWN;
}

const char* dataTypeToString(DataType type) {
    switch (type) {
        case TYPE_INT: return "int";
        case TYPE_FLOAT32: return "float32";
        case TYPE_FLOAT64: return "float64";
        case TYPE_STRING: return "string";
        case TYPE_BOOL: return "bool";
        case TYPE_RUNE: return "rune";
        case TYPE_BYTE: return "byte";
        case TYPE_VOID: return "void";
        case TYPE_CUSTOM: return "custom";
        case TYPE_UNKNOWN: return "unknown";
        default: return "unknown";
    }
}

bool areTypesCompatible(DataType type1, DataType type2) {
    // Tipos desconocidos son compatibles con todo (para evitar cascada de errores)
    if (type1 == TYPE_UNKNOWN || type2 == TYPE_UNKNOWN) {
        return true;
    }
    
    // Mismos tipos
    if (type1 == type2) {
        return true;
    }
    
    // Conversiones implícitas permitidas en Go (simplificado)
    // int -> float32/float64
    if (type1 == TYPE_INT && (type2 == TYPE_FLOAT32 || type2 == TYPE_FLOAT64)) {
        return true;
    }
    if (type2 == TYPE_INT && (type1 == TYPE_FLOAT32 || type1 == TYPE_FLOAT64)) {
        return true;
    }
    
    // float32 <-> float64
    if ((type1 == TYPE_FLOAT32 && type2 == TYPE_FLOAT64) ||
        (type1 == TYPE_FLOAT64 && type2 == TYPE_FLOAT32)) {
        return true;
    }
    
    return false;
}

DataType getResultType(DataType type1, DataType type2, const char *op) {
    // Si alguno es desconocido, retornar desconocido
    if (type1 == TYPE_UNKNOWN || type2 == TYPE_UNKNOWN) {
        return TYPE_UNKNOWN;
    }
    
    // Para operaciones aritméticas
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || 
        strcmp(op, "*") == 0 || strcmp(op, "/") == 0) {
        
        // Si ambos son int, resultado es int
        if (type1 == TYPE_INT && type2 == TYPE_INT) {
            return TYPE_INT;
        }
        
        // Si hay float64, resultado es float64
        if (type1 == TYPE_FLOAT64 || type2 == TYPE_FLOAT64) {
            return TYPE_FLOAT64;
        }
        
        // Si hay float32, resultado es float32
        if (type1 == TYPE_FLOAT32 || type2 == TYPE_FLOAT32) {
            return TYPE_FLOAT32;
        }
    }
    
    // Para operaciones de comparación
    if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
        strcmp(op, "<") == 0 || strcmp(op, ">") == 0 ||
        strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0) {
        return TYPE_BOOL;
    }
    
    // Para operaciones lógicas
    if (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0) {
        return TYPE_BOOL;
    }
    
    return type1; // Por defecto, retornar el primer tipo
}

// ========== REPORTE DE ERRORES ==========

void semanticError(int line, int column, const char *format, ...) {
    fprintf(stderr, "Error semántico [línea %d, columna %d]: ", line, column);
    
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    
    fprintf(stderr, "\n");
    semanticErrors++;
}

void printSymbol(Symbol *sym, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    
    printf("%-20s | ", sym->name);
    
    switch (sym->kind) {
        case SYM_VARIABLE:
            printf("Variable    | %-10s", dataTypeToString(sym->type));
            if (!sym->initialized) printf(" (no inicializada)");
            break;
        case SYM_CONSTANT:
            printf("Constante   | %-10s", dataTypeToString(sym->type));
            break;
        case SYM_FUNCTION:
            printf("Función     | retorna %-10s | %d parámetros", 
                   dataTypeToString(sym->returnType), sym->paramCount);
            break;
        case SYM_TYPE:
            printf("Tipo        | %-10s", dataTypeToString(sym->type));
            break;
        case SYM_PARAMETER:
            printf("Parámetro   | %-10s", dataTypeToString(sym->type));
            break;
    }
    
    printf(" (línea %d)\n", sym->line);
    
    // Imprimir parámetros si es función
    if (sym->kind == SYM_FUNCTION && sym->parameters) {
        Parameter *param = sym->parameters;
        while (param) {
            for (int i = 0; i < level + 1; i++) printf("  ");
            printf("  param: %s : %s\n", param->name, dataTypeToString(param->type));
            param = param->next;
        }
    }
}

void printScope(Scope *scope) {
    printf("\n--- Scope nivel %d ---\n", scope->level);
    Symbol *current = scope->symbols;
    while (current != NULL) {
        printSymbol(current, scope->level);
        current = current->next;
    }
}

// ========== LIBERACIÓN DE MEMORIA ==========

void freeParameter(Parameter *param) {
    if (!param) return;
    free(param->name);
    freeParameter(param->next);
    free(param);
}

void freeSymbol(Symbol *sym) {
    if (!sym) return;
    free(sym->name);
    if (sym->customType) free(sym->customType);
    if (sym->customReturnType) free(sym->customReturnType);
    if (sym->parameters) freeParameter(sym->parameters);
    free(sym);
}

void freeScope(Scope *scope) {
    if (!scope) return;
    
    Symbol *current = scope->symbols;
    while (current != NULL) {
        Symbol *temp = current;
        current = current->next;
        freeSymbol(temp);
    }
    
    free(scope);
}

void freeSymbolTable() {
    Scope *current = globalScope;
    while (current != NULL) {
        Scope *temp = current;
        current = current->parent;
        freeScope(temp);
    }
    globalScope = NULL;
    currentScope = NULL;
}