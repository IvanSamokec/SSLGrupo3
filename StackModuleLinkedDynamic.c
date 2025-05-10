#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definición de un nodo de la pila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definición de la pila
typedef struct Stack {
    Node* top;
} Stack;

// Inicializa la pila
void InitializeStack(Stack* stack) {
    stack->top = NULL;
}

// Verifica si la pila está vacía
bool IsEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Empuja un elemento a la pila
void Push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Saca un elemento de la pila
int Pop(Stack* stack) {
    if (IsEmpty(stack)) {
        fprintf(stderr, "Error: Intento de hacer Pop en una pila vacía.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Devuelve el elemento en la cima de la pila sin sacarlo
int Peek(Stack* stack) {
    if (IsEmpty(stack)) {
        fprintf(stderr, "Error: Intento de hacer Peek en una pila vacía.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Libera toda la memoria de la pila
void FreeStack(Stack* stack) {
    while (!IsEmpty(stack)) {
        Pop(stack);
    }
}