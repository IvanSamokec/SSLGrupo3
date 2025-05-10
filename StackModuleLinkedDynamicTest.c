#include "stackModuleLinkedDynamic.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>

void TestStackOperations() {
    Stack stack;
    InitializeStack(&stack);

    // Test IsEmpty en un stack vacío
    assert(IsEmpty(&stack) == true);

    // Test Push
    Push(&stack, 10);
    assert(IsEmpty(&stack) == false);
    assert(Peek(&stack) == 10);

    // Test Push y Pop
    Push(&stack, 20);
    assert(Peek(&stack) == 20);
    assert(Pop(&stack) == 20);
    assert(Peek(&stack) == 10);

    // Test Pop hasta vaciar el stack
    assert(Pop(&stack) == 10);
    assert(IsEmpty(&stack) == true);

    // Test de múltiples Push y FreeStack
    for (int i = 0; i < 5; i++) {
        Push(&stack, i);
    }
    FreeStack(&stack);
    assert(IsEmpty(&stack) == true);
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
    printf("Tiempo total de ejecución (dinámico): %f segundos\n", cpu_time_used);
    return 0;
}