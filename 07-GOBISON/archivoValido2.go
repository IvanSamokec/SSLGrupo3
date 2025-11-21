package main

import "fmt"

// Simulación de enum con iota
type Color int

const (
    ROJO Color = iota + 1
    VERDE
    AZUL
)

// Constante
const PI float64 = 3.14159

// Variable global (simulando extern)
var nombre string

// Función para verificar si un número es par
func esPar(num int) int {
    if num%2 == 0 {
        return 1
    } else {
        return 0
    }
}

// Factorial
func factorial(n int) float64 {
    resultado := 1.0
    i := 1
    for i <= n {
        resultado = resultado * float64(i)
        i++
    }
    return resultado
}

func main() {
    a, b := 10, 2
    var res, i int
    d := 5.0

    res = a + b*3
    res *= 2

    if res > 50 {
        a = 1
    } else {
        a = 0
    }

    for i = 0; i < 5; i++ {
        res += int(factorial(i))
    }

    // No existe operador ternario, se reemplaza con if inline
    if esPar(a) == 1 {
        res = a
    } else {
        res = -1
    }

    res = esPar(a + b)

    fmt.Println("Color ROJO:", ROJO)
    fmt.Println("Constante PI:", PI)
    fmt.Println("Variable nombre:", nombre)
    fmt.Println("Resultado final:", res, "d:", d)
}
