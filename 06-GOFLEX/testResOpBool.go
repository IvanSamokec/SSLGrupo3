package main

import "fmt"

func main() {

    var x int = 5
    var decimal float64 = 3.14
    var letra rune = 'A'
    var grande float64 = 1.23e+10
    var contador int = 0o755        
    var real float64 = 0.001
    var variable1 int = 10
    var promedioFinal float64 = 8.75
    var activo bool = true
    var i int

    // if/else válido
    if x == contador {
        x += 2
    } else {
        contador--
    }

    //  "while" usando for
    for x > contador && x < 100 {
        x = x - 1
    }

    // for
    for i = 0; i < 10; i++ {
        fmt.Printf("Iteración %d\n", i)
        i -= 1
    }
    const mensaje string = "Hola mundo"

    var resultado int
    if activo {
        resultado = 1
    } else {
        resultado = 0
    }

    fmt.Println("Resultado:", resultado)
}
