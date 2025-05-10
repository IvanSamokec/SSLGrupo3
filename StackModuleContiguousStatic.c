#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>

void Push(Stack *stack, int value) {
    if (IsFull(stack)) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

int Pop(Stack *stack) {
    if (IsEmpty(stack)) {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

bool IsEmpty(const Stack *stack) {
    return stack->top == -1;
}

bool IsFull(const Stack *stack) {
    return stack->top == STACK_MAX_SIZE - 1;
}