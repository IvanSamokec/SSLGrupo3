package main

import "fmt"

// funciones que reciben punteros
func modificar(p *int) {
    *p = 100
}

func obtener(p *int) int {
    valor := *p
    return valor
}

func main() {
    // variables "simples"
    var x, y int
    var numero, resultado int

    // inicialización de punteros
    ptr1 := new(int) // reserva espacio para un int y devuelve *int
    ptr2 := new(int)

    mensaje := new(string) // equivalente a char* en C, pero en Go usamos string

    // asignaciones
    numero = 10

    resultado = *ptr1
    *ptr2 = 20

    *ptr1 = numero
    numero = *ptr1

    *ptr1 = *ptr2

    x = *ptr1 + 5
    *ptr2 = x - 3

    if *ptr1 > 0 {
        *ptr1 = 50
    }

    for *ptr2 < 10 {
        *ptr2 = *ptr2 + 1
    }

    modificar(ptr1)

    resultado = obtener(ptr2)

    fmt.Println("mensaje:", *mensaje)
    fmt.Println("numero:", numero)
    fmt.Println("resultado:", resultado)
    fmt.Println("x:", x, "y:", y)
    fmt.Println("ptr1:", *ptr1, "ptr2:", *ptr2)
}
