package main

import "fmt"

// Constante global
const LIMITE int = 100

// Variable global (simulando extern)
var mensaje string

// Variables globales
var x, y, z int = 0, 5, 0
var promedio float64

// Función sumar
func sumar(a int, b int) int {
    resultado := a + b
    return resultado
}

// Función calcularPromedio
func calcularPromedio(n int) float64 {
    suma := 0.0
    for i := 0; i < n; i++ {
        suma += float64(i)
    }
    if n > 0 {
        return suma / float64(n)
    }
    return 0
}

// Función saludar
func saludar() int {
    return 0
}

func main() {
    var i int
    var prom float64

    i = 10

    sumar(5, 1)

    // while en Go → for con condición
    for i > 0 {
        i = i - 1
    }

    // for clásico
    for i = 0; i < 10; i = i + 1 {
        prom = prom + float64(i)
    }

    if i == 0 {
        prom = calcularPromedio(5)
    } else {
        prom = 0
    }

    // operador ternario no existe en Go → if inline
    var res int
    if i == 10 {
        res = 1
    } else {
        res = 0
    }

    fmt.Println("x:", x, "y:", y, "z:", z)
    fmt.Println("promedio:", promedio, "prom:", prom)
    fmt.Println("mensaje:", mensaje)
    fmt.Println("resultado final:", res)
}
