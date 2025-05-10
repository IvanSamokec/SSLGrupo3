#include "StackModule.h"
#include <assert.h>
#include <stdio.h>
#include <time.h> // Incluye la biblioteca para medir el tiempo

void TestStackOperations() {
    Stack stack = {.top = -1}; // Inicialización del stack

    // Test IsEmpty en un stack vacío
    assert(IsEmpty(&stack) == true);
    assert(IsFull(&stack) == false);

    // Test Push
    Push(&stack, 10);
    assert(IsEmpty(&stack) == false);
    assert(stack.data[stack.top] == 10);

    // Test Push y Pop
    Push(&stack, 20);
    assert(stack.data[stack.top] == 20);
    assert(Pop(&stack) == 20);
    assert(stack.data[stack.top] == 10);

    // Test Pop hasta vaciar el stack
    assert(Pop(&stack) == 10);
    assert(IsEmpty(&stack) == true);

    // Test de límite superior
    for (int i = 0; i < STACK_MAX_SIZE; i++) {
        Push(&stack, i);
    }
    assert(IsFull(&stack) == true);
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    int iterations = 100000; // Número de iteraciones para medir el tiempo promedio

    start = clock(); // Inicia la medición del tiempo

    for (int i = 0; i < iterations; i++) {
        TestStackOperations(); // Ejecuta las pruebas en un bucle
    }

    end = clock(); // Termina la medición del tiempo

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcula el tiempo total en segundos

    printf("Tests pasados exitosamente.\n");
    printf("Tiempo total de ejecución (estático): %f segundos\n", cpu_time_used);

    return 0;
}