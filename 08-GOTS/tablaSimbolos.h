#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackModule.h"
#include "arrayModule.h"

typedef enum {
    VARIABLE,
    ENUM,
    FUNCION
} SimboloTipo;

typedef struct {
    char* key;              // id
    SimboloTipo clase;      // var/fun
    char* tipoDato;         // tipo de dato
    int lineaDeclaracion;   // linea en la que se declaro
    int nivelScope;         // scope declaracion
    int constante;          // 1 cte o 0 no cte
    int externo;            // 1 externo o 0 no
    int unsg;               // 1 unsigned o 0 signed

    Array* miembros;       // funcion: array con el tipoDato parametros
                          // enum: array con valores del enum
    int cantMiembros;     // cantParametros funcion o cantVals enum
} Simbolo;

typedef struct {
    Array* simbolos;  // array de simbolos
    int cantidad;
} Scope;

typedef struct {
    stack_t* ambitos;   // pila de scopes
} TablaScopes;

typedef struct {
    char* nombre;
    int* valor;      // solo válido si tieneValor = 1
    int tieneValor;
} EnumMiembro;

TablaScopes* initTS() {
    TablaScopes* ts = (TablaScopes*) malloc(sizeof(TablaScopes));
    ts->ambitos = createStack();
    abrirScope(ts); // Scope global
    return ts;
}

void destroyTS(TablaScopes* tabla) {
    while (!isEmpty(tabla->ambitos)) {
        Scope* s = (Scope*) pop(tabla->ambitos);
        destruirScope(s);
    }
    destroyStack(tabla->ambitos);
    free(tabla);
}

Scope* crearScope() {
    Scope* s = (Scope*) malloc(sizeof(Scope));
    s->cantidad = 0;
    s->simbolos = createArray(50);
    return s;
}

void destruirScope(Scope* s) {
    for (int i = 0; i < arraySize(s->simbolos); i++) {
        Simbolo* sym = (Simbolo*) findElemArray(s->simbolos, i);
        if (sym->miembros) destroyArray(sym->miembros); // destruir array miembros dentro de cada simbolo q lo tenga
        free(sym);
    }
    destroyArray(s->simbolos);
    free(s);
}

void abrirScope(TablaScopes* tabla) {
    Scope* nuevo = crearScope();
    push(tabla->ambitos, nuevo);
    printf(">>> Nuevo scope abierto (nivel %d)\n", stackSize(tabla->ambitos));
}

void cerrarScope(TablaScopes* tabla) {
    if (!isEmpty(tabla->ambitos)) {
        Scope* actual = (Scope*) pop(tabla->ambitos);
        printf("<<< Cerrando scope (nivel %d)\n", stackSize(tabla->ambitos));
        destruirScope(actual);
    }
}

Simbolo* crearSimbolo ( 
    char* key,
    SimboloTipo clase,
    char* tipoDato,
    int lineaDeclaracion,
    int nivelScope,
    int constante,
    int externo,
    int unsg ) {
        Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
        s->key = key;
        s->clase = clase;
        s->tipoDato = tipoDato;
        s->lineaDeclaracion = lineaDeclaracion;
        s->nivelScope = nivelScope;
        s->constante = constante;
        s->externo = externo;
        s->unsg = unsg;
        s->miembros = createArray(50);
        s->cantMiembros = 0;

        return s;
}

// 1 (se agrego) o 0 duplicado
int agregarSimbolo(TablaScopes* tabla, Simbolo* nuevo) {
    Scope* actual = scopeActual(tabla);

    // Verificar duplicados en el mismo scope
    for (int i = 0; i < arraySize(actual->simbolos); i++) {
        Simbolo* existente = (Simbolo*) findElemArray(actual->simbolos, i);
        if (strcmp(existente->key, nuevo->key) == 0) {
            fprintf(stderr, "Error semántico: redeclaración de '%s' en el mismo scope (línea %d).\n",
                    nuevo->key, nuevo->lineaDeclaracion);
            return 0;
        }
    }

    insertElemArray(actual->simbolos, nuevo);
    actual->cantidad++;
    return 1;
}

//Buscar símbolo en todos los scopes (de adentro hacia afuera)
Simbolo* buscarSimbolo(TablaScopes* tabla, char* key) {
    node* actual = tabla->ambitos->top; //node con el scope actual y nodo al sig scope
    while (actual != NULL) {
        Scope* scope = (Scope*) actual->value;
        for (int i = 0; i < arraySize(scope->simbolos); i++) {
            Simbolo* s = (Simbolo*) findElemArray(scope->simbolos, i);
            if (strcmp(s->key, key) == 0) {
                return s;
            }
        }
        actual = actual->next; // siguiente scope exterior
    }
    return NULL; // no encontrado
}

Scope* scopeActual(TablaScopes* tabla) {
    if (isEmpty(tabla->ambitos)) return NULL;
    return (Scope*) tabla->ambitos->top->value;
}

#endif