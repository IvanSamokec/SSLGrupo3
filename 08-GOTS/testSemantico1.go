package main

func main() {
    // Error: uso de variable no declarada
    x = 10
    
    // Error: uso de variable no declarada en expresión
    y := z + 5
    
    // Error: variable no declarada en condición
    if w > 0 {
        var a int = 1
    }
    
    // Correcto: variable declarada antes de usar
    var b int
    b = 20
}