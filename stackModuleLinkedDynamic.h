#ifndef STACKMODULE_DYNAMIC_H
#define STACKMODULE_DYNAMIC_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* Stack;

void InitializeStack(Stack *stack);
bool IsEmpty(Stack *stack);
void Push(Stack *stack, int value);
int Pop(Stack *stack);
int Peek(Stack *stack);
void FreeStack(Stack *stack);

#endif
