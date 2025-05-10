#ifndef STACKMODULE_H
#define STACKMODULE_H

#include <stdbool.h>

// Define el tamaño máximo del stack
#define STACK_MAX_SIZE 100

// Tipo de dato para el stack
typedef struct {
    int data[STACK_MAX_SIZE]; // Arreglo que almacena los elementos del stack
    int top;                  // Índice del elemento superior del stack
} Stack;

/**
 * @brief Agrega un elemento al stack.
 * @param stack Puntero al stack donde se agregará el elemento.
 * @param value Valor del elemento a agregar.
 * @pre El stack no debe estar lleno (IsFull(stack) == false).a
 * @post El elemento se agrega al tope del stack.
 */
void Push(Stack *stack, int value);

/**
 * @brief Elimina y devuelve el elemento superior del stack.
 * @param stack Puntero al stack del cual se eliminará el elemento.
 * @return El valor del elemento eliminado.
 * @pre El stack no debe estar vacío (IsEmpty(stack) == false).
 * @post El elemento superior se elimina del stack.
 */
int Pop(Stack *stack);

/**
 * @brief Verifica si el stack está vacío.
 * @param stack Puntero al stack a verificar.
 * @return true si el stack está vacío, false en caso contrario.
 * @pre Ninguna.
 * @post No modifica el estado del stack.
 */
bool IsEmpty(const Stack *stack);

/**
 * @brief Verifica si el stack está lleno.
 * @param stack Puntero al stack a verificar.
 * @return true si el stack está lleno, false en caso contrario.
 * @pre Ninguna.
 * @post No modifica el estado del stack.
 */
bool IsFull(const Stack *stack);

#endif 

